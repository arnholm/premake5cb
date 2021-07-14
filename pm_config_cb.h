#ifndef PM_CONFIG_CB_H
#define PM_CONFIG_CB_H

#include "pm_config.h"
class ProjectBuildTarget;
class pm_settings;

class pm_config_cb : public pm_config {
public:
   pm_config_cb(ProjectBuildTarget* cbtarget);
   virtual ~pm_config_cb();

   // return config name
   virtual wxString name() const { return m_name; }

   virtual std::shared_ptr<pm_settings> settings() { return m_settings; }

   wxString kind();

   bool is_debug() const;

protected:

   void get_defines();

private:
   ProjectBuildTarget*          m_cbtarget;
   std::shared_ptr<pm_settings> m_settings;  // settings on config/target level
   bool                         m_is_debug;  // this is a debug config
   wxString                     m_name;
};

#endif // PM_CONFIG_CB_H
