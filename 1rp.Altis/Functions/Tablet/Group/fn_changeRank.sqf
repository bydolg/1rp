/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_changeRank";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([2] call ULP_fnc_canGroupRank) exitWith {
	["У вас нет разрешения на выполнение этого действия!"] call ULP_fnc_hint;
};

private _memberList = _display displayCtrl 23062;
private _rankList = _display displayCtrl 23068;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];
private _selectedRank = lbCurSel _rankList;

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["Вы должны выбрать члена своей группы, чтобы изменить его ранг!"] call ULP_fnc_hint;
};

private _currentRank = _memberList lnbValue [_selected, 1];
private _myRank = [] call ULP_fnc_getGroupRank;

// Проверки ранга...
if (_selectedRank isEqualTo _currentRank) exitWith { ["Этот член уже имеет этот ранг!"] call ULP_fnc_hint; };
if (_currentRank >= _myRank) exitWith { ["Вы не можете изменить ранг кого-то, равного или выше вашего ранга!"] call ULP_fnc_hint; };
if (_selectedRank >= _myRank) exitWith { ["Вы не можете назначить кого-то рангом выше или равным вашему!"] call ULP_fnc_hint; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Подтверждение", ["Подтвердить", "Отменить"],
	format ["Вы уверены, что хотите изменить ранг <t color='#B92DE0'>%1</t>?", _name], [_display, _selectedMember, _selectedRank, _name],
	{
		_this params [ "_display", "_member", "_rank", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member, _rank] call ULP_fnc_setGroupRank) then {
			if !(_member isEqualType "") then {
				["GroupRankChanged", [_rank, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["Вы изменили ранг <t color='#B92DE0'>%1</t> на <t color='#B92DE0'>%2</t>", _name, [_rank] call ULP_fnc_rankName]] call ULP_fnc_hint;
		} else {
			[format ["Вы не смогли изменить ранг <t color='#B92DE0'>%1</t> в группе, пожалуйста, попробуйте позже...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;
