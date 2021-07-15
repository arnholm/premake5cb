#include "pm_project.h"
#include "pm_settings.h"
#include "pm_file.h"
#include "pm_config.h"

pm_project::pm_project()
{}

pm_project::~pm_project()
{}

void pm_project::premake_export(std::ostream& out)
{
   wxString kind = (*config_begin())->kind();
   if(kind=="WindowedApp")return;

   out << std::endl
       << "\tproject \""    << name() << "\"" << std::endl
       << "\t\tlocation \"" << location_name() << "\"" << std::endl;

   if(auto opt = settings()) opt->premake_export(2,out);

   // path from workspace to project
   wxString project_path = relative_path();

   // traverse files
   out << std::endl;
   out << "\t\t-- file paths below are relative to this .lua file" << std::endl;
   out << "\t\tfiles {" << std::endl;
   size_t icount = 0;
   for(auto f : *this) {
      out << "\t\t\t";
      if(icount++>0) out << ',';
      out << "\"" << project_path << '/' << f->relative_filename().GetFullPath()  << "\"" ;
      out << std::endl;
   }
   out << "\t\t\t}" << std::endl;

   // traverse configs
   size_t numdbg=0;
   size_t numrel=0;
   for(auto it = config_begin(); it!= config_end(); it++) {
      auto config = *it;
      if(config->is_debug()) {
         if(numdbg==0) {
            config->premake_export(out);
            numdbg++;
         }
      }
      else {
         if(numrel==0) {
            config->premake_export(out);
            numrel++;
         }
      }
   }

}
