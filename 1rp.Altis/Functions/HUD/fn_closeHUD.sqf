/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_closeHUD";

_this params [
	"_ui"
];

if !(isNull _ui) then {
	private _frame = _ui getVariable ["eachframe", -1];
	if !(_frame isEqualTo -1) then { [_frame] call ULP_fnc_removeEachFrame; };

	private _eventhandler = _ui getVariable ["eventhandler", -1];
	if !(_eventhandler isEqualTo -1) then { ["OnXPIncreased", _eventhandler] call ULP_fnc_removeEventHandler; };

	private _money = _ui getVariable ["money", -1];
	if !(_money isEqualTo -1) then { ["MoneyChanged", _money] call ULP_fnc_removeEventHandler; };
	
	["RscHUD"] call ULP_UI_fnc_destroyLayer;
};