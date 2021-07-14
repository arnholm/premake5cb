#ifndef PM_PROJECT_CB_H
#define PM_PROJECT_CB_H

#include "pm_project.h"
#include "pm_utils.h"
class pm_workspace;
class cbProject;
class pm_regex;
class pm_settings;

class pm_project_cb : public pm_project {
public:
   pm_project_cb(pm_workspace* ws, cbProject* cbproject);
   virtual ~pm_project_cb();

   // return full filename of the original cb project
   virtual wxFileName filename() const;

   // premake5 location
   virtual wxString location_name();

   virtual size_t size() const { return m_files.size(); }
   pm_file_iterator begin()    { return m_files.begin(); }
   pm_file_iterator end()      { return m_files.end(); }

   virtual std::shared_ptr<pm_settings> settings() { return m_settings; }

   pm_config_iterator config_begin() { return m_configs.begin(); }
   pm_config_iterator config_end() { return m_configs.end(); }

   virtual pm_project_vec dependencies() const;

   virtual void resolve_includes();

protected:
   void get_files();
   void get_configs();
   void get_defines();

private:
   pm_workspace*  m_ws;         // parent workspace
   cbProject*     m_cbproject;  // C::B project

   std::shared_ptr<pm_regex> m_regx;

   pm_file_vec               m_files;
   pm_config_vec             m_configs;

   std::shared_ptr<pm_settings> m_settings;  // settings on project level
};

#endif // PM_PROJECT_CB_H
