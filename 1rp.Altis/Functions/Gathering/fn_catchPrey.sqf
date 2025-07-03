/*
** Author: Bydolg
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_catchPrey";

_this params [
	["_prey", objNull, [objNull]]
];

if (isNull _prey || { alive _prey }) exitWith { false };

private _typeOf = typeOf _prey;

if !(_typeOf in getArray (missionConfigFile >> "CfgGathering" >> "prey")) exitWith { false };

private _name = (_typeOf splitString "_") param [0, "prey"];

if ([format["%1_Raw", _typeOf], 1] call ULP_fnc_handleItem) exitWith {
	[format ["Вы добыли <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
  
	["Fishing", 1, 40] call ULP_fnc_increaseProfession;

	true
};

[format ["У вас недостаточно места в инвентаре для хранения <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
