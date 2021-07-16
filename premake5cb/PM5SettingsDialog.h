#ifndef PM5SettingsDialog_H
#define PM5SettingsDialog_H

#include <vector>
#include "pm_defaults.h"

//(*Headers(PM5SettingsDialog)
#include "scrollingdialog.h"
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class PM5SettingsDialog: public wxScrollingDialog
{
	public:

		PM5SettingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PM5SettingsDialog();

		void ToDialog(std::shared_ptr<pm_defaults> defaults);
		void FromDialog(std::shared_ptr<pm_defaults> defaults);

		std::vector<wxString> GetLines(wxTextCtrl* ctrl);
		void PutLines(wxTextCtrl* ctrl, const std::vector<wxString>& lines);

		//(*Declarations(PM5SettingsDialog)
		wxCheckBox* CheckExport;
		wxCheckBox* CheckUsePrefix;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* ConfigsDebug;
		wxTextCtrl* ConfigsRelease;
		wxTextCtrl* FileMasks;
		wxTextCtrl* ProjectDefaults;
		//*)

	protected:

		//(*Identifiers(PM5SettingsDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL4;
		static const long ID_PANEL3;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL2;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(PM5SettingsDialog)
		void OnFactorySettingsButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
   private:
     std::shared_ptr<pm_defaults> m_defaults;
};

#endif