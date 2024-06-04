/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_movesMenu";

if (!(alive player) || { isDowned(player) } || { !(isNull (objectParent player)) } || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isKnocked } || { dialog }) exitWith {};

if (createDialog "DialogMoves") then {
	private _display = findDisplay 4600;
	if (isNull _display) exitWith {};

	private _list = _display displayCtrl 4601;
	lbClear _list;

	{
		private _move = _list lbAdd getText (_x >> "displayName");
		_list lbSetData [_move, getText (_x >> "animation")];
	} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgMoves"));

	if ((lbSize _list) < 1) then {
		_list lbAdd "У вас нет доступных движений.";
	} else {
		_list lbSetCurSel 0;
	};
};
