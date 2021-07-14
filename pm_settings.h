#ifndef pm_settings_H
#define pm_settings_H

#include <ostream>
#include <wx/string.h>
#include <vector>
#include <map>
#include "pm_utils.h"

// helper class to contain settings of various kinds
class pm_settings {
public:
   using settings_map = std::map<wxString,string_vec>;
   using iterator     = settings_map::iterator;

   pm_settings();
   virtual ~pm_settings();

   // assign a vector of values to a setting
   void assign(const wxString& key, const string_vec& v) { m_settings[key] = v; }

   // push a single value to a named setting
   void push_back(const wxString& key, const wxString& value) { m_settings[key].push_back(value); }

   // look up a particiular setting
   iterator find(const wxString& key) { return m_settings.find(key); }

   // traverse settings
   iterator begin() { return m_settings.begin(); }
   iterator end()   { return m_settings.end(); }

   // export to Lua
   void premake_export(size_t tabs, std::ostream& out);

private:
   settings_map m_settings;
};

#endif // pm_settings_H
