#include "pm_regex.h"

#include <regex>

pm_regex::pm_regex()
{
   //ctor
}

pm_regex::~pm_regex()
{
   //dtor
}

void pm_regex::push_back(wxString mask)
{
   mask.Replace(".","\\.");
   mask.Replace("?",".");
   mask.Replace("*",".*");
   m_masks.push_back(mask.ToStdString());
}

bool pm_regex::regex_match(const wxString& wxname)
{
   std::string name = wxname.ToStdString();
   for(auto& mask : m_masks) {
      std::smatch what;
      std::regex pattern(mask);
      if(std::regex_match(name,what,pattern)) return true;
   }
   return false;
}

std::shared_ptr<pm_regex>  pm_regex::default_cpp()
{
   auto regx = std::make_shared<pm_regex>();
   regx->push_back("*.cpp");
   regx->push_back("*.c");
   regx->push_back("*.h");

   return regx;
}
