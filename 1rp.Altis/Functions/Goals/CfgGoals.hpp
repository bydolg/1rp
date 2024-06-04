class CfgGoals {
	class Personal {
		class Daily {
			Amount = 3;

			class ArrestPeople {
        item = ""; // Для таких целей мы не предоставляем предмет, но поле все равно требуется
        icon = "\dataM\UI\Goals\arrests.paa"; // Необязательное переопределение
        title = "Арест Преступников";
        description = "Арестуйте некоторых преступников до конца сегодняшнего дня!";
				tiers[] = { 5, 10, 20 };
				factions[] = { "Police" };
				class Event {
					eventType = "ArrestedSomeone";
					getQuantity = "1";
				};
				condition = "true";
			};

			class GatherApple {
				item = "FreshApple";
        title = "Сбор Яблок";
        description = "Соберите свежие яблоки до конца сегодняшнего дня!";
				tiers[] = { 250, 500, 1000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "GatheredVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class GatherPeach : GatherApple {
				item = "FreshPeach";
        title = "Сбор Персиков";
        description = "Соберите свежие персики до конца сегодняшнего дня!";
			};

			class GatherCoral : GatherApple {
				item = "Coral";
        title = "Сбор Кораллов";
        description = "Соберите кораллы до конца сегодняшнего дня!";
				tiers[] = { 100, 300, 500 };
			};

			class GatherCorn : GatherApple {
				item = "Corn";
        title = "Сбор Кукурузы";
        description = "Соберите кукурузу до конца сегодняшнего дня!";
			};

			class MineCoal : GatherApple {
				item = "Coal";
        title = "Добыча Угля";
        description = "Добудьте уголь до конца сегодняшнего дня!";
				tiers[] = { 100, 300, 750 };
			};

			class MineCopper : MineCoal {
				item = "CopperOre";
        title = "Добыча Меди";
        description = "Добудьте медь до конца сегодняшнего дня!";
			};

			class MineSilver : MineCoal {
				item = "SilverOre";
        title = "Добыча Серебра";
        description = "Добудьте серебро до конца сегодняшнего дня!";
			};

			class MineIron : MineCoal {
				item = "IronOre";
        title = "Добыча Железа";
        description = "Добудьте железо до конца сегодняшнего дня!";
			};

			class ProcessTobacco {
				item = "Tobacco";
        title = "Переработка Табака";
        description = "Переработайте табак до конца сегодняшнего дня!";
				tiers[] = { 100, 250, 500 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "ProcessedVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class ProcessOil : ProcessTobacco {
				item = "UnprocessedOil";
        title = "Переработка Нефти";
        description = "Переработайте нефть до конца сегодняшнего дня!";
			};
			
			class ProcessSand : ProcessTobacco {
				item = "Sand";
        title = "Переработка Песка";
        description = "Переработайте песок до конца сегодняшнего дня!";
			};

			class ProcessSalt : ProcessTobacco {
				item = "UnrefinedSalt";
        title = "Переработка Соли";
        description = "Переработайте соль до конца сегодняшнего дня!";
			};

			class UncutDiamond : ProcessTobacco {
				item = "UncutDiamond";
        title = "Переработка Алмазов";
        description = "Переработайте алмазы до конца сегодняшнего дня!";
			};

			class ProcessUranium : ProcessTobacco {
				item = "UraniumOre";
        title = "Переработка Урана";
        description = "Переработайте уран до конца сегодняшнего дня!";
				tiers[] = { 100, 200, 300 };
			};
		};

		class Weekly {
			Amount = 2;

			class SellSchnapps {
				item = "Schnapps";
        title = "Продать Шнапс";
        description = "Продайте Шнапс до конца недели!";
				tiers[] = { 1000, 2000, 3000 };
				factions[] = { "Civilian" };
				class Event {
					eventType = "SoldVirtualItem";
					getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
				};
				condition = "true";
			};

			class SellCigarette : SellSchnapps {
				item = "Cigarette";
    title = "Продать Сигареты";
        description = "Продайте Сигареты до конца недели!";
			};

			class SellCigar : SellSchnapps {
				item = "Cigar";
    title = "Продать Сигары";
        description = "Продайте Сигары до конца недели!";
			};

			class SellCopper : SellSchnapps {
				item = "CopperBar";
    title = "Продать Медь";
        description = "Продайте Медь до конца недели!";
			};

			class SellSilver : SellSchnapps {
				item = "SilverBar";
    title = "Продать Серебро";
        description = "Продайте Серебро до конца недели!";
			};

			class SellIron : SellSchnapps {
				item = "IronBar";
    title = "Продать Железо";
        description = "Продайте Железо до конца недели!";
			};

			class SellSand : SellSchnapps {
				item = "Glass";
    title = "Продать Стекло";
        description = "Продайте Стекло до конца недели!";
			};

			class SellSalt : SellSchnapps {
				item = "RefinedSalt";
    title = "Продать Соль";
        description = "Продайте Соль до конца недели!";
			};

			class SellDiamond : SellSchnapps {
				item = "CutDiamond";
    title = "Продать Алмаз";
        description = "Продайте Алмаз до конца недели!";
			};

			class SellMoonshine : SellSchnapps {
				item = "Moonshine";
    title = "Продать Самогон";
        description = "Продайте Самогон до конца недели!";
			};
		};
	};

	class Community {
		amountPerFaction[] =  { { "Police", 1 }, { "Medic", 1 }, { "Hato", 1 }, { "Civilian", 2 } };

		class ArrestPeople {
			item = ""; // For goals like these we don't provide an item, the field is still required
			icon = "\dataM\UI\Goals\arrests.paa"; // Optional override
        title = "Арест Преступников";
			basePayout = 50000;
			maxPayout = 500000;
			tiers[] = { 200, 360, 500 };
			duration = 7; 
			factions[] = { "Police" };
			class Event {
				eventType = "ArrestedSomeone";
				getQuantity = "1";
			};
		};
		
		class GatherApple {
			item = "FreshApple";
        title = "Собрать Яблоки";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "GatheredVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellSchnapps {
			item = "Schnapps";
        title = "Продать Шнапс";
			basePayout = 1000000;
			maxPayout = 16000000;
			tiers[] = { 2000, 3600, 4880, 5904, 6723, 7378, 7902, 8321, 8656, 9000 };
			duration = 14; // In days
			factions[] = { "Civilian" };
			class Event {
				eventType = "SoldVirtualItem";
				getQuantity = "_this params [ ""_cfgItem"", ""_eventParams"" ]; _eventParams params [ ""_eventItem"", ""_eventAmount"" ];  if !(_eventItem isEqualTo _cfgItem) exitWith { 0 }; _eventAmount";
			};
		};

		class SellCigarette : SellSchnapps {
			item = "Cigarette";
    title = "Продать Сигареты";
		};

		class SellCigar : SellSchnapps {
			item = "Cigar";
    title = "Продать Сигары";
		};

		class SellCopper : SellSchnapps {
			item = "CopperBar";
    title = "Продать Медь";
		};

		class SellSilver : SellSchnapps {
			item = "SilverBar";
    title = "Продать Серебро";
		};

		class SellIron : SellSchnapps {
			item = "IronBar";
    title = "Продать Железо";
		};

		class SellSand : SellSchnapps {
			item = "Glass";
    title = "Продать Стекло";
		};

		class SellSalt : SellSchnapps {
			item = "RefinedSalt";
    title = "Продать Соль";
		};

		class SellDiamond : SellSchnapps {
			item = "CutDiamond";
    title = "Продать Алмаз";
		};

		class SellMoonshine : SellSchnapps {
			item = "Moonshine";
    title = "Продать Самогон";
		};
	};
};