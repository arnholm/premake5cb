#include "pm_workspace.h"
#include "pm_project.h"
#include "pm_defaults.h"
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
   bool post_build_copy = defaults()->get_bool_flag("post_build_copy");

   out << "-- premake5 script, generated by Code::Blocks plugin premake5cb by cacb" << std::endl;

   out << std::endl;
   out << "function build_location()" << std::endl;
   out << "   -- _ACTION is the premake5 action, e.g. gmake2, vs2019 etc." << std::endl;
   out << "   return \"build/\".._ACTION" << std::endl;
   out << "end" << std::endl;

   out << std::endl;
   out << "function file_exists(name)" << std::endl;
   out << "   local f=io.open(name,\"r\")" << std::endl;
   out << "   if f~=nil then io.close(f) return true else return false end" << std::endl;
   out << "end" << std::endl;

   const std::string external_dependencies = name().ToStdString() + "_external_dependencies.lua";
   out << std::endl;
   out << "function external_dependencies()" << std::endl;
   out << "    if file_exists(\""<<external_dependencies<<"\") then" << std::endl;
   out << "       include \""<<external_dependencies<<"\"" << std::endl;
   out << "       print (\"including '"<<external_dependencies<<"'\")" << std::endl;
   out << "    end" << std::endl;
   out << "end" << std::endl;

   if(post_build_copy) {
      out << std::endl;
      out << "function post_build_copy()" << std::endl;
      out << "   postbuildcommands ( \"{MKDIR} %{wks.location}/%{cfg.shortname}\" ) " << std::endl;
      out << "   postbuildcommands ( \"{COPYFILE} %{cfg.buildtarget.directory}/* %{wks.location}/%{cfg.shortname}\" ) " << std::endl;
      out << "end" << std::endl;
   }

   out << std::endl;
   out << "workspace \"" << name() << "\"" << std::endl;
   out << "\tlocation ( " << location_path() <<" )"<< std::endl;
   out << "\texternal_dependencies()"<< std::endl;
   if(post_build_copy) out << "\tpost_build_copy()"<< std::endl;

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
