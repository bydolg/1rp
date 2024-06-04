class CfgMissions {
	class Delivery {
		name = "Миссия Доставки";
		description = "Вам нужно доставить указанный груз до %1";
		factions[] = { "Civilian" };
		condition = "true";
		eachFrame = "";
		onClaimed = "";
		onFinished = "";
		class Locations {
			class DP1 {
				pos = "DP_1";
				name = "Пункт доставки 1";
			};
			class DP2 {
				pos = "DP_2";
				name = "Пункт доставки 2";
			};
			class DP3 {
				pos = "DP_3";
				name = "Пункт доставки 3";
			};
			class DP4 {
				pos = "DP_4";
				name = "Пункт доставки 4";
			};
			class DP5 {
				pos = "DP_5";
				name = "Пункт доставки 5";
			};
			class DP6 {
				pos = "DP_6";
				name = "Пункт доставки 6";
			};
			class DP7 {
				pos = "DP_7";
				name = "Пункт доставки 7";
			};
			class DP8 {
				pos = "DP_8";
				name = "Пункт доставки 8";
			};
			class DP9 {
				pos = "DP_9";
				name = "Пункт доставки 9";
			};
			class DP10 {
				pos = "DP_10";
				name = "Пункт доставки 10";
			};
			class DP11 {
				pos = "DP_11";
				name = "Пункт доставки 11";
			};
			class DP12 {
				pos = "DP_12";
				name = "Пункт доставки 12";
			};
			class DP13 {
				pos = "DP_13";
				name = "Пункт доставки 13";
			};
			class DP14 {
				pos = "DP_14";
				name = "Пункт доставки 14";
			};
			class DP15 {
				pos = "DP_15";
				name = "Пункт доставки 15";
			};
			class DP16 {
				pos = "DP_16";
				name = "Пункт доставки 16";
			};
			class DP17 {
				pos = "DP_17";
				name = "Пункт доставки 17";
			};
			class DP18 {
				pos = "DP_18";
				name = "Пункт доставки 18";
			};
		};
		class Rewards {
			moneyReward = 3;
			xpReward = 150;
		};
		class Messages {
			onFinishWithoutMission = "У вас нет груза для доставки сюда...";
			onAlreadyHas = "У вас уже есть активная миссия доставки, выполните ее, прежде чем запросить другую...";
			onNoLocations = "В данный момент нет доступных миссий доставки для выполнения, попробуйте позже...";
			onAssigned = "Вам поручено доставить этот груз до %1";
			onFinished = "Вы успешно доставили груз, вам выплачено $%1";
		};
	};

	class Patrol {
		name = "Миссия Патрулирования";
		description = "Вам нужно патрулировать %1";
		factions[] = { "Police", "Medic", "Hato" };
		condition = "true";
		eachFrame = "";
		onClaimed = "[ { (player distance _this) <= 10 }, _this, { [""Patrol""] call ULP_fnc_finishMission; } ] call ULP_fnc_waitUntilExecute;";
		onFinished = "";
		class Locations {
			// Города, городки и ключевые места
			class KavalaSquare {
				pos = "civ_spawn_kavala";
				name = "Площадь Кавала";
			};
			class CentralAthira {
				pos = "car_dealership_athira_01";
				name = "Центр Афиры";
			};
			class CityOfPyrgos {
				pos = "civ_spawn_pyrgos";
				name = "Город Пиргос";
			};
			class TownOfSofia {
				pos = "civ_spawn_sofia";
				name = "Город София";
			};
			class AgiosCenter {
				pos = "civ_spawn_agios";
				name = "Центр Агиоса";
			};
			class AltisInternational {
				pos = "altis_international";
				name = "Международный аэропорт Алтиса";
			};
			class AbandonedCheckpoint {
				pos = "abandoned_checkpoint";
				name = "Заброшенный блокпост";
			};
			class HuntingCamp {
				pos = "hunting_camp";
				name = "Охотничий лагерь";
			};
			class JewelleryStore {
				pos = "jewellery_store";
				name = "Магазин ювелирных изделий";
			};
			class AltisArcheologists {
				pos = "altis_archeologists";
				name = "Археологи Алтиса";
			};
			class Supermarket {
				pos = "supermarket";
				name = "Супермаркет";
			};
			class ImpoundFacility {
				pos = "impound_facility";
				name = "Автосклад";
			};
			class KavalaStreet {
				pos = "10_kavala_street";
				name = "Улица Кавала, 10";
			};

			// Места минорных преступлений
			class WesternRegionalBank {
				pos = "regional_bank_01";
				name = "Западный региональный банк";
			};
			class EasternRegionalBank {
				pos = "regional_bank_02";
				name = "Восточный региональный банк";
			};

			// Места мажорных преступлений
			class HMTreasury {
				pos = "hm_treasury";
				name = "Сокровищница Государственного управления Алтиса";
			};
			class HMPrisonAltis {
				pos = "hm_prison_altis";
				name = "Тюрьма Государственного управления Алтиса";
			};
			class PoliceEvidenceStorage {
				pos = "police_evidence_storage";
				name = "Хранилище доказательств полиции";
			};

			// Места сбора, обработки и торговли
			class AltisMetalExports {
				pos = "altis_metal_exports";
				name = "Экспорт металла Алтиса";
			};
		};
		class Rewards {
			moneyReward = 1;
			xpReward = 100;
		};
		class Messages {
			onFinishWithoutMission = "Вы не можете завершить патруль, так как вам не назначена миссия...";
			onAlreadyHas = "Вам уже назначен патруль, выполните его, прежде чем запросить другой...";
			onNoLocations = "Нет доступных патрулей, попробуйте позже...";
			onAssigned = "Вам поручено патрулировать %1";
			onFinished = "Вы успешно выполнили задание по патрулированию, вам выплачен бонус в размере $%1";
		};
	};
class ArchaeologyCommon {
	name = "Общие археологические площадки";
	description = "Вам нужно использовать археологическое оборудование на отмеченном месте...";
	factions[] = { "Civilian" };
	condition = "true";
	eachFrame = "";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Common""; ULP_SurveyTotal = 0; [""CommonMap"", 1, true] call ULP_fnc_handleItem;";
	onFinished = "";
	class Locations {
		class dig_site_01 {
			pos = "dig_site_01";
			name = "Зарос";
		};
		class dig_site_02 {
			pos = "dig_site_02";
			name = "Зарос";
		};
		class dig_site_03 {
			pos = "dig_site_03";
			name = "Зарос";
		};
		class dig_site_04 {
			pos = "dig_site_04";
			name = "Зарос";
		};
		class dig_site_05 {
			pos = "dig_site_05";
			name = "Зарос";
		};
		class dig_site_06 {
			pos = "dig_site_06";
			name = "Зарос";
		};
		class dig_site_07 {
			pos = "dig_site_07";
			name = "Зарос";
		};
		class dig_site_08 {
			pos = "dig_site_08";
			name = "Зарос";
		};
		class dig_site_09 {
			pos = "dig_site_09";
			name = "Зарос";
		};
		class dig_site_10 {
			pos = "dig_site_10";
			name = "Аликампос";
		};
		class dig_site_11 {
			pos = "dig_site_11";
			name = "Коре";
		};
		class dig_site_12 {
			pos = "dig_site_12";
			name = "Сирта";
		};
		class dig_site_13 {
			pos = "dig_site_13";
			name = "Абдера";
		};
		class dig_site_14 {
			pos = "dig_site_14";
			name = "Галати";
		};
		class dig_site_15 {
			pos = "dig_site_15";
			name = "Галати";
		};
		class dig_site_16 {
			pos = "dig_site_16";
			name = "Галати";
		};
		class dig_site_17 {
			pos = "dig_site_17";
			name = "Телос";
		};
		class dig_site_18 {
			pos = "dig_site_18";
			name = "Антракия";
		};
		class dig_site_19 {
			pos = "dig_site_19";
			name = "Чаркия";
		};
		class dig_site_20 {
			pos = "dig_site_20";
			name = "Дорида";
		};
		class dig_site_21 {
			pos = "dig_site_21";
			name = "Дорида";
		};
		class dig_site_22 {
			pos = "dig_site_22";
			name = "Дорида";
		};
		class dig_site_23 {
			pos = "dig_site_23";
			name = "Дорида";
		};
		class dig_site_24 {
			pos = "dig_site_24";
			name = "Чалкея";
		};
		class dig_site_25 {
			pos = "dig_site_25";
			name = "Чалкея";
		};
		class dig_site_26 {
			pos = "dig_site_26";
			name = "Пиргос";
		};
		class dig_site_27 {
			pos = "dig_site_27";
			name = "Чалкея";
		};
		class dig_site_28 {
			pos = "dig_site_28";
			name = "Ореокастра";
		};
		class dig_site_29 {
			pos = "dig_site_29";
			name = "Ореокастра";
		};
		class dig_site_30 {
			pos = "dig_site_30";
			name = "Териса";
		};
	};
	class Rewards {
		moneyReward = 0;
		xpReward = 0;
	};
	class Messages {
		onFinishWithoutMission = "Вы не можете исследовать это место, так как вам не назначена миссия...";
		onAlreadyHas = "Вы должны исследовать назначенное вам место перед получением другого...";
		onNoLocations = "Нет доступных мест для исследования, попробуйте позже...";
		onAssigned = "Археологическое место отмечено на вашей карте рядом с %1";
		onFinished = "";
	};
};

class ArchaeologyUncommon : ArchaeologyCommon {
	name = "Необычные археологические площадки";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Uncommon""; ULP_SurveyTotal = 0; [""UncommonMap"", 1, true] call ULP_fnc_handleItem;";
	class Rewards : Rewards {};
	class Messages : Messages {};
};

class ArchaeologyRare : ArchaeologyCommon {
	name = "Редкие археологические площадки";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Rare""; ULP_SurveyTotal = 0; [""RareMap"", 1, true] call ULP_fnc_handleItem;";
	class Rewards : Rewards {};
	class Messages : Messages {};
};

class CorporateFreight {
	name = "Корпоративные грузы";
	description = "Вам нужно доставить данный корпоративный груз к %1";
	factions[] = { "Civilian" };
		condition = "[""Freight""] call ULP_fnc_hasGroupPerk";
	eachFrame = "";
	onClaimed = "";
	onFinished = "_this call ULP_fnc_finishFreight";
	class Locations {
		class Kavala_Freight {
			pos = "Kavala_Freight";
			name = "Логистический центр Кавала";
		};
		class Sofia_Freight {
			pos = "Sofia_Freight";
			name = "Логистический центр София";
		};
	};
	class Rewards {
		moneyReward = 10;
		xpReward = 250;
	};
	class Messages {
		onFinishWithoutMission = "У вас нет пакетов для доставки сюда...";
		onAlreadyHas = "У вас уже есть активная миссия по доставке корпоративных грузов, выполните ее, прежде чем просить другую...";
		onNoLocations = "В настоящее время нет доступных миссий по доставке корпоративных грузов, попробуйте позже...";
		onAssigned = "Ваш грузовик загружен грузом, доставьте его к %1";
		onFinished = "Вы успешно доставили груз, вам заплатили $%1";
	};
};
};