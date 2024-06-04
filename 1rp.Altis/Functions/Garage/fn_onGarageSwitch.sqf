/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onGarageSwitch";

if (canSuspend) exitWith {
    [ULP_fnc_onGarageSwitch, _this] call ULP_fnc_directCall;
};

_this params [
    ["_list", controlNull, [controlNull]],
    ["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _settings = _display displayCtrl 3502;
private _info = _display displayCtrl 3503;
private _textureText = _display displayCtrl 3504;

private _itemData = (_list lbData _index);
if (_itemData isEqualTo "") exitWith {};

_itemData = parseSimpleArray _itemData;

private _impound = _display getVariable ["impound", false];

_itemData params [
    "_id", "_classname", "_texture", "", "_faction"
];

private _cfg = [_classname] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
    "", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

private _retrievalPrice = [
    round (getNumber(_missionCfg >> "buyPrice") * getNumber(missionConfigFile >> "CfgVehicles" >> "retrievalPerc")),
    (_list lbValue _index)
] select (_impound);

if (["MatesRates"] call ULP_fnc_hasPerk) then { _retrievalPrice = _retrievalPrice * 0.5 };

_itemData set [3, _retrievalPrice];
_itemData set [4, _index];
_itemData set [5, _faction];
_display setVariable ["selected", _itemData];

_textureText ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", getText(_missionCfg >> "Textures" >> _texture >> "displayName")];

_settings ctrlSetStructuredText parseText format ["
<br/><br/><br/>
<img image = '%1' align='center' size='3.5' /> <br/>
<t align = 'center' size = '1.5'>%2</t><br/>
<t align = 'left' size = '1'><br/>%3</t>", _picture, _name, getText(_missionCfg >> "description")];

_info ctrlSetStructuredText parseText format ["<t align = 'left' size = '1'>%8<t align='right'>%1</t></t>
<t align='left' size='1'><br/>Виртуальная вместимость <t align='right'>%2</t></t>
<t align='left' size='1'><br/>Максимальная скорость <t align='right'>%3 км/ч</t></t>
<t align='left' size='1'><br/>Уровень брони <t align='right'>%4</t></t>
<t align='left' size='1'><br/>Пассажирские места <t align='right'>%5</t></t>
<t align='left' size='1'><br/>Лошадинные силы <t align='right'>%6 л.с.</t></t>
<t align='left' size='1'><br/>Емкость топливного бака <t align='right'>%7</t></t>", 
([format["$%1", [_retrievalPrice] call ULP_fnc_numberText], "-"] select (_retrievalPrice < 1)),
getNumber(_missionCfg >> "virtualSpace"), _topSpeed, _armor, _seats + 1, _power, _fuel, (["Retreival Price", "Unimpound Fee"] select (_impound))];
