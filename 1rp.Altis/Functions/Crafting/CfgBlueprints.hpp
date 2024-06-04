class CfgBlueprints {
	class CraftingMaterials {
		displayName = "Материалы для изготовления";

		class B_Clay {
			icon = "\dataM\Icons\clay.paa";
			displayName = "Глина";
			description = "Простой материал, используемый для изготовления.";
			materials[] = { {"Sand", 2}, {"Water", 1} };
			item = "Clay";
			isDefault = true;
			workbench = false;
			time = 15;
		};
		class B_Steel : B_Clay {
			icon = "\dataM\Icons\ingot.paa";
			displayName = "Стальной пруток";
			description = "Обработанный металлический пруток.";
			materials[] = { {"IronBar", 2}, {"ProcessedOil", 1} };
			item = "SteelBar";
			workbench = true;
		};
		class B_ExplosiveMaterials : B_Steel {
			icon = "\dataM\Icons\explosiveMaterials.paa";
			displayName = "Взрывчатые материалы";
			description = "Набор взрывчатых материалов, часто используемых в рецептах для изготовления.";
			materials[] = { {"IronBar", 64}, {"ProcessedOil", 18}, {"SeizedContraband", 2} };
			item = "ExplosiveMaterials";
			isDefault = false;
			workbench = true;
			time = 90;
		};
	};

	class Tools {
		displayName = "Инструменты";

		class B_Toolbox {
			icon = "\dataM\Icons\toolbox.paa";
			displayName = "Инструментальный ящик";
			description = "Ящик с инструментами для разборки предметов на основные компоненты.";
			materials[] = { {"IronBar", 4} };
			item = "Toolbox";
			isDefault = true;
			workbench = false;
			time = 60;
		};
		class B_Pickaxe : B_Toolbox {
			icon = "\dataM\Icons\pickaxe.paa";
			displayName = "Кирка";
			description = "Простой инструмент для добычи минералов.";
			materials[] = { {"IronBar", 3}, {"Wood", 2} };
			item = "Pickaxe";
			isDefault = false;
		};
		class B_LumberAxe : B_Pickaxe {
			icon = "\dataM\Icons\lumberAxe.paa";
			displayName = "Лесопильный топор";
			item = "LumberAxe";
		};
		class B_Shovel : B_Pickaxe {
			icon = "\dataM\Icons\shovel.paa";
			displayName = "Лопата";
			materials[] = { {"IronBar", 1}, {"Wood", 2} };
			item = "Shovel";
		};
		class B_Extractor : B_Pickaxe {
			icon = "\dataM\Icons\extractor.paa";
			displayName = "Экстрактор";
			materials[] = { {"SteelBar", 4}, {"SilverBar", 2} };
			item = "Extractor";
		};
		class B_SurveyingEquipment : B_Pickaxe {
			icon = "\dataM\Icons\surveyingEquipment.paa";
			displayName = "Изыскательское оборудование";
			description = "Оборудование, используемое для обследования месторождения для поиска артефактов.";
			materials[] = { {"CopperBar", 4}, {"SilverBar", 2}, {"Glass", 1} };
			item = "SurveyingEquipment";
			workbench = true;
			time = 40;
		};
		class B_ArchaeologistsEquipment : B_SurveyingEquipment {
			icon = "\dataM\Icons\archaeologistsEquipment.paa";
			displayName = "Археологическое оборудование";
			description = "Оборудование, используемое для аккуратного раскопа артефактов на раскопках.";
			materials[] = { {"Pickaxe", 1}, {"Shovel", 1}, {"SharpStoneKnife", 1} };
			item = "ArchaeologistsEquipment";
		};
		class B_FuelCan : B_Pickaxe {
			icon = "\dataM\Icons\fuelCan.paa";
			displayName = "Канистра с топливом";
			description = "Может использоваться для заправки вашего транспортного средства в любом месте.";
			materials[] = { {"IronBar", 7}, {"ProcessedOil", 2} };
			item = "fuelCan";
			time = 30;
		};
	class B_Lighter : B_Pickaxe {
		icon = "\dataM\Icons\lighter.paa";
		displayName = "Зажигалка";
		description = "Простая зажигалка, используемая для создания огня.";
		materials[] = { {"Iron", 3}, {"ProcessedOil", 1} };
		item = "Lighter";
		time = 30;
	};
	class B_Lockpick : B_Pickaxe {
		icon = "\dataM\Icons\lockpick.paa";
		displayName = "Отмычка";
		description = "Инструмент, используемый для взлома замков на транспортных средствах и наручниках.";
		materials[] = { {"Iron", 4} };
		item = "Lockpick";
		time = 30;
	};
	class B_BoltCutter : B_Pickaxe {
		icon = "\dataM\Icons\boltCutter.paa";
		displayName = "Болтовой отрезчик";
		description = "Инструмент, используемый для срезания крепких замков, обнаруженных на зданиях, ящиках с припасами и прочих укрепленных дверях.";
		materials[] = { {"SteelBar", 16} };
		item = "BoltCutter";
		workbench = true;
		time = 120;
	};
	class B_HackingDevice : B_BoltCutter {
		icon = "\dataM\Icons\hackingDevice.paa";
		displayName = "Устройство взлома";
		description = "Инструмент, используемый для взлома различных систем и незаконного получения доступа к этим системам.";
		materials[] = { {"Silver", 8}, {"CutDiamond", 4}, {"DecryptedDrive", 1} };
		item = "HackingDevice";
		time = 300;
	};
	class B_ExplosiveCharge : B_BoltCutter {
		icon = "\dataM\Icons\explosiveCharge.paa";
		displayName = "Взрывчатый заряд";
		description = "Инструмент, используемый для уничтожения укрепленных замков.";
		materials[] = { {"ExplosiveMaterials", 8}, {"Coal", 14}, {"CutDiamond", 6}, {"BrokenTimepiece", 1} };
		item = "ExplosiveCharge";
		time = 360;
	};
	class B_IndustrialDrill : B_ExplosiveCharge {
		icon = "\dataM\Icons\industrialDrill.paa";
		displayName = "Промышленная дрель";
		materials[] = { {"SteelBar", 16}, {"CutDiamond", 4}, {"DrillBit", 1} };
		item = "IndustrialDrill";
	};
	};

	class PoliceEquipment {
		displayName = "Полицейское снаряжение";

		class B_PanicButton {
			icon = "\dataM\Icons\panicButton.paa";
			displayName = "Аварийная кнопка";
			description = "При нажатии оповещает полицию о том, что вам срочно нужна помощь.";
			materials[] = { {"CopperBar", 20}, {"SilverBar", 16}, {"Glass", 2} };
			item = "PanicButton";
			isDefault = false;
			workbench = true;
			time = 90;
		};
		class B_MakeshiftStinger : B_PanicButton {
			icon = "\dataM\Icons\stinger.paa";
			displayName = "Самодельный колючий барьер";
			description = "Переносной полосой из колючек, используемой для прокола шин транспортных средств.";
			materials[] = { {"SteelBar", 45}, {"Ziptie", 6} };
			item = "MakeshiftStinger";
			time = 180;
		};
	};

	class MedicalEquipment {
		displayName = "Медицинское снаряжение";

		class B_FieldDressing {
			icon = "\dataM\Icons\fieldDressing.paa";
			displayName = "Повязка";
			description = "Бинт, лучше всего подходит для обработки царапин.";
			materials[] = { {"Bandage", 1} };
			item = "FieldDressing";
			isDefault = true;
			workbench = false;
			time = 15;
		};
		class B_Packing : B_FieldDressing {
			icon = "\dataM\Icons\packingBandage.paa";
			displayName = "Повязка для упаковки";
			description = "Бинт, лучше всего подходит для обработки царапин и разрывов.";
			materials[] = { {"Bandage", 2} };
			item = "Packing";
		};
		class B_Elastic : B_FieldDressing {
			icon = "\dataM\Icons\elasticBandage.paa";
			displayName = "Упругая повязка";
			description = "Бинт, лучше всего подходит для обработки царапин и разрывов.";
			item = "Elastic";
		};
		class B_QuickClot : B_FieldDressing {
			icon = "\dataM\Icons\quikClot.paa";
			displayName = "QuickClot";
			description = "Бинт, лучше всего подходит для обработки царапин и разрывов.";
			materials[] = { {"Bandage", 1}, {"Sand", 1} };
			item = "Elastic";
		};
		class B_FirstAidKit : B_FieldDressing {
			icon = "\dataM\Icons\firstAidKit.paa";
			displayName = "Аптечка первой помощи";
			description = "Комплект, содержащий различные известные места нахождения артефактов.";
			materials[] = { {"Painkillers", 2}, {"Bandage", 4}, {"BloodBag", 1} };
			item = "FirstAidKit";
			workbench = true;
			time = 120;
		};
		class B_MediKit : B_FirstAidKit {
			icon = "\dataM\Icons\mediKit.paa";
			displayName = "Медицинский набор";
			materials[] = { {"Painkillers", 5}, {"Morphine", 2}, {"Epinephrine", 1}, {"Bandage", 10}, {"BloodBag", 3} };
			item = "MediKit";
		};
		class B_AutomatedExternalDefibrillator : B_FirstAidKit {
			icon = "\dataM\Icons\defibrillator.paa";
			displayName = "Автоматический внешний дефибриллятор";
			materials[] = { {"SilverBar", 6}, {"CutDiamond", 2} };
			item = "AutomatedExternalDefibrillator";
			time = 180;
		};
	};
	class Electronics {
		displayName = "Электроника";

		class B_MiningRig {
			icon = "\dataM\Icons\miningRig.paa";
			displayName = "Шахтёрская установка";
			description = "Собранная установка для майнинга криптовалюты в специализированных складах.";
			materials[] = { {"Motherboard", 1}, {"CPU", 1}, {"GPU", 2}, {"RAM", 4}, {"PSU", 1} };
			item = "MiningRig";
			isDefault = false;
			workbench = true;
			time = 300;
		};
		class B_Motherboard : B_MiningRig {
			icon = "\dataM\Icons\motherboard.paa";
			displayName = "Материнская плата";
			description = "Компонент, используемый для создания шахтёрских установок.";
			materials[] = { {"Motherboard", 1} };
			item = "Motherboard";
			time = 180;
		};
		class B_CPU : B_Motherboard {
			icon = "\dataM\Icons\cpu.paa";
			displayName = "Процессор";
			item = "CPU";
		};
		class B_GPU : B_Motherboard {
			icon = "\dataM\Icons\gpu.paa";
			displayName = "Графический процессор";
			item = "GPU";
		};
		class B_RAM : B_Motherboard {
			icon = "\dataM\Icons\ram.paa";
			displayName = "Оперативная память";
			item = "RAM";
		};
		class B_PSU : B_Motherboard {
			icon = "\dataM\Icons\psu.paa";
			displayName = "Блок питания";
			item = "PSU";
		};
	};

	class Archaeology {
		displayName = "Археологические находки";
		
		class B_CommonMap {
			icon = "\dataM\Icons\map.paa";
			displayName = "Обычная карта";
			description = "Карта с известными местами нахождения артефактов.";
			materials[] = { {"CommonMapFragment", 4} };
			item = "CommonMap";
			isDefault = true;
			workbench = false;
			time = 90;
		};
		class B_UncommonMap : B_CommonMap {
			icon = "\dataM\Icons\map.paa";
			displayName = "Необычная карта";
			materials[] = { {"UncommonMapFragment", 4} };
			item = "UncommonMap";
		};
		class B_RareMap : B_CommonMap {
			icon = "\dataM\Icons\map.paa";
			displayName = "Редкая карта";
			materials[] = { {"RareMapFragment", 4} };
			item = "RareMap";
		};
		class B_CoinBundle : B_CommonMap {
			icon = "\dataM\Icons\coinBundle.paa";
			displayName = "Набор монет";
			description = "Пачка старых монет, собранных на раскопках и продаваемых археологам.";
			materials[] = { {"OldCoin", 30} };
			item = "CoinBundle";
		};
		class B_RestoredPot : B_CoinBundle {
			icon = "\dataM\Icons\restoredPot.paa";
			displayName = "Восстановленный горшок";
			description = "Восстановленный артефакт, который можно продать археологам.";
			materials[] = { {"BrokenPot", 1}, {"Clay", 3} };
			item = "RestoredPot";
			time = 300;
		};
		class B_SharpStoneKnife : B_RestoredPot {
			icon = "\dataM\Icons\sharpStoneKnife.paa";
			displayName = "Острый каменный нож";
			materials[] = { {"BluntStoneKnife", 1}, {"Rock", 1} };
			item = "SharpStoneKnife";
		};
		class B_IdentifiedSkull : B_RestoredPot {
			icon = "\dataM\Icons\unidentifiedSkull.paa";
			displayName = "Идентифицированный череп";
			materials[] = { {"UnidentifiedSkull", 1}, {"DecryptedDrive", 1} };
			item = "IdentifiedSkull";
			time = 420;
		};
		class B_DiamondRing : B_RestoredPot {
			icon = "\dataM\Icons\diamondRing.paa";
			displayName = "Бриллиантовое кольцо";
			materials[] = { {"StrongMetalRing", 1}, {"CutDiamond", 1} };
			item = "DiamondRing";
			time = 360;
		};
	};
};
