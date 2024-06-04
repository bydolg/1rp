/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_drill";

private _object = cursorObject;
if (isNull _object || { (player distance _object) > 5 } || { _object getVariable ["drilled", true] }) exitWith {
	["Вы или слишком далеко от объекта для сверления, или он уже открыт..."] call ULP_fnc_hint;
};

["Сверление контейнера", 240, [_object], { (player distance (_this select 0)) <= 5 }, {
	private _object = _this select 0;
	
	["Вы успешно сломали замок!"] call ULP_fnc_hint;
	_object setVariable ["drilled", nil, true];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
