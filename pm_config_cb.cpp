#include "pm_config_cb.h"
#include <projectbuildtarget.h>
#include "pm_settings.h"

pm_config_cb::pm_config_cb(ProjectBuildTarget* cbtarget)
: m_cbtarget(cbtarget)
, m_settings(std::make_shared<pm_settings>())
, m_is_debug(false)
{
  m_name = m_cbtarget->GetTitle();

  get_defines();
}

pm_config_cb::~pm_config_cb()
{}

wxString pm_config_cb::kind()
{
   wxString stype = "Unknown";
   TargetType type = m_cbtarget->GetTargetType();
   switch(type) {
      case ttExecutable:   { stype = "WindowedApp"; break; }
      case ttConsoleOnly:  { stype = "ConsoleApp"; break; }
      case ttStaticLib:    { stype = "StaticLib"; break; }
      case ttDynamicLib:   { stype = "SharedLib"; break; }
      case ttCommandsOnly: { stype = "None"; break; }
      case ttNative:       { stype = "None"; break; }
      default: { stype = "None"; }
   };
   return stype;
}

void pm_config_cb::get_defines()
{
   const wxArrayString& opts = m_cbtarget->GetCompilerOptions();
   for(int i=0; i<opts.GetCount(); i++) {
      wxString str = opts[i];
      wxString sub = str.SubString(0,2);
      if(sub=="-D" || sub == "/D") {
         wxString def = sub.erase(0,2);
         m_settings->push_back("defines",def);
      }
      else {
         int j = str.Find("c++");
         if(j != wxNOT_FOUND) {
            m_settings->push_back("cppdialect",str.Mid(j));
         }
      }

      if(!m_is_debug) {
         if(str.Find("MDd") != wxNOT_FOUND) m_is_debug = true;
         else if(str.Find("DEBUG") != wxNOT_FOUND) m_is_debug = true;
      }
   }

   if(m_is_debug) {
      m_name =  "configurations:debug";
      m_settings->push_back("defines","DEBUG");
      m_settings->push_back("symbols","On");
   }
   else {
      m_name =  "configurations:release";
      m_settings->push_back("defines","NDEBUG");
      m_settings->push_back("optimize","On");
   }
   m_settings->push_back("kind",kind());

   const wxArrayString& links = m_cbtarget->GetLinkLibs();
   for(int i=0; i<links.GetCount(); i++) {

      // anything but MS libraries
      if(links[i].Find("msvc") == wxNOT_FOUND) {
         m_settings->push_back("links",links[i]);
      }
   }
}

bool pm_config_cb::is_debug() const
{
   return m_is_debug;
}
