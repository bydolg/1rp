/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_triggerEvent";

_this params [
	["_item", "", [""]],
	["_eventCfg", configNull, [configNull]]
];

if (isNull _cfg || { _item isEqualTo "" }) exitWith { false };

if (missionNamespace getVariable [format ["ULP_SRV_%1_Active", configName _eventCfg], false]) exitWith {
	["Событие этого типа уже активно, пожалуйста, попробуйте еще раз, когда текущее завершится"] call ULP_fnc_hint;
	false
};

if ([_item, 1, true] call ULP_fnc_handleItem) exitWith {
	[_eventCfg, true] remoteExecCall ["ULP_SRV_fnc_spawnEvent", RSERV];
	["Вы вызвали событие"] call ULP_fnc_hint;
	true
};

false
