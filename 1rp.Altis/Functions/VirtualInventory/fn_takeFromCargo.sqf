/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_takeFromCargo";

if (canSuspend) exitWith {
    [ULP_fnc_takeFromCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _container = _display getVariable ["container", objNull];
if (isNull _container || { !([_container] call ULP_fnc_isCargoUser) }) exitWith {
	_ctrl ctrlEnable false;
	["Вы должны быть зарегистрированным пользователем груза, чтобы брать или класть предметы в этот контейнер!"] call ULP_fnc_hint;
};

private _containerList = _display displayCtrl 4208;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	["Вы должны выбрать что-то, чтобы взять из этого контейнера!"] call ULP_fnc_hint;
};

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;

// Системные предметы добавляются / удаляются из транспортных средств с помощью скрипта
if ([getNumber (_vItem >> "Settings" >> "isSystemItem")] call ULP_fnc_bool) exitWith {
	["Этот предмет нельзя перемещать из этого контейнера вручную"] call ULP_fnc_hint;
};

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

private _data = _cargo getOrDefault [_item, 0];

private _count = _data;

if (_count isEqualType []) then {
	_count = 1;

	private _index = _data find (_containerList lnbData [(lnbCurSelRow _containerList), 1]);

	if (_index < 0) then {
		_count = 0;
	} else {
		_data = _data select _index;
	};
} else {
	_data = -1;
};

if (_count <= 0) exitWith {
	["Вы не можете взять этот предмет из контейнера, так как он отсутствует в нем!"] call ULP_fnc_hint;
};

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];
private _maxCarry = floor ((_maxWeight - _carryWeight) / getNumber(_vItem >> "weight"));

if (_maxCarry <= 0) exitWith {
	["У вас недостаточно места в инвентаре, чтобы поместить хотя бы один из этих предметов!"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, (_count min _maxCarry)], [_display, _container, _item, _data],
	{
		_this params [
			["_display", displayNull, [displayNull]],
			["_container", objNull, [objNull]],
			["_item", "", [""]],
			["_data", 1, [0, "", []]],
			"",
			["_value", 1, [0]]
		];

		if (isNull _display || { _item isEqualTo "" }) exitWith {};

		private _name = getText (missionConfigFile >> "CfgVirtualItems" >> _item >> "displayName");
		if ([getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
			_value = _data;
			_name = format [_name, _value];
		};

		if ([_item, _value] call ULP_fnc_handleItem) then {
			if ([_container, _item, _value] call ULP_fnc_removeFromCargo) then {
				[format["Вы взяли <t color='#B92DE0'>%1 %2(а/ов)</t> из этого контейнера!", _value, _name]] call ULP_fnc_hint;
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_item, _value, true] call ULP_fnc_handleItem;
				[format["В этом контейнере нет <t color='#B92DE0'>%1 %2(а/ов)</t> для взятия!", _value, _name]] call ULP_fnc_hint;
			};
		} else {
			[format["У вас недостаточно места в инвентаре, чтобы взять <t color='#B92DE0'>%1 %2(а/ов)</t>!", _value, _name]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_selectNumber;
