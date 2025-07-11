/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initReputation";

["Initialising Reputation"] call ULP_fnc_logIt;

["ReputationChanged", {
	_this params [
		["_reason", "", [""]],
		["_oldReputation", 0, [0]],
		["_newReputation", 0, [0]]
	];

	if !(_newReputation isEqualTo _oldReputation) then {
		ULP_Reputation = _newReputation;
	};

	[format ["Ваша репутация была <t color='#B92DE0'>%1</t> потомучто вы %2", (["уменшена", "увеличена"] select (ULP_Reputation > _oldReputation)), _reason]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["Incapacitated", {
	_this params [
		"_unit", "_killer"
	];

	if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) } && { (_killer getVariable ["robbed_by_me", -300]) < (time - 300) }) then {
		[_killer, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
			case (ULP_Reputation >= 500): { "IncapHighRep" };
			case (ULP_Reputation > -500): { "IncapNormal" };
			default { "IncapLowRep" };
		})] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};
}] call ULP_fnc_addEventHandler;