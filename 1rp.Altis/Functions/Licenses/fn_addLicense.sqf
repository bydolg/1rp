/*
** Автор: Джек "Scarso" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addLicense";

_this params [
	["_license", "", [""]],
	["_price", -1, [0]],
	["_save", true, [false]]
];

_license = missionConfigFile >> "CfgLicenses" >> _license;
if (!isClass _license || 
	{ [_license] call ULP_fnc_hasLicense } || 
	{ !([player] call ULP_fnc_getFaction in getArray (_license >> "factions")) } || 
	{ !([] call compile getText(_license >> "conditions")) }
) exitWith { false };

if (!(_price isEqualTo -1) && { !([_price, false, format["Приобретено %1", getText (_license >> "displayName")]] call ULP_fnc_removeMoney) }) exitWith {
	[format["У вас недостаточно средств для приобретения этой лицензии. Вам нужно <t color='#B92DE0'>$%1</t>...", [_price] call ULP_fnc_numberText]] call ULP_fnc_hint;
	false breakOut "fn_addLicense";
};

ULP_Licenses pushBackUnique (configName _license);

if (_save) then {
	[player, 0, ULP_Licenses] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

true
