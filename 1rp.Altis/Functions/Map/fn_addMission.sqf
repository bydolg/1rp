/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
** Использование:
** 	[this, "<t color='#073763'>[CIV]</t>", "Миссия по доставке", "Доставка", "DP1"] call ULP_fnc_addMission;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addMission";

_this params [
	["_trader", objNull, [objNull]],
	["_prefix", "", [""]],
	["_title", "", [""]],
	["_type", "", [""]],
	["_location", "", [""]],
	["_allowFinish", true, [false]]
];

if (isNull _trader || { _title isEqualTo "" } || { _type isEqualTo "" } || { _location isEqualTo "" }) exitWith {};

_trader addAction [format["%1 Запросить %2", _prefix, _title], { (_this select 3) call ULP_fnc_claimMission }, [_type, _location], 1.5, true, true, "", "true", 3];

if (_allowFinish) then {
	_trader addAction [format["%1 Завершить %2", _prefix, _title], { (_this select 3) call ULP_fnc_finishMission }, [_type], 1.5, true, true, "", "true", 3];
};
