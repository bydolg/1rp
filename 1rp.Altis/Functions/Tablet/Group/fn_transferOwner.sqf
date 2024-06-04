/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_transferOwner";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = group player;

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["Только владелец может передать права владения группой!"] call ULP_fnc_hint;
	false
};

if !((ULP_Houses findIf { [_x, player, false] call ULP_fnc_isHouseOwner && { !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _x) >> "condition")) } }) isEqualTo -1) exitWith {
	["Вы должны продать все дома, зависящие от группы, прежде чем передать права владения!"] call ULP_fnc_hint;
	false
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Вы должны выбрать члена вашей группы, чтобы передать ему права владения!"] call ULP_fnc_hint;
};

if (_selectedMember isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["Вы не можете передать права владения себе"] call ULP_fnc_hint;
	false
};

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Вы уверены, что хотите передать права владения %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_setGroupOwner) then {
			if !(_member isEqualType "") then {
				["GroupOwner", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Вы назначили <t color='#B92DE0'>%1</t> владельцем группы...", _name]] call ULP_fnc_hint;
		} else {
			[format ["Вы не передали права владения <t color='#B92DE0'>%1</t>, попробуйте еще раз позже...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;
