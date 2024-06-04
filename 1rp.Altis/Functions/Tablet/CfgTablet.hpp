class CfgTablet {
    globalIdcs[] = {
        23001, 23012, 23013
    };

    class BaseScreen {
        idc = -1;
        pageTitle = "";
        pageIdcs[] = {};
        onLoad = "";
        onUnload = "";
        rebindEsc = "";
    };

	class Home : BaseScreen {
        idc = -1;
        pageTitle = "";
        pageIdcs[] = {
            23002, 23003, 23004, 23005, 23006, 23007, 23008, 23009, 23010, 23011
        };
        onLoad = "[(_this getVariable [""group_check"", -1])] call ULP_fnc_removeEachFrame; (_this displayCtrl 23001) ctrlSetStructuredText parseText format[""<t align='left'>%1</t><t align='right'>$%2</t>"", name player, [ULP_547_Bank] call ULP_fnc_numberText]";
    };

	class Profile : BaseScreen {
        idc = 23002;
        pageTitle = "Профиль";
        pageIdcs[] = {
            23024, 23025, 23026, 23027, 23028
        };
        onLoad = "_this call ULP_fnc_profile";
    };

	class Professions : Profile {
        pageTitle = "Профиль - Профессии";
        pageIdcs[] = {
            23024, 23025, 23026, 23027, 23028, 23029, 23030
        };
        onLoad = "_this call ULP_fnc_professions";
    };

	class Achievements : Profile {
        pageTitle = "Профиль - Достижения";
        pageIdcs[] = {
            23024, 23025, 23026, 23027, 23028, 23029, 23030
        };
        onLoad = "_this call ULP_fnc_achievements";
    };

	class Loyalty : Profile {
        pageTitle = "Профиль - Личные цели";
        pageIdcs[] = {
            23024, 23025, 23026, 23027, 23028, 23029, 23030
        };
        onLoad = "_this call ULP_fnc_personalGoals";
    };

	class PlayerTag : Profile {
        pageTitle = "Профиль - Тег игрока";
        pageIdcs[] = {
            23024, 23025, 23026, 23027, 23028, 23029, 23053, 23054, 23055, 23056, 23057, 23058, 23069, 23070, 23071, 23072, 23073, 23074, 23075
        };
        onLoad = "_this call ULP_fnc_nameTags";
        onUnload = "private _colour = _this getVariable [""color_selected"", """"]; if ([] call ULP_fnc_donatorLevel > 0 && { !(_colour isEqualTo """") }) then { profileNamespace setVariable['selected_name_colour', _colour]; }; private _ctrl = _this displayCtrl 23056; profileNamespace setVariable['selected_title', (_ctrl lbData (lbCurSel _ctrl))]; _ctrl = _this displayCtrl 23069; profileNamespace setVariable['selected_icon', (_ctrl tvData (tvCurSel _ctrl))]; saveProfileNamespace; [] call ULP_fnc_setTags;";
    };

	class Inventory : BaseScreen {
        idc= 23003;
        pageTitle = "Инвентарь";
        pageIdcs[] = {
            23014, 23015, 23016, 23017, 23018, 23019
        };
        onLoad = "_this call ULP_fnc_inventory";
    };

	class VirtualInventory : Inventory {
        onLoad = "_this call ULP_fnc_virtualInventory";
    };

	class Licenses : Inventory {
        pageTitle = "Лицензии";
        pageIdcs[] = { 23014, 23016, 23017 };
        onLoad = "_this call ULP_fnc_licenses";
    };

	class Crafting : Inventory {
        pageTitle = "Ремесло";
        pageIdcs[] = { 23014, 23017, 23077, 23078 };
        onLoad = "_this call ULP_fnc_crafting";
    };

	class Messaging : BaseScreen {
        idc= 23004;
        pageTitle = "Сообщения";
        pageIdcs[] = {
            23036, 23037, 23038, 23039, 23040, 23041, 23042, 23043, 23044, 23045, 23046, 23047, 23048, 23049, 23050
        };
        onLoad = "_this call ULP_fnc_messages";
    };

	class Group : BaseScreen {
        idc= 23005;
        pageTitle = "Группа";
        pageIdcs[] = {
            23061
        };
        onLoad = "_this call ULP_fnc_group";
    };
    
	class GroupOverview : Group {
        pageTitle = "Группа - Обзор";
        pageIdcs[] = {
            23061, 23062, 23063, 23064, 23065, 23066, 23067, 23068, 23076, 23079, 23080, 23081, 23089
        };
        onLoad = "_this call ULP_fnc_overview";
        onUnload = "[""GroupMembersChanged"", (_this getVariable [""members_changed"", -1])] call ULP_fnc_removeEventHandler; _this setVariable [""members_changed"", nil]; [""GroupMoneyChanged"", (_this getVariable [""funds_changed"", -1])] call ULP_fnc_removeEventHandler; _this setVariable [""funds_changed"", nil];";
    };

	class GroupProgression : Group {
        pageTitle = "Группа - Прогресс";
        pageIdcs[] = {
            23061, 23082, 23083, 23084, 23085, 23086
        };
        onLoad = "_this call ULP_fnc_progression";
    };

	class GroupSettings : Group {
        pageTitle = "Группа - Настройки";
        pageIdcs[] = {
             23061, 23087, 23088
        };
        onLoad = "_this call ULP_fnc_settings";
    };

	class Keys : BaseScreen {
        idc= 23006;
        pageTitle = "Ключи";
        pageIdcs[] = {
            23021, 23022
        };
        onLoad = "_this call ULP_fnc_keys";
    };

	class Dispute : Home {
        idc= 23007;
        pageTitle = "Спор";
        onLoad = "_this call ULP_fnc_dispute";
    };

	class Market : BaseScreen {
        idc= 23008;
        pageTitle = "Рынок";
        pageIdcs[] = {
            23032, 23033, 23034, 23035
        };
        onLoad = "_this call ULP_fnc_market";
    };

	class Goals : BaseScreen {
        idc= 23009;
        pageTitle = "Цели сообщества";
        pageIdcs[] = { 23090 };
		onLoad = "_this call ULP_fnc_communityGoals";
		onUnload = "[""CommunityGoalsReceived"", _this getVariable [""community_goals_received"", -1]] call ULP_fnc_removeEventHandler;";
    };

	class Perks : BaseScreen {
        idc= 23010;
        pageTitle = "Привилегии";
        pageIdcs[] = {
            23059, 23060
        };
		onLoad = "_this setVariable [""perksEvent"", [""PerksChanged"", { (findDisplay 23000) call ULP_fnc_perks; }] call ULP_fnc_addEventHandler]; _this call ULP_fnc_perks;";
		onUnload = "[""PerksChanged"", _this getVariable [""perksEvent"", -1]] call ULP_fnc_removeEventHandler; [player, 11, ULP_Perks] remoteExecCall [""ULP_SRV_fnc_savePlayerState"", 2];";
    };

	class Settings {
        idc= 23011;
        pageTitle = "Настройки";
        pageIdcs[] = {
            23023
        };
        onLoad = "_this call ULP_fnc_options";
        onUnload = "saveProfileNamespace;";
    };
};
