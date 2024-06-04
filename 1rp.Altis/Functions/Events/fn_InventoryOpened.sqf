/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_InventoryOpened";

_this params [
	["_unit", objNull, [objNull]],
	["_container", objNull, [objNull]],
	["_secondaryContainer", objNull, [objNull]]
];

private _uniform = (uniformContainer player) getVariable ["texture", ""];
private _backpack = (backpackContainer player) getVariable ["texture", ""];

if !(_uniform isEqualTo "") then { [player, uniform player, uniformContainer player, _uniform] call ULP_fnc_setTextures; };
if !(_backpack isEqualTo "") then { [unitBackpack player, typeOf (unitBackpack player), backpackContainer player, _backpack] call ULP_fnc_setTextures; };

if ([getNumber (configFile >> "CfgVehicles" >> (typeOf _container) >> "isBackpack")] call ULP_fnc_bool) exitWith {
    ["Вам запрещено заглядывать в рюкзак других людей!"] call ULP_fnc_hint;
    true
};

if ([_container, ["LandVehicle", "Air", "Ship"]] call ULP_fnc_isKindOf) exitWith {
    if (!(_container in ULP_Keys) && ((locked _container) isEqualTo 2)) exitWith {
        ["Вам запрещено получать доступ к этому транспортному средству, пока оно заперто."] call ULP_fnc_hint;
        true
    };

    if ([] call ULP_fnc_isRestrained || { [] call ULP_fnc_isKnocked } || { [] call ULP_fnc_isSurrendered }) exitWith {
        ["Вы не можете получить доступ к транспортному средству, пока ограничены движением, закованы наручниками или сдались."] call ULP_fnc_hint;
        true
    };
};

if (_container isKindOf "Man" && { !alive _container }) exitWith {
    ["Вам запрещено обыскивать тела мертвых."] call ULP_fnc_hint;
    true
};
