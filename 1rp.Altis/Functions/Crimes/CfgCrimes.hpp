class CfgCrimes {
	class Altis {
		class HMTreasury {
			title = "ХМ Сокровищница";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Взлом системы безопасности хранилища";
					time = 300;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Система безопасности хранилища в ХМ Сокровищнице подвергается воздействию!""], _targets] call ULP_fnc_sendMessage; [""Вы начали отключение системы безопасности хранилища, полиция уведомлена!""] call ULP_fnc_hint;"; // Уведомление полиции...
					onCompleted = "[""HMTreasury"", 1] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Вы успешно отключили систему безопасности хранилища...""] call ULP_fnc_hint;"; // Заполнение хранилищ, разрешение бурения хранилищ...
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 5) : { ""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""Для выполнения этого действия вам нужно устройство для взлома..."" }; default { ""Система безопасности хранилища уже отключена..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 } && { (count [""Police""] call ULP_fnc_allMembers) >= 5 }";
				};
			};
			class Buildings {
				class MilitaryOfficeOne {
					classname = "Land_MilOffices_V1_F";
					position[] = {16009.7, 16900.3, 0.372055};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""В один из офисов безопасности в ХМ Сокровищнице взломали!""], _targets] call ULP_fnc_sendMessage; [""Вы случайно вызвали сигнализацию при взломе замка, полиция уведомлена!""] call ULP_fnc_hint;";
						onFail = "[""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления...""] call ULP_fnc_hint;";
						condition = "(count [""Police""] call ULP_fnc_allMembers) >= 5 || { missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false] }";
					};
				};
				class MilitaryOfficeTwo : MilitaryOfficeOne { position[] = {16216.4, 17071.3, 0.0516109}; };

				class DomeOne : MilitaryOfficeOne {
					classname = "Land_Dome_Big_F";
					position[] = {16019, 16953.4, 0};
					class BreakIn : BreakIn {
						breakIn = 300;
					};
				};
				class DomeTwo : DomeOne { position[] = {16015.1, 17043.1, 0}; };
				class DomeThree : DomeOne { position[] = {16084, 17082.7, 0}; };
				class DomeFour : DomeOne { position[] = {16152.7, 17044.1, 0}; };
				class DomeFive : DomeOne { position[] = {16152.6, 16961.7, 0}; };
				class DomeSix : DomeOne { position[] = {16084.9, 16915.2, 0}; };

				class VaultOne {
					classname = "Land_Research_house_V1_F";
					position[] = {16015.1, 16958.1, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {-1.71973, 3.15625, 0.0583897}, 0.16 } };
				};
				class VaultThree : VaultOne { position[] = {16092.7, 17092.8, 0}; };
				class VaultFive : VaultOne { position[] = {16146.8, 16951.2, 0}; };

				class VaultTwo : VaultOne {
					classname = "Land_Research_HQ_F";
					position[] = {16023.7, 17031.4, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {6.24316, 5.4707, -3.1177}, 0.16 } };
				};
				class VaultFour : VaultTwo { position[] = {16151.8, 17044.7, 0}; };
				class VaultSix : VaultTwo { position[] = {16076.4, 16917.9, 0}; };
			};
			class Items {
				class MarkedGold {
					amount = 20;
					extra = "((count playableUnits) / 4) + ((time / 2) / 240)";
				};
			};
		};
		class HMSLiberty {
			title = "HMS Либерти";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Отключение системы безопасности сервера";
					time = 480;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Системы на HMS Либерти подвергаются воздействию!""], _targets] call ULP_fnc_sendMessage; [""Вы начали отключение системы безопасности сервера, полиция уведомлена!""] call ULP_fnc_hint;";
					onCompleted = "[""HMSLiberty"", 1, hms_liberty_server] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Вы успешно отключили систему безопасности сервера...""] call ULP_fnc_hint;";
					onEachFrame = "hms_liberty_server animateSource [""server_move_source"", (_this / 100)];";
					onProgressStop = "hms_liberty_server animateSource [""server_move_source"", 0]";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 5) : { ""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""Вам нужно устройство для взлома, чтобы выполнить это действие..."" }; default { ""Система безопасности сервера уже отключена..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class Ship {
					classname = "Land_Destroyer_01_interior_02_F";
					position[] = {14054.8, 11509.4, -2.1181};
					class BreakIn {
						breakIn = 360;
						onBreakIn = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""На мосту HMS Либерти незаконно получен доступ!""], _targets] call ULP_fnc_sendMessage; [""Вы случайно вызвали сигнализацию при взломе замка, полиция уведомлена!""] call ULP_fnc_hint;";
						onFail = "[""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления...""] call ULP_fnc_hint;";
						condition = "true";
					};
				};
			};
			class Items {
				class EncryptedDrive {
					amount = 8;
					extra = "(random 24) max 1";
				};
			};
		};
class PoliceEvidenceStorage {
	title = "Хранилище доказательств полиции";
	factions[] = { "Civilian" };
	cooldown = 1000;
	class Stages {
		class Drill {
			displayName = "Сверление в сейф с доказательствами";
			time = 600;
			onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""В хранилище доказательств полиции незаконно получен доступ!""], _targets] call ULP_fnc_sendMessage; [""Вы начали сверление в сейф с доказательствами, полиция уведомлена!""] call ULP_fnc_hint;";
			onCompleted = "[""PoliceEvidenceStorage"", 1, evidence_storage_vault] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Вы успешно отключили систему безопасности сервера...""] call ULP_fnc_hint;";
			onEachFrame = "";
			onProgressStop = "";
			onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 5) : { ""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""Для выполнения этого действия вам нужен промышленный бур..."" }; default { ""Система безопасности сейфа уже отключена..."" }; })] call ULP_fnc_hint;";
			condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false]) && { [""IndustrialDrill""] call ULP_fnc_hasItem > 0 }";
		};
	};
	class Buildings {
		class MilitaryOffice {
			classname = "Land_MilOffices_V1_F";
			position[] = {3266.77, 12448.9, 0.117};
			class BreakIn {
				breakIn = 240;
				onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Вход в помещение хранилища доказательств полиции был взломан!""], _targets] call ULP_fnc_sendMessage; [""Вы случайно вызвали сигнализацию при взломе замка, полиция уведомлена!""] call ULP_fnc_hint;";
				onFail = "[""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления...""] call ULP_fnc_hint;";
				condition = "(count [""Police""] call ULP_fnc_allMembers) >= 5 || { missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false] }";
			};
		};
	};
	class Items {
		class SeizedContraband {
			amount = 30;
			extra = "((count playableUnits) / 2) + ((time / 2) / 240)";
		};
	};
};

class ResearchFacility {
	title = "Исследовательское хранилище";
	factions[] = { "Civilian" };
	cooldown = 1000;
	class Stages {
		class Drill {
			displayName = "Сверление в хранилище";
			time = 900;
			onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""В подводном исследовательском центре незаконно получен доступ!""], _targets] call ULP_fnc_sendMessage; [""Вы начали сверление в подводном исследовательском центре, полиция уведомлена!""] call ULP_fnc_hint;";
			onCompleted = "[""ResearchFacility"", 1, researchFacilityCapsule] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""Вы успешно отключили систему безопасности сервера...""] call ULP_fnc_hint;";
			onEachFrame = "";
			onProgressStop = "";
			onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 5) : { ""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""Для выполнения этого действия вам нужен промышленный бур..."" }; default { ""Система безопасности сейфа уже отключена..."" }; })] call ULP_fnc_hint;";
			condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false]) && { [""IndustrialDrill""] call ULP_fnc_hasItem > 0 }";
		};
	};
	class Buildings {
		class OuterDome {
			classname = "Land_Dome_Big_F";
			position[] = {24842,13219.9,0};
			class BreakIn {
				breakIn = 240;
				onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Вход в подводный исследовательский центр был взломан!""], _targets] call ULP_fnc_sendMessage; [""Вы случайно вызвали сигнализацию при взломе замка, полиция уведомлена!""] call ULP_fnc_hint;";
				onFail = "[""Должно быть не менее <t color='#B92DE0'>5 полицейских</t> для начала этого преступления...""] call ULP_fnc_hint;";
				condition = "(count [""Police""] call ULP_fnc_allMembers) >= 5 || { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] }";
			};
		};
		class InnerDome {
			classname = "Land_Dome_Small_F";
			position[] = {24844.1,13219.7,0};
		};
		class InnerVault {
			classname = "Land_Research_HQ_F";
			position[] = {24844.1,13219.7,0};
		};
	};
	class Items {
		class SpaceCapsuleDataDrive {
			amount = 1;
			extra = "(random 2) max 1";
		};
	};
};
};
};