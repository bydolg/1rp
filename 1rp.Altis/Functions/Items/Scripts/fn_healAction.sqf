/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_healAction";

private _target = _this;
if (isNull _target || { !([_target] call ULP_fnc_canHeal) }) exitWith { false };

private _hasMedkit = ((["MediKit"] call ULP_fnc_hasItem) > 0);

private _time = 15;
if (_hasMedkit) then { _time = 8; };

if !([format["Лечим %1", name _target], _time, [_target, _hasMedkit], { [(_this select 0)] call ULP_fnc_canHeal }, {
	_this params [ "_target", "_hasMedkit" ];

	if !([_target] call ULP_fnc_canHeal) exitWith {};

	if !(_hasMedkit) then { ["FirstAidKit", 1, true] call ULP_fnc_handleItem; };

	_target setDamage ([["FirstAider", 0.25] call ULP_fnc_activatePerk, 0] select (_hasMedkit));
	[format ["Вы исцелили <t color='#B92DE0'>%1</t>!", name _target]] call ULP_fnc_hint;
}, {}, ["GRAB", (["PRONE", "CROUCH"] select ((stance player) isEqualTo "STAND"))]] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете исцелять, выполняя другое действие..."] call ULP_fnc_hint;
	false
};

true
