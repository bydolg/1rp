/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveMoney";

if (canSuspend) exitWith {
    [ULP_fnc_recieveMoney, _this] call ULP_fnc_directCall;
};

_this params [
    ["_amount", 0, [0]],
    ["_bank", false, [true]],
    ["_name", "", [""]]
];

if (_amount < 1) exitWith {};

if ([_amount, _bank, format ["Получено от %1%2 через %3", "$", [_amount] call ULP_fnc_numberText, ["cash", "bank"] select (_bank)]] call ULP_fnc_addMoney) then {
    [format ["%1 %2 вам <t color='#B92DE0'>%3%4</t>", _name, ["given", "transferred"] select (_bank), "$", [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
};
