/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
** Использование:
** 	[this] call ULP_fnc_addBank;
** 	[this, "Банковский счет"] call ULP_fnc_addBank;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addBank";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "Банкомат", [""]]
];

if (isNull _trader || { _title isEqualTo "" }) exitWith {};

_trader addAction [_title, { [] call ULP_fnc_openBank }, nil, 1.5, true, true, "", "true", 3];
