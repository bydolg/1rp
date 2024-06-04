/*
** Author: Jack "Scarso" Farhall
** Description: Shared initialization of the player and server.
*/
#include "script_macros.hpp"

if (IS_DEBUG_MODE) then { ULP_DebugMode = true; };
null = [] execVM "ADS_system\functions\initADS.sqf";

// CSWR > HIDE THE SCRIPT MARKERS:
// Documentation: your_mission\CSWRandomizr\_CSWR_Script_Documentation.pdf
//if !CSWR_isOnDebugGlobal then {{private _mkr = toUpper _x; private _mkrChecking = _mkr splitString "_"; if (_mkrChecking find "CSWR" != -1) then {_x setMarkerAlpha 0}} forEach allMapMarkers};