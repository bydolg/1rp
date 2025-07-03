/*
** Author: 
** Description: Starts the initialization of the player.
*/
#include "script_macros.hpp"

CONST(BIS_fnc_endMission,BIS_fnc_endMission);

enableRadio false;
enableSentences false;
enableEnvironment false;
showHud false;
showChat false;

player createDiaryRecord ["Diary", ["Управление","

<font color='#7FFF00' size='16'>Y</font>: открыть планшет игрока.<br/> 
<font color='#7FFF00' size='16'>Левый WIN</font>: основная клавиша взаимодействия. Используется для взаимодействия с такими объектами, как транспортные средства, дома, банкоматы и обездвиженные игроки. Можно перенастроить на одну клавишу, например H, нажав ESC->Настроить->Элементы управления->Пользовательский->Использовать действие 10.<br/> 
<font color='#7FFF00' size='16'>Shift + V</font>: перешагнуть препятствие<br/> 

<font color='#7FFF00' size='16'>U</font>: блокировать и разблокировать автомобили и дома.<br/> 
<font color='#7FFF00' size='16'>T</font>: Багажник автомобиля и виртуальное хранилище предметов в доме.<br/> 

<font color='#7FFF00' size='16'>Левый Shift + B</font>: сдаться (руки за голову).<br/> 
<font color='#7FFF00' size='16'>Левый Shift + H</font>: убирает оружие в руки.<br/> 
<font color='#7FFF00' size='16'>Левый Ctrl + H</font>: отменить действие кобуры.<br/> 
<font color='#7FFF00' size='16'>Левый Ctrl + R</font>: перепаковать магазины [Left Ctrl]+[Reload].<br/> 


<font color='#7FFF00' size='16'>Левый Shift + G</font>: Нокаутировать/оглушить (Требуется оружие в руках. Используется для грабежа).<br/> 

<font color='#7FFF00' size='16'>F</font>: Сирена.<br/> 
<font color='#7FFF00' size='16'>L</font>: Радар скорости (только полиция и оружие с глушителем P07).<br/> 
<font color='#7FFF00' size='16'>Левый Shift + L</font>: Активирует свет сирены.<br/> 
<font color='#7FFF00' size='16'>Левый Shift + R</font>: Связать (только полиция).<br/>
/*<font color='#7FFF00' size='16'>Shift + пробел</font>: прыжок.<br/>*/ 

<font color='#7FFF00' size='16'>Левый Shift + O</font>: беруши (затычки для ушей)."]];

[] spawn ULP_fnc_initialisation;
[] spawn ZOR_fnc_handleRadiation;
[] spawn ZOR_fnc_handleGasmasks;

0 spawn {   
  private _safezoneMarkers = allMapMarkers select {_x find "greenzone_" > -1};       
  {                                           
    _safeMark = _x;  
    private _isRec = false; if (markerShape _x == "RECTANGLE") then {_isRec = true};  
    private _markSize = markerSize _x #0;        
    if (markerSize _x #0 < markerSize _x #1) then { _markSize = markerSize _x #1 };  
 
    private _allObj = nearestTerrainObjects  [getMarkerPos _x, [], _markSize, false]; 
    private _safeObj = _allObj inAreaArray [getMarkerPos _x, (markerSize _x #0), (markerSize _x #1), markerDir _x, _isRec, -1];       
    {_x allowdamage false} forEach _safeObj; 
 
    private _allObj = -1 allObjects 0; 
    private _safeObj = _allObj inAreaArray [getMarkerPos _x, (markerSize _x #0), (markerSize _x #1), markerDir _x, _isRec, -1];       
    {_x allowdamage false} forEach _safeObj; 
       
   
  } forEach _safezoneMarkers;   
};

