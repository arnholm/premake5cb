#ifndef PM_CONFIG_H
#define PM_CONFIG_H

#include "pm_base.h"
class pm_settings;

class pm_config : public pm_base {
public:
   pm_config();
   virtual ~pm_config();

   // return C::B config name
   virtual wxString name() const = 0;

   virtual std::shared_ptr<pm_settings> settings() = 0;

   virtual wxString kind() = 0;

   virtual bool is_debug() const = 0;

   virtual void premake_export(std::ostream& out);
};

#endif // PM_CONFIG_H
