/*
** Автор: Jack "Scarso" Farhall
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_revivePatient";

if (canSuspend) exitWith {
    [ULP_fnc_revivePatient, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if (!([player, ["Medic"]] call ULP_fnc_isFaction) && { (count (["Medic"] call ULP_fnc_allMembers)) > 0 }) exitWith {
	["Вы не можете оживить кого-то, пока медики в сети..."] call ULP_fnc_hint;
};

private _unit = _display getVariable ["patient", objNull];

if !(isDowned(_unit)) exitWith {
	["Этот пациент стабилен и не требует перевязки..."] call ULP_fnc_hint;
};

if ((count (_unit getVariable ["IncapacitatedWounds", createHashMap])) > 0) exitWith {
	["У этого пациента есть открытые раны, которые нужно закрыть..."] call ULP_fnc_hint;
};

if (["AutomatedExternalDefibrillator"] call ULP_fnc_hasItem < 1) exitWith {
	["Для оживления этого пациента вам нужен дефибриллятор..."] call ULP_fnc_hint;
};

closeDialog 0;

private _time = ["LifeSaver", 20] call ULP_fnc_activatePerk;

[format ["Оживление %1", [_unit, true] call ULP_fnc_getName], _time, [_unit], { isDowned(_this select 0) && { (player distance (_this select 0)) < 5 } }, {
	_this params [ "_unit" ];

	if !(isDowned(_unit)) exitWith {
		["Этот пациент стабилен и не требует перевязки..."] call ULP_fnc_hint;
	};

	private _payOut = ["Revival", 5000] call ULP_fnc_getLegislation;

	if ([player, ["Medic"]] call ULP_fnc_isFaction && { [_payOut, true, format ["Оживление %1", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_addMoney }) then {
		[format ["Вы оживили <t color='#B92DE0'>%1</t> и получили <t color='#B92DE0'>%2%3</t>", [_unit] call ULP_fnc_getName, "$", [_payOut] call ULP_fnc_numberText]] call ULP_fnc_hint;
	} else {
		[format ["Вы оживили <t color='#B92DE0'>%1</t>", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	};

	["LifeSaver"] call ULP_fnc_achieve;
	[100, format ["Оживление %1", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_addXP;

	[player] remoteExecCall ["ULP_fnc_revived", _unit];
	[getPlayerUID player, "Оживление", [_unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
}, {} , ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
