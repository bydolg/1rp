/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_nearWorkbench";

//((count (player nearEntities ["Land_Workbench_01_F", 5])) > 0)
({typeof _x == "Land_Workbench_01_F"} count (player nearObjects 10) > 0)