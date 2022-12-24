#include <wx/wx.h>
#include <fstream>
#include <string>
#include "globals.h"

/*
Code make by zabbix | zabbix@ztrunks.space
*/

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString &title);

private:
	void on_load_button(wxCommandEvent &evt);
	void on_pistol_menu_deagle(wxCommandEvent &evt);
	void on_pistol_menu_TEC9(wxCommandEvent& evt);
	void on_pistol_menu_P2000(wxCommandEvent& evt);
	void on_pistol_menu_Glock(wxCommandEvent& evt);
	void on_pistol_menu_Berettas(wxCommandEvent& evt);
	void on_pistol_menu_CZ75A(wxCommandEvent& evt);
	void on_pistol_menu_P250(wxCommandEvent& evt);
	void on_pistol_menu_SeveN(wxCommandEvent& evt);
	void on_pistol_menu_Revolver(wxCommandEvent& evt);
	void on_change_star_value(wxCommandEvent& evt);
	void on_change_name_value(wxCommandEvent& evt);
	void on_change_knife_skin_value(wxCommandEvent& evt);
	void update_skin_id_knife(wxCommandEvent& evt);
	void on_pistol_menu_UPS(wxCommandEvent& evt);
	void st_stk(wxCommandEvent& evt);
	void on_pistol_menu_FAMAS(wxCommandEvent& evt);
	void on_pistol_menu_M4A4(wxCommandEvent& evt);
	void on_pistol_menu_M4A1(wxCommandEvent& evt);
	void on_pistol_menu_AUG(wxCommandEvent& evt);
	void on_pistol_menu_SCAR(wxCommandEvent& evt);
	void on_pistol_menu_SSG08(wxCommandEvent& evt);
	void on_pistol_menu_AWP(wxCommandEvent& evt);
	void on_pistol_menu_GALIL(wxCommandEvent& evt);
	void on_pistol_menu_AK(wxCommandEvent& evt);
	void on_pistol_menu_SG(wxCommandEvent& evt);
	void on_pistol_menu_G3SG1(wxCommandEvent& evt);
	void on_pistol_menu_Nova(wxCommandEvent& evt);
	void on_pistol_menu_XM1014(wxCommandEvent& evt);
	void on_pistol_menu_Sawed(wxCommandEvent& evt);
	void on_pistol_menu_MAG(wxCommandEvent& evt);
	void on_pistol_menu_M249(wxCommandEvent& evt);
	void on_pistol_menu_Negev(wxCommandEvent& evt);
	void on_pistol_menu_MP9(wxCommandEvent& evt);
	void on_pistol_menu_MAC(wxCommandEvent& evt);
	void on_pistol_menu_MP7(wxCommandEvent& evt);
	void on_pistol_menu_UMP(wxCommandEvent& evt);
	void on_pistol_menu_P90(wxCommandEvent& evt);
	void on_pistol_menu_Bizon(wxCommandEvent& evt);
	void on_pistol_menu_MP5(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};


class UPSDialog : public wxDialog
{
public:
	UPSDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};




class DeagleDialog : public wxDialog
{
public:
    DeagleDialog(wxWindow* parent, const wxString& value);

private:
    void on_change(wxCommandEvent& evt);
};


class Tec9Dialog : public wxDialog
{
public:
	Tec9Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};


class P2000Dialog : public wxDialog
{
public:
	P2000Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class GlockDialog : public wxDialog
{
public:
	GlockDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class BerettasDialog : public wxDialog
{
public:
	BerettasDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class CZ75Dialog : public wxDialog
{
public:
	CZ75Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class P250Dialog : public wxDialog
{
public:
	P250Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class SeveNDialog : public wxDialog
{
public:
	SeveNDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class R8Dialog : public wxDialog
{
public:
	R8Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
}; 

class FAMASDialog : public wxDialog
{
public:
	FAMASDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};


class M4A4Dialog : public wxDialog
{
public:
	M4A4Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};


class M4A1Dialog : public wxDialog
{
public:
	M4A1Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class AUGDialog : public wxDialog
{
public:
	AUGDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class SCARDialog : public wxDialog
{
public:
	SCARDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class SSG08Dialog : public wxDialog
{
public:
	SSG08Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class AWPDialog : public wxDialog
{
public:
	AWPDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class GALILDialog : public wxDialog
{
public:
	GALILDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};


class AKDialog : public wxDialog
{
public:
	AKDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class SGDialog : public wxDialog
{
public:
	SGDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class G3SG1Dialog : public wxDialog
{
public:
	G3SG1Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class NovaDialog : public wxDialog
{
public:
	NovaDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class XM1014Dialog : public wxDialog
{
public:
	XM1014Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class SawedDialog : public wxDialog
{
public:
	SawedDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class MAGDialog : public wxDialog
{
public:
	MAGDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class M249Dialog : public wxDialog
{
public:
	M249Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class NegevDialog : public wxDialog
{
public:
	NegevDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class MP9Dialog : public wxDialog
{
public:
	MP9Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class MACDialog : public wxDialog
{
public:
	MACDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class MP7Dialog : public wxDialog
{
public:
	MP7Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class UMPDialog : public wxDialog
{
public:
	UMPDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class P90Dialog : public wxDialog
{
public:
	P90Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class BizonDialog : public wxDialog
{
public:
	BizonDialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};

class MP5Dialog : public wxDialog
{
public:
	MP5Dialog(wxWindow* parent, const wxString& value);

private:
	void on_change(wxCommandEvent& evt);
};