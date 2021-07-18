#include "pm_workspace.h"
#include "pm_project.h"
#include "pm_settings.h"
#include "pm_utils.h"
#include <set>

using project_set = std::set<std::shared_ptr<pm_project>>;

static void export_depends(std::shared_ptr<pm_project> proj, project_set& done, std::ostream& out)
{
   if(done.find(proj) == done.end()) {

      pm_project_vec deps = proj->dependencies();
      for(auto dep_proj : deps) {
         export_depends(dep_proj,done,out);
      }

      proj->premake_export(out);
      done.insert(proj);
   }
}

pm_workspace::pm_workspace()
{}

pm_workspace::~pm_workspace()
{}

void pm_workspace::premake_export(std::ostream& out)
{
   out << "-- premake5 script, genrated by Code::Blocks plugin premake5cb by cacb" << std::endl;
   out << "workspace \"" << name() << "\"" << std::endl;
   out << "\tlocation \"" << location_path() << "\"" << std::endl;

   // export the workspace settings
   if(auto opt = settings()) {
      opt->premake_export(1,out);
   }

   std::set<std::shared_ptr<pm_project>> projects_done;

   // export each project, taking dependencies into account
   // Not sure if this is required, because we issue premake "dependson" commands,
   // but this should ensure that "dependson" references are to projects listed above in the premake5 file,
   // i.e. that projects are listed in an order consistent with dependencies
   project_set done;
   for(auto proj : *this) {
      export_depends(proj,done,out);
   }
}
