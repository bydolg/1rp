/*
** Автор: Джек "Scarso" Фархолл
** Описание: Добавляет действия прокрутки избирательного участка для данного торговца
** Использование:
** 	[this] call ULP_fnc_addPollingStation;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addPollingStation";

_this params [
	["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

_trader addAction ["<t color='#B528D0'>[GOV]</t> Избирательный участок", { _this call ULP_fnc_openPollingStation }, 
	nil, 1.5, true, true, "", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false]", 5];

_trader addAction ["<t color='#B528D0'>[GOV]</t> Взломать избирательный участок", { _this call ULP_fnc_rigPollingStation }, 
	nil, 1.5, true, true, "", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false] && { [""PollRigging"", group _this] call ULP_fnc_hasGroupPerk } && { !((_target getVariable [""rigged_group"", grpNull]) isEqualTo (group _this)) }", 5];

_trader addAction ["<t color='#B528D0'>[GOV]</t> Призыв к выборам", { [] call ULP_fnc_enlist }, 
	nil, 1.5, true, true, "", "!(missionNamespace getVariable [""ULP_SRV_Setting_Election"", false])", 5];
