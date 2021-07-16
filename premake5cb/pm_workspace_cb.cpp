#include "pm_workspace_cb.h"
#include <stdexcept>
#include <set>

#include "projectmanager.h"
#include "pm_project_cb.h"
#include "pm_config.h"
#include "pm_settings.h"
#include <cbworkspace.h>
#include <cbproject.h>

pm_workspace_cb::pm_workspace_cb()
: m_settings(std::make_shared<pm_settings>())
{
 //  m_settings->assign("configurations",{"debug","release"});

   get_projects();
   get_dependencies();
}

pm_workspace_cb::~pm_workspace_cb()
{}

wxFileName pm_workspace_cb::filename() const
{
   cbWorkspace* ws = Manager::Get()->GetProjectManager()->GetWorkspace();
   return ws->GetFilename();
}


bool pm_workspace_cb::is_local_workspace() const
{
   for(auto proj : m_projects) {
      if(!proj->is_workspace_subdir())return false;
   }
   return true;
}


wxString pm_workspace_cb::location_name() const
{
   return "buildpm5";
}

void pm_workspace_cb::get_projects()
{
   m_projects.clear();

   std::set<wxString> configs;

   if(ProjectsArray* projects = Manager::Get()->GetProjectManager()->GetProjects()) {
      // number of projects in workspace
      int nproj = projects->GetCount();
      m_projects.reserve(nproj);
      for(int iproj=0; iproj<nproj; iproj++) {
         cbProject* project = (*projects)[iproj];
         if(project) {

            // insert project into workspace sorted vector
            auto pm_proj = std::make_shared<pm_project_cb>(this,project);
            m_projects.push_back(pm_proj);

            for(auto it=pm_proj->config_begin(); it!=pm_proj->config_end(); it++) {
               auto config = *it;
               if(config->is_debug())configs.insert("debug");
               else                  configs.insert("release");
            }

            // also insert in lookup map
            m_pmap[project] = pm_proj;
         }
      }
   }

   for(auto c : configs) {
      m_settings->push_back("configurations",c);
   }
}

void pm_workspace_cb::get_dependencies()
{
   for(auto proj : m_projects) {
      proj->resolve_includes();
   }
}

pm_project_vec pm_workspace_cb::dependencies(const cbProject* cbproject) const
{
   pm_project_vec deps;

   if(const ProjectsArray* depends = Manager::Get()->GetProjectManager()->GetDependenciesForProject(const_cast<cbProject*>(cbproject))) {
      int ndep = depends->GetCount();
      for(int i=0; i<ndep; i++) {
         cbProject* dep = (*depends)[i];
         auto it = m_pmap.find(dep);
         if(it!=m_pmap.end()) deps.push_back(it->second);
      }
   }

   return deps;
}