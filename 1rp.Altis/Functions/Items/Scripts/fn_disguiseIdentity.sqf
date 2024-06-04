/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_disguiseIdentity";

_this params [
	["_item", "", [""]],
	["_identity", name player, [""]]
];

// Нет активной личности и эта личность наша
if (isNil { player getVariable "name" } && { (name player) isEqualTo _identity }) exitWith {};

// Прекратить спам...
if (time < (player getVariable ["last_disguised", 0])) exitWith {
	["Вы недавно маскировались, пожалуйста, подождите..."] call ULP_fnc_hint;
	false
};
player setVariable ["last_disguised", time + 3];

if (_identity isEqualTo (name player) || { ((player getVariable ["name", name player]) isEqualTo _identity) }) then {
	player setVariable ["name", nil, true];
	["Вы вернули свою общедоступную личность к нормальному."] call ULP_fnc_hint;
} else {
	player setVariable ["name", _identity, true];
	[format ["Вы сменили свою общедоступную личность на <t color='#B92DE0'>%1</t>.", _identity]] call ULP_fnc_hint;
};

true
