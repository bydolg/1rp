/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_inviteMember";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([3] call ULP_fnc_canGroupRank) exitWith {
	["У вас нет разрешения на выполнение этого действия!"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), ["Civilian"], [], {
	_this params [
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};

	private _list = _display displayCtrl 3809;

	private _unit = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _unit) exitWith {
		["Вы не выбрали никого для приглашения!"] call ULP_fnc_hint;
	};
	
	if (_unit getVariable ["group_invited", false]) exitWith {
		["Вы уже пригласили этого человека..."] call ULP_fnc_hint;
	};
	_unit setVariable ["group_invited", true];
	
	["GroupInvite", [group player, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
}, false, true, { !([group _x] call ULP_fnc_isGroup) }] call ULP_fnc_selectPlayer;
