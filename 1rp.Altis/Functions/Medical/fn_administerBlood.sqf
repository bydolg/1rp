/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_administerBlood";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(alive _unit) }) exitWith {};

if ((0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1) exitWith { ["Вам нужен мешок крови, чтобы провести переливание крови!"] call ULP_fnc_hint; };
if !(isDowned(_unit)) exitWith { ["Вы можете проводить переливание крови только пострадавшим игрокам!"] call ULP_fnc_hint; };

private _name = [_unit, true] call ULP_fnc_getName;

private _time = 30;

if !([format["Переливание крови для %1", _name], _time, [_unit, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { isDowned((_this select 0)) } && { (0 max (["BloodBag"] call ULP_fnc_hasItem)) > 0 } && 
	{ (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_unit", "_name" ];

	if (isNull _unit || { !(alive _unit) } || { !(isDowned(_unit)) } || { (0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1 }) exitWith {
		["Вы потеряли мешок с кровью, или пациент, которого вы лечили, умер..."] call ULP_fnc_hint;
	};

	if ([] call ULP_fnc_isGroup) then {
		if (_unit in (units (group player))) then {
			[(group player), "MedicalAid"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
		};
	};

	["BloodBag", 1, true] call ULP_fnc_handleItem;
	[format ["Вы провели переливание крови <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;

	[player, ["BloodCarrier", getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BloodBagIncrease")] call ULP_fnc_activatePerk] remoteExecCall ["ULP_fnc_receivedBlood", _unit];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете проводить переливание крови, выполняя другое действие..."] call ULP_fnc_hint;
};

closeDialog 0;
