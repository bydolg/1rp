/*
** Автор: Jack "Scarso" Farhall
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_leaveGroup";

if !([] call ULP_fnc_isGroup) exitWith { false };

private _group = group player;

if ([] call ULP_fnc_isGroupOwner) exitWith {
	["Вы должны передать владение группой кому-то другому, прежде чем вы сможете покинуть её!"] call ULP_fnc_hint;
	false
};

private _name = [_group] call ULP_fnc_getGroupName;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Leave", "Cancel"],
	format ["Вы уверены, что хотите покинуть %1...", _name], [_group, _name],
	{	
		_this params [ "_group", "_name" ];

		if ([group player, player] call ULP_fnc_removeMember) then {
			[format ["Вы <t color='#B92DE0'>покинули %1</t>", _name]] call ULP_fnc_hint;

			["Home"] call ULP_fnc_setScreen;
			[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
		} else {
			[format ["Вы не смогли покинуть <t color='#B92DE0'>%1</t>, пожалуйста, попробуйте позже...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;

true
