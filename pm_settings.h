#ifndef pm_settings_H
#define pm_settings_H

#include <ostream>
#include <wx/string.h>
#include <vector>
#include <map>
#include "pm_utils.h"

class pm_settings {
public:
   using settings_map = std::map<wxString,string_vec>;
   using iterator     = settings_map::iterator;

   pm_settings();
   virtual ~pm_settings();

   void assign(const wxString& key, const string_vec& v) { m_settings[key] = v; }
   void push_back(const wxString& key, const wxString& value) { m_settings[key].push_back(value); }

   iterator find(const wxString& key) { return m_settings.find(key); }

   iterator begin() { return m_settings.begin(); }
   iterator end()   { return m_settings.end(); }

   void premake_export(size_t tabs, std::ostream& out);

private:
   settings_map m_settings;
};

#endif // pm_settings_H
