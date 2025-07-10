/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_clearWarrants";

if (canSuspend) exitWith {
    [ULP_fnc_clearWarrants, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display || { !([player, ["Police"]] call ULP_fnc_isFaction) }) exitWith {};

private _group = _display displayCtrl 4703;
private _list = _group controlsGroupCtrl 102;
private _path = tvCurSel _list;

private _unit = [_list tvData _path] call ULP_fnc_playerByUid;
if (isNull _unit) exitWith {
        [LSTRING(PNC_SELECT_WARRANT)] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Clear", "Cancel"],
        format [LSTRING(PNC_CLEAR_CONFIRM), name _unit], [_unit, _display, _list, _path],
	{	
		_this params [ "_unit", "_display", "_list", "_path" ];
		
		if (isNull _unit) exitWith {};

		_display setVariable ["warrant_steam_id", nil];
		_display setVariable ["act_cfg_name", nil];
		_display setVariable ["crime_cfg_name", nil];

		_list tvDelete _path;

                [getPlayerUID _unit] remoteExecCall ["ULP_SRV_fnc_clearWarrants", RSERV];
                [format [LSTRING(PNC_CLEARED), name _unit]] call ULP_fnc_hint;
	}, {}, false
] call ULP_fnc_confirm;
