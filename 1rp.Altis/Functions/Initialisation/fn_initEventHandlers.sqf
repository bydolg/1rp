/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["Fired", { _this call ULP_fnc_onFired }];
player addEventHandler ["Reloaded", { _this call ULP_fnc_onReloaded }];
player addEventHandler ["GetInMan", { _this call ULP_fnc_onGetIn }];
player addEventHandler ["GetOutMan", { _this call ULP_fnc_onGetOut }];
player addEventHandler ["Take", { _this call ULP_fnc_onTake }];
player addEventHandler ["Put", { _this call ULP_fnc_onPut }];
player addEventHandler ["InventoryOpened", { _this call ULP_fnc_InventoryOpened }];
player addEventHandler ["InventoryClosed", { _this call ULP_fnc_InventoryClosed }];

["KeysGiven", {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_giver", objNull, [objNull]]
	];

	if (isNull _vehicle) exitWith {};

	if (((ULP_Keys pushBackUnique _vehicle) > -1) && { !(isNull _giver) }) then {
		[format ["<t color='#B92DE0'>%1</t> передал вам ключи от <t color='#B92DE0'>%2</t>...", name _giver, ([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "чего-то"]]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["HouseAdded", {
	_this params [
		["_house", objNull, [objNull]]
	];

	ULP_Houses pushBackUnique _house;
	
	private _name = _house getVariable ["building_name", ""];
	
	private _marker = createMarkerLocal [format["house_%1", _house call BIS_fnc_netId], position _house];
	_marker setMarkerTypeLocal "loc_Lighthouse";
	_marker setMarkerColorLocal (["ColorIndependent", "colorBLUFOR"] select ([_house, player, false] call ULP_fnc_isHouseOwner));

	if !(_name isEqualTo "") then {
		_marker setMarkerTextLocal _name;
	};

	_house setVariable ["building_marker", _marker];
}] call ULP_fnc_addEventHandler;

["HouseRemoved", {
	_this params [
		["_house", objNull, [objNull]]
	];

	if (_house in ULP_Houses) then { ULP_Houses deleteAt (ULP_Houses find _house); };
	
	private _marker = _house getVariable ["building_marker", ""];
	if !(_marker isEqualTo "") then {
		deleteMarkerLocal _marker;
	};
}] call ULP_fnc_addEventHandler;

["HouseRenamed", {
	_this params [
		["_house", objNull, [objNull]]
	];

	private _marker = _house getVariable ["building_marker", ""];
	if !(_marker isEqualTo "") then {
		private _name = _house getVariable ["building_name", ""];

		if !(_name isEqualTo (markerText _marker)) then {
			_marker setMarkerTextLocal _name;
		};
	};
}] call ULP_fnc_addEventHandler;

// События настроек...
["OptionChanged", {
	_this params [
		"_option", "_category", "_newSetting", "_lastSetting"
	];

	switch (format["%1_%2", _category, _option]) do {
		case "General_NightLight": { if (hasInterface && { !(isNil "ULP_NightLight") }) then { ULP_NightLight setLightBrightness _newSetting; }; };
		case "HUD_SideChat": { 1 enableChannel ([_newSetting] call ULP_fnc_bool); };
		case "HUD_EnableHUD": {
			if (_newSetting isEqualTo 1) then {
				[] call ULP_UI_fnc_openHUD;
			} else {
				[(["RscHUD"] call ULP_UI_fnc_getLayer)] call ULP_UI_fnc_closeHUD;
			};
		};
		case "HUD_EnableXPBar": { [(_newSetting isEqualTo 1)] call ULP_UI_fnc_updateXpHud; };
		case "HUD_EnablePlayerTags": { [(_newSetting isEqualTo 1)] call ULP_fnc_playerTags };
		case "Indicators_EnableIndicators": { [(_newSetting isEqualTo 1)] call ULP_fnc_groupIndicators };
		case "Audio_EffectsFade": { if (ULP_FadeSound) then { 0 fadeSound _newSetting; }; };
		case "Audio_MusicFade": { if (ULP_FadeSound) then { 0 fadeMusic _newSetting; }; };
		case "Audio_EnableAmbientSounds": { enableEnvironment [true, [_newSetting] call ULP_fnc_bool]; };
	};
}] call ULP_fnc_addEventHandler;

if ([player, ["Police", "Hato"]] call ULP_fnc_isFaction) then {
	["ClampFinePaid", {
		_this params [
			["_payer", "", [""]],
			["_vehicle", objNull, [objNull]],
			["_fine", 1, [0]]
		];

		private _cut = round (_fine / 2);

		if ([_cut, true, format["Штраф оплачен"]] call ULP_fnc_addMoney) then {
			[
				format [
					"<t color='#B92DE0'>%1</t> оплатил штраф в размере <t color='#B92DE0'>%2</t> за <t color='#B92DE0'>%3%4</t>, и вы получили <t color='#B92DE0'>%3%5</t> в качестве награды...",
					_payer,
					"$", [_fine] call ULP_fnc_numberText, [_cut] call ULP_fnc_numberText
				]
			] call ULP_fnc_hint;
		};
	}] call ULP_fnc_addEventHandler;
};

["Blindfold", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};
	
	if (player getVariable ["blindfold", false]) then {
		cutText ["","BLACK OUT"];
  		[format ["<t color='#B92DE0'>%1</t> наложил на вас повязку на глаза...", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	} else {
		cutText ["","BLACK IN"];
  		[format ["<t color='#B92DE0'>%1</t> снял с вас повязку с глаз...", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["Incapacitated", {
	[] call ULP_fnc_stopPlacement;
}] call ULP_fnc_addEventHandler;

["CommunicationsSeized", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};

	if (_unit isEqualTo player) then {
		["Вы уничтожили свою связь. <t color='#B92DE0'>Вам больше нельзя разговаривать вне каналов прямой связи или транспорта!</t>"] call ULP_fnc_hint;
	} else {
		[format ["<t color='#B92DE0'>%1</t> уничтожил вашу связь. <t color='#B92DE0'>Вам больше нельзя разговаривать вне каналов прямой связи или транспорта!</t>", [_unit] call ULP_fnc_getName]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["EnteredRedzone", {
	["<t align='center'>Вы вошли в <t color='#cc0001'>Зону Боевых Действий</t></t>"] call ULP_UI_fnc_zoneText;
}] call ULP_fnc_addEventHandler;

["LeftRedzone", {
	["<t align='center'>Вы вышли из <t color='#00cc65'>Зоны Боевых Действий</t></t>"] call ULP_UI_fnc_zoneText;
}] call ULP_fnc_addEventHandler;

["EnteredSafezone", {
	["<t align='center'>Вы вошли в <t color='#00cc65'>Зону Безопасности</t></t>"] call ULP_UI_fnc_zoneText;
}] call ULP_fnc_addEventHandler;

["LeftSafezone", {
	["<t align='center'>Вы вышли из <t color='#cc0001'>Зоны Безопасности</t></t>"] call ULP_UI_fnc_zoneText;
}] call ULP_fnc_addEventHandler;
