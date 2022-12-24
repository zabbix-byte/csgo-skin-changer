#include <wx/wx.h>
#include "app.h"
#include "main_frame.h"
#include "logo.xpm"


/*
Code make by zabbix | zabbix@ztrunks.space

This UI SkinChanger for CsGo.

*/

wxIMPLEMENT_APP(SkinChanger);

bool SkinChanger::OnInit()
{
	MainFrame *mainFrame = new MainFrame("ZT - Skin Changer");
	mainFrame->SetIcon(logo);
	mainFrame->SetClientSize(350, 150);
	mainFrame->Center();
	mainFrame->Show();
	mainFrame->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER));
	mainFrame->SetBackgroundColour(wxColour(*wxWHITE));
	return true;
}
