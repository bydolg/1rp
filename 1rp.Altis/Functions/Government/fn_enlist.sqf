/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_enlist";

if (missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["Вы не можете записаться на выборы, пока они продолжаются..."] call ULP_fnc_hint;
};

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["Вы должны быть гражданином, чтобы записаться на следующие выборы..."] call ULP_fnc_hint;
};

if !([] call ULP_fnc_isGroup || { ["Governor"] call ULP_fnc_hasGroupPerk }) exitWith {
	["Ваша группа не имеет возможности баллотироваться на пост губернатора..."] call ULP_fnc_hint;
};

if ([] call ULP_fnc_isGovernor) exitWith {
	["Как губернатор, вы не можете баллотироваться на следующих выборах..."] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Подтверждение", ["Подтвердить", "Отмена"],
	format ["Вы уверены, что хотите баллотироваться на пост губернатора, как %1...", profileName], [],
	{	
		if (player getVariable ["enlisting", false]) exitWith {
			["Ваш запрос на запись уже обрабатывается!"] call ULP_fnc_hint;
		};

		player setVariable ["enlisting", true];

		["Enlistment", {
			[_this param [0, "Вы успешно записались на следующие выборы..."]] call ULP_fnc_hint;
			player setVariable ["enlisting", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Запрос на запись..."] call ULP_fnc_hint;
		[player] remoteExecCall ["ULP_SRV_fnc_enlistCandidate", RSERV];
	}, {}, false
] call ULP_fnc_confirm;
