#include "main_frame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/menu.h>
#include "process.h"
#include <iostream>
#include <sstream>

using namespace std;

/*
Code make by zabbix | zabbix@ztrunks.space
*/


struct  WeapSKIN weapskin;
struct  AppConfig appconf;


#define item1 (wxID_HIGHEST + 1)


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	// EVT_TEXT(ID_DEAGLE, MainFrame::on_deagle_change)
wxEND_EVENT_TABLE()

int get_skin_id_by_name(const char* name) 
{

	int default_index = 0;
	if (_stricmp("KNIFE", name) == 0) { return ID_KNIFE; }
	if (_stricmp("KNIFE_T", name) == 0) { return ID_KNIFE_T; }
	if (_stricmp("BUTTERFLY", name) == 0) { return ID_KNIFE_BUTTERFLY; }
	if (_stricmp("FALCHION", name) == 0) { return ID_KNIFE_FALCHION; }
	if (_stricmp("FLIP", name) == 0) { return ID_KNIFE_FLIP;  }
	if (_stricmp("GUT", name) == 0) { return ID_KNIFE_GUT; }
	if (_stricmp("NAVAJA", name) == 0) { return ID_KNIFE_NAVAJA; }
	if (_stricmp("KARAMBIT", name) == 0) { return ID_KNIFE_KARAMBIT; }
	if (_stricmp("M9_BAYONET", name) == 0) { return ID_KNIFE_M9_BAYONET; }
	if (_stricmp("DAGGERS", name) == 0) { return ID_KNIFE_DAGGERS; }
	if (_stricmp("STILETTO", name) == 0) { return ID_KNIFE_STILETTO; }
	if (_stricmp("BOWIE", name) == 0) { return ID_KNIFE_BOWIE; }
	if (_stricmp("HUNTSMAN", name) == 0) { return ID_KNIFE_HUNTSMAN; }
	if (_stricmp("URSUS", name) == 0) { return ID_KNIFE_URSUS; }
	if (_stricmp("TALON", name) == 0) { return ID_KNIFE_TALON; }
	return default_index;
}

const char* get_skin_name_by_id(int id)
{
	const char* default_index = "KNIFE";
	if (ID_KNIFE == id) { return "KNIFE"; }
	if (ID_KNIFE_T == id) { return "KNIFE_T"; }
	if (ID_KNIFE_BUTTERFLY == id) { return "BUTTERFLY"; }
	if (ID_KNIFE_FALCHION == id) { return "FALCHION"; }
	if (ID_KNIFE_FLIP == id) { return "FLIP"; }
	if (ID_KNIFE_GUT == id) { return "GUT"; }
	if (ID_KNIFE_NAVAJA == id) { return "NAVAJA"; }
	if (ID_KNIFE_KARAMBIT == id) { return "KARAMBIT"; }
	if (ID_KNIFE_M9_BAYONET == id) { return "M9_BAYONET"; }
	if (ID_KNIFE_DAGGERS == id) { return "DAGGERS"; }
	if (ID_KNIFE_STILETTO == id) { return "STILETTO"; }
	if (ID_KNIFE_BOWIE == id) { return "BOWIE"; }
	if (ID_KNIFE_HUNTSMAN == id) { return "HUNTSMAN"; }
	if (ID_KNIFE_URSUS == id) { return "URSUS"; }
	if (ID_KNIFE_TALON == id) { return "TALON"; }
	return default_index;
}


int get_skin_list_id_with_id(int id)
{
	int default_index = 0;
	if (ID_KNIFE == id) { return 0; }
	if (ID_KNIFE_T == id) { return 1; }
	if (ID_KNIFE_BUTTERFLY == id) { return 2; }
	if (ID_KNIFE_FALCHION == id) { return 3; }
	if (ID_KNIFE_FLIP == id) { return 4; }
	if (ID_KNIFE_GUT == id) { return 5; }
	if (ID_KNIFE_NAVAJA == id) { return 6; }
	if (ID_KNIFE_KARAMBIT == id) { return 7; }
	if (ID_KNIFE_M9_BAYONET == id) { return 8; }
	if (ID_KNIFE_DAGGERS == id) { return 9; }
	if (ID_KNIFE_STILETTO == id) { return 10; }
	if (ID_KNIFE_BOWIE == id) { return 11; }
	if (ID_KNIFE_HUNTSMAN == id) { return 12; }
	if (ID_KNIFE_URSUS == id) { return 13; }
	if (ID_KNIFE_TALON == id) { return 14; }
	return default_index;
}

const char* get_model_string_by_id(int knifeID)
{
	UINT modelIndex = 0;
	switch (knifeID)
	{
	case ID_KNIFE:
		return  "models/weapons/v_knife_default_ct.mdl";
		break;
	case ID_KNIFE_T:
		return  "models/weapons/v_knife_default_t.mdl";
		break;
	case ID_KNIFE_BUTTERFLY:
		return  "models/weapons/v_knife_butterfly.mdl";
		break;
	case ID_KNIFE_FALCHION:
		return  "models/weapons/v_knife_falchion_advanced.mdl";
		break;
	case ID_KNIFE_FLIP:
		return  "models/weapons/v_knife_flip.mdl";
		break;
	case ID_KNIFE_GUT:
		return  "models/weapons/v_knife_gut.mdl";
		break;
	case ID_KNIFE_NAVAJA:
		return  "models/weapons/v_knife_gypsy_jackknife.mdl";
		break;
	case ID_KNIFE_KARAMBIT:
		return  "models/weapons/v_knife_karam.mdl";
		break;
	case ID_KNIFE_M9_BAYONET:
		return  "models/weapons/v_knife_m9_bay.mdl";
		break;
	case ID_KNIFE_DAGGERS:
		return  "models/weapons/v_knife_push.mdl";
		break;
	case ID_KNIFE_STILETTO:
		return  "models/weapons/v_knife_stiletto.mdl";
		break;
	case ID_KNIFE_BOWIE:
		return  "models/weapons/v_knife_survival_bowie.mdl";
		break;
	case ID_KNIFE_HUNTSMAN:
		return  "models/weapons/v_knife_tactical.mdl";
		break;
	case ID_KNIFE_URSUS:
		return  "models/weapons/v_knife_ursus.mdl";
		break;
	case ID_KNIFE_TALON:
		return  "models/weapons/v_knife_widowmaker.mdl";
		break;
	default:
		break;
	}
	return "ERROR";
}


bool write_game_config() 
{

	ifstream skins_file("./skins.config");
	ofstream fw("./skins.config", std::ofstream::out);

	if (fw.is_open())
	{
		fw << "DEAGLE "<< weapskin.DEAGLE << endl;
		fw << "SCAR20 "<< weapskin.SCAR20 << endl;
		fw << "ELITE "<< weapskin.ELITE << endl;
		fw << "FIVESEVEN "<< weapskin.FIVESEVEN << endl;
		fw << "GLOCK "<< weapskin.GLOCK << endl;
		fw << "AK47 "<< weapskin.AK47 << endl;
		fw << "AUG "<< weapskin.AUG << endl;
		fw << "AWP "<< weapskin.AWP << endl;
		fw << "FAMAS "<< weapskin.FAMAS << endl;
		fw << "G3SG1 "<< weapskin.G3SG1 << endl;
		fw << "GALILAR "<< weapskin.GALILAR << endl;
		fw << "M249 "<< weapskin.M249 << endl;
		fw << "M4A1 "<< weapskin.M4A1 << endl;
		fw << "MAC10 "<< weapskin.MAC10 << endl;
		fw << "P90 "<< weapskin.P90 << endl;
		fw << "MP5SD "<< weapskin.MP5SD << endl;
		fw << "UMP45 "<< weapskin.UMP45 << endl;
		fw << "XM1014 "<< weapskin.XM1014 << endl;
		fw << "BIZON "<< weapskin.BIZON << endl;
		fw << "MAG7 "<< weapskin.MAG7 << endl;
		fw << "NEGEV "<< weapskin.NEGEV << endl;
		fw << "SAWEDOFF "<< weapskin.SAWEDOFF << endl;
		fw << "TEC9 "<< weapskin.TEC9 << endl;
		fw << "TASER "<< weapskin.TASER << endl;
		fw << "HKP2000 "<< weapskin.HKP2000 << endl;
		fw << "MP7 "<< weapskin.MP7 << endl;
		fw << "MP9 "<< weapskin.MP9 << endl;
		fw << "NOVA "<< weapskin.NOVA << endl;
		fw << "P250 "<< weapskin.P250 << endl;
		fw << "SG556 "<< weapskin.SG556 << endl;
		fw << "SSG08 "<< weapskin.SSG08 << endl;
		fw << "M4A1_SILENCER "<< weapskin.M4A1_SILENCER << endl;
		fw << "USP_SILENCER "<< weapskin.USP_SILENCER << endl;
		fw << "CZ75A "<< weapskin.CZ75A << endl;
		fw << "REVOLVER "<< weapskin.REVOLVER << endl;
		fw.close();
	}
	return true;
}


bool write_app_config()
{

	ifstream skins_file("./app.config");
	ofstream fw("./app.config", std::ofstream::out);

	if (fw.is_open())
	{
		fw << "StatTrak " << appconf.StatTrak << endl;
		fw << "NameOfStatTrak " << appconf.ST_NAME << endl;
		fw << "StatTrakValue " << to_string(appconf.StatTrakValue) << endl;
		fw << "SkinValueKnife " << to_string(appconf.SkinValueKnife) << endl;
		fw << "SkinKnife " << to_string(appconf.SkinKnife) << endl;

		
		fw.close();
	}
	return true;
}


// loadin game config
bool load_game_config()
{
	ifstream skins_file;
	ifstream app_conf_file;

	skins_file.open("skins.config", ios::in);

	if (skins_file.is_open())
	{
		string param;
		int value;
		while (!skins_file.eof())
		{
			skins_file >> param;
			skins_file >> value;
			if (param == "DEAGLE")
			{
				weapskin.DEAGLE = value;
			}
			if (param == "SCAR20")
			{
				weapskin.SCAR20 = value;
			}
			if (param == "ELITE")
			{
				weapskin.ELITE = value;
			}
			if (param == "FIVESEVEN")
			{
				weapskin.FIVESEVEN = value;
			}
			if (param == "GLOCK")
			{
				weapskin.GLOCK = value;

			}
			if (param == "AK47")
			{
				weapskin.AK47 = value;

			}
			if (param == "AUG")
			{
				weapskin.AUG = value;
			}
			if (param == "AWP")
			{
				weapskin.AWP = value;
			}
			if (param == "FAMAS")
			{
				weapskin.FAMAS = value;
			}
			if (param == "G3SG1")
			{
				weapskin.G3SG1 = value;
			}
			if (param == "GALILAR")
			{
				weapskin.GALILAR = value;
			}
			if (param == "M249")
			{
				weapskin.M249 = value;
			}
			if (param == "M4A1")
			{
				weapskin.M4A1 = value;
			}
			if (param == "MAC10")
			{
				weapskin.MAC10 = value;
			}
			if (param == "P90")
			{
				weapskin.P90 = value;
			}
			if (param == "MP5SD")
			{
				weapskin.MP5SD = value;
			}
			if (param == "UMP45")
			{
				weapskin.UMP45 = value;
			}
			if (param == "XM1014")
			{
				weapskin.XM1014 = value;
			}
			if (param == "BIZON")
			{
				weapskin.BIZON = value;
			}
			if (param == "MAG7")
			{
				weapskin.MAG7 = value;
			}
			if (param == "NEGEV")
			{
				weapskin.NEGEV = value;
			}
			if (param == "SAWEDOFF")
			{
				weapskin.SAWEDOFF = value;
			}
			if (param == "TEC9")
			{
				weapskin.TEC9 = value;
			}
			if (param == "TASER")
			{
				weapskin.TASER = value;
			}
			if (param == "HKP2000")
			{
				weapskin.HKP2000 = value;
			}
			if (param == "MP7")
			{
				weapskin.MP7 = value;
			}
			if (param == "MP9")
			{
				weapskin.MP9 = value;
			}
			if (param == "NOVA")
			{
				weapskin.NOVA = value;
			}
			if (param == "P250")
			{
				weapskin.P250 = value;
			}
			if (param == "SG556")
			{
				weapskin.SG556 = value;
			}
			if (param == "SSG08")
			{
				weapskin.SSG08 = value;
			}
			if (param == "M4A1_SILENCER")
			{
				weapskin.M4A1_SILENCER = value;
			}
			if (param == "USP_SILENCER")
			{
				weapskin.USP_SILENCER = value;
			}
			if (param == "REVOLVER") 
			{
				weapskin.REVOLVER = value;
			}
			if (param == "CZ75A") {
				weapskin.CZ75A = value;
			}


		}

		skins_file.close();
	}

	app_conf_file.open("app.config", ios::in);

	if (app_conf_file.is_open())
	{
		string param;
		string value;
		while (!app_conf_file.eof())
		{
			app_conf_file >> param;
			app_conf_file >> value;

			if (param == "StatTrak")
			{
				appconf.StatTrak = value;
			}
			if (param == "NameOfStatTrak")
			{
				appconf.ST_NAME = value;
			}
			if (param == "StatTrakValue")
			{
				appconf.StatTrakValue = stoi(value);
			}
			if (param == "SkinValueKnife")
			{
				appconf.SkinValueKnife = stoi(value);
			}
			if (param == "SkinKnife")
			{
				appconf.SkinKnife = stoi(value);
			}
			
		}

		app_conf_file.close();
	}


	return true;
}


enum IDs
{
	RESET_BUTTON = 1200,
	DEAGLE_MENU = 1201,
	UPDATE_MENU = 1202,
	PISTOL_WINDOW = 1203,
	TEC9_MENU = 1204,
	P2000_MENU = 1205,
	Glock_MENU  = 1206,
	Berettas_MENU = 1207,
	CZ75_MENU = 1208,
	P250_MENU = 1209,
	SeveN_MENU = 1210,
	R8_MENU = 1211,
	UPS_MENU = 1211,
	FAMAS_MENU = 1212,
	M4A4_MENU = 1213,
	M4A1_MENU = 1214,
	AUG_MENU = 1215,
	SCAR_MENU = 1216,
	SSG08_MENU = 1217,
	AWP_MENU = 1218,
	GALIL_MENU = 1219,
	AK_MENU = 1220,
	SG_MENU = 1221,
	G3SG1_MENU = 1222,
	Nova_MENU = 1223,
	XM1014_MENU = 1224,
	Sawed_MENU = 1225,
	MAG_MENU = 1226,
	M249_MENU = 1227,
	Negev_MENU = 1228,
	MP9_MENU = 1229,
	MAC_MENU = 1230,
	MP7_MENU = 1231,
	UMP_MENU = 1232,
	P90_MENU = 1233,
	Bizon_MENU = 1234,
	MP5_MENU = 1235
};


MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
	load_game_config();
	
	/* MENU BAR */
	wxMenuBar *menu_bar = new wxMenuBar();

	wxMenu *pistols_menu = new wxMenu();
	wxMenu *heavy_menu = new wxMenu();
	wxMenu *smgs_menu = new wxMenu();
	wxMenu *rifels_menu = new wxMenu();
	wxMenu *knifes_menu = new wxMenu();
	wxMenu *app = new wxMenu();

	menu_bar->Append(pistols_menu, _("&PISTOLS"));
	menu_bar->Append(heavy_menu, _("&HEAVY"));
	menu_bar->Append(smgs_menu, _("&SMGS"));
	menu_bar->Append(rifels_menu, _("&RIFELS"));
	menu_bar->Append(app, _("&APP"));

	pistols_menu->Append(DEAGLE_MENU, "DEAGLE");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_deagle, this, DEAGLE_MENU);

	pistols_menu->Append(TEC9_MENU, "TEC9");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_TEC9, this, TEC9_MENU);

	pistols_menu->Append(P2000_MENU, "P2000");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_P2000, this, P2000_MENU);

	pistols_menu->Append(Glock_MENU, "Glock");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Glock, this, Glock_MENU);

	pistols_menu->Append(Berettas_MENU, "Berettas");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Berettas, this, Berettas_MENU);

	pistols_menu->Append(CZ75_MENU, "CZ75A");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_CZ75A, this, CZ75_MENU);

	pistols_menu->Append(P250_MENU, "P250");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_P250, this, P250_MENU);

	pistols_menu->Append(SeveN_MENU, "Five-SeveN");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_SeveN, this, SeveN_MENU);


	pistols_menu->Append(R8_MENU, "R8 Revolver");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Revolver, this, R8_MENU);


	pistols_menu->Append(UPS_MENU, "UPS");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_UPS, this, UPS_MENU);

	rifels_menu->Append(FAMAS_MENU, "FAMAS");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_FAMAS, this, FAMAS_MENU);

	rifels_menu->Append(M4A4_MENU, "M4A4");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_M4A4, this, M4A4_MENU);

	rifels_menu->Append(M4A1_MENU, "M4A1");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_M4A1, this, M4A1_MENU);

	rifels_menu->Append(AUG_MENU, "AUG");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_AUG, this, AUG_MENU);

	rifels_menu->Append(SCAR_MENU, "SCAR");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_SCAR, this, SCAR_MENU);

	rifels_menu->Append(SSG08_MENU, "SSG08");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_SSG08, this, SSG08_MENU);

	rifels_menu->Append(AWP_MENU, "AWP");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_AWP, this, AWP_MENU);

	rifels_menu->Append(GALIL_MENU, "GALIL");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_GALIL, this, GALIL_MENU);

	rifels_menu->Append(AK_MENU, "AK");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_AK, this, AK_MENU);

	rifels_menu->Append(SG_MENU, "SG");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_SG, this, SG_MENU);

	rifels_menu->Append(G3SG1_MENU, "G3SG1");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_G3SG1, this, G3SG1_MENU);

	heavy_menu->Append(Nova_MENU, "Nova");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Nova, this, Nova_MENU);

	heavy_menu->Append(XM1014_MENU, "XM1014");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_XM1014, this, XM1014_MENU);

	heavy_menu->Append(Sawed_MENU, "Sawed");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Sawed, this, Sawed_MENU);

	heavy_menu->Append(MAG_MENU, "MAG");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_MAG, this, MAG_MENU);

	heavy_menu->Append(Sawed_MENU, "M249");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_M249, this, Sawed_MENU);

	heavy_menu->Append(Negev_MENU, "Negev");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Negev, this, Negev_MENU);

	

	smgs_menu->Append(MP9_MENU, "MP9");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_MP9, this, MP9_MENU);

	smgs_menu->Append(MAC_MENU, "MAC");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_MAC, this, MAC_MENU);

	smgs_menu->Append(MP7_MENU, "MP7");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_MP7, this, MP7_MENU);

	smgs_menu->Append(UMP_MENU, "UMP");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_UMP, this, UMP_MENU);

	smgs_menu->Append(P90_MENU, "P90");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_P90, this, P90_MENU);

	smgs_menu->Append(Bizon_MENU, "Bizon");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_Bizon, this, Bizon_MENU);

	smgs_menu->Append(MP5_MENU, "MP5");
	this->Bind(wxEVT_MENU, &MainFrame::on_pistol_menu_MP5, this, MP5_MENU);

	app->Append(UPDATE_MENU, "Update - F1 to stop");
	this->Bind(wxEVT_MENU, &MainFrame::on_load_button, this, UPDATE_MENU);



	SetMenuBar(menu_bar);

	/* END */

	wxPanel *pistol_panel = new wxPanel(this);
	pistol_panel->SetBackgroundColour(wxColour(*wxBLACK));
	pistol_panel->Show(true);
	
	wxCheckBox* STAK = new wxCheckBox(pistol_panel, wxID_ANY, "StatTrak", wxPoint(10, 12));
	if (appconf.StatTrak == "1") {
		STAK->SetValue(true);
	}
	STAK->Bind(wxEVT_CHECKBOX, &MainFrame::st_stk, this);

	STAK->SetForegroundColour(wxColour(*wxWHITE));
	wxButton* RUN = new wxButton(pistol_panel, wxID_ANY, "LOAD SKINS - PRESS F1 TO STOP", wxPoint(30, 90), wxSize(280, 50));
	RUN->Bind(wxEVT_BUTTON, &MainFrame::on_load_button, this);


	RUN->SetBackgroundColour(wxColour(*wxBLACK));
	RUN->SetForegroundColour(wxColour(*wxWHITE));
	
	wxStaticText* label_value = new wxStaticText(pistol_panel, wxID_ANY, "Knife Skin:", wxPoint(150, 37), wxSize(60, 15));
	label_value->SetForegroundColour(wxColour(*wxWHITE));

	wxStaticText* label_star = new wxStaticText(pistol_panel, wxID_ANY, "Tag Name:", wxPoint(150, 12), wxSize(60, 15));
	label_star->SetForegroundColour(wxColour(*wxWHITE));

	wxStaticText* label_knife = new wxStaticText(pistol_panel, wxID_ANY, "Knife:", wxPoint(150, 60), wxSize(40, 15));
	label_knife->SetForegroundColour(wxColour(*wxWHITE));


	wxTextCtrl* star_value = new wxTextCtrl(pistol_panel, wxID_ANY, to_string(appconf.StatTrakValue), wxPoint(10, 37), wxSize(120, 20));
	star_value->SetValue(to_string(appconf.StatTrakValue));
	star_value->Bind(wxEVT_TEXT, &MainFrame::on_change_star_value, this);

	wxTextCtrl* star_text = new wxTextCtrl(pistol_panel, wxID_ANY, appconf.ST_NAME, wxPoint(220, 10), wxSize(120, 20));
	star_text->SetValue(appconf.ST_NAME);
	star_text->Bind(wxEVT_TEXT, &MainFrame::on_change_name_value, this);

	wxTextCtrl* skin_text = new wxTextCtrl(pistol_panel, wxID_ANY, to_string(appconf.SkinValueKnife), wxPoint(220, 35), wxSize(120, 20));
	skin_text->SetValue(to_string(appconf.SkinValueKnife));
	skin_text->Bind(wxEVT_TEXT, &MainFrame::on_change_knife_skin_value, this);
	
	
	wxArrayString choises;
	choises.Add("KNIFE");
	choises.Add("KNIFE_T");
	choises.Add("BUTTERFLY");
	choises.Add("FALCHION");
	choises.Add("FLIP");
	choises.Add("GUT");
	choises.Add("NAVAJA");
	choises.Add("KARAMBIT");
	choises.Add("M9_BAYONET");
	choises.Add("DAGGERS");
	choises.Add("STILETTO");
	choises.Add("BOWIE");
	choises.Add("HUNTSMAN");
	choises.Add("URSUS");
	choises.Add("TALON");




	wxChoice* choise = new wxChoice(pistol_panel, wxID_ANY, wxPoint(220, 60), wxSize(120, 20), choises);
	choise->Select(get_skin_list_id_with_id(appconf.SkinKnife));
	choise->Bind(wxEVT_CHOICE, &MainFrame::update_skin_id_knife, this);
	wxString current_knife = choise->GetStringSelection();
	appconf.SkinKnife = get_skin_id_by_name(current_knife.c_str());

	CreateStatusBar();

	wxLogStatus(" Made by ZABBIX | ZT SKINCHANGER");


}


void MainFrame::update_skin_id_knife(wxCommandEvent& evt)
{
	appconf.SkinKnife = get_skin_id_by_name(evt.GetString().c_str());
	write_app_config();
	wxLogStatus("Updating model to: %s", evt.GetString().c_str());
}



void MainFrame::st_stk(wxCommandEvent& evt)
{
	if (appconf.StatTrak == "1") {
		appconf.StatTrak = "0";
	}
	else {
		appconf.StatTrak = "1";
	}
	write_app_config();
}

void MainFrame::on_change_star_value(wxCommandEvent& evt)
{
	appconf.StatTrakValue = atoi(evt.GetString().c_str());
	write_app_config();
}

void MainFrame::on_change_name_value(wxCommandEvent& evt)
{
	appconf.ST_NAME = evt.GetString().c_str();
	write_app_config();
}

void MainFrame::on_change_knife_skin_value(wxCommandEvent& evt)
{
	appconf.SkinValueKnife = atoi(evt.GetString().c_str());
	write_app_config();
}


/* UPS */
UPSDialog::UPSDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_USP_SILENCER, to_string(weapskin.USP_SILENCER), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &UPSDialog::on_change, this);
}

void UPSDialog::on_change(wxCommandEvent& evt)
{
	weapskin.USP_SILENCER = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_UPS(wxCommandEvent& evt)
{
	UPSDialog* ne = new UPSDialog(this, "Editing UPS");
	ne->Show(true);
}
/* END */

/* DEAGLE */
DeagleDialog::DeagleDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        wxPanel* ne_p = new wxPanel(this);
        ne_p->SetBackgroundColour(wxColour(*wxWHITE));
        wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_DEAGLE, to_string(weapskin.DEAGLE), wxPoint(15, 15), wxSize(200, 25));
        ne_p->Show(true);
		id_skin->Bind(wxEVT_TEXT, &DeagleDialog::on_change, this);
}

void DeagleDialog::on_change(wxCommandEvent &evt)
{
	weapskin.DEAGLE = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_deagle(wxCommandEvent &evt)
{
	DeagleDialog* ne = new DeagleDialog(this, "Editing deagle");
	ne->Show(true);
}
/* END */


/* TEC9 */
Tec9Dialog::Tec9Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_DEAGLE, to_string(weapskin.TEC9), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &Tec9Dialog::on_change, this);
}

void Tec9Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.TEC9 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_TEC9(wxCommandEvent& evt)
{
	Tec9Dialog* ne = new Tec9Dialog(this, "Editing TEC9");
	ne->Show(true);
}
/* END */

/* P2000Dialog */
P2000Dialog::P2000Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_HKP2000, to_string(weapskin.HKP2000), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &P2000Dialog::on_change, this);
}

void P2000Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.HKP2000 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_P2000(wxCommandEvent& evt)
{
	P2000Dialog* ne = new P2000Dialog(this, "Editing P2000");
	ne->Show(true);
}
/* END */

/* GlockDialog */
GlockDialog::GlockDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_GLOCK, to_string(weapskin.GLOCK), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &GlockDialog::on_change, this);
}

void GlockDialog::on_change(wxCommandEvent& evt)
{
	weapskin.GLOCK = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Glock(wxCommandEvent& evt)
{
	GlockDialog* ne = new GlockDialog(this, "Editing Glock");
	ne->Show(true);
}
/* END */

/* BerettasDialog */
BerettasDialog::BerettasDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_ELITE, to_string(weapskin.ELITE), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &BerettasDialog::on_change, this);
}

void BerettasDialog::on_change(wxCommandEvent& evt)
{
	weapskin.ELITE = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Berettas(wxCommandEvent& evt)
{
	BerettasDialog* ne = new BerettasDialog(this, "Editing Berettas");
	ne->Show(true);
}
/* END */


/* CZ75Dialog */
CZ75Dialog::CZ75Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_CZ75A, to_string(weapskin.CZ75A), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &CZ75Dialog::on_change, this);
}

void CZ75Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.CZ75A = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_CZ75A(wxCommandEvent& evt)
{
	CZ75Dialog* ne = new CZ75Dialog(this, "Editing CZ75A");
	ne->Show(true);
}
/* END */


/* P250Dialog */
P250Dialog::P250Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_P250, to_string(weapskin.P250), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &P250Dialog::on_change, this);
}

void P250Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.P250 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_P250(wxCommandEvent& evt)
{
	P250Dialog* ne = new P250Dialog(this, "Editing P250");
	ne->Show(true);
}
/* END */


/* SeveNDialog */
SeveNDialog::SeveNDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_FIVESEVEN, to_string(weapskin.FIVESEVEN), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &SeveNDialog::on_change, this);
}

void SeveNDialog::on_change(wxCommandEvent& evt)
{
	weapskin.FIVESEVEN = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_SeveN(wxCommandEvent& evt)
{
	SeveNDialog* ne = new SeveNDialog(this, "Editing FIVESEVEN");
	ne->Show(true);
}
/* END */


/* SeveNDialog */
R8Dialog::R8Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_REVOLVER, to_string(weapskin.REVOLVER), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &R8Dialog::on_change, this);
}

void R8Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.REVOLVER = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Revolver(wxCommandEvent& evt)
{
	R8Dialog* ne = new R8Dialog(this, "Editing Revolver");
	ne->Show(true);
}
/* END */


/* FAMASDialog */
FAMASDialog::FAMASDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_FAMAS, to_string(weapskin.FAMAS), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &FAMASDialog::on_change, this);
}

void FAMASDialog::on_change(wxCommandEvent& evt)
{
	weapskin.FAMAS = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_FAMAS(wxCommandEvent& evt)
{
	FAMASDialog* ne = new FAMASDialog(this, "Editing FAMAS");
	ne->Show(true);
}
/* END */


/* M4A4Dialog */
M4A4Dialog::M4A4Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_M4A1, to_string(weapskin.M4A1), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &M4A4Dialog::on_change, this);
}

void M4A4Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.M4A1 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_M4A4(wxCommandEvent& evt)
{
	M4A4Dialog* ne = new M4A4Dialog(this, "Editing M4A4");
	ne->Show(true);
}
/* END */

/* M4A1Dialog */
M4A1Dialog::M4A1Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_M4A1_SILENCER, to_string(weapskin.M4A1_SILENCER), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &M4A1Dialog::on_change, this);
}

void M4A1Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.M4A1_SILENCER = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_M4A1(wxCommandEvent& evt)
{
	M4A1Dialog* ne = new M4A1Dialog(this, "Editing M4A1");
	ne->Show(true);
}
/* END */

/* AUGDialog */
AUGDialog::AUGDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_AUG, to_string(weapskin.AUG), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &AUGDialog::on_change, this);
}

void AUGDialog::on_change(wxCommandEvent& evt)
{
	weapskin.AUG = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_AUG(wxCommandEvent& evt)
{
	AUGDialog* ne = new AUGDialog(this, "Editing AUG");
	ne->Show(true);
}

/* END */

/* SCARDialog */
SCARDialog::SCARDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_SCAR20, to_string(weapskin.SCAR20), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &SCARDialog::on_change, this);
}

void SCARDialog::on_change(wxCommandEvent& evt)
{
	weapskin.SCAR20 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_SCAR(wxCommandEvent& evt)
{
	SCARDialog* ne = new SCARDialog(this, "Editing SCAR20");
	ne->Show(true);
}

/* END */

/* SSG08Dialog */
SSG08Dialog::SSG08Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_SSG08, to_string(weapskin.SSG08), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &SSG08Dialog::on_change, this);
}

void SSG08Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.SSG08 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_SSG08(wxCommandEvent& evt)
{
	SSG08Dialog* ne = new SSG08Dialog(this, "Editing SSG08");
	ne->Show(true);
}
/* END */

/* SSG08Dialog */
AWPDialog::AWPDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_AWP, to_string(weapskin.AWP), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &AWPDialog::on_change, this);
}

void AWPDialog::on_change(wxCommandEvent& evt)
{
	weapskin.AWP = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_AWP(wxCommandEvent& evt)
{
	AWPDialog* ne = new AWPDialog(this, "Editing AWP");
	ne->Show(true);
}
/* END */

/* GALILDialog */
GALILDialog::GALILDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_GALILAR, to_string(weapskin.GALILAR), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &GALILDialog::on_change, this);
}

void GALILDialog::on_change(wxCommandEvent& evt)
{
	weapskin.GALILAR = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_GALIL(wxCommandEvent& evt)
{
	GALILDialog* ne = new GALILDialog(this, "Editing GALIL");
	ne->Show(true);
}
/* END */

/* AKDialog */
AKDialog::AKDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_AK47, to_string(weapskin.AK47), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &AKDialog::on_change, this);
}

void AKDialog::on_change(wxCommandEvent& evt)
{
	weapskin.AK47 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_AK(wxCommandEvent& evt)
{
	AKDialog* ne = new AKDialog(this, "Editing AK");
	ne->Show(true);
}
/* END */

/* SGDialog */
SGDialog::SGDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_SG556, to_string(weapskin.SG556), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &SGDialog::on_change, this);
}

void SGDialog::on_change(wxCommandEvent& evt)
{
	weapskin.SG556 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_SG(wxCommandEvent& evt)
{
	SGDialog* ne = new SGDialog(this, "Editing SG");
	ne->Show(true);
}
/* END */

/* G3SG1Dialog */
G3SG1Dialog::G3SG1Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_G3SG1, to_string(weapskin.G3SG1), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &G3SG1Dialog::on_change, this);
}

void G3SG1Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.G3SG1 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_G3SG1(wxCommandEvent& evt)
{
	G3SG1Dialog* ne = new G3SG1Dialog(this, "Editing G3SG1");
	ne->Show(true);
}
/* END */

/* NovaDialog */
NovaDialog::NovaDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_NOVA, to_string(weapskin.NOVA), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &NovaDialog::on_change, this);
}

void NovaDialog::on_change(wxCommandEvent& evt)
{
	weapskin.NOVA = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Nova(wxCommandEvent& evt)
{
	NovaDialog* ne = new NovaDialog(this, "Editing Nova");
	ne->Show(true);
}
/* END */


/* XM1014Dialog */
XM1014Dialog::XM1014Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_XM1014, to_string(weapskin.XM1014), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &XM1014Dialog::on_change, this);
}

void XM1014Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.XM1014 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_XM1014(wxCommandEvent& evt)
{
	XM1014Dialog* ne = new XM1014Dialog(this, "Editing XM1014");
	ne->Show(true);
}
/* END */

/* SawedDialog */
SawedDialog::SawedDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_SAWEDOFF, to_string(weapskin.SAWEDOFF), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &SawedDialog::on_change, this);
}

void SawedDialog::on_change(wxCommandEvent& evt)
{
	weapskin.SAWEDOFF = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Sawed(wxCommandEvent& evt)
{
	SawedDialog* ne = new SawedDialog(this, "Editing SAWEDOFF");
	ne->Show(true);
}
/* END */

/* MAGDialog */
MAGDialog::MAGDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_MAG7, to_string(weapskin.MAG7), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &MAGDialog::on_change, this);
}

void MAGDialog::on_change(wxCommandEvent& evt)
{
	weapskin.MAG7 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_MAG(wxCommandEvent& evt)
{
	MAGDialog* ne = new MAGDialog(this, "Editing MAG7");
	ne->Show(true);
}
/* END */


/* MAGDialog */
M249Dialog::M249Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_M249, to_string(weapskin.M249), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &M249Dialog::on_change, this);
}

void M249Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.M249 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_M249(wxCommandEvent& evt)
{
	M249Dialog* ne = new M249Dialog(this, "Editing M249");
	ne->Show(true);
}
/* END */

/* NegevDialog */
NegevDialog::NegevDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_NEGEV, to_string(weapskin.NEGEV), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &NegevDialog::on_change, this);
}

void NegevDialog::on_change(wxCommandEvent& evt)
{
	weapskin.NEGEV = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Negev(wxCommandEvent& evt)
{
	NegevDialog* ne = new NegevDialog(this, "Editing NEGEV");
	ne->Show(true);
}
/* END */

/* MP9Dialog */
MP9Dialog::MP9Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_MP9, to_string(weapskin.MP9), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &MP9Dialog::on_change, this);
}

void MP9Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.MP9 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_MP9(wxCommandEvent& evt)
{
	MP9Dialog* ne = new MP9Dialog(this, "Editing MP9");
	ne->Show(true);
}
/* END */

/* MACDialog */
MACDialog::MACDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_MAC10, to_string(weapskin.MAC10), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &MACDialog::on_change, this);
}

void MACDialog::on_change(wxCommandEvent& evt)
{
	weapskin.MAC10 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_MAC(wxCommandEvent& evt)
{
	MACDialog* ne = new MACDialog(this, "Editing MAC10");
	ne->Show(true);
}
/* END */

/* MP7Dialog */
MP7Dialog::MP7Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_MP7, to_string(weapskin.MP7), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &MP7Dialog::on_change, this);
}

void MP7Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.MP7 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_MP7(wxCommandEvent& evt)
{
	MP7Dialog* ne = new MP7Dialog(this, "Editing MP7");
	ne->Show(true);
}
/* END */

/* MP7Dialog */
UMPDialog::UMPDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_UMP45, to_string(weapskin.UMP45), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &UMPDialog::on_change, this);
}

void UMPDialog::on_change(wxCommandEvent& evt)
{
	weapskin.UMP45 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_UMP(wxCommandEvent& evt)
{
	UMPDialog* ne = new UMPDialog(this, "Editing UMP45");
	ne->Show(true);
}
/* END */

/* P90Dialog */
P90Dialog::P90Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_P90, to_string(weapskin.P90), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &P90Dialog::on_change, this);
}

void P90Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.P90 = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_P90(wxCommandEvent& evt)
{
	P90Dialog* ne = new P90Dialog(this, "Editing P90");
	ne->Show(true);
}
/* END */

/* BizonDialog */
BizonDialog::BizonDialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_BIZON, to_string(weapskin.BIZON), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &BizonDialog::on_change, this);
}

void BizonDialog::on_change(wxCommandEvent& evt)
{
	weapskin.BIZON = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_Bizon(wxCommandEvent& evt)
{
	BizonDialog* ne = new BizonDialog(this, "Editing BIZON");
	ne->Show(true);
}
/* END */

/* MP5Dialog */
MP5Dialog::MP5Dialog(wxWindow* parent, const wxString& value) : wxDialog(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(250, 100))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* ne_p = new wxPanel(this);
	ne_p->SetBackgroundColour(wxColour(*wxWHITE));
	wxTextCtrl* id_skin = new wxTextCtrl(ne_p, ID_MP5SD, to_string(weapskin.MP5SD), wxPoint(15, 15), wxSize(200, 25));
	ne_p->Show(true);
	id_skin->Bind(wxEVT_TEXT, &MP5Dialog::on_change, this);
}

void MP5Dialog::on_change(wxCommandEvent& evt)
{
	weapskin.MP5SD = atoi(evt.GetString().c_str());
	write_game_config();
}

void MainFrame::on_pistol_menu_MP5(wxCommandEvent& evt)
{
	MP5Dialog* ne = new MP5Dialog(this, "Editing MP5");
	ne->Show(true);
}
/* END */

void MainFrame::on_load_button(wxCommandEvent& evt)
{
	wxLogStatus(" ZT | PRESS F1 TO STOP CHARGING THE SKINS");
	uintptr_t cs_go_pid;

	do
	{
		cs_go_pid = get_process_id(L"csgo.exe");
	} while (cs_go_pid == 0);

	uintptr_t base_module = get_module_base_address(cs_go_pid, L"client.dll");

	uintptr_t engine_m = get_module_base_address(cs_go_pid, L"engine.dll");

	HANDLE h_proc = OpenProcess(PROCESS_ALL_ACCESS, 0, cs_go_pid);

	UINT knifeIndex = 0;

	bool isGetted = false;
	bool refesh = true;

	const int itemIDHigh = -1;
	const float fallbackWear = 0.0001f;
	DWORD modelIndex = 0;

	int current_paint_kit_weap = 0;
	const string weap_name = "  " + appconf.ST_NAME;

	int knifeID = 0;
	int knifeIDOffset = knifeID < 10 ? 0 : 1;

	short last_weapon = 0;

	auto e_ponter = Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState);
	auto g_state = Memory::Read<int>(h_proc, e_ponter + 0x108);

	// 6 mean in game
	while (g_state == 6)
	{
		DWORD local_player = Memory::Read<DWORD>(h_proc, base_module + addr_local_player);
		g_state = Memory::Read<int>(h_proc, e_ponter + 0x108);

		// 6 mean in game
		if (g_state == 6) {
			for (int i = 0; i < 8; i++)
			{
				DWORD myWeapons = Memory::Read<DWORD>(h_proc, local_player + m_hMyWeapons + i * 0x4) & 0xfff;
				DWORD weaponEntity = Memory::Read<DWORD>(h_proc, base_module + addr_entity_lit + (myWeapons - 1) * 0x10);
				int accountID = Memory::Read<int>(h_proc, weaponEntity + m_OriginalOwnerXuidLow);

				if (weaponEntity == 0) { continue;}

				short weaponID = Memory::Read<short>(h_proc, weaponEntity + m_iItemDefinitionIndex);
				if (last_weapon != weaponID) {
					last_weapon = weaponID;
					
					
				}

				if (weaponID == 0) { continue; }
				else if (weaponID == ID_DEAGLE){current_paint_kit_weap = weapskin.DEAGLE;}
				else if (weaponID == ID_ELITE) { current_paint_kit_weap = weapskin.ELITE; }
				else if (weaponID == ID_FIVESEVEN) { current_paint_kit_weap = weapskin.FIVESEVEN; }
				else if (weaponID == ID_GLOCK) { current_paint_kit_weap = weapskin.GLOCK; }
				else if (weaponID == ID_AK47) { current_paint_kit_weap = weapskin.AK47; }
				else if (weaponID == ID_AUG) { current_paint_kit_weap = weapskin.AUG; }
				else if (weaponID == ID_AWP) { current_paint_kit_weap = weapskin.AWP; }
				else if (weaponID == ID_FAMAS) { current_paint_kit_weap = weapskin.FAMAS; }
				else if (weaponID == ID_G3SG1) { current_paint_kit_weap = weapskin.G3SG1; }
				else if (weaponID == ID_GALILAR) { current_paint_kit_weap = weapskin.GALILAR; }
				else if (weaponID == ID_M249) { current_paint_kit_weap = weapskin.M249; }
				else if (weaponID == ID_M4A1) { current_paint_kit_weap = weapskin.M4A1; }
				else if (weaponID == ID_MAC10) { current_paint_kit_weap = weapskin.MAC10; }
				else if (weaponID == ID_P90) { current_paint_kit_weap = weapskin.P90; }
				else if (weaponID == ID_MP5SD) { current_paint_kit_weap = weapskin.MP5SD; }
				else if (weaponID == ID_UMP45) { current_paint_kit_weap = weapskin.UMP45; }
				else if (weaponID == ID_XM1014) { current_paint_kit_weap = weapskin.XM1014; }
				else if (weaponID == ID_BIZON) { current_paint_kit_weap = weapskin.BIZON; }
				else if (weaponID == ID_MAG7) { current_paint_kit_weap = weapskin.MAG7; }
				else if (weaponID == ID_NEGEV) { current_paint_kit_weap = weapskin.NEGEV; }
				else if (weaponID == ID_SAWEDOFF) { current_paint_kit_weap = weapskin.SAWEDOFF; }
				else if (weaponID == ID_TEC9) { current_paint_kit_weap = weapskin.TEC9; }
				else if (weaponID == ID_TASER) { current_paint_kit_weap = weapskin.TASER; }
				else if (weaponID == ID_HKP2000) { current_paint_kit_weap = weapskin.HKP2000; }
				else if (weaponID == ID_MP7) { current_paint_kit_weap = weapskin.MP7; }
				else if (weaponID == ID_MP9) { current_paint_kit_weap = weapskin.MP9; }
				else if (weaponID == ID_NOVA) { current_paint_kit_weap = weapskin.NOVA; }
				else if (weaponID == ID_P250) { current_paint_kit_weap = weapskin.P250; }
				else if (weaponID == ID_SCAR20) { current_paint_kit_weap = weapskin.SCAR20; }
				else if (weaponID == ID_SG556) { current_paint_kit_weap = weapskin.SG556; }
				else if (weaponID == ID_SSG08) { current_paint_kit_weap = weapskin.SSG08; }
				else if (weaponID == ID_M4A1_SILENCER) { current_paint_kit_weap = weapskin.M4A1_SILENCER; }
				else if (weaponID == ID_USP_SILENCER) { current_paint_kit_weap = weapskin.USP_SILENCER; }
				else if (weaponID == ID_CZ75A) { current_paint_kit_weap = weapskin.CZ75A; }
				else if (weaponID == ID_REVOLVER) { current_paint_kit_weap = weapskin.REVOLVER; }
				else if (weaponID == ID_KNIFE || weaponID == ID_KNIFE_T || weaponID == appconf.SkinKnife)
				{
					current_paint_kit_weap = appconf.SkinValueKnife;
					Memory::Write<short>(h_proc, weaponEntity + m_iItemDefinitionIndex, appconf.SkinKnife);
					Memory::Write<int>(h_proc, weaponEntity + m_nModelIndex, knifeIndex);
				}
				else { continue; }
				if (Memory::Read<int>(h_proc, weaponEntity + m_iItemIDHigh) != -1) {
					Memory::Write<int>(h_proc, weaponEntity + m_iItemIDHigh, -1);
				}

				Memory::Write<int>(h_proc, weaponEntity + m_iAccountID, accountID);
				Memory::Write<DWORD>(h_proc, weaponEntity + m_nFallbackPaintKit, current_paint_kit_weap);
				Memory::Write<int>(h_proc, weaponEntity + m_nFallbackSeed, 420);
				Memory::Write<int>(h_proc, weaponEntity + m_iItemIDHigh, itemIDHigh);
				Memory::Write<float>(h_proc, weaponEntity + m_flFallbackWear, fallbackWear);

				if (weap_name != "  ") {
					Memory::Write<string>(h_proc, weaponEntity + m_szCustomName, weap_name);
				}

				if ( appconf.StatTrak == "1") { Memory::Write<int>(h_proc, weaponEntity + m_nFallbackStatTrak, appconf.StatTrakValue);}
			}

			
			if (isGetted == false) {

				UINT ClientState = Memory::Read<UINT>(h_proc, engine_m + dwbase_moduleState);

				int m_pModelPrecacheTable = Memory::Read<UINT>(h_proc, ClientState + 0x52A4);
				int nsd = Memory::Read<UINT>(h_proc, m_pModelPrecacheTable + 0x40);
				int m_pItems = Memory::Read<UINT>(h_proc, nsd + 0xC);

				for (UINT i = 0; i < 4096; i++)
				{
					int nsdi_i = Memory::Read<UINT>(h_proc, m_pItems + 0xC + (i * 0x34));
					char str[128] = { 0 };

					if (ReadProcessMemory(h_proc, (LPCVOID)nsdi_i, str, sizeof(str), NULL))
					{
						if (_stricmp(str, get_model_string_by_id(appconf.SkinKnife)) == 0)
						{
							knifeIndex = i;
						}
					}
				}
				isGetted = true;
			}

			UINT  activeWeapon = Memory::Read<DWORD>(h_proc, local_player + m_hActiveWeapon) & 0xfff;
			UINT m_iBase = Memory::Read<UINT>(h_proc, base_module + addr_entity_lit + (activeWeapon - 1) * 0x10);
			short weaponIndex = Memory::Read<short>(h_proc, m_iBase + m_iItemDefinitionIndex);

			if (weaponIndex == ID_KNIFE || weaponIndex == ID_KNIFE_T || weaponIndex == appconf.SkinKnife)
			{
				
				DWORD knifeViewModel = Memory::Read<DWORD>(h_proc, local_player + m_hViewModel) & 0xfff;
				knifeViewModel = Memory::Read<DWORD>(h_proc, base_module + addr_entity_lit + (knifeViewModel - 1) * 0x10);

				if (knifeViewModel == 0) { continue; }

				Memory::Write<DWORD>(h_proc, knifeViewModel + m_nModelIndex, knifeIndex);
			}
		}
		else 
		{
			isGetted = !isGetted;
		}

		if (refesh == true) {
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			refesh = false;
		}


		if (GetAsyncKeyState(VK_HOME))
		{
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
			Memory::Write<int>(h_proc, Memory::Read<DWORD>(h_proc, engine_m + dwbase_moduleState) + 0x174, -1);
		}
		

		if (GetAsyncKeyState(VK_F1))
		{
			break;
		}
	}

	wxLogStatus(" ZT | Skinchanger has been stoped");

	if (g_state != 6)
	{
		wxLogStatus(" ZT | You are not in a match");
	}

	CloseHandle(h_proc);
}

