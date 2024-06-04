/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_openGroup";

if !(isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Groups")) exitWith {
	["У вас нет доступа к этому!"] call ULP_fnc_hint;
};

if (ULP_Group_Creating) exitWith {
	["Вы не можете использовать это приложение, так как оно обрабатывает предыдущий запрос на создание!"] call ULP_fnc_hint;
};

if ([] call ULP_fnc_isGroup) then {
	["Group"] call ULP_fnc_setScreen;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [], [],
		{
			scopeName "fn_creationCheck";

			_this params [
				["_display", displayNull, [displayNull]],
				["_tagText", "", [""]],
				["_nameText", "", [""]],
				["_type", "", [""]]
			];
			
			private _cfg = missionConfigFile >> "CfgGroups";
			if !(isClass (_cfg >> "Types" >> _type)) exitWith {
				["Выбранный тип группы не существует!"] call ULP_fnc_hint;
			};

			{
				_x params ["_text", "_cfgSettings"];

				private _min = getNumber (_cfgSettings >> "MinLength");
				private _max = getNumber (_cfgSettings >> "MaxLength");
				private _length = count _text;

				switch (true) do {
					case (_length < _min): {
						[format["%1 вашей группы должно быть <t color='#B92DE0'>не менее %2</t> символов!", configName _cfgSettings, _min]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
					case (_length > _max): {
						[format["%1 вашей группы должно быть <t color='#B92DE0'>не более %2</t> символов!", configName _cfgSettings, _max]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
					case (_text in getArray (_cfgSettings >> "Blacklisted")): {
						[format["%1 вашей группы находится в <t color='#B92DE0'>черном списке</t> и не может быть использовано!", configName _cfgSettings]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
				};
			} forEach [
				[_tagText, _cfg >> "Tag"],
				[_nameText, _cfg >> "Name"]
			];

			ULP_Group_Creating = true;

			[player, _tagText, _nameText, _type] remoteExecCall ["ULP_SRV_fnc_createGroup", RSERV];
			true
		}
	] call ULP_fnc_inputGroupInfo;
};
