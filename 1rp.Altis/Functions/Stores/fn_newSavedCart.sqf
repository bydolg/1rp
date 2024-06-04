/*
** Автор: Джек "Scarso" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_newSavedCart";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Введите имя корзины", ["Save", "Cancel"], "Введите имя здесь...", [_display],
	{	
		_this params [
			["_display", displayNull, [displayNull]],
			["_name", "", [""]]
		];

		_name = [_name] call ULP_fnc_stripString;

		private _maxLengthCart = getNumber (missionConfigFile >> "CfgStores" >> "maxCartNameLength");

		if ((count _name) > _maxLengthCart) exitWith {
			[format["Максимальная длина имени корзины - %1 символа!", _maxLengthCart]] call ULP_fnc_hint;
		};

		[_display, _name] call ULP_fnc_saveCart;
	}, false
] call ULP_fnc_enterString;
