#include "PM5SettingsDialog.h"

//(*InternalHeaders(PM5SettingsDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PM5SettingsDialog)
const long PM5SettingsDialog::ID_TEXTCTRL1 = wxNewId();
const long PM5SettingsDialog::ID_CHECKBOX1 = wxNewId();
const long PM5SettingsDialog::ID_CHECKBOX2 = wxNewId();
const long PM5SettingsDialog::ID_STATICTEXT3 = wxNewId();
const long PM5SettingsDialog::ID_BUTTON1 = wxNewId();
const long PM5SettingsDialog::ID_PANEL1 = wxNewId();
const long PM5SettingsDialog::ID_STATICTEXT2 = wxNewId();
const long PM5SettingsDialog::ID_TEXTCTRL4 = wxNewId();
const long PM5SettingsDialog::ID_PANEL3 = wxNewId();
const long PM5SettingsDialog::ID_STATICTEXT1 = wxNewId();
const long PM5SettingsDialog::ID_TEXTCTRL3 = wxNewId();
const long PM5SettingsDialog::ID_TEXTCTRL2 = wxNewId();
const long PM5SettingsDialog::ID_PANEL2 = wxNewId();
const long PM5SettingsDialog::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PM5SettingsDialog,wxScrollingDialog)
	//(*EventTable(PM5SettingsDialog)
	//*)
END_EVENT_TABLE()

PM5SettingsDialog::PM5SettingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PM5SettingsDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxButton* FactorySettingsButton;
	wxNotebook* Notebook1;
	wxPanel* PanelConfigDefaults;
	wxPanel* PanelGeneral;
	wxPanel* PanelProjectDefaults;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("File masks"));
	FileMasks = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(-1,200), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(FileMasks, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(0,400,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 2, wxALL|wxEXPAND, 5);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(200,0), 0, _T("ID_NOTEBOOK1"));
	PanelGeneral = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	CheckExport = new wxCheckBox(PanelGeneral, ID_CHECKBOX1, _("Automatic export on build"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckExport->SetValue(false);
	BoxSizer3->Add(CheckExport, 0, wxALL|wxALIGN_LEFT, 5);
	CheckUsePrefix = new wxCheckBox(PanelGeneral, ID_CHECKBOX2, _("Use workspace prefix in premake5 filename"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckUsePrefix->SetValue(false);
	BoxSizer3->Add(CheckUsePrefix, 0, wxALL|wxALIGN_LEFT, 5);
	BoxSizer3->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, PanelGeneral, _("Factory settings"));
	StaticText3 = new wxStaticText(PanelGeneral, ID_STATICTEXT3, _("Warning: This cannot be undone!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FactorySettingsButton = new wxButton(PanelGeneral, ID_BUTTON1, _("Restore factory settings"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer4->Add(FactorySettingsButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND, 5);
	PanelGeneral->SetSizer(BoxSizer3);
	PanelProjectDefaults = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(PanelProjectDefaults, ID_STATICTEXT2, _("Settings apply to premake project level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer8->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer8, 0, wxEXPAND, 5);
	ProjectDefaults = new wxTextCtrl(PanelProjectDefaults, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer5->Add(ProjectDefaults, 1, wxALL|wxEXPAND, 5);
	PanelProjectDefaults->SetSizer(BoxSizer5);
	PanelConfigDefaults = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(PanelConfigDefaults, ID_STATICTEXT1, _("Settings apply to premake configurations filters"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer7->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer7, 0, wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, PanelConfigDefaults, _("Debug"));
	ConfigsDebug = new wxTextCtrl(PanelConfigDefaults, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer3->Add(ConfigsDebug, 1, wxALL|wxEXPAND, 5);
	BoxSizer6->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, PanelConfigDefaults, _("Release"));
	ConfigsRelease = new wxTextCtrl(PanelConfigDefaults, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer1->Add(ConfigsRelease, 1, wxALL|wxEXPAND, 5);
	BoxSizer6->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	BoxSizer4->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
	PanelConfigDefaults->SetSizer(BoxSizer4);
	Notebook1->AddPage(PanelGeneral, _("General"), false);
	Notebook1->AddPage(PanelProjectDefaults, _("Project defaults"), false);
	Notebook1->AddPage(PanelConfigDefaults, _("Config defaults"), false);
	BoxSizer2->Add(Notebook1, 6, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxEXPAND, 5);
	BoxSizer1->Add(900,0,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, wxEmptyString));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PM5SettingsDialog::OnFactorySettingsButtonClick);
	//*)
}

PM5SettingsDialog::~PM5SettingsDialog()
{
	//(*Destroy(PM5SettingsDialog)
	//*)
}

std::vector<wxString> PM5SettingsDialog::GetLines(wxTextCtrl* ctrl)
{
   std::vector<wxString> strings;
   for(int i=0; i<ctrl->GetNumberOfLines(); i++) {
      strings.push_back(ctrl->GetLineText(i));
   }
   return strings;
}

void PM5SettingsDialog::PutLines(wxTextCtrl* ctrl, const std::vector<wxString>& lines)
{
   ctrl->Clear();
   for(auto& l : lines) (*ctrl) << l << '\n';
}


void PM5SettingsDialog::ToDialog(std::shared_ptr<pm_defaults> defaults)
{
   m_defaults = defaults;
   PutLines(FileMasks,defaults->get("FileMasks"));
   PutLines(ProjectDefaults,defaults->get("ProjectDefaults"));
   PutLines(ConfigsRelease,defaults->get("ConfigsRelease"));
   PutLines(ConfigsDebug,defaults->get("ConfigsDebug"));
}

void PM5SettingsDialog::FromDialog(std::shared_ptr<pm_defaults> defaults)
{
   defaults->put("FileMasks",GetLines(FileMasks));
   defaults->put("ProjectDefaults",GetLines(ProjectDefaults));
   defaults->put("ConfigsRelease",GetLines(ConfigsRelease));
   defaults->put("ConfigsDebug",GetLines(ConfigsDebug));
   m_defaults = defaults;
}

void PM5SettingsDialog::OnFactorySettingsButtonClick(wxCommandEvent& event)
{
   if(m_defaults.get()) {
      m_defaults->factory_settings();
      ToDialog(m_defaults);
   }
}
