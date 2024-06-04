/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openLicenses";

_this params [
	["_store", "", [""]]
];

private _cfg = missionConfigFile >> "CfgLicenseStores" >> _store;
if (dialog || { !(isClass _cfg) }) exitWith {};

if !(call compile getText(_cfg >> "conditions")) exitWith {
	["РЈ РІР°СЃ РЅРµС‚ РґРѕСЃС‚СѓРїР°!"] call ULP_fnc_hint;
};

if (createDialog "DialogLicenses") then {
	private _display = findDisplay 3900;
	if (isNull _display) exitWith {};

	_display setVariable ["store", _cfg];

	private _title = _display displayCtrl 3901;
	_title ctrlSetText getText (_cfg >> "title");

	[] call ULP_fnc_listLicenses;
};