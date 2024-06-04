/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyItems";

_this params [
	"_ctrl"
];

if !(canSuspend) exitWith { _this spawn ULP_fnc_buyItems; };

if ([player] call ULP_fnc_onDuty) exitWith {
	["Вы не можете продавать или покупать товары на службе..."] call ULP_fnc_hint;
};

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _onItemBuy = getText((_display getVariable "storeCfg") >> "onItemBuy");
if (_onItemBuy isEqualTo "") exitWith {};

private _cartList = _display displayCtrl 3107;
if ((lbSize _cartList) isEqualTo 0) exitWith {
	["Вы должны добавить что-то в корзину, прежде чем оформить заказ!"] call ULP_fnc_hint;
};

_ctrl ctrlEnable false;

private _override = cbChecked (_display displayCtrl 3114);
private _cartValue = _display getVariable "cartValue";

if (!([[player] call ULP_fnc_getFaction, "physical"] call ULP_fnc_factionFree) && { CASH < _cartValue }) then {
	["Вы не можете позволить себе эти товары!"] call ULP_fnc_hint;
} else {
	private _itemsBought = 0;
	private _itemsNotBought = createHashMap;

	for "_i" from 0 to ((lbSize _cartList) - 1) do {
		private _data = _cartList lbData _i;
		_data = parseSimpleArray _data;

		_data params [
			"_className", "_texClass"
		];

		([_className] call ULP_fnc_itemCfg) params [
			"_cfgName",
			"_itemCfg", "", "", "", "_name"
		];
		
		if ([_cartValue, _cartList, _className, _texClass, _cfgName, _itemCfg, _i, _override] call compile _onItemBuy) then {
			_itemsBought = _itemsBought + 1;
		} else {
			_itemsNotBought set [_name, (_itemsNotBought getOrDefault [_name, 0]) + 1];
			_cartValue = _cartValue - (_cartList lbValue _i);
		};
	};

	if !(_itemsBought isEqualTo 0) then {
		// Очистить корзину...
		lbClear _cartList;
		_cartList lbSetCurSel -1;

		(_display displayCtrl 3115) ctrlEnable false;
		(_display displayCtrl 3117) ctrlEnable false;
		(_display displayCtrl 3118) ctrlEnable false;

		// Оплатить и очистить общую стоимость...
		if !([[player] call ULP_fnc_getFaction, "physical"] call ULP_fnc_factionFree) then {
			[_cartValue, false, format ["Bought Items"]] call ULP_fnc_removeMoney;
		};
		_display setVariable ["cartValue", 0];

		if ((count _itemsNotBought) isEqualTo 0) then {
			[format["Вы купили эти товары за <t color='#B92DE0'>$%1</t>.", [_cartValue] call ULP_fnc_numberText]] call ULP_fnc_hint;
		} else {
			private _message = [format["Вы купили товары за $%1.<br/><br/>У вас не было места для следующих товаров, поэтому с вас не взяли деньги за них:<br/>", [_cartValue] call ULP_fnc_numberText]];
			
			{
				_message pushBack format [" - %1 (%2)", _x, [_y] call ULP_fnc_numberText];
			} forEach _itemsNotBought;

			[_message joinString "<br/>"] call ULP_fnc_hint;
		};
	} else {
		["У вас недостаточно места для этих товаров!"] call ULP_fnc_hint;
	};
};

[] call ULP_fnc_syncPlayerInfo;
_ctrl ctrlEnable true;
