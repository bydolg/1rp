/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_panic";

if ((["PanicButton"] call ULP_fnc_hasItem) < 1) exitWith {};

// Прекратить спам...
private _cd = player getVariable ["panic_cooldown", 0];
if (time < _cd) exitWith {
	[format ["Вы недавно использовали паническую кнопку и не можете использовать ее в течение еще <t color='#B92DE0'>%1</t> секунд...", [_cd - time] call ULP_fnc_numberText]] call ULP_fnc_hint;
	false
};
player setVariable ["panic_cooldown", time + 60];

private _cfg = missionConfigFile >> "CfgMessages" >> "Panic";
private _targets = getText (_cfg >> "targets");

[_cfg, "Была нажата паническая кнопка! Требуется немедленная помощь.", _targets] call ULP_fnc_sendMessage;
["Вы нажали на паническую кнопку, полиция оповещена!"] call ULP_fnc_hint;

[player, "panicButton", 100, 1] remoteExecCall ["ULP_fnc_say3D"];

true
