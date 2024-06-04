/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initGroups";

["Инициализация групп"] call ULP_fnc_logIt;

["GroupCreationSucceeded", {
    _this params [
        ["_groupId", -1, [0]]
    ];
    
    ["Ваша группа создана."] call ULP_fnc_hint;
    ULP_Group_Creating = false;

    [format["Создана группа (%1)", _groupId]] call ULP_fnc_logIt;

    [ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupCreationFailed", {
    _this params [
        ["_reason", "Unknown", [""]]
    ];

    [_reason] call ULP_fnc_hint;
    ULP_Group_Creating = false;

    [format["Создание группы не удалось (%1)", _reason]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupWithdraw", {
    _this params [
        ["_message", "", [""]],
        ["_amount", 0, [0]],
        ["_total", 0, [0]]
    ];

    if (_amount > 0) then {
		[_amount, false, format ["Group Funds"]] call ULP_fnc_addMoney;
    };

    [_message] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupRankChanged", {
    _this params [
        ["_rank", 0, [0]],
        ["_actioner", objNull, [objNull]]
    ];

    _rank = [_rank] call ULP_fnc_rankName;
    [format ["Ваш ранг установлен на <t color='#B92DE0'>%1</t>", ([format["%1 от %2!", _rank, name _actioner], _rank] select (isNull _actioner))]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupOwner", {
    [format ["<t color='#B92DE0'>%1</t> передал(а) вам <t color='#B92DE0'>владение группой</t>!", name (_this param [0, objNull])]] call ULP_fnc_hint;
    [ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupInvite", {
    _this params [
        ["_group", grpNull, [grpNull]],
        ["_unit", objNull, [objNull]]
    ];

    if (isNull _group || { isNull _unit }) exitWith {};

    if ([["EnableAutoDecline"] call ULP_fnc_getOption] call ULP_fnc_bool) then {
        ["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
    };

    [
        (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Принять", "Отклонить"],
        format ["<t color='#B92DE0'>%1</t> пригласил(а) вас присоединиться к <t color='#B92DE0'>%2</t>, вы принимаете приглашение?", name _unit, [_group] call ULP_fnc_getGroupName], [_group, _unit],
        {
            _this params [ "_group", "_unit" ];

            [_group, player] remoteExecCall ["ULP_SRV_fnc_addGroupMember", RSERV];
        }, {
            private _unit = _this param [1, objNull];
            if (isNull _unit) exitWith {};
            ["GroupInviteRejected", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
        }, false
    ] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;

["GroupInviteRejected", {
    _this params [
        ["_unit", objNull, [objNull]]
    ];

    if (isNull _unit) exitWith {};

    _unit setVariable ["group_invited", nil];
    [format ["<t color='#B92DE0'>%1</t> отклонил(а) приглашение в группу, которое вы ему отправили!", name _unit]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupJoined", {
    _this params [
        ["_unit", objNull, [objNull]]
    ];

    if (isNull _unit) exitWith {};
    
    if (_unit isEqualTo player) then {
        [ { !([] call ULP_fnc_isGroup) }, [], {
			["JoinGroup"] call ULP_fnc_achieve;

            [format ["Вы успешно <t color='#B92DE0'>присоединились к %1</t>", [] call ULP_fnc_getGroupName]] call ULP_fnc_hint;
            [] call ULP_fnc_setTags;
        }] call ULP_fnc_waitUntilExecute;
    } else {
        _unit setVariable ["group_invited", nil];
        [format ["<t color='#B92DE0'>%1</t> присоединился(ась) к вашей группе", name _unit]] call ULP_fnc_hint;
    };
}] call ULP_fnc_addEventHandler;

["GroupKicked", {
    [format ["<t color='#B92DE0'>%1</t> исключил(а) вас из группы! Теперь вы без группы! :(", name (_this param [0, objNull])]] call ULP_fnc_hint;
    [ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupDisbanded", {
    [format ["<t color='#B92DE0'>%1</t> распустил(а) группу! Теперь вы без группы! :(", name (_this param [0, objNull])]] call ULP_fnc_hint;
    [ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;
