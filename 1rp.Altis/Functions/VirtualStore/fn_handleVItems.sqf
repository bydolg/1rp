/*
** Автор: Джек "Скарсо" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVItems";

private _ctrl =

_this params [
	"_controls",
	["_remove", false, [true]]
];

_controls params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if ([player] call ULP_fnc_onDuty) exitWith {
	["Вы не можете покупать или продавать предметы, находясь на службе..."] call ULP_fnc_hint;
};

private _list = _display displayCtrl 3303;

private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lnbData [(lnbCurSelRow _list), 0]);
if !(isClass _curSel) exitWith { ["Сначала выберите предмет!"] call ULP_fnc_hint; };

private _buyPrice = _list lnbValue [(lnbCurSelRow _list), 1];
private _sellPrice = _list lnbValue [(lnbCurSelRow _list), 2];
(parseSimpleArray (_list lnbData [(lnbCurSelRow _list), 2])) params [ "_gangTax", "_cartels" ];
private _amount = 1;

if (_remove) then {
	_amount = [configName _curSel] call ULP_fnc_hasItem;
	if (_amount isEqualTo -1) exitWith {
		["У вас нет таких предметов для продажи!"] call ULP_fnc_hint;
		false breakOut "fn_buyVItems";
	};
} else {
	_amount = [getNumber(_curSel >> "weight")] call ULP_fnc_getMaxQuantity;
	if (_amount isEqualTo 0) exitWith {
		["У вас недостаточно места в инвентаре!"] call ULP_fnc_hint;
		false breakOut "fn_buyVItems";
	};
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel, _remove, _buyPrice, _sellPrice, _gangTax, _cartels],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_remove", false, [true]],
			["_buyPrice", 0, [0]],
			["_sellPrice", 0, [0]],
			["_gangTax", 0, [0]],
			["_cartels", [], [[]]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		_display = findDisplay 3300; // Мы больше не нуждаемся в выборе, поэтому переключаемся на виртуальный магазин...
		if (isNull _display || { isNull _cfg }) exitWith {};

		_buyPrice = _buyPrice * _value;
		_sellPrice = _sellPrice * _value;
		_gangTax = _gangTax * _value;

		private _name = getText(_cfg >> "displayName");

		if (_remove) then {
			if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
				["SoldVirtualItem", [configName _cfg, _value, _sellPrice, [getNumber (_cfg >> "Settings" >> "isIllegal")] call ULP_fnc_bool]] call ULP_fnc_invokeEvent;
				[_sellPrice, false, format["Продано %1 %2(ов)", _value, _name]] call ULP_fnc_addMoney;

				{
					_x params [ "_group", "_price" ];
					if ([_group] call ULP_fnc_isGroup) then {
						[_group, round (_price * _value), true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
					};
				} forEach _cartels;

				if ([] call ULP_fnc_isGroup && { _gangTax > 0 }) then {
					[group player, _gangTax, true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
					[format["Вы продали %1 %2(ов) за <t color='#B92DE0'>$%3</t>, и $%4 было взято в качестве налога вашей группой!", _value, _name, [_sellPrice] call ULP_fnc_numberText, [_gangTax] call ULP_fnc_numberText]] call ULP_fnc_hint;
				} else {
					[format["Вы продали %1 %2(ов) за <t color='#B92DE0'>$%3</t>!", _value, _name, [_sellPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
				};

				[true] call ULP_fnc_saveGear;
			} else {
				[format["У вас нет %1 %2(ов) для продажи!", _value, _name]] call ULP_fnc_hint;
			};
		} else {
			if ([_buyPrice, false, format["Куплено %1 %2(ов)", _value, _name]] call ULP_fnc_removeMoney) then {
				if ([configName _cfg, _value, false] call ULP_fnc_handleItem) then {
					[format["Вы купили %1 %2(ов) за $%3!", _value, _name, [_buyPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
					[true] call ULP_fnc_saveGear;
				} else {
					[_buyPrice, false] call ULP_fnc_addMoney; // Вернуть им деньги, они не получили то, за что заплатили...
					["У вас недостаточно места в инвентаре!"] call ULP_fnc_hint;
				};
			} else {
				[format["У вас недостаточно средств <t color='#B92DE0'>$%1</t> для %2 %3(ов)!", [_buyPrice] call ULP_fnc_numberText, _value, _name]] call ULP_fnc_hint;
			};
		};

		[_display] call ULP_fnc_updateVStore;
	}, false
] call ULP_fnc_selectNumber;
