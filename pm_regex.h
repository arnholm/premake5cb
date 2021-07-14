#ifndef PM_REGEX_H
#define PM_REGEX_H

#include <wx/string.h>
#include <string>
#include <vector>
#include <memory>

class pm_regex {
public:
   pm_regex();
   virtual ~pm_regex();

   void push_back(wxString mask);

   bool regex_match(const wxString& name);

   // create pm_regex for typical c/c++ project
   static std::shared_ptr<pm_regex> default_cpp();

private:
   std::vector<std::string> m_masks;
};

#endif // PM_REGEX_H
