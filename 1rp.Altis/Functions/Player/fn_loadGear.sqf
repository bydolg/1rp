/*
** Author: Jack "Scarso" Farhall
** Description: Загружает экипировку игрока из сохранённых данных.
*/
#include "..\..\script_macros.hpp"
scopeName "fn_loadGear";

_this params [
    ["_itemArray", ULP_Gear, [[]]]
];


[_itemArray] spawn {
    params [["_itemArray", []]];

    waitUntil {
        sleep 0.1;
        !isNull player && local player && alive player
    };

    diag_log "[ULP] Игрок локален и жив — продолжаем.";
 waitUntil {
    sleep 0.1;
    !isNull player &&
    local player &&
    alive player &&
    { getPosATL player select 2 > 0.1 } // Игрок уже "на земле"
};
    [] call ULP_fnc_stripGear;
    sleep 0.1;


    if (_itemArray isEqualTo [] || count _itemArray == 0) exitWith {
        diag_log "[ULP] Пустой itemArray — выдаём дефолтный Loadout";
        [] call ULP_fnc_setLoadout;
    };

    _itemArray params [
        ["_pItems", []],
        ["_yItems", []],
        ["_textures", []]
    ];

player setUnitLoadout _pItems;
sleep 0.25;
[_pItems] call ULP_fnc_safeLoadout;

    // Текстуры
    _textures params [
        ["_uniform", "", [""]],
        ["_backpack", "", [""]]
    ];

    if !(_uniform isEqualTo "") then {
        ULP_UniformTexture = _uniform;
        [player, uniform player, uniformContainer player, _uniform] call ULP_fnc_setTextures;
    };

    if !(_backpack isEqualTo "") then {
        ULP_BackpackTexture = _backpack;
        [player, backpack player, backpackContainer player, _backpack] call ULP_fnc_setTextures;
    };

    // Виртуальные предметы
{
    _x params ["_item", "_data"];
    [_item, _data] call ULP_fnc_handleItem;
} forEach _yItems;

    [] call ULP_fnc_maxCarry;

    diag_log "[ULP] Экипировка успешно применена.";
};
