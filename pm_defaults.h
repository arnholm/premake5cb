#ifndef PM_DEFAULTS_H
#define PM_DEFAULTS_H

#include <map>
#include <vector>
#include <wx/string.h>
#include <memory>

#include <configmanager.h>

using SettingsMap = std::map<wxString,std::vector<wxString>>;

class pm_defaults {
public:
   pm_defaults(ConfigManager* cfgmgr);
   virtual ~pm_defaults();

   // retrieve a vector ov values assiciated with the key
   const std::vector<wxString>&  get(const wxString& key) { return m_settings_map[key]; }

   // store a vector of values under the key
   void put(const wxString& key, const std::vector<wxString>& vals) { m_settings_map[key] = vals; }

   // save settings to C::B ConfigManager
   void ToConfigManager();

   // restore settings from C::B ConfigManager
   void FromConfigManager();

   // these are the initial default settings you get
   // they may be overridden by the user by editing in the GUI
   // and they may be overridden by translatingthe C::B project data
   void factory_settings();

private:
   SettingsMap    m_settings_map;
   ConfigManager* m_cfgmgr;
};

#endif // PM_DEFAULTS_H
