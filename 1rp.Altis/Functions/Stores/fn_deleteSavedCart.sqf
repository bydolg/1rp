/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_deleteSavedCart";

private _display = _this param [0, displayNull, [displayNull]];
private _name = _this param [1, _display getVariable ["saved_cart", ""], [""]];

if (isNull _display) exitWith {};

if (_name isEqualTo "" || { isNil "_name" }) exitWith {
	["Вы не выбрали сохраненную корзину"] call ULP_fnc_hint;
};

private _storeCfgName = format["%1%2", configName (_display getVariable "storeCfg"), configName (_display getVariable "curStore")];
private _allSavedCarts = + (profileNamespace getVariable ["ULP_SavedCarts", createHashMap]);
private _savedCarts = _allSavedCarts getOrDefault [_storeCfgName, createHashMap];

_savedCarts deleteAt _name;

if (_savedCarts isEqualTo []) then {
	_allSavedCarts deleteAt _storeCfgName;
} else {
	_allSavedCarts set [_storeCfgName, _savedCarts];
};

profileNamespace setVariable ["ULP_SavedCarts", _allSavedCarts];
saveProfileNamespace;

_display setVariable ["saved_cart", nil];
(_display displayCtrl 3117) ctrlEnable false;
(_display displayCtrl 3118) ctrlEnable false;

[format ["Корзина '%1' была удалена", _name]] call ULP_fnc_hint;
