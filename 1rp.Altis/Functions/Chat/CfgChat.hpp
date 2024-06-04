class CfgChat {
	class Messages {
		class Injured {
			message = "%1 был серьезно ранен";
			params = 1;
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Bleedout : Injured {
			message = "%1 истекает кровью...";
		};
		class Executed {
			message = "%1 был казнен %2";
			params = 2;
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class InjuredBy : Executed {
			message = "%1 был серьезно ранен %2";
		};
		class Revived : Executed {
			message = "%1 был возрожден %2";
			condition = "[[""EnableMessagesRevived"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Prisoned {
			message = "%1 был заключен в тюрьму %2 на %3 минуты";
			params = 3;
			condition = "[[""EnableMessagesPrisoned"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Garaged : Prisoned {
			message = "%2 %1 был поставлен в гараж %3";
			condition = "[[""EnableMessagesVehicle"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Crushed : Garaged {
			message = "%2 владельца %1 был уничтожен %3";
		};
		class Impounded : Garaged {
			message = "%2 владельца %1 был конфискован %3 для %4";
			params = 4;
		};
		class IssuedFine : Prisoned {
			message = "%1 выписал %2 штраф в размере %3";
			condition = "[[""EnableMessagesTicket"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class FinePaid : IssuedFine {
			message = "%1 заплатил штраф в размере %2";
			params = 2;
		};
		class FineRefused : FinePaid {
			message = "%1 отказался от штрафа в размере %2";
		};
		class FinePoor : FinePaid {
			message = "%1 не может позволить себе штраф в размере %2";
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