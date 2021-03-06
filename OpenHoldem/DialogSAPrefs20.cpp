//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose:
//
//******************************************************************************

// DialogSAPrefs20.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSAPrefs20.h"

#include "CPreferences.h"
#include "SAPrefsSubDlg.h"

// CDlgSAPrefs20 dialog

IMPLEMENT_DYNAMIC(CDlgSAPrefs20, CDialog)

CDlgSAPrefs20::CDlgSAPrefs20(CWnd* pParent /*=NULL*/)
	: CSAPrefsSubDlg(CDlgSAPrefs20::IDD, pParent)
{

}

CDlgSAPrefs20::~CDlgSAPrefs20()
{
}

void CDlgSAPrefs20::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	// No need for any DDX.
	// We do it the good old Win95-way. :)
}


BEGIN_MESSAGE_MAP(CDlgSAPrefs20, CDialog)
END_MESSAGE_MAP()

// Button position
const int kPositionFirstX =   4;
const int kPositionFirstY =  23;
const int kPositionDeltaX = 155;
const int kPositionDeltaY =  22;
const int kButtonWidthX   = 150;
const int kButtonWidthY   =  10;
const int kMaxButtonsInYDirection = 23;

void CDlgSAPrefs20::AlignButton(int button_ID) {
  assert(_buttons_aligned >= 0);
  assert(_buttons_aligned <= 100);
  int x_slot = _buttons_aligned / kMaxButtonsInYDirection;
  int y_slot = _buttons_aligned % kMaxButtonsInYDirection;
  int x_position = kPositionFirstX + x_slot * kPositionDeltaX;
  int y_position = kPositionFirstY + y_slot * kPositionDeltaY;
  CWnd* button = GetDlgItem(button_ID);
  assert(button != NULL);
  button->SetWindowPos(NULL, x_position, y_position, kButtonWidthX, kButtonWidthY, SWP_SHOWWINDOW);
  ++_buttons_aligned;
}

void CDlgSAPrefs20::AlignbuttonsInAlphabeticalOrder() {
  _buttons_aligned = 0;
  AlignButton(IDC_DEBUG_ALLIN_ADJUSTMENT);
  AlignButton(IDC_DEBUG_AST_PRIORITY_ORDERING);
  AlignButton(IDC_DEBUG_AUTOCONNECTOR);
  AlignButton(IDC_DEBUG_AUTOPLAYER);
  AlignButton(IDC_DEBUG_AUTO_TRACE);
  AlignButton(IDC_DEBUG_AUTOSTARTER);
  AlignButton(IDC_DEBUG_BETSIZE_ADJUSTMENT);
  AlignButton(IDC_DEBUG_BLINDLOCKING);
  AlignButton(IDC_DEBUG_BOARD_EXPRESSIONS);
  AlignButton(IDC_DEBUG_DLL_EXTENSION);
  AlignButton(IDC_DEBUG_ENGINE_CONTAINER);
  AlignButton(IDC_DEBUG_FILENAMES);
  AlignButton(IDC_DEBUG_FORMULA);
  AlignButton(IDC_DEBUG_GUI);
  AlignButton(IDC_DEBUG_HANDHISTORY);
  AlignButton(IDC_DEBUG_HANDRESET_DETECTOR);
  AlignButton(IDC_DEBUG_HEARTBEAT);
  AlignButton(IDC_DEBUG_HOPPER_MESSAGES);
  AlignButton(IDC_DEBUG_ICM);
  AlignButton(IDC_DEBUG_ISTOURNAMENT);
  AlignButton(IDC_DEBUG_LAZY_SCRAPER);
  AlignButton(IDC_DEBUG_MEMORY_SYMBOLS);
  AlignButton(IDC_DEBUG_MEMORY_USAGE);
  AlignButton(IDC_DEBUG_OCCLUSSION);
  AlignButton(IDC_DEBUG_OPENHOLDEM);
  AlignButton(IDC_DEBUG_PARSER);
  AlignButton(IDC_DEBUG_POKERTRACKER);
  AlignButton(IDC_DEBUG_POPUP_BLOCKER);
  AlignButton(IDC_DEBUG_PREFERENCES);
  AlignButton(IDC_DEBUG_PRWIN);
  AlignButton(IDC_DEBUG_REBUY);
  AlignButton(IDC_DEBUG_REPLAYFRAMES);
  AlignButton(IDC_DEBUG_SCRAPER);
  // Called "scraper directory monitor"
  AlignButton(IDC_DEBUG_FILESYSTEM_MONITOR);
  AlignButton(IDC_DEBUG_SCRAPER_PREPROCESSOR);
  AlignButton(IDC_DEBUG_SESSIONCOUNTER);
  AlignButton(IDC_DEBUG_SHAREDMEM);
  AlignButton(IDC_DEBUG_SINGLETONS);
  AlignButton(IDC_DEBUG_STABLEFRAMESCOUNTER);
  AlignButton(IDC_DEBUG_SYMBOLENGINE);
  AlignButton(IDC_DEBUG_SYMBOLENGINE_OPENPPL);
  AlignButton(IDC_DEBUG_TABLE_LIMITS);
  AlignButton(IDC_DEBUG_TABLEMAP_LOADER);
  AlignButton(IDC_DEBUG_TABLEPOINTS);
  AlignButton(IDC_DEBUG_TABLE_POSITIONER);
  AlignButton(IDC_DEBUG_TIMERS);
  AlignButton(IDC_DEBUG_TOKENIZER);
  AlignButton(IDC_DEBUG_VERSUS);
  AlignButton(IDC_DEBUG_WATCHDOG);
  // "all the rest" at the very end.
  // It contains all temp-debug.
  AlignButton(IDC_DEBUG_ALLTHEREST);
}

// CDlgSAPrefs20 message handlers
BOOL CDlgSAPrefs20::OnInitDialog()
{	
  AlignbuttonsInAlphabeticalOrder();
	CheckDlgButton(IDC_DEBUG_AUTOCONNECTOR , preferences.debug_autoconnector() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_AUTOPLAYER, preferences.debug_autoplayer() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_HEARTBEAT, preferences.debug_heartbeat() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_PRWIN, preferences.debug_prwin() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_ICM, preferences.debug_icm() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_OCCLUSSION, preferences.debug_occlusionchecker() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_POKERTRACKER, preferences.debug_pokertracker() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_REBUY, preferences.debug_rebuy() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_REPLAYFRAMES, preferences.debug_replayframes() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_SCRAPER, preferences.debug_scraper() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_SESSIONCOUNTER, preferences.debug_sessioncounter() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_STABLEFRAMESCOUNTER, preferences.debug_stableframescounter() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_SYMBOLENGINE, preferences.debug_symbolengine() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_SYMBOLENGINE_OPENPPL, preferences.debug_symbolengine_open_ppl() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_MEMORY_USAGE, preferences.debug_memory_usage() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_PARSER, preferences.debug_parser() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_BLINDLOCKING, preferences.debug_blindlocking() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_MEMORY_SYMBOLS, preferences.debug_memorysymbols() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_TABLEMAP_LOADER, preferences.debug_tablemap_loader() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_FILESYSTEM_MONITOR, preferences.debug_filesystem_monitor() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_TABLE_POSITIONER, preferences.debug_table_positioner() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_ISTOURNAMENT, preferences.debug_istournament() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_GUI, preferences.debug_gui() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_TABLE_LIMITS, preferences.debug_table_limits() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_LAZY_SCRAPER, preferences.debug_lazy_scraper() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_BETSIZE_ADJUSTMENT, preferences.debug_betsize_adjustment() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_ALLIN_ADJUSTMENT, preferences.debug_allin_adjustment() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_HANDRESET_DETECTOR, preferences.debug_handreset_detector() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_ENGINE_CONTAINER, preferences.debug_engine_container() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_HANDHISTORY, preferences.debug_handhistory() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_PREFERENCES, preferences.debug_preferences() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_DLL_EXTENSION, preferences.debug_dll_extension() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_SCRAPER_PREPROCESSOR, preferences.debug_scraper_preprocessor() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_HOPPER_MESSAGES, preferences.debug_hopper_messages() ? MF_CHECKED : MF_UNCHECKED);
	CheckDlgButton(IDC_DEBUG_OPENHOLDEM, preferences.debug_openholdem() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_POPUP_BLOCKER, preferences.debug_popup_blocker() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_FORMULA, preferences.debug_formula() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_ALLTHEREST, preferences.debug_alltherest() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_VERSUS, preferences.debug_versus() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_AUTO_TRACE, preferences.debug_auto_trace() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_FILENAMES, preferences.debug_filenames() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_AST_PRIORITY_ORDERING, preferences.debug_ast_priority_ordering() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_BOARD_EXPRESSIONS, preferences.debug_hand_and_baord_expressions() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_TOKENIZER, preferences.debug_tokenizer() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_TABLEPOINTS, preferences.debug_tablepoints() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_SHAREDMEM, preferences.debug_sharedmem() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_SINGLETONS, preferences.debug_singletons() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_AUTOSTARTER, preferences.debug_autostarter() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_WATCHDOG, preferences.debug_watchdog() ? MF_CHECKED : MF_UNCHECKED);
  CheckDlgButton(IDC_DEBUG_TIMERS, preferences.debug_timers() ? MF_CHECKED : MF_UNCHECKED);
  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSAPrefs20::OnOK()
{
	preferences.SetValue(k_prefs_debug_autoconnector, IsDlgButtonChecked(IDC_DEBUG_AUTOCONNECTOR));
	preferences.SetValue(k_prefs_debug_autoplayer, IsDlgButtonChecked(IDC_DEBUG_AUTOPLAYER));
	preferences.SetValue(k_prefs_debug_heartbeat, IsDlgButtonChecked(IDC_DEBUG_HEARTBEAT));
	preferences.SetValue(k_prefs_debug_prwin, IsDlgButtonChecked(IDC_DEBUG_PRWIN));
	preferences.SetValue(k_prefs_debug_icm, IsDlgButtonChecked(IDC_DEBUG_ICM));
	preferences.SetValue(k_prefs_debug_occlusionchecker, IsDlgButtonChecked(IDC_DEBUG_OCCLUSSION));
	preferences.SetValue(k_prefs_debug_pokertracker, IsDlgButtonChecked(IDC_DEBUG_POKERTRACKER));
	preferences.SetValue(k_prefs_debug_rebuy, IsDlgButtonChecked(IDC_DEBUG_REBUY));
	preferences.SetValue(k_prefs_debug_replayframes, IsDlgButtonChecked(IDC_DEBUG_REPLAYFRAMES));
	preferences.SetValue(k_prefs_debug_scraper, IsDlgButtonChecked(IDC_DEBUG_SCRAPER));
	preferences.SetValue(k_prefs_debug_sessioncounter, IsDlgButtonChecked(IDC_DEBUG_SESSIONCOUNTER));
	preferences.SetValue(k_prefs_debug_stableframescounter, IsDlgButtonChecked(IDC_DEBUG_STABLEFRAMESCOUNTER));
	preferences.SetValue(k_prefs_debug_symbolengine, IsDlgButtonChecked(IDC_DEBUG_SYMBOLENGINE));
	preferences.SetValue(k_prefs_debug_symbolengine_open_ppl, IsDlgButtonChecked(IDC_DEBUG_SYMBOLENGINE_OPENPPL));
  preferences.SetValue(k_prefs_debug_memory_usage, IsDlgButtonChecked(IDC_DEBUG_MEMORY_USAGE));
  preferences.SetValue(k_prefs_debug_parser, IsDlgButtonChecked(IDC_DEBUG_PARSER));
	preferences.SetValue(k_prefs_debug_blindlocking, IsDlgButtonChecked(IDC_DEBUG_BLINDLOCKING));
	preferences.SetValue(k_prefs_debug_memorysymbols, IsDlgButtonChecked(IDC_DEBUG_MEMORY_SYMBOLS));
	preferences.SetValue(k_prefs_debug_tablemap_loader, IsDlgButtonChecked(IDC_DEBUG_TABLEMAP_LOADER));
	preferences.SetValue(k_prefs_debug_filesystem_monitor, IsDlgButtonChecked(IDC_DEBUG_FILESYSTEM_MONITOR));
	preferences.SetValue(k_prefs_debug_table_positioner, IsDlgButtonChecked(IDC_DEBUG_TABLE_POSITIONER));
	preferences.SetValue(k_prefs_debug_istournament, IsDlgButtonChecked(IDC_DEBUG_ISTOURNAMENT));
	preferences.SetValue(k_prefs_debug_gui, IsDlgButtonChecked(IDC_DEBUG_GUI));
	preferences.SetValue(k_prefs_debug_table_limits, IsDlgButtonChecked(IDC_DEBUG_TABLE_LIMITS));
	preferences.SetValue(k_prefs_debug_lazy_scraper, IsDlgButtonChecked(IDC_DEBUG_LAZY_SCRAPER));
	preferences.SetValue(k_prefs_debug_betsize_adjustment, IsDlgButtonChecked(IDC_DEBUG_BETSIZE_ADJUSTMENT));
  preferences.SetValue(k_prefs_debug_allin_adjustment, IsDlgButtonChecked(IDC_DEBUG_ALLIN_ADJUSTMENT));
	preferences.SetValue(k_prefs_debug_handreset_detector, IsDlgButtonChecked(IDC_DEBUG_HANDRESET_DETECTOR));
	preferences.SetValue(k_prefs_debug_engine_container, IsDlgButtonChecked(IDC_DEBUG_ENGINE_CONTAINER));
	preferences.SetValue(k_prefs_debug_handhistory, IsDlgButtonChecked(IDC_DEBUG_HANDHISTORY));
	preferences.SetValue(k_prefs_debug_preferences, IsDlgButtonChecked(IDC_DEBUG_PREFERENCES));
	preferences.SetValue(k_prefs_debug_dll_extension, IsDlgButtonChecked(IDC_DEBUG_DLL_EXTENSION));
	preferences.SetValue(k_prefs_debug_scraper_preprocessor, IsDlgButtonChecked(IDC_DEBUG_SCRAPER_PREPROCESSOR));
	preferences.SetValue(k_prefs_debug_hopper_messages, IsDlgButtonChecked(IDC_DEBUG_HOPPER_MESSAGES));
	preferences.SetValue(k_prefs_debug_openholdem, IsDlgButtonChecked(IDC_DEBUG_OPENHOLDEM));
	preferences.SetValue(k_prefs_debug_popup_blocker, IsDlgButtonChecked(IDC_DEBUG_POPUP_BLOCKER));
  preferences.SetValue(k_prefs_debug_formula, IsDlgButtonChecked(IDC_DEBUG_FORMULA));
	preferences.SetValue(k_prefs_debug_alltherest, IsDlgButtonChecked(IDC_DEBUG_ALLTHEREST));
  preferences.SetValue(k_prefs_debug_versus, IsDlgButtonChecked(IDC_DEBUG_VERSUS));
  preferences.SetValue(k_prefs_debug_auto_trace, IsDlgButtonChecked(IDC_DEBUG_AUTO_TRACE));
  preferences.SetValue(k_prefs_debug_filenames, IsDlgButtonChecked(IDC_DEBUG_FILENAMES));
  preferences.SetValue(k_prefs_debug_ast_priority_ordering, IsDlgButtonChecked(IDC_DEBUG_AST_PRIORITY_ORDERING));
  preferences.SetValue(k_prefs_debug_hand_and_baord_expressions, IsDlgButtonChecked(IDC_DEBUG_BOARD_EXPRESSIONS));
  preferences.SetValue(k_prefs_debug_tokenizer, IsDlgButtonChecked(IDC_DEBUG_TOKENIZER));
  preferences.SetValue(k_prefs_debug_tablepoints, IsDlgButtonChecked(IDC_DEBUG_TABLEPOINTS));
  preferences.SetValue(k_prefs_debug_sharedmem, IsDlgButtonChecked(IDC_DEBUG_SHAREDMEM));
  preferences.SetValue(k_prefs_debug_singletons, IsDlgButtonChecked(IDC_DEBUG_SINGLETONS));
  preferences.SetValue(k_prefs_debug_autostarter, IsDlgButtonChecked(IDC_DEBUG_AUTOSTARTER));
  preferences.SetValue(k_prefs_debug_watchdog, IsDlgButtonChecked(IDC_DEBUG_WATCHDOG));
  preferences.SetValue(k_prefs_debug_timers, IsDlgButtonChecked(IDC_DEBUG_TIMERS));
	CSAPrefsSubDlg::OnOK();
}


