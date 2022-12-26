/*
Code make by zabbix | zabbix@ztrunks.space
*/

/*
thanks frk1 for: https://github.com/frk1/hazedumper/blob/master/csgo.hpp
*/

#include <string>
#include <iostream>

using namespace std;

#define addr_local_player 0xDEA964
#define addr_entity_lit 0x4DFFF14
#define net_health 0x100
#define m_iItemDefinitionIndex 0x2FBA
#define m_hMyWeapons 0x2E08
#define m_iItemIDHigh 0x2FD0
#define m_nFallbackPaintKit 0x31D8
#define m_flFallbackWear 0x31E0 
#define dwbase_moduleState 0x59F194
#define m_nViewModelIndex 0x29D0
#define m_hViewModel 0x3308
#define m_nModelIndex 0x258
#define m_szCustomName 0x304C
#define m_iEntityQuality 0x2FBC
#define m_hActiveWeapon 0x2F08
#define m_nFallbackStatTrak 0x31E4
#define m_OriginalOwnerXuidLow 0x31D0
#define m_iAccountID 0x2FD8
#define m_nFallbackSeed 0x31DC

/*
weapons ID
*/
#define ID_DEAGLE 1
#define ID_ELITE 2
#define ID_FIVESEVEN 3
#define ID_GLOCK 4
#define ID_AK47 7
#define ID_AUG 8
#define ID_AWP 9
#define ID_FAMAS 10
#define ID_G3SG1 11
#define ID_GALILAR 13
#define ID_M249 14
#define ID_M4A1 16
#define ID_MAC10 17
#define ID_P90 19
#define ID_MP5SD 23
#define ID_UMP45 24
#define ID_XM1014 25
#define ID_BIZON 26
#define ID_MAG7 27
#define ID_NEGEV 28
#define ID_SAWEDOFF 29
#define ID_TEC9 30
#define ID_TASER 31
#define ID_HKP2000 32
#define ID_MP7 33
#define ID_MP9 34
#define ID_NOVA 35
#define ID_P250 36
#define ID_SHIELD 37
#define ID_SCAR20 38
#define ID_SG556 39
#define ID_SSG08 40
#define ID_KNIFEGG 41
#define ID_KNIFE 42
#define ID_FLASHBANG 43
#define ID_HEGRENADE 44
#define ID_SMOKEGRENADE 45
#define ID_MOLOTOV 46
#define ID_DECOY 47
#define ID_INCGRENADE 48
#define ID_C4 49
#define ID_HEALTHSHOT 57
#define ID_KNIFE_T 59
#define ID_M4A1_SILENCER 60
#define ID_USP_SILENCER 61
#define ID_CZ75A 63
#define ID_REVOLVER 64
#define ID_TAGRENADE 68
#define ID_FISTS 69
#define ID_BREACHCHARGE 70
#define ID_TABLET 72
#define ID_MELEE 74
#define ID_AXE 75
#define ID_HAMMER 76
#define ID_SPANNER 78
#define ID_KNIFE_GHOST 80
#define ID_FIREBOMB 81
#define ID_DIVERSION 82
#define ID_FRAG_GRENADE 83
#define ID_SNOWBALL 84
#define ID_BUMPMINE 85
#define ID_BAYONET 500
#define ID_KNIFE_FLIP 505
#define ID_KNIFE_GUT 506
#define ID_KNIFE_KARAMBIT 507
#define ID_KNIFE_M9_BAYONET 508
#define ID_KNIFE_HUNTSMAN 509
#define ID_KNIFE_FALCHION 512
#define ID_KNIFE_BOWIE 514
#define ID_KNIFE_BUTTERFLY 515
#define ID_KNIFE_DAGGERS 516
#define ID_KNIFE_URSUS 519
#define ID_KNIFE_NAVAJA 520
#define ID_KNIFE_STILETTO 522
#define ID_KNIFE_TALON 523
#define ID_STUDDED_BLOODHOUND_GLOVES 5027
#define ID_T_GLOVES  5028
#define ID_CT_GLOVES 5029
/*
weapons SKIN
*/

struct WeapSKIN
{
	int DEAGLE;
	int SCAR20;
	int ELITE;
	int FIVESEVEN;
	int GLOCK;
	int AK47;
	int AUG;
	int AWP;
	int FAMAS;
	int G3SG1;
	int GALILAR;
	int M249;
	int M4A1;
	int MAC10;
	int P90;
	int MP5SD;
	int UMP45;
	int XM1014;
	int BIZON;
	int MAG7;
	int NEGEV;
	int SAWEDOFF;
	int TEC9;
	int TASER;
	int HKP2000;
	int MP7;
	int MP9;
	int NOVA;
	int P250;
	int SHIELD;
	int SG556;
	int SSG08;
	int KNIFEGG;
	int KNIFE;
	int FLASHBANG;
	int HEGRENADE;
	int SMOKEGRENADE;
	int MOLOTOV;
	int DECOY;
	int INCGRENADE;
	int C4;
	int HEALTHSHOT;
	int KNIFE_T;
	int M4A1_SILENCER;
	int USP_SILENCER;
	int CZ75A;
	int REVOLVER;
	int TAGRENADE;
	int FISTS;
	int BREACHCHARGE;
	int TABLET;
	int MELEE;
	int AXE;
	int HAMMER;
	int SPANNER;
	int KNIFE_GHOST;
	int FIREBOMB;
	int DIVERSION;
	int FRAG_GRENADE;
	int SNOWBALL;
	int BUMPMINE;
	int BAYONET;
	int KNIFE_FLIP;
	int KNIFE_GUT;
	int KNIFE_KARAMBIT;
	int KNIFE_M9_BAYONET;
	int KNIFE_HUNTSMAN;
	int KNIFE_FALCHION;
	int KNIFE_BOWIE;
	int KNIFE_BUTTERFLY;
	int KNIFE_DAGGERS;
	int KNIFE_URSUS;
	int KNIFE_NAVAJA;
	int KNIFE_STILETTO;
	int KNIFE_TALON;
	int STUDDED_BLOODHOUND_GLOVES;
	int T_GLOVES;
	int CT_GLOVES;
	int SPORTY_GLOVES;
	int SLICK_GLOVES;
	int LEATHER_HANDWRAPS;
	int MOTORCYCLE_GLOVES;
	int SPECIALIST_GLOVES;
	int STUDDED_HYDRA_GLOVES;
};

struct AppConfig {
	string StatTrak;
	string ST_NAME;
	int StatTrakValue;
	int SkinValueKnife;
	int SkinKnife;
};