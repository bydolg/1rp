/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_buyVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _texList = _display displayCtrl 3408;

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"", "_missionCfg", "_picture", "_name"
];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _plate = false;
private _texture = _texList lbData (lbCurSel _texList);

private _textureCfg = _missionCfg >> "Textures" >> _texture;
if (isClass _textureCfg) then {
	if !([configName _missionCfg, _texture] call ULP_fnc_isTextureUnlocked) then {
		[format ["Текстура <t color='#B92DE0'>%1</t> в данный момент заблокирована, вам нужно разблокировать ее, прежде чем вы сможете ее использовать!", getText (_textureCfg >> "displayName")]] call ULP_fnc_hint;
		breakOut "fn_buyVehicle";
	};
};

private _spawns = _display getVariable ["spawns", []];

_spawns = _spawns apply {
	if (_x isEqualType []) exitWith { [_x] };
	[markerPos _x, markerDir _x]
};

private _spawn = {
	if (((_x select 0) nearEntities [["Car", "Ship", "Air"], 8]) isEqualTo []) exitWith { _x };
} forEach _spawns;

if (isNil "_spawn") exitWith {
	["Нет доступных точек появления!"] call ULP_fnc_hint;
};

private _faction = [player] call ULP_fnc_getFaction;

if ([_faction, "vehicles"] call ULP_fnc_factionFree || { [_buyPrice, false, format ["Куплено %1", _name]] call ULP_fnc_removeMoney }) exitWith {

	if ([_faction, "vehicles"] call ULP_fnc_factionPresistant) then {
		["VehicleBought", {
			_this params [
				["_params", [], [[]]],
				["_limitReached", false, [true]],
				["_price", 0, [0]],
				["_limit", 0, [0]]
			];

			if (_limitReached) exitWith {
				([_params select 0] call ULP_fnc_vehicleCfg) params [
					"", "", "", ["_name", "Unknown", [""]], "", "", "", "", ""
				];
				
				[_price, false, "Limit Refund"] call ULP_fnc_addMoney;
				[([format ["Ваша покупка не может быть сделана, так как вы достигли максимального гаражного лимита для %1 <t color='#B92DE0'>%2</t>", _name, [_limit] call ULP_fnc_numberText], format ["Вам вернули %1%2 за %3, так как вы достигли максимального гаражного лимита %4...", "$", [_price] call ULP_fnc_numberText, _name, [_limit] call ULP_fnc_numberText]] select (_price > 0))] call ULP_fnc_hint;
			};

			_params call ULP_fnc_createVehicle;
		}, true] call ULP_fnc_addEventHandler;

		[
			_buyPrice, 
			getPlayerUID player, 
			profileName, _faction, 
			configName _missionCfg, 
			_spawn, 
			_texture, 
			["VehicleCollector"] call ULP_fnc_hasPerk
		] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
	} else {
		[configName _missionCfg, _spawn, _texture] call ULP_fnc_createVehicle;
	};

	["BuyVehicle"] call ULP_fnc_achieve;
	closeDialog 0;
};

[format["У вас нет денег на покупку этого автомобиля. Вам нужно $%1.", [_buyPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
