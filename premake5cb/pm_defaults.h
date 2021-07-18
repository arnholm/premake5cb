#ifndef PM_DEFAULTS_H
#define PM_DEFAULTS_H

#include <map>
#include <vector>
#include <wx/string.h>
#include <memory>

#include <configmanager.h>

class pm_settings;

using SettingsMap = std::map<wxString,std::vector<wxString>>;
using AliasMap    = std::map<wxString,wxString>; // <libname,projectname>

class pm_defaults {
public:
   pm_defaults(ConfigManager* cfgmgr);
   virtual ~pm_defaults();

   // translate selected categoryo int a pm_settings object
   //   "workspace_defaults"
   //   "project_defaults"
   //   "configurations_release"
   //   "configurations_debug"
   std::shared_ptr<pm_settings> get_settings(const wxString& category);

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
   // and they may be overridden by translating the C::B project data
   void factory_settings();

   // insert a name alias, libname is name of library in build target to be replaced by alias = project name
   void insert_alias(const wxString& libname, const wxString& projname) { m_alias_map[libname] = projname; }

   // look up alias, return libname if not found
   wxString get_alias(const wxString& libname) const;

private:
   SettingsMap    m_settings_map;
   ConfigManager* m_cfgmgr;

   AliasMap       m_alias_map;
};

#endif // PM_DEFAULTS_H


