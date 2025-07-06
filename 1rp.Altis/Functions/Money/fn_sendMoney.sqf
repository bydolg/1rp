/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sendMoney";

if (canSuspend) exitWith {
    [ULP_fnc_sendMoney, _this] call ULP_fnc_directCall;
};

_this params [
    ["_unit", objNull, [objNull]],
    ["_amount", 0, [0]],
    ["_bank", false, [true]]
];

if (isNull _unit || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isSurrendered } || { isDowned(player) } || { isDowned(_unit) } || { !_bank && ((player distance _unit) > 3) }) exitWith {
    ["Вы должны быть близко, не ограничены и не сдаваться, чтобы передавать деньги..."] call ULP_fnc_hint;
};

if (_amount < 1) exitWith {
    ["У вас нет денег для передачи в данный момент..."] call ULP_fnc_hint;
};

if !([_amount, _bank, format ["%1 %2", ["Given to", "Transferred to"] select (_bank), name _unit]] call ULP_fnc_removeMoney) exitWith {
        [format ["У вас нет <t color='#B92DE0'>%1%2</t>, чтобы %3...", "$", [_amount] call ULP_fnc_numberText, ["передать", "перевести"] select (_bank)]] call ULP_fnc_hint;
};

[_amount, _bank, profileName] remoteExecCall ["ULP_fnc_recieveMoney", _unit];
[format ["Вы %1 <t color='#B92DE0'>%2%3</t> %4", ["передали", "перевели"] select (_bank), "$", [_amount] call ULP_fnc_numberText, name _unit]] call ULP_fnc_hint;
