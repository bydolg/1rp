/*
** Автор: Jack "Scarso" Farhall
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_changeRank";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([4] call ULP_fnc_canGroupRank) exitWith {
	["У вас нет разрешения на выполнение этого действия!"] call ULP_fnc_hint;
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Вы должны выбрать члена своей группы, чтобы исключить!"] call ULP_fnc_hint;
};

// Проверки ранга...
if ((_memberList lnbValue [_selected, 1]) >= ([] call ULP_fnc_getGroupRank)) exitWith { ["Вы не можете исключить человека, равного или выше вашего ранга!"] call ULP_fnc_hint; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Вы уверены, что хотите исключить %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_removeMember) then {
			if !(_member isEqualType "") then {
				["GroupKicked", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Вы исключили <t color='#B92DE0'>%1</t> из группы", _name]] call ULP_fnc_hint;
		} else {
			[format ["Вы не смогли исключить <t color='#B92DE0'>%1</t>, пожалуйста, попробуйте позже...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;
