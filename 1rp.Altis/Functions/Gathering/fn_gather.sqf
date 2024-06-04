/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_gather";

_this params [
	["_zone", configNull, [configNull]]
];

if (isNull _zone || { !([player] call ULP_fnc_getFaction in getArray (_zone >> "factions")) } || { !(call compile getText (_zone >> "condition")) }) exitWith { false };

private _reqItems = getArray (_zone >> "reqItems");
{
	if ([_x] call ULP_fnc_hasItem isEqualTo -1) exitWith {
		[format["Для сбора в этой зоне необходимы следующие предметы: <t color='#B92DE0'>%1</t>!", _reqItems]] call ULP_fnc_hint;
		false breakOut "fn_gather";
	};

	nil
} count _reqItems;

private _reqLicenses = getArray (_zone >> "reqLicenses");
{
	if !([_x] call ULP_fnc_hasLicense) exitWith {
		[format["Вам нужны лицензии для сбора здесь: <t color='#B92DE0'>%1</t>!", _reqLicenses]] call ULP_fnc_hint;
		false breakOut "fn_gather";
	};

	nil
} count _reqLicenses;

private _resources = getArray (_zone >> "items");
if (_resources isEqualTo []) exitWith { false };

private _items = _resources apply { _x select 0 };
private _weights = _resources apply { (_x select 1) / 100 };

private _item = missionConfigFile >> "CfgVirtualItems" >> (_items selectRandomWeighted _weights);
if !(isClass _item) exitWith {};

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

private _total = floor ((_maxWeight - _carryWeight) / getNumber(_item >> "weight"));
if (_total isEqualTo 0) exitWith {
	["Ваш инвентарь полон!"] call ULP_fnc_hint;
	false
};

private _title = ["Сбор", getText (_zone >> "actionTitle")] select (isText (_zone >> "actionTitle"));
private _profession = getArray (_zone >> "profession");
private _leveling = getArray (_zone >> "leveling");

private _time = getNumber(_zone >> "gatherTime");

if !(_profession isEqualTo []) then {
	private _profCal = [(_profession select 0)] call ULP_fnc_getProfessionCalculation;
	if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };
};

[format["%1 %2(ов)", _title, getText(_item >> "displayName")], _time * _total, [_item, _total, _profession, _leveling], { true }, {
	_this params [ "_item", "_total", "_profession", "_leveling" ];

	[configName _item, _total] call ULP_fnc_handleItem;

	[format["Вы собрали <t color='#B92DE0'>%1 %2(ов)</t>.", _total, getText(_item >> "displayName")]] call ULP_fnc_hint;
	["GatheredVirtualItem", [configName _item, _total]] call ULP_fnc_invokeEvent;

	if (time >= (player getVariable ["GatherCooldown", time - 30])) then {
		if !(_profession isEqualTo []) then { _profession call ULP_fnc_increaseProfession; };
		if !(_leveling isEqualTo []) then { _leveling call ULP_fnc_addXP; };
		player setVariable ["GatherCooldown", time + 30];
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true
