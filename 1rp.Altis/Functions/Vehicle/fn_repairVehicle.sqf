/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_repairVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

private _hasToolkit = "ToolKit" in (items player);
private _isPatching = !_hasToolkit && { [_vehicle] call ULP_fnc_hasTyreDamage };

if !(isClass _missionCfg) exitWith {};
if (!_hasToolkit && { !_isPatching }) exitWith {
	["Для ремонта транспортного средства вам потребуется инструменты!"] call ULP_fnc_hint;
};

private _time = 40;
if (isNumber (_missionCfg >> "repairTime")) then {
	_time = _time + getNumber (_missionCfg >> "repairTime");
};

private _profession = ["Repairing"] call ULP_fnc_getProfessionCalculation;
if (_profession > 0) then {
	_time = _time - (_time * (_profession / 100));
};

if !([format["%1 %2", ["Repairing", "Patching"] select (_isPatching), _name], _time, [_vehicle, _name, _isPatching], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { "ToolKit" in (items player) || { (_this select 2) } } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_isPatching" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { !("ToolKit" in (items player)) && { !_isPatching } }) exitWith {
		[format["Вы не смогли отремонтировать <t color='#B92DE0'>%1</t>, так как оно либо находится в аварийном состоянии, либо у вас нет необходимых инструментов."]] call ULP_fnc_hint;
	};
	
	if (!([player, ["Hato"]] call ULP_fnc_isFaction) && { !_isPatching }) then {

		// Нет перка - 0, перк 1 уровня - 0.25, перк 2 уровня - 0.5, перк 3 уровня - 0.75, перк 4 уровня - 1
		private _perkValue = ["GeneralMechanic", 0] call ULP_fnc_activatePerk;

		// Для всех, кроме ХАТО, применить перк "Главный механик"
		if ((1 - _perkValue) <= (random 1)) exitWith {
			["Вы сохранили свои инструменты."] call ULP_fnc_hint;
		};

		player removeItem "Toolkit";
	};

	if (_isPatching) then {
		{
			if (((toLower (configName _x)) find "wheel") > -1) then {
				_vehicle setHitPointDamage [configName _x, 0];
			};
		} forEach ("isClass _x" configClasses (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints"));

		[format["Вы заклеили колеса <t color='#B92DE0'>%1</t>, вам понадобятся инструменты для ремонта других повреждений.", _name]] call ULP_fnc_hint;
	} else {
		_vehicle setDamage 0;
		[format["Вы отремонтировали <t color='#B92DE0'>%1</t> с помощью инструментов.", _name]] call ULP_fnc_hint;
	};

	if (time >= (_vehicle getVariable ["ProfessionCooldown", time - 120])) then {
		["Repairing", 1, 40] call ULP_fnc_increaseProfession;
		_vehicle setVariable ["ProfessionCooldown", time + 120];
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете ремонтировать транспортное средство, выполняя другое действие!"] call ULP_fnc_hint;
};

closeDialog 0;
