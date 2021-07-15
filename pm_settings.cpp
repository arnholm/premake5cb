#include "pm_settings.h"

pm_settings::pm_settings()
{}

pm_settings::~pm_settings()
{}

void pm_settings::premake_export(size_t tabs, std::ostream& out)
{
   // traverse all contained settings
   for(auto& p : *this) {
      const wxString& key    = p.first;
      const string_vec& vals = p.second;

      // looks like "()" is for single values and "{}" is for multiple
      char left='(';
      char right=')';
      if(vals.size()>1){
         left='{';
         right='}';
      }

      if(key == "includedirs") {
         for(size_t i=0;i<tabs;i++) out << '\t';
         out << "-- include dirs are relative to location of generated makefile" << std::endl;
      }

      for(size_t i=0;i<tabs;i++) out << '\t';
      out << key << " "<< left << " ";
      for(size_t i=0; i<vals.size();i++) {
         if(i>0) out << ',';
         out << "\""<<vals[i]<<"\"";
      }
      out << " "<<right << " " << std::endl;
   }
}
