/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleEngine";

_this params [
	["_vehicle", objNull, [objNull]],
	["_engineOn", false, [true]]
];

if (local _vehicle && { _engineOn }) then {
	private _clamp = _vehicle getVariable ["clamp_fine", []];

	if !(_clamp isEqualTo []) then {
		_vehicle engineOn false;

		_clamp params [ "_finer", "_steamid", "_fine" ];

		if (CASH < _fine) exitWith {
			if (time >= _vehicle getVariable ["clamp_notify", 0]) then {
				[format ["Ваше транспортное средство было заблокировано <t color='#B92DE0'>%1</t>, и у вас нет денег, чтобы оплатить штраф <t color='#B92DE0'>%2%3</t>...", _finer, "$", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
			_vehicle setVariable ["clamp_notify", time + 3];
		};

		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Штраф за Транспорт", ["Оплатить", "Отмена"],
			format ["%1 заблокировал ваше транспортное средство и наложил на вас штраф в размере %2%3", _finer, "$", [_fine] call ULP_fnc_numberText], [_vehicle, _fine, _steamid],
			{	
				_this params [ "_vehicle", "_fine", "_steamid" ];

				if ([_fine, false, "Штраф за Транспорт"] call ULP_fnc_removeMoney) then {
					_vehicle engineOn true;
					_vehicle setVariable ["clamp_fine", nil, true];

					[format ["Вы оплатили штраф в размере <t color='#B92DE0'>%1%2</t>, и с вас сняли заблокировку с транспортного средства...", "$", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;

					private _unit = [_steamid] call ULP_fnc_playerByUID;
					if (!(isNull _unit) && { [player, ["Police", "Hato"]] call ULP_fnc_isFaction }) then {
						["ClampFinePaid", [profileName, _vehicle, _fine]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
					};
				} else {
					["У вас недостаточно денег, чтобы оплатить штраф..."] call ULP_fnc_hint;
				};
			}, {}, false
		] call ULP_fnc_confirm;
	};
};
