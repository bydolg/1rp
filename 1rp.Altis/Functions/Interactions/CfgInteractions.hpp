class CfgInteractions {
	class Money {
		class Pickup {
			title = "Подобрать деньги";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_pickupMoney";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0";
		};
		class Burn : Pickup {
			title = "Сжечь деньги";
			onClick = "deleteVehicle (_this select 0)";
			condition = "(_this getVariable [""ULP_MoneyStack"", 0]) > 0 && { (([""Lighter""] call ULP_fnc_hasItem) > 0) }";
		};
	};

	class Placeable {
		class Remove {
			title = "Убрать объект";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_removeObject; closeDialog 0;";
			condition = "[player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""RemovePlaceable"", false] call ULP_fnc_checkPower } }";
		};
	};

	class Person {
		class GiveKeys {
			title = "Дать ключи";
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "!([player] call ULP_fnc_isRestrained)";
		};
		class GiveCash : GiveKeys {
			title = "Дать деньги";
			onClick = "if ([_this select 0] call ULP_fnc_giveMoney) then { closeDialog 0; };";
		};
		class GiveItems : GiveKeys {
			title = "Дать предметы";
			onClick = "_this call ULP_fnc_giveVirtualItems";
		};
		class ShowLicenses : GiveKeys {
			title = "Показать лицензии";
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (time < (_unit getVariable [""licenses_shown"", 0])) exitWith { [""Вы недавно показали этому человеку свои лицензии, подождите, прежде чем попробовать снова...""] call ULP_fnc_hint; }; _unit setVariable [""licenses_shown"", time + 5]; [""LicensesShown"", [player, ULP_Licenses, true]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; [format [""Вы показали лицензии %1..."", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;";
		};

		class RobCash {
			title = "Ограбить деньги";
			factions[] = { "Medic", "Hato", "Civilian" };
			onClick = "[0, _this] call ULP_fnc_robMoney; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isKnocked || { [_this] call ULP_fnc_isSurrendered } || { [_this] call ULP_fnc_isRestrained && (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) }";
		};

		class Unrestrain : GiveKeys {
			title = "Снять наручники";
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty }";
		};
		class Escort : Unrestrain {
			title = "Сопровождение";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "Прекратить сопровождение";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_isEscorted }";
		};
		class FeedHydrate : Unrestrain { // TODO
			title = "Кормление/Гидратация";
			onClick = "hint ""Привет"";";
		};
		class Blindfold : Unrestrain {
			title = "Завязать глаза";
			onClick = "_this call ULP_fnc_blindfold";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { ([""Blindfold""] call ULP_fnc_hasItem) > 0 } && { !(_this getVariable [""blindfold"", false]) }";
		};
		class Unblindfold : Blindfold {
			title = "Снять повязку";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { _this getVariable [""blindfold"", false] }";
		};
		class CountCash : Unrestrain {
			title = "Посчитать деньги";
			onClick = "[0, _this] call ULP_fnc_checkMoney;";
		};
		class SeizeCash : RobCash {
			title = "Конфисковать деньги";
			factions[] = { "Police" };
		};
		class InventoryCheck : Unrestrain {
			title = "Проверить инвентарь";
			onClick = "player action [""Gear"", cursorObject]; closeDialog 0;";
		};
		class vItemCheck : Unrestrain {
			title = "Проверить виртуальные предметы";
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; [""Попытка открыть инвентарь...""] call ULP_fnc_hint; closeDialog 0; [_unit, true] call ULP_fnc_openInventory;";
		};
		class LicenseCheck : Unrestrain {
			title = "Проверить лицензии";
			factions[] = { "Police" };
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (_unit getVariable [""licenses_requested"", false]) exitWith { [""Вы уже запросили лицензии этого человека...""] call ULP_fnc_hint; }; _unit setVariable [""licenses_requested"", true]; [""RequestLicenses"", [player]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; if !([_unit] call ULP_fnc_isRestrained) then { [format [""Вы запросили лицензии у %1..."", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint; };";
		};
class LicenseRequest : LicenseCheck {
    title = "Запросить лицензии";
    condition = "!([_this] call ULP_fnc_isRestrained)";
};
class SeizeCommunications : Unrestrain {
    title = "Уничтожить связь";
    onClick = "_this call ULP_fnc_seizeComms;";
    condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_hasComms }";
};
class Ticket {
    title = "Выписать штраф";
    factions[] = { "Police" };
    onClick = "_this call ULP_fnc_issueTicket;";
    condition = "true";
};
class Imprision : Unrestrain {
    title = "Отправить в тюрьму";
    onClick = "_this call ULP_fnc_setPrisonTime; closeDialog 0;";
    condition = "[player] call ULP_fnc_canImprison && { [_this] call ULP_fnc_canImprisoned }";
};

// Административные команды...
class AdminHeal {
    title = "Административное исцеление";
    factions[] = { "Police", "Medic", "Hato", "Civilian" };
    onClick = "(_this select 0) setDamage 0; [format[""Вы исцелили этого игрока с использованием административных полномочий...""]] call ULP_fnc_hint; [getPlayerUID player, ""Админ"", [""AdminHeal"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { (damage _this) > 0 } && { [""Medical"", false] call ULP_fnc_checkPower }";
		};
};

class PersonMedical {
    class Revive {
        title = "Открыть мед.сумку";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "_this call ULP_fnc_openMedical";
        condition = "true";
    };

    class AdministerBlood : Revive {
        title = "Ввести кровь";
        onClick = "_this call ULP_fnc_administerBlood";
        condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
    };

    class SeizeCommunications : Revive {
        title = "Захватить связь";
        onClick = "_this call ULP_fnc_seizeComms;";
        condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) || [player] call ULP_fnc_onDuty } && { [_this] call ULP_fnc_hasComms }";
    };

    // Административные команды...
    class AdminRevive : Revive {
        title = "Административное воскрешение";
			onClick = "[player] remoteExecCall [""ULP_fnc_revived"", _this select 0]; (_this select 0) setDamage 0; [format[""You've revived this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRevive"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Medical"", false] call ULP_fnc_checkPower }";
    };
};

class PersonEscortOnly {
    class StopEscort {
        title = "Прекратить сопровождение";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
        condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
    };
    class PutInVehicle : StopEscort {
        title = "Посадить в транспортное средство";
        onClick = "private _vehicle = cursorObject; if (isNull _vehicle || { !((((typeOf _vehicle) call BIS_fnc_objectType) param [1, """"]) in [""Car"", ""Helicopter"", ""Plane"", ""Ship""]) }) exitWith { [""Вы должны доставить их к транспортному средству, чтобы посадить их туда...""] call ULP_fnc_hint; }; if !(((fullCrew _vehicle) findIf { isNull (_x param [0, objNull]) }) isEqualTo -1) exitWith { [""В этом транспортном средстве нет пустых мест..""] call ULP_fnc_hint; }; [_this select 0, player, false] call ULP_fnc_escort; [_vehicle, _this select 0] remoteExecCall [""ULP_fnc_putVehicleUnit"", _this select 0]; closeDialog 0; [format [""Вы посадили %1 в транспортное средство..."", [_this select 0, true] call ULP_fnc_getName]] call ULP_fnc_hint;";
    };
};

class House {
    class BuyHouse {
        title = "Купить дом";
        factions[] = { "Civilian" };
        onClick = "_this call ULP_fnc_buyHouse;";
        condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) }";
    };
};

class HouseOwner {
    class SellHouse {
        title = "Продать дом";
        factions[] = { "Civilian" };
        onClick = "_this call ULP_fnc_sellHouse;";
        condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
    };
};

class HouseStorage {
    class OpenStorage {
        title = "Открыть хранилище";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "if ((missionNamespace getVariable [""ULP_HouseStorageEvent"", -1]) > -1) exitWith { [""Запрос уже активен...""] call ULP_fnc_hint; }; ULP_HouseStorageEvent = [""HouseStorage"", { _this params [ ""_house"", ""_storage"" ]; ULP_HouseStorageEvent = nil; if (isNull _house || { (player distance _house) > 15 }) exitWith { [""Вы слишком далеко от дома, чтобы получить доступ к физическому хранилищу...""] call ULP_fnc_hint; }; if (isNull _storage) exitWith { [""У этого дома нет физического хранилища...""] call ULP_fnc_hint; }; player action [""gear"", _storage]; }, true] call ULP_fnc_addEventHandler; [(_this select 0) getVariable [""building"", objNull]] remoteExecCall [""ULP_SRV_fnc_getStorage"", 2]; [""Запрос физического хранилища...""] call ULP_fnc_hint; closeDialog 0;";
        condition = "[_this getVariable [""building"", objNull], player, false] call ULP_fnc_isHouseOwner";
    };
};
class EquipmentBox {
    class ClearBox {
        title = "Очистить ящик";
        factions[] = { "Police" };
        onClick = "_this call ULP_fnc_clearCargo;";
        condition = "true";
    };

    class ResetLoadout {
        title = "Сбросить снаряжение";
        factions[] = { "Police", "Medic", "Hato" };
        onClick = "[] call ULP_fnc_setLoadout;";
        condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
    };
    class RestoreLoadout {
        title = "Вернуть сохраненное снаряжение";
        factions[] = { "Police", "Medic", "Hato" };
        onClick = "[ULP_Gear_Safe] call ULP_fnc_LoadGear;";
        condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
    };
};

class Vault {
    class Repair {
        title = "Починить сейф";
        factions[] = { "Police" };
        onClick = "[""Восстановление сейфа"", 60, _this, { (player distance (_this select 0)) <= 5 }, { private _object = _this select 0; [""Вы успешно восстановили замок!""] call ULP_fnc_hint; _object setVariable [""drilled"", false, true]; }, {}, [""GRAB"", ""CROUCH""]] call ULP_UI_fnc_startProgress;";
        condition = "_this getVariable [""drilled"", true]";
    };
};

class Vehicle {
    class Repair {
        title = "Починить";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "_this call ULP_fnc_repairVehicle";
        condition = """ToolKit"" in (items player)";
    };

    class PatchTyres : Repair {
        title = "Починить шины";
        condition = "!(""ToolKit"" in (items player)) && { _this call ULP_fnc_hasTyreDamage }";
    };

    class Refuel : Repair {
        title = "Заправиться топливом";
        onClick = "_this call ULP_fnc_fuelCan";
        condition = "[""FuelCan""] call ULP_fnc_hasItem > 0";
    };

    class Lockpick : Repair {
        title = "Отмычка";
        onClick = "_this call ULP_fnc_lockpickVehicle";
        condition = "!(_this in ULP_Keys) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
    };

    class Registration : Repair {
        title = "Регистрация";
        onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
        factions[] = { "Police", "Hato" };
    };

    class Clamp : Repair {
        title = "Захват";
        onClick = "_this call ULP_fnc_clampVehicle";
        factions[] = { "Police", "Hato" };
        condition = "(_this getVariable [""clamp_fine"", []]) isEqualTo [] && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
    };

    class RemoveClamp : Clamp {
        title = "Удалить захват";
        onClick = "_this call ULP_fnc_removeVehicleClamp";
        condition = "!((_this getVariable [""clamp_fine"", []]) isEqualTo []) && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
    };

    class Garage : Repair {
        title = "Гараж";
        onClick = "_this call ULP_fnc_garageVehicle";
        factions[] = { "Police", "Hato" };
        condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
    };

    class Impound : Garage {
        title = "Арестовать";
        onClick = "_this call ULP_fnc_impoundVehicle";
        condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 2] call ULP_fnc_hasAccess }";
    };

    class Scrap : Repair {
        title = "Уничтожить";
        onClick = "_this call ULP_fnc_crushVehicle";
        factions[] = { "Police" };
        condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess && { [""bluezone_""] call ULP_fnc_isUnitsInZone }";
    };

    class PulloutOccupants : Repair {
        title = "Извлечь пассажиров";
        onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
        condition = "(speed _this) <= 4 && { _this in ULP_Keys || [""Police_Main"", 1] call ULP_fnc_hasAccess }";
    };

    class Unflip : Repair {
        title = "Перевернуть";
        onClick = "[_this select 0, 0] call ULP_fnc_flipVehicle";
    };

		/*
                class Push : Repair { // TODONOW (for boats)
			title = "Push";
			onClick = "hint ""Hello"";";
		};
		*/

		// Admin Commands...
    class AdminRepair {
        title = "Административное восстановление";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
			onClick = "(_this select 0) setDamage 0; [format[""You've repaired this vehicle using admin powers.""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRepair"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
    };

    class AdminRefuel {
        title = "Административная заправка";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "if ((count (units (_this select 0))) > 0) exitWith { [""Никто не может находиться в транспортном средстве во время его заправки!""] call ULP_fnc_hint; }; [(_this select 0), 1] remoteExecCall [""ULP_fnc_setFuel"", (_this select 0)]; hint format[""Вы заправили это транспортное средство с использованием административных полномочий...""]; [getPlayerUID player, ""Admin"", [""AdminFuel"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
        condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Транспорт"", false] call ULP_fnc_checkPower }";
    };

    class AdminGarage {
        title = "Административный гараж";
        factions[] = { "Police", "Medic", "Hato", "Civilian" };
        onClick = "_this call ULP_fnc_garageVehicle; [getPlayerUID player, ""Admin"", [""AdminGarage"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
        condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
    };
};
};