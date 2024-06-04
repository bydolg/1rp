/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_settings";

_display = _this;
if (isNull _display) exitWith {};

(_display displayCtrl 23088) ctrlSetStructuredText parseText format ["Налог Группы<t align='right'>(%1%2)</t>", (([] call ULP_fnc_groupTax) * 100), "%"];
