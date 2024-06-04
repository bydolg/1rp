/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placeObject";

if (canSuspend) exitWith { _this call ULP_fnc_placeObject; };

_this params [
	["_placeable", "", [""]],
	["_item", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPlaceables" >> "Objects" >> _placeable;
if !(isClass _cfg) exitWith { false };

if !(isNull (objectParent player)) exitWith {
	["Вы должны быть вне транспортного средства..."] call ULP_fnc_hint;
	false
};

if !(isNull (missionNamespace getVariable ["ULP_PlaceableObject", objNull])) exitWith {
	["Вы должны разместить текущий объект перед тем, как размещать другой..."] call ULP_fnc_hint;
	false
};

private _maxPlaceables = getNumber (missionConfigFile >> "CfgPlaceables" >> "maxPlaceables");
if (([] call ULP_fnc_placedObjects) >= _maxPlaceables) exitWith {
	[format ["У вас есть %1 активных объектов, удалите некоторые, чтобы разместить больше...", _maxPlaceables]] call ULP_fnc_hint;
	false
};

// Убедитесь, что для этого шага не открыто ни одного диалогового окна
[] spawn ULP_UI_fnc_closeDialogs;

[{ !dialog }, [_cfg, _item], {
	_this params [ "_cfg", "_item" ];

	private _className = getText(_cfg >> "className");
	private _positioning = getArray(_cfg >> "positioning") params [
		"_attachPoint", "_rot"
	];

	private _object = createVehicle [_className, [0, 0, 0]];
	_object attachTo [player, _attachPoint];
	_object setDir _rot;
	_object setVariable ["object_owner", [getPlayerUID player, profileName, _item], true];

	ULP_PlaceableObject = _object;

	ULP_PlaceableObjectAction = player addAction [format ["Разместить %1", getText(_cfg >> "displayName")], {
		_this params ["", "", "_actionId", "_params"];
		_params params [ "_cfg", "_item" ];

		private _object = missionNamespace getVariable ["ULP_PlaceableObject", objNull];
		player removeAction _actionId;

		if (isNull _object) exitWith {
			["Произошла ошибка при попытке разместить этот объект..."] call ULP_fnc_hint;
		};

		[format ["Размещение %1", getText(_cfg >> "displayName")], getNumber(_cfg >> "placementTime"), 
			[_object, _item, _cfg], { !(isNull (_this select 0)) && { ([(_this select 1)] call ULP_fnc_hasItem) > 0 } }, {
			_this params [ "_object", "_item", "_cfg" ];

			if (isNull _object) exitWith {};
			
			if !([_item, 1, true] call ULP_fnc_handleItem) exitWith {
				deleteVehicle _object;
			};

			detach _object;

			private _pos = getPosATL _object;
			_pos set[2, 0];

			_object setPosATL _pos;
			_object setVectorUp surfaceNormal _pos;

			[_object] call compile getText(_cfg >> "onPlaced");

			[format["Вы разместили %1...", getText(_cfg >> "displayName")]] call ULP_fnc_hint;
			[false] call ULP_fnc_stopPlacement;
		}, {
			[] call ULP_fnc_stopPlacement;
		}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, [_cfg, _item], 10, false, false, "", "!(isNull (missionNamespace getVariable [""ULP_PlaceableObject"", objNull]))"];
}] call ULP_fnc_waitUntilExecute;

true
