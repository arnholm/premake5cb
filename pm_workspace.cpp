#include "pm_workspace.h"
#include "pm_project.h"
#include "pm_settings.h"
#include "pm_utils.h"

pm_workspace::pm_workspace()
{}

pm_workspace::~pm_workspace()
{}

void pm_workspace::premake_export(std::ostream& out)
{
   out << "workspace \"" << name() << "\"" << std::endl;
   out << "\tlocation \"" << location_name() << "\"" << std::endl;

   if(auto opt = settings()) opt->premake_export(1,out);

   for(auto proj : *this) {
      proj->premake_export(out);
   }
}
