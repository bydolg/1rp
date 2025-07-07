class CfgChat {
	class Messages {
                class Injured {
                        message = "$STR_CHAT_INJURED";
                        params = 1;
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
                class Bleedout : Injured {
                        message = "$STR_CHAT_BLEEDOUT";
                };
                class Executed {
                        message = "$STR_CHAT_EXECUTED";
			params = 2;
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
                class InjuredBy : Executed {
                        message = "$STR_CHAT_INJURED_BY";
                };
                class Revived : Executed {
                        message = "$STR_CHAT_REVIVED";
                        condition = "[[""EnableMessagesRevived"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
                };
                class Prisoned {
                        message = "$STR_CHAT_PRISONED";
			params = 3;
			condition = "[[""EnableMessagesPrisoned"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
                class Garaged : Prisoned {
                        message = "$STR_CHAT_GARAGED";
                        condition = "[[""EnableMessagesVehicle"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
                };
                class Crushed : Garaged {
                        message = "$STR_CHAT_CRUSHED";
                };
                class Impounded : Garaged {
                        message = "$STR_CHAT_IMPOUNDED";
                        params = 4;
                };
                class IssuedFine : Prisoned {
                        message = "$STR_CHAT_ISSUEDFINE";
			condition = "[[""EnableMessagesTicket"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
                class FinePaid : IssuedFine {
                        message = "$STR_CHAT_FINEPAID";
                        params = 2;
                };
                class FineRefused : FinePaid {
                        message = "$STR_CHAT_FINEREFUSED";
                };
                class FinePoor : FinePaid {
                        message = "$STR_CHAT_FINEPOOR";
                };
	};
	class Commands {
		class Players {
			action = "[""Total Players:"", format [""%1"", count allPlayers]]";
			condition = "true";
		};
		class PID {
			action = "[""ARP ID:"", format [""%1"", [ULP_ID] call ULP_fnc_numberText]]";
			condition = "(missionNamespace getVariable [""ULP_ID"", -1]) > -1";
		};
		class SteamID : Players {
			action = "[""Steam ID:"", format [""%1"", getPlayerUID player]]";
		};
	};
};