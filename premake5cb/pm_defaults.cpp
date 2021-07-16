#include "pm_defaults.h"

/* for debugging
#include <manager.h>
#include <logmanager.h>
*/

pm_defaults::pm_defaults(ConfigManager* cfgmgr)
: m_cfgmgr(cfgmgr)
{
   factory_settings();
   FromConfigManager();
}

pm_defaults::~pm_defaults()
{}

void pm_defaults::factory_settings()
{
//   Manager::Get()->GetLogManager()->Log("premake5cb: factory_settings()");

   m_settings_map["FileMasks"] =
   {
      "*.cpp"
     ,"*.h"
     ,"*.c"
   };

   m_settings_map["ProjectDefaults"] =
   {
      "language (\"c++\")"
      ,"cppdialect (\"c++17\")"
      ,"architecture (\"x86_64\")"
      ,"exceptionhandling (\"on\")"
      ,"pic (\"on\")"
      ,"rtti (\"on\")"
      ,"staticruntime (\"off\")"
   };

   m_settings_map["ConfigsRelease"] =
   {
      "defines (\"NDEBUG\")"
      ,"optimize (\"on\")"
   };

   m_settings_map["ConfigsDebug"] =
   {
      "defines (\"DEBUG\")"
      ,"symbols (\"on\")"
   };
}

void pm_defaults::FromConfigManager()
{
   for(auto& p : m_settings_map) {
      const wxString& key  = p.first;

      // only if the key exist in the config manager, we override the factory settings with those values
      if(m_cfgmgr->Exists(key)) {
         std::vector<wxString>&  vals = p.second;
         vals.clear();
         wxArrayString arr    = m_cfgmgr->ReadArrayString(key);

         // convert to vector
         size_t nval = arr.Count();
         for(size_t i=0; i<nval; i++) vals.push_back(arr[i]);
      }
   }
}

void pm_defaults::ToConfigManager()
{
   // traverse the settings and save with ConfigManager

   for(auto& p : m_settings_map) {
      const wxString& key                = p.first;
      const std::vector<wxString>&  vals = p.second;

      // convert to wxArrayString because ConfigManager supports that
      wxArrayString arr;
      for(auto s : vals) arr.Add(s);

      m_cfgmgr->Write(key,arr);
   }
}

