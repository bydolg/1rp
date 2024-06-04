class CfgVirtualItems {
	// Свежие продукты
	class FreshApple {
		displayName = "Свежие яблоки";
		description = "Свежие фрукты, собранные с местных деревьев и продаваемые на рынках.";
		icon = "\dataM\Icons\freshApples.paa";
		buyPrice = -1;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class FreshPeach : FreshApple {
		displayName = "Свежие персики";
		icon = "\dataM\Icons\freshPeaches.paa";
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	
	// Обычная еда
	class Apple {
		displayName = "Купленное яблоко";
		description = "Обычный фрукт, купленный на обычном рынке.";
		icon = "\dataM\Icons\apple.paa";
		buyPrice = 90;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Peach : Apple {
		displayName = "Купленный персик";
		icon = "\dataM\Icons\peach.paa";
		buyPrice = 102;
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Bacon : Apple {
		displayName = "Бекон";
		description = "Обычная еда, купленная в разных местах на Алтисе.";
		icon = "\dataM\Icons\bacon.paa";
		buyPrice = 130;
		sellPrice = 65;
		class Settings : Settings {};
		class Sustain {
			hunger = 50;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Burger : Bacon {
		displayName = "Бургер";
		icon = "\dataM\Icons\burger.paa";
		buyPrice = 165;
		sellPrice = 83;
		class Settings : Settings {};
		class Sustain {
			hunger = 70;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Hotdog : Bacon {
		displayName = "Хот-дог";
		icon = "\dataM\Icons\hotdog.paa";
		buyPrice = 140;
		sellPrice = 70;
		class Settings : Settings {};
		class Sustain {
			hunger = 60;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Chips : Bacon {
		displayName = "Чипсы";
		icon = "\dataM\Icons\chips.paa";
		buyPrice = 105;
		sellPrice = 53;
		class Settings : Settings {};
		class Sustain {
			hunger = 45;
			thirst = 0;
		};
		class Events : Events {};
	};
class RationPack : Bacon {
	displayName = "Пайковый набор";
	icon = "\dataM\Icons\rationPack.paa";
	buyPrice = 325;
	sellPrice = 162;
	class Settings : Settings {};
	class Sustain {
		hunger = 80;
		thirst = 0;
	};
	class Events : Events {};
};
class Doughnut : Bacon {
	displayName = "Пончик";
	icon = "\dataM\Icons\doughnut.paa";
	buyPrice = 20;
	sellPrice = 10;
	class Settings : Settings {};
	class Sustain {
		hunger = 20;
		thirst = 0;
	};
	class Events : Events {};
};
class Sweetie : Bacon {
	displayName = "Леденец";
	icon = "\dataM\Icons\sweetie.paa";
	buyPrice = 8;
	sellPrice = 4;
	class Settings : Settings {};
	class Sustain {
		hunger = 5;
		thirst = 0;
	};
	class Events : Events {};
};

// Обычные напитки
class Water {
	displayName = "Вода";
	description = "Обычный напиток, помогает поддерживать уровень гидратации.";
	icon = "\dataM\Icons\bottle.paa";
	buyPrice = 10;
	sellPrice = 5;
	weight = 1;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Sustain {
		hunger = 0;
		thirst = 70;
	};
	class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
	conditions = "true";
};
class Coffee : Water {
	displayName = "Кофе";
	icon = "\dataM\Icons\coffee.paa";
	buyPrice = 35;
	sellPrice = 18;
	class Settings : Settings {};
	class Sustain {
		hunger = 0;
		thirst = 60;
	};
	class Events : Events {};
};
class Tea : Coffee {
	displayName = "Чай";
	icon = "\dataM\Icons\tea.paa";
	buyPrice = 30;
	sellPrice = 15;
	class Settings : Settings {};
	class Sustain : Sustain {};
	class Events : Events {};
};

// Энергетические напитки
class Redbull {
	displayName = "Redbull";
	description = "Энергетический напиток, способствующий более быстрой реакции человека.";
	icon = "\dataM\Icons\can.paa";
	buyPrice = 2100;
	sellPrice = 1050;
	weight = 1;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Sustain {
		hunger = 0;
		thirst = 50;
	};
	class Events { onUse = "if ([(_this select 0)] call ULP_fnc_addSustenance) then { player setCustomAimCoef 0.5; [ { !(alive player) || { player getVariable [""isIncapacitated"", false] } || { diag_tickTime > (_this select 0) } }, [diag_tickTime + (3 * 60)], { player setCustomAimCoef 1; }] call ULP_fnc_waitUntilExecute; };"; };
	conditions = "true";
};
// Алкогольные напитки
class Beer {
	displayName = "Пиво";
	description = "Алкогольный напиток, вызывающий неприятные побочные эффекты.";
	icon = "\dataM\Icons\beer.paa";
	buyPrice = 290;
	sellPrice = 145;
	weight = 1;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Sustain {
		hunger = 0;
		thirst = 25;
	};
	class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
	conditions = "true";
};
class Schnapps : Beer {
	displayName = "Шнапс";
	icon = "\dataM\Icons\schnapps.paa";
	buyPrice = 580;
	sellPrice = 290;
	class Settings {
		onMarket = true;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Sustain {
		hunger = 0;
		thirst = 30;
	};
	class Events : Events {};
	conditions = "true";
};
class Gin : Beer {
	displayName = "Джин";
	icon = "\dataM\Icons\gin.paa";
	buyPrice = 375;
	sellPrice = 188;
	class Settings : Settings {};
	class Sustain {
		hunger = 0;
		thirst = 25;
	};
	class Events : Events {};
};
class Whiskey : Beer {
	displayName = "Виски";
	icon = "\dataM\Icons\whiskey.paa";
	buyPrice = 495;
	sellPrice = 248;
	class Settings : Settings {};
	class Sustain {
		hunger = 0;
		thirst = 15;
	};
	class Events : Events {};
};

// Награды за опыт
class TinyXPReward {
	displayName = "Маленькая награда за опыт";
	description = "Бутылка, которая, используя, предоставит ценный опыт.";
	icon = "\dataM\Icons\xpReward.paa";
	buyPrice = -1;
	sellPrice = -1;
	weight = 0;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [100, ""Использована награда за опыт""] call ULP_fnc_addXP; };"; };
	conditions = "true";
};
// Награды за опыт
class SmallXPReward : TinyXPReward {
	displayName = "Маленькая награда опыта";
	icon = "\dataM\Icons\xpReward.paa";
	class Settings : Settings {};
	class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [500, ""Использована награда опыта""] call ULP_fnc_addXP; };"; };
};
class MediumXPReward : TinyXPReward {
	displayName = "Средняя награда опыта";
	icon = "\dataM\Icons\xpReward.paa";
	class Settings : Settings {};
	class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [1000, ""Использована награда опыта""] call ULP_fnc_addXP; };"; };
};
class LargeXPReward : TinyXPReward {
	displayName = "Большая награда опыта";
	icon = "\dataM\Icons\xpReward.paa";
	class Settings : Settings {};
	class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [5000, ""Использована награда опыта""] call ULP_fnc_addXP; };"; };
};
class HugeXPReward : TinyXPReward {
	displayName = "Огромная награда опыта";
	icon = "\dataM\Icons\xpReward.paa";
	class Settings : Settings {};
	class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [10000, ""Использована награда опыта""] call ULP_fnc_addXP; };"; };
};

// Триггеры событий
class AirdropTrigger {
	displayName = "Триггер авиапоставки";
	description = "Предмет, используемый для запуска конкретного островного события.";
	icon = "\dataM\Icons\airdropTrigger.paa";
	buyPrice = -1;
	sellPrice = -1;
	weight = 0;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Airdrop""] call ULP_fnc_triggerEvent"; };
	conditions = "true";
};

class ShipwreckTrigger : AirdropTrigger {
	displayName = "Триггер кораблекрушения";
	icon = "\dataM\Icons\shipwreckTrigger.paa";
	class Settings : Settings {};
	class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Shipwreck""] call ULP_fnc_triggerEvent"; };
};

// Общие предметы
class Identification {
	displayName = "Удостоверение личности";
	description = "Карточка, содержащая данные личности. Однако их легко подделать.";
	icon = "\dataM\Icons\identification.paa";
	buyPrice = 75000;
	sellPrice = -1;
	weight = 0;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = true;
		isSystemItem = false;
	};
	class Events {
		onUse = "_this call ULP_fnc_disguiseIdentity;";
		onRemove = "if ((player getVariable [""name"", """"]) isEqualTo (_this select 1)) then { player setVariable [""name"", nil, true]; [""Вы потеряли удостоверение личности, которым маскировались!""] call ULP_fnc_hint; };";
	};
	conditions = "true";
};

class Pickaxe {
	displayName = "Кирка";
	description = "Простой инструмент для добычи минералов.";
	icon = "\dataM\Icons\pickaxe.paa";
	buyPrice = 1200;
	sellPrice = 600;
	weight = 2;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Deconstruction {
		time = 20;
		workbench = false;
		blueprints[] = { { "Tools", "B_Pickaxe" } };
		materials[] = { {"IronBar", 1}, {"Wood", 1} };
	};
	conditions = "true";
};
class LumberAxe : Pickaxe {
	displayName = "Лесопильная топор";
	icon = "\dataM\Icons\lumberAxe.paa";
	buyPrice = 1180;
	sellPrice = 590;
	class Settings : Settings {};
	class Deconstruction {
		time = 20;
		workbench = false;
		blueprints[] = { { "Tools", "B_LumberAxe" } };
		materials[] = { {"IronBar", 1}, {"Wood", 1} };
	};
};
class Shovel : Pickaxe {
	displayName = "Лопата";
	icon = "\dataM\Icons\shovel.paa";
	buyPrice = 1100;
	sellPrice = 550;
	class Settings : Settings {};
	class Deconstruction {
		time = 20;
		workbench = false;
		blueprints[] = { { "Tools", "B_Shovel" } };
		materials[] = { {"Wood", 1} };
	};
};
class Extractor : Pickaxe {
	displayName = "Экстрактор";
	icon = "\dataM\Icons\extractor.paa";
	buyPrice = 1950;
	sellPrice = 975;
	class Settings : Settings {};
	class Deconstruction {
		time = 20;
		workbench = false;
		blueprints[] = { { "Tools", "B_Extractor" } };
		materials[] = { {"IronBar", 2}, {"SilverBar", 1} };
	};
};
class FishingNet : Pickaxe {
	displayName = "Рыболовная сеть";
	description = "Сеть, предназначенная для развертывания с лодки и ловли рыбы.";
	icon = "\dataM\Icons\fishingNet.paa";
	buyPrice = 750;
	sellPrice = 375;
	class Settings : Settings {};
	class Deconstruction {
		time = 30;
		workbench = false;
		blueprints[] = { { "Tools", "B_FishingNet" } };
		materials[] = { {"Rope", 2} };
	};
};
class FuelCan : Pickaxe {
	displayName = "Канистра с топливом";
	description = "Может использоваться для заправки вашего транспортного средства в любом месте.";
	icon = "\dataM\Icons\fuelCan.paa";
	buyPrice = 3000;
	sellPrice = 1500;
	weight = 3;
	class Settings : Settings {};
	class Deconstruction {
		time = 30;
		workbench = false;
		blueprints[] = { { "Tools", "B_FuelCan" } };
		materials[] = { {"IronBar", 3} };
	};
};
class Breathalyser : Pickaxe { // TODO
	displayName = "Алкотестер";
	description = "Используется для определения нахождения кого-либо под воздействием алкоголя.";
	icon = "\dataM\Icons\breathalyser.paa";
	buyPrice = 0;
	sellPrice = 0;
	weight = 1;
	class Settings : Settings {};
};
class PanicButton : Pickaxe {
	displayName = "Паническая кнопка";
	description = "При нажатии на эту кнопку полиция будет оповещена о вашей неотложной потребности в помощи.";
	icon = "\dataM\Icons\panicButton.paa";
	buyPrice = 900;
	sellPrice = 450;
	weight = 1;
	class Settings : Settings {};
	class Deconstruction {
		time = 60;
		workbench = true;
		blueprints[] = { { "PoliceEquipment", "B_PanicButton" } };
		materials[] = { {"CopperBar", 10}, {"SilverBar", 8} };
	};
	class Events { onUse = "[] call ULP_fnc_panic;"; };
};
class Ziptie : Pickaxe {
	displayName = "Зип-перчатки";
	description = "Инструмент, используемый для удержания других лиц.";
	icon = "\dataM\Icons\ziptie.paa";
	buyPrice = 13500;
	sellPrice = 6750;
	weight = 1;
	class Settings : Settings {};
};
class Blindfold : Pickaxe { // TODO
	displayName = "Глазная повязка";
	description = "Инструмент, используемый для закрывания глаз других.";
	icon = "\dataM\Icons\blindfold.paa";
	buyPrice = 17000;
	sellPrice = 8500;
	weight = 1;
	class Settings : Settings {};
	conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
};
class Stinger {
	displayName = "Полоса с шипами";
	description = "Устройство с шипами, используемое для прокола шин автомобиля.";
	icon = "\dataM\Icons\stinger.paa";
	buyPrice = 8400;
	sellPrice = 2200;
	weight = 3;
	class Settings {
		onMarket = false;
		isIllegal = true;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Deconstruction {
		time = 30;
		workbench = true;
		blueprints[] = { { "Tools", "B_MakeshiftStinger" } };
		materials[] = { {"SteelBar", 22} };
	};
	class Events { onUse = "_this call ULP_fnc_spikeStrip;"; };
	conditions = "true";
};
class MakeshiftStinger : Stinger {
	displayName = "Самодельный шип";
	class Settings : Settings {};
};
class VehicleClamp : Stinger {
	displayName = "Зажим для транспортных средств";
	description = "Подвижный зажим, используемый для предотвращения движения транспортного средства.";
	icon = "\dataM\Icons\vehicleClamp.paa";
	buyPrice = 18200;
	sellPrice = 9700;
	weight = 4;
	class Settings : Settings {};
	class Events { onUse = "[] call ULP_fnc_clampVehicle;"; };
};
class Lighter : Stinger {
	displayName = "Зажигалка";
	description = "Простая зажигалка, используемая для создания огня.";
	icon = "\dataM\Icons\lighter.paa";
	buyPrice = 890;
	sellPrice = 445;
	weight = 1;
	class Settings : Settings {};
	class Events {};
	class Deconstruction {
		time = 10;
		workbench = false;
		blueprints[] = { { "Tools", "B_Lighter" } };
		materials[] = { {"Iron", 1} };
	};
};
class Lockpick : Stinger {
	displayName = "Отмычка";
	description = "Инструмент, используемый для отмычки замков на транспортных средствах и наручниках.";
	icon = "\dataM\Icons\lockpick.paa";
	buyPrice = 2500;
	sellPrice = 1250;
	weight = 1;
	class Settings : Settings {};
	class Events {};
	class Deconstruction {
		time = 10;
		workbench = false;
		blueprints[] = { { "Tools", "B_Lockpick" } };
		materials[] = { {"Iron", 2} };
	};
};
class BoltCutter : Stinger {
	displayName = "Болторез";
	description = "Инструмент, используемый для разрезания крепких замков на дверях, ящиках и прочих объектах.";
	icon = "\dataM\Icons\boltCutter.paa";
	buyPrice = 345000;
	sellPrice = 172500;
	weight = 4;
	class Settings : Settings {};
	class Events { onUse = "[] call ULP_fnc_boltcut;"; };
	class Deconstruction {
		time = 40;
		workbench = false;
		blueprints[] = { { "Tools", "B_BoltCutter" } };
		materials[] = { {"Iron", 8} };
	};
};
class BigRedKey : BoltCutter {
	displayName = "Большой красный ключ";
	buyPrice = 31200;
	sellPrice = 15600;
	class Settings : Settings {};
	class Events : Events {};
};
class signalJammer : Stinger { // TODO (крафт)
	displayName = "Помехозащищенное устройство";
	description = "Инструмент, используемый для помехи любым электронным сигналам в ограниченном радиусе.";
	icon = "\dataM\Icons\signalJammer.paa";
	buyPrice = 110300;
	sellPrice = 55150;
	weight = 2;
	class Settings : Settings {};
};
class HackingDevice : Stinger {
	displayName = "Устройство взлома";
	description = "Инструмент, используемый для взлома различных систем и незаконного доступа к ним.";
	icon = "\dataM\Icons\hackingDevice.paa";
	buyPrice = 475000;
	sellPrice = 237500;
	weight = 3;
	class Settings : Settings {};
	class Events {};
	class Deconstruction {
		time = 120;
		workbench = true;
		blueprints[] = { { "Tools", "B_HackingDevice" } };
		materials[] = { {"Silver", 4}, {"CutDiamond", 2} };
	};
};
class ExplosiveCharge : Stinger {
	displayName = "Взрывное устройство";
	description = "Инструмент, используемый для уничтожения укрепленных замков.";
	icon = "\dataM\Icons\explosiveCharge.paa";
	buyPrice = 750000;
	sellPrice = 375000;
	weight = 4;
	class Settings : Settings {};
	class Events {};
	class Deconstruction {
		time = 180;
		workbench = true;
		blueprints[] = { { "Tools", "B_ExplosiveCharge" } };
		materials[] = { {"ExplosiveMaterials", 4}, {"Coal", 7}, {"CutDiamond", 3} };
	};
};
class IndustrialDrill : ExplosiveCharge {
	displayName = "Промышленный бур";
	icon = "\dataM\Icons\industrialDrill.paa";
	buyPrice = 600000;
	sellPrice = 300000;
	class Settings : Settings {};
	class Events { onUse = "[] call ULP_fnc_drill;"; };
	class Deconstruction {
		time = 180;
		workbench = true;
		blueprints[] = { { "Tools", "B_IndustrialDrill" } };
		materials[] = { {"IronBar", 8}, {"CutDiamond", 2} };
	};
};
class Toolbox : Stinger {
	displayName = "Ящик с инструментами";
	description = "Ящик с инструментами, используемыми для разборки предметов на составляющие их основные компоненты.";
	icon = "\dataM\Icons\toolbox.paa";
	buyPrice = 25000;
	sellPrice = 12500;
	weight = 8;
	class Settings : Settings {};
	class Events {};
};

// Медицинское оборудование
class Painkillers { // TODO (Будет восстанавливать здоровье сразу после использования)
	displayName = "Обезболивающее";
	description = "Два таблетки, восстанавливающие небольшое количество здоровья.";
	icon = "\dataM\Icons\painkillers.paa";
	buyPrice = 800;
	sellPrice = 400;
	weight = 1;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	conditions = "true";
};
class Bandage : Painkillers {
	displayName = "Обычное бинтование";
	description = "Используется как материал для изготовления медицинского оборудования.";
	icon = "\dataM\Icons\bandage.paa";
	buyPrice = 850;
	sellPrice = 425;
	class Settings : Settings {};
};
class FieldDressing : Bandage {
	displayName = "Полевое бинтование";
	icon = "\dataM\Icons\fieldDressing.paa";
	description = "Бинт, наилучшим образом подходящий для лечения ссадин.";
};
class Packing : Bandage {
	displayName = "Компрессионное бинтование";
	icon = "\dataM\Icons\packingBandage.paa";
	description = "Бинт, наилучшим образом подходящий для лечения ссадин и разрывов кожи.";
	buyPrice = 1000;
	sellPrice = 655;
};
class Elastic : Bandage {
	displayName = "Эластичное бинтование";
	icon = "\dataM\Icons\elasticBandage.paa";
	description = "Бинт, наилучшим образом подходящий для лечения ссадин и порезов.";
	buyPrice = 1085;
	sellPrice = 750;
};
class QuickClot : Bandage {
	displayName = "Быстроустраняющее бинтование";
	icon = "\dataM\Icons\quikClot.paa";
	description = "Бинт, наилучшим образом подходящий для лечения ссадин и разрывов кожи.";
	buyPrice = 345;
	sellPrice = 125;
};
class BloodBag : Painkillers {
	displayName = "Кровяной мешок";
	description = "Используется для предотвращения истечения крови у обездвиженного человека.";
	icon = "\dataM\Icons\bloodbag.paa";
	buyPrice = 1000;
	sellPrice = 500;
	class Settings : Settings {};
};
class Morphine : Painkillers {
	displayName = "Морфий";
	description = "Используется для увеличения частоты сердечных сокращений человека с целью оживления.";
	icon = "\dataM\Icons\injector.paa";
	buyPrice = 1200;
	sellPrice = 600;
	class Settings : Settings {};
};
class Epinephrine : Morphine {
	displayName = "Эпинефрин";
	description = "Используется для снижения частоты сердечных сокращений человека с целью оживления.";
	class Settings : Settings {};
};
class FirstAidKit : Painkillers {
	displayName = "Аптечка первой помощи";
	description = "Набор, содержащий различные медицинские инструменты, которые могут оказать помощь.";
	icon = "\dataM\Icons\firstAidKit.paa";
	buyPrice = 1500;
	sellPrice = 750;
	class Settings : Settings {};
};
class MediKit : FirstAidKit {
	displayName = "Медицинский набор";
	icon = "\dataM\Icons\mediKit.paa";
	buyPrice = 18700;
	sellPrice = 9350;
	weight = 2;
	class Settings : Settings {};
};
class AutomatedExternalDefibrillator : MediKit {
	displayName = "Автоматический внешний дефибриллятор";
	description = "Портативное электронное устройство, автоматически диагностирующее жизнеугрожающие нарушения сердечного ритма.";
	icon = "\dataM\Icons\defibrillator.paa";
	buyPrice = 22600;
	sellPrice = 11300;
	weight = 2;
	class Settings : Settings {};
};
// Размещаемые предметы
class TapeSign_F { 
	displayName = "Красно-белая лента";
	description = "Свёрнутый предмет, готовый к установке.";
	icon = "\dataM\Icons\roadBarrier.paa";
	buyPrice = 0;
	sellPrice = 0;
	weight = 2;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	class Events { onUse = "[""TapeSign"", _this select 0] call ULP_fnc_placeObject;"; };
	conditions = "true";
};
class PlasticBarrier_02_yellow_F : TapeSign_F { 
	displayName = "Пластиковый барьер (Средний, Желтый)";
	buyPrice = 0;
	sellPrice = 0;
	weight = 3;
	class Settings : Settings {};
};
class PlasticBarrier_02_grey_F : PlasticBarrier_02_yellow_F { 
	displayName = "Пластиковый барьер (Средний, Серый)";
	class Settings : Settings {};
};
class PlasticBarrier_03_orange_F : TapeSign_F { 
	displayName = "Пластиковый барьер (Большой, Оранжевый)";
	buyPrice = 0;
	sellPrice = 0;
	weight = 4;
	class Settings : Settings {};
};
class PlasticBarrier_03_blue_F : PlasticBarrier_03_orange_F { 
	displayName = "Пластиковый барьер (Большой, Синий)";
	class Settings : Settings {};
};
class RoadBarrier_small_F : TapeSign_F { 
	displayName = "Дорожный барьер (Маленький)";
	buyPrice = 0;
	sellPrice = 0;
	weight = 3;
	class Settings : Settings {};
};
class RoadBarrier_F : TapeSign_F { 
	displayName = "Дорожный барьер (Большой)";
	buyPrice = 0;
	sellPrice = 0;
	weight = 5;
	class Settings : Settings {};
};
class RoadCone_F : TapeSign_F { 
	displayName = "Дорожный конус";
	icon = "\dataM\Icons\cone.paa";
	buyPrice = 0;
	sellPrice = 0;
	weight = 2;
	class Settings : Settings {};
	class Events { onUse = "[""RoadCone"", _this select 0] call ULP_fnc_placeObject;"; };
};
class RoadCone_L_F : RoadCone_F { 
	displayName = "Дорожный конус (световой)";
	class Settings : Settings {};
	class Events { onUse = "[""RoadConeWithLight"", _this select 0] call ULP_fnc_placeObject;"; };
};
class Land_PortableLight_single_F : TapeSign_F { 
	displayName = "Портативный фонарь (одиночный)";
	icon = "\dataM\Icons\portableLight.paa";
	buyPrice = 0;
	sellPrice = 0;
	class Settings : Settings {};
	class Events { onUse = "[""SinglePortableLight"", _this select 0] call ULP_fnc_placeObject;"; };
};
class Land_PortableLight_double_F : Land_PortableLight_single_F { 
	displayName = "Портативный фонарь (двойной)";
	buyPrice = 0;
	sellPrice = 0;
	class Settings : Settings {};
	class Events { onUse = "[""DoublePortableLight"", _this select 0] call ULP_fnc_placeObject;"; };
};
class TargetP_Inf4_F : TapeSign_F { 
	displayName = "Поднимающаяся мишень (враждебная)";
	icon = "\dataM\Icons\popupTarget.paa";
	buyPrice = 0;
	sellPrice = 0;
	class Settings : Settings {};
};
class TargetP_Civ_F : TargetP_Inf4_F { 
	displayName = "Поднимающаяся мишень (дружественная)";
	class Settings : Settings {};
};
class TargetP_Civ3_F : TargetP_Inf4_F { 
	displayName = "Поднимающаяся мишень (заложник)";
	class Settings : Settings {};
};

// Сельскохозяйственное оборудование (TODO - Рынок фермеров, Трактор)
class FarmingEquipment { // TODO (изготовление)
	displayName = "Сельскохозяйственное оборудование";
	description = "Набор инструментов, используемых для сельского хозяйства в специализированных хранилищах.";
	icon = "\dataM\Icons\farmingEquipment.paa";
	buyPrice = 8900;
	sellPrice = 4450;
	weight = 3;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	conditions = "true";
};
class FertileSoil : FarmingEquipment { // TODO
	displayName = "Семена культур";
	description = "Небольшой пакет семян, готовых для посадки в плодородную почву в специализированном хранилище.";
	icon = "\dataM\Icons\fertileSoil.paa";
	buyPrice = 1230;
	sellPrice = 615;
	weight = 1;
	class Settings : Settings {};
};
class CropSeeds : FertileSoil { // TODO
	displayName = "Семена культур";
	description = "Небольшой пакет семян, готовых для посадки в плодородную почву в специализированном хранилище.";
	icon = "\dataM\Icons\seeds.paa";
	buyPrice = 900;
	sellPrice = 450;
	class Settings : Settings {};
};
// Компоненты для компьютеров (TODO - какой-то магазин для всего этого)
class MiningRig { // TODO (изготовление)
	displayName = "Майнинг-риг";
	description = "Собранный риг для майнинга криптовалюты в специализированных складах.";
	icon = "\dataM\Icons\miningRig.paa";
	buyPrice = -1;
	sellPrice = -1;
	weight = 4;
	class Settings {
		onMarket = false;
		isIllegal = false;
		isSavable = true;
		isScripted = false;
		isEventItem = false;
		isSystemItem = false;
	};
	conditions = "true";
};
class Motherboard : MiningRig { // TODO (изготовление)
	displayName = "Материнская плата";
	description = "Компонент, используемый для изготовления майнинг-ригов.";
	icon = "\dataM\Icons\motherboard.paa";
	weight = 1;
	class Settings : Settings {};
};
class CPU : Motherboard { // TODO (изготовление)
	displayName = "Процессор";
	icon = "\dataM\Icons\cpu.paa";
	class Settings : Settings {};
};
class GPU : Motherboard { // TODO (изготовление)
	displayName = "Графический процессор (GPU)";
	icon = "\dataM\Icons\gpu.paa";
	class Settings : Settings {};
};
class RAM : Motherboard { // TODO (изготовление)
	displayName = "Оперативная память (RAM)";
	icon = "\dataM\Icons\ram.paa";
	class Settings : Settings {};
};
class PSU : Motherboard { // TODO (изготовление)
	displayName = "Блок питания (PSU)";
	icon = "\dataM\Icons\psu.paa";
	class Settings : Settings {};
};

// Прочие предметы для бега
class StolenCargo {
	displayName = "Украденный груз";
	description = "Герметичные грузовые ящики, заполненные украденными товарами.";
	icon = "\dataM\Icons\crate.paa";
	buyPrice = -1;
	sellPrice = 98500;
	weight = 14;
	class Settings {
		onMarket = true;
		isIllegal = true;
		isSavable = false;
		isScripted = false;
		isEventItem = false;
		isSystemItem = true;
	};
	conditions = "true";
};
class FreightCargo : StolenCargo {
	displayName = "Фрахтовый груз";
	description = "Герметичные грузовые ящики, заполненные фрахтовыми товарами.";
	icon = "\dataM\Icons\freightCargo.paa";
	sellPrice = 45680;
	weight = 24;
	class Settings : Settings {
		isIllegal = false;
	};
};
class SeizedContraband : StolenCargo {
	displayName = "Изъятые контрабандные товары";
	description = "Контрабанда изъятая полицией и хранимая в хранилище улик.";
	icon = "\dataM\Icons\seizedContraband.paa";
	sellPrice = 237600;
	weight = 4;
	class Settings : Settings {};
};
class SpaceCapsuleDataDrive : StolenCargo {
	displayName = "Дисковод данных космической капсулы";
	description = "Дисковод данных из космической капсулы, содержащий неизвестные секреты.";
	icon = "\dataM\Icons\drive.paa";
	sellPrice = 7000000;
	weight = 10;
	class Settings : Settings {};
};
class SmallGalleryPiece : StolenCargo {
	displayName = "Маленький художественный элемент";
	description = "Художественное произведение, обычно хранящееся в Галерее.";
	icon = "\dataM\Icons\galleryPiece.paa";
	sellPrice = 365000;
	weight = 6;
	class Settings : Settings {};
};
class MediumGalleryPiece : SmallGalleryPiece {
	displayName = "Средний художественный элемент";
	icon = "\dataM\Icons\galleryPiece.paa";
	sellPrice = 496000;
	weight = 9;
	class Settings : Settings {};
};
class LargeGalleryPiece : SmallGalleryPiece {
	displayName = "Большой художественный элемент";
	icon = "\dataM\Icons\galleryPiece.paa";
	sellPrice = 732500;
	weight = 13;
	class Settings : Settings {};
};
class MarkedGold : StolenCargo {
	displayName = "Помеченное золото";
	description = "Золотая слиток с маркировкой, которая обычно хранится в Государственной сокровищнице.";
	icon = "\dataM\Icons\ingot.paa";
	sellPrice = 250000;
	weight = 16;
	class Settings : Settings {};
};
class UnmarkedGold : MarkedGold {
	displayName = "Непомеченное золото";
	description = "Золотая слиток, с маркировкой, которая была удалена ювелиром.";
	sellPrice = 700000;
	class Settings : Settings {};
};
class EncryptedDrive : StolenCargo {
	displayName = "Зашифрованный носитель данных";
	description = "Зашифрованный носитель данных с секретными файлами, взятыми с командного моста HMS Liberty.";
	icon = "\dataM\Icons\drive.paa";
	sellPrice = 400000;
	weight = 8;
	class Settings : Settings {};
};
class DecryptedDrive : EncryptedDrive {
	displayName = "Расшифрованный носитель данных";
	description = "Расшифрованный носитель данных с секретными файлами, взятыми с командного моста HMS Liberty.";
	icon = "\dataM\Icons\drive.paa";
	sellPrice = 1000000;
	class Settings : Settings {};
};
// Легальные необработанные ресурсы
class Tobacco {
    displayName = "Табак";
    description = "Обычный лист, который можно обработать в сигареты или сигары.";
    icon = "\dataM\Icons\tobacco.paa";
    buyPrice = -1;
    sellPrice = -1;
    weight = 4;
    class Settings {
        onMarket = false;
        isIllegal = false;
        isSavable = false;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class Clay : Tobacco {
    displayName = "Глина";
    description = "Простой материал, используемый для создания.";
    icon = "\dataM\Icons\clay.paa";
    weight = 1;
    class Settings : Settings {};
};
class Wood : Tobacco {
    displayName = "Дерево";
    description = "Простой кусок дерева, обычно используемый в рецептах для создания.";
    icon = "\dataM\Icons\wood.paa";
    sellPrice = 6;
    weight = 2;
    class Settings : Settings {};
};
class Rope : Tobacco {
    displayName = "Веревка";
    description = "Простой кусок веревки, обычно используемый в рецептах для создания.";
    icon = "\dataM\Icons\rope.paa";
    weight = 1;
    class Settings : Settings {};
};
class DrillBit : Tobacco {
    displayName = "Сверло";
    description = "Прочное сверло, обычно используемое в рецептах для создания.";
    icon = "\dataM\Icons\drillBit.paa";
    weight = 1;
    class Settings : Settings {};
};
class Rock : Tobacco {
    displayName = "Камень";
    description = "Простой камень, обычно собираемый на территории ХМП.";
    icon = "\dataM\Icons\ore.paa";
    sellPrice = 3;
    weight = 3;
    class Settings : Settings {};
    conditions = "ULP_Imprisioned";
};
class CopperOre : Tobacco {
    displayName = "Медная руда";
    description = "Руда, добываемая в минеральных шахтах.";
    icon = "\dataM\Icons\ore.paa";
    weight = 3;
    class Settings : Settings {};
};
class SilverOre : CopperOre {
    displayName = "Серебряная руда";
    icon = "\dataM\Icons\ore.paa";
    class Settings : Settings {};
};
class IronOre : CopperOre {
    displayName = "Железная руда";
    icon = "\dataM\Icons\ore.paa";
    weight = 5;
    class Settings : Settings {};
};
class Sand : Tobacco {
    displayName = "Песок";
    description = "Зерна песка, которые можно обработать в стекло.";
    icon = "\dataM\Icons\sand.paa";
    weight = 2;
    class Settings : Settings {};
};
class UnrefinedSalt : Tobacco {
    displayName = "Нерафиниров. соль";
    description = "Соль, добываемая на соляных озерах.";
    icon = "\dataM\Icons\saltUnrefined.paa";
    weight = 3;
    class Settings : Settings {};
};
class UnprocessedOil : Tobacco {
    displayName = "Нерафинир. масло";
    description = "Нерафинированное масло, извлеченное из нефтяной скважины.";
    icon = "\dataM\Icons\oilUnrefined.paa";
    weight = 6;
    class Settings : Settings {};
};
class UncutDiamond : CopperOre {
    displayName = "Несломанный алмаз";
    icon = "\dataM\Icons\ore.paa";
    class Settings : Settings {};
};

// Легально обработанные товары
class Cigarette {
    displayName = "Сигарета";
    description = "Пачка табака, которую можно продать или выкурить.";
    icon = "\dataM\Icons\cigarette.paa";
    buyPrice = 5700;
    sellPrice = 2850;
    weight = 3;
    class Settings {
        onMarket = true;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = true;
        isSystemItem = false;
    };
    conditions = "true";
};
class Cigar : Cigarette {
    displayName = "Сигара";
    icon = "\dataM\Icons\cigar.paa";
    buyPrice = 6720;
    sellPrice = 3360;
    class Settings : Settings {};
};
class Coal : Cigarette {
    displayName = "Уголь";
    description = "Простой угольный кусок, который можно продать на угольной электростанции.";
    icon = "\dataM\Icons\ore.paa";
    buyPrice = -1;
    sellPrice = 2400;
    weight = 4;
    class Settings : Settings {};
};
class CopperBar : Coal {
    displayName = "Медный слиток";
    description = "Обработанный металлический слиток.";
    icon = "\dataM\Icons\ingot.paa";
    sellPrice = 1900;
    weight = 2;
    class Settings : Settings {};
};
class SilverBar : CopperBar {
    displayName = "Серебряный слиток";
    sellPrice = 2200;
    class Settings : Settings {};
};
class IronBar : CopperBar {
    displayName = "Железный слиток";
    sellPrice = 7350;
    class Settings : Settings {};
};
class SteelBar : CopperBar {
    displayName = "Стальной слиток";
    sellPrice = 9670;
    class Settings {
        onMarket = true;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
};
class Glass : CopperBar {
    displayName = "Стекло";
    description = "Прочное стекло, готовое к продаже.";
    icon = "\dataM\Icons\glass.paa";
    sellPrice = 2450;
    weight = 1;
    class Settings : Settings {};
};
class RefinedSalt : CopperBar {
    displayName = "Рафинированная соль";
    description = "Рафинированная соль, готовая к продаже.";
    icon = "\dataM\Icons\saltRefined.paa";
    sellPrice = 3200;
    class Settings : Settings {};
};
class ProcessedOil : CopperBar {
    displayName = "Рафинированное масло";
    description = "Рафинированное масло, оставшееся полностью воспламеняющимся.";
    icon = "\dataM\Icons\oilRefinded.paa";
    sellPrice = 9850;
    weight = 4;
    class Settings : Settings {};
};
class CutDiamond : CopperBar {
    displayName = "Ограненный алмаз";
    description = "Тщательно ограненный алмаз, который, по-видимому, очень нравится женщинам.";
    icon = "\dataM\Icons\diamond.paa";
    sellPrice = 6100;
    class Settings {
        onMarket = true;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
};
// Незаконно необработанные ресурсы
class UraniumOre : CopperOre {
    displayName = "Урановая руда";
    icon = "\dataM\Icons\ore.paa";
    weight = 8;
    class Settings {
        onMarket = false;
        isIllegal = true;
        isSavable = false;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
};
class ExplosiveMaterials : UraniumOre {
    displayName = "Взрывчатые вещества";
    description = "Набор взрывчатых материалов, которые часто используются в рецептах для создания.";
    icon = "\dataM\Icons\explosiveMaterials.paa";
    weight = 3;
    class Settings : Settings {};
    class Deconstruction {
        time = 180;
        workbench = true;
        blueprints[] = { { "CraftingMaterials", "B_ExplosiveMaterials" } };
        materials[] = { {"IronBar", 32}, {"ProcessedOil", 9} };
    };
};
class Corn : UraniumOre {
    displayName = "Кукуруза";
    description = "Товар, оставшийся незаконным из-за популярности самогоноварения.";
    icon = "\dataM\Icons\corn.paa";
    weight = 3;
    class Settings : Settings {};
};
class EphedrineBarrel : CopperOre {
    displayName = "Бочка с эфедрином";
    description = "Основной материал для производства метамфетамина.";
    icon = "\dataM\Icons\methUnprocessed.paa";
    buyPrice = 6050;
    weight = 12;
    class Settings {
        onMarket = false;
        isIllegal = true;
        isSavable = false;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
};
class UnprocessedWeed : UraniumOre {
    displayName = "Необработанный сорняк";
    description = "Наркотик, бесполезный до обработки.";
    icon = "\dataM\Icons\weedUnprocessed.paa";
    weight = 4;
    class Settings : Settings {};
};
class UnprocessedHeroin : UnprocessedWeed {
    displayName = "Опий";
    icon = "\dataM\Icons\heroinUnprocessed.paa";
    weight = 5;
    class Settings : Settings {};
};
class UnprocessedCocaine : UnprocessedHeroin {
    displayName = "Кока-лист";
    icon = "\dataM\Icons\cocaineUnprocessed.paa";
    weight = 6;
    class Settings : Settings {};
};

// Незаконно обработанные товары
class Coral {
    displayName = "Коралл";
    description = "Коралл, добываемый у берегов Кавалы.";
    icon = "\dataM\Icons\coral.paa";
    buyPrice = -1;
    sellPrice = 6700;
    weight = 7;
    class Settings {
        onMarket = true;
        isIllegal = true;
        isSavable = false;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class ProcessedWeed : Coral {
    displayName = "Обработанный сорняк";
    description = "Обработанные наркотики, которые можно использовать, продавать или покупать у наркодилера.";
    icon = "\dataM\Icons\weedProcessed.paa";
    buyPrice = 6680;
    sellPrice = 3340;
    weight = 3;
    class Settings {
        onMarket = true;
        isIllegal = true;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
};
class ProcessedHeroin : ProcessedWeed {
    displayName = "Обработанный героин";
    icon = "\dataM\Icons\heroinProcessed.paa";
    buyPrice = 14160;
    sellPrice = 7080;
    weight = 4;
    class Settings : Settings {};
};
class ProcessedCocaine : ProcessedWeed {
    displayName = "Обработанный кокаин";
    icon = "\dataM\Icons\cocaineProcessed.paa";
    buyPrice = 22900;
    sellPrice = 11450;
    weight = 5;
    class Settings : Settings {};
};
class ProcessedMeth : ProcessedWeed {
    displayName = "Метамфетамин";
    icon = "\dataM\Icons\methProcessed.paa";
    buyPrice = 61000;
    sellPrice = 30500;
    weight = 5;
    class Settings : Settings {};
};
class Moonshine : ProcessedWeed {
    displayName = "Самогон";
    icon = "\dataM\Icons\moonshine.paa";
    buyPrice = 13400;
    sellPrice = 6700;
    weight = 2;
    class Settings : Settings {};
};
class Ecstasy : ProcessedWeed {
    displayName = "Экстази";
    icon = "\dataM\Icons\ecstasy.paa";
    buyPrice = 10500;
    sellPrice = 5250;
    weight = 1;
    class Settings : Settings {};
};
class UraniumBar : ProcessedWeed {
    displayName = "Урановый слиток";
    description = "Чрезвычайно опасный минерал, полученный из радиационной зоны.";
    icon = "\dataM\Icons\ingot.paa";
    buyPrice = -1;
    sellPrice = 28650;
    weight = 6;
    class Settings : Settings {};
};
// Незаконно очищенные товары
class PurifiedWeed {
    displayName = "Очищенный сорняк";
    description = "Самые высококачественные наркотики на Алтисе, созданные для увеличения прибыли.";
    icon = "\dataM\Icons\weedProcessed.paa";
    buyPrice = 9018;
    sellPrice = 4509;
    weight = 3;
    class Settings {
        onMarket = true;
        isIllegal = true;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class PurifiedHeroin : PurifiedWeed {
    displayName = "Очищенный героин";
    icon = "\dataM\Icons\heroinProcessed.paa";
    buyPrice = 19116;
    sellPrice = 9558;
    weight = 4;
    class Settings : Settings {};
};
class PurifiedCocaine : PurifiedWeed {
    displayName = "Очищенный кокаин";
    icon = "\dataM\Icons\cocaineProcessed.paa";
    buyPrice = 30915;
    sellPrice = 15457;
    weight = 5;
    class Settings : Settings {};
};
class PurifiedMeth : PurifiedWeed {
    displayName = "Очищенный метамфетамин";
    icon = "\dataM\Icons\methProcessed.paa";
    buyPrice = 82350;
    sellPrice = 41175;
    weight = 5;
    class Settings : Settings {};
};
class PurifiedMoonshine : PurifiedWeed {
    displayName = "Очищенный самогон";
    icon = "\dataM\Icons\moonshine.paa";
    buyPrice = 18090;
    sellPrice = 9045;
    weight = 1;
    class Settings : Settings {};
};

// Сырая рыба
class Salema_F_Raw {
    displayName = "Сырая салема";
    description = "Сырая рыба, которую можно продать на рыбном рынке или приготовить в общественной кухне.";
    icon = "\dataM\Icons\fish.paa";
    buyPrice = -1;
    sellPrice = 450;
    weight = 2;
    class Settings {
        onMarket = false;
        isIllegal = false;
        isSavable = false;
        isScripted = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class Ornate_random_F_Raw : Salema_F_Raw {
    displayName = "Сырая рыба орнатус";
    sellPrice = 660;
    class Settings : Settings {};
};
class Mackerel_F_Raw : Salema_F_Raw {
    displayName = "Сырая рыба макрель";
    sellPrice = 740;
    class Settings : Settings {};
};
class Tuna_F_Raw : Salema_F_Raw {
    displayName = "Сырая рыба тунец";
    sellPrice = 822;
    class Settings : Settings {};
};
class Mullet_F_Raw : Salema_F_Raw {
    displayName = "Сырая рыба барабанщик";
    sellPrice = 990;
    class Settings : Settings {};
};
class CatShark_F_Raw : Salema_F_Raw {
    displayName = "Сырая рыба кошачий акула";
    sellPrice = 1237;
    class Settings : Settings {};
};
class Turtle : Salema_F_Raw {
    displayName = "Черепаха";
    icon = "\dataM\Icons\turtle.paa";
    sellPrice = 65000;
    class Settings {
        onMarket = true;
        isIllegal = true;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
    };
};

// Приготовленная рыба
class CookedSalema {
    displayName = "Приготовленная салема";
    description = "Приготовленная рыба, которую можно продать на рыбном рынке.";
    icon = "\dataM\Icons\fish.paa";
    buyPrice = 2250;
    sellPrice = 1125;
    weight = 2;
    class Settings {
        onMarket = true;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class CookedOrnate : CookedSalema {
    displayName = "Приготовленная орнатус";
    buyPrice = 3300;
    sellPrice = 1650;
    class Settings : Settings {};
};
class CookedMackerel : CookedSalema {
    displayName = "Приготовленная макрель";
    buyPrice = 3700;
    sellPrice = 1850;
    class Settings : Settings {};
};
class CookedTuna : CookedSalema {
    displayName = "Приготовленная тунец";
    buyPrice = 4112;
    sellPrice = 2056;
    class Settings : Settings {};
};
class CookedMullet : CookedSalema {
    displayName = "Приготовленная барабанщик";
    buyPrice = 4950;
    sellPrice = 2475;
    class Settings : Settings {};
};
class CookedCatshark : CookedSalema {
    displayName = "Приготовленная кошачий акула";
    buyPrice = 6187;
    sellPrice = 3093;
    class Settings : Settings {};
};

// Археологические предметы
class CommonMap {
    displayName = "Обычная карта";
    description = "Карта с известными артефактами на всей территории.";
    icon = "\dataM\Icons\map.paa";
    buyPrice = 20000;
    sellPrice = 10000;
    weight = 2;
    class Settings {
        onMarket = false;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    class Events { onUse = "[""Common""] call ULP_fnc_getSite;"; };
    conditions = "true";
};
class UncommonMap : CommonMap {
    displayName = "Необычная карта";
    buyPrice = -1;
    sellPrice = 135000;
    class Settings : Settings {};
    class Events { onUse = "[""Uncommon""] call ULP_fnc_getSite;"; };
};
class RareMap : UncommonMap {
    displayName = "Редкая карта";
    sellPrice = 180000;
    class Settings : Settings {};
    class Events { onUse = "[""Rare""] call ULP_fnc_getSite;"; };
};

class CommonMapFragment : UncommonMap {
    displayName = "Фрагмент обычной карты";
    description = "Фрагмент карты с незавершенными данными.";
    icon = "\dataM\Icons\mapFragment.paa";
    sellPrice = 15000;
    class Settings : Settings {};
};
class UncommonMapFragment : CommonMapFragment {
    displayName = "Фрагмент необычной карты";
    sellPrice = 30000;
    class Settings : Settings {};
};
class RareMapFragment : CommonMapFragment {
    displayName = "Фрагмент редкой карты";
    sellPrice = 45000;
    class Settings : Settings {};
};

class SurveyingEquipment {
    displayName = "Оборудование для землемерства";
    description = "Оборудование, используемое для землемерства на раскопках для поиска артефактов.";
    icon = "\dataM\Icons\surveyingEquipment.paa";
    buyPrice = 28900;
    sellPrice = 14450;
    weight = 9;
    class Settings {
        onMarket = false;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    class Events { onUse = "[ULP_Archaeology] call ULP_fnc_surveySite;"; };
    class Deconstruction {
        time = 120;
        workbench = true;
        blueprints[] = { { "Tools", "B_SurveyingEquipment" } };
        materials[] = { {"CopperBar", 2}, {"SilverBar", 1} };
    };
    conditions = "true";
};
class ArchaeologistsEquipment : SurveyingEquipment {
    displayName = "Оборудование археолога";
    description = "Оборудование, используемое для осторожного извлечения артефактов на раскопках.";
    icon = "\dataM\Icons\archaeologistsEquipment.paa";
    buyPrice = 24500;
    sellPrice = 12250;
    weight = 6;
    class Settings : Settings {};
    class Events { onUse = "[ULP_Archaeology] call ULP_fnc_digSite;"; };
    class Deconstruction {
        time = 120;
        workbench = true;
        blueprints[] = { { "Tools", "B_ArchaeologistsEquipment" } };
        materials[] = { {"IronBar", 4}, {"Wood", 2}, {"Rock", 1} };
    };
};
// Общие награды
class OldCoin {
    displayName = "Старая монета";
    description = "Артефакт, собранный с раскопок и проданный археологам.";
    icon = "\dataM\Icons\oldCoin.paa";
    buyPrice = -1;
    sellPrice = 8287;
    weight = 1;
    class Settings {
        onMarket = true;
        isIllegal = false;
        isSavable = true;
        isScripted = false;
        isEventItem = false;
        isSystemItem = false;
    };
    conditions = "true";
};
class CoinBundle : OldCoin {
    displayName = "Пачка монет";
    icon = "\dataM\Icons\coinBundle.paa";
    sellPrice = 310781;
    weight = 6;
    class Settings : Settings {};
};
class BrokenPot : OldCoin {
    displayName = "Сломанная горшок";
    icon = "\dataM\Icons\brokenPot.paa";
    sellPrice = 16575;
    weight = 5;
    class Settings : Settings {};
};
class RestoredPot : BrokenPot {
    displayName = "Восстановленный горшок";
    icon = "\dataM\Icons\restoredPot.paa";
    sellPrice = 41437;
    class Settings : Settings {};
};
class BluntStoneKnife : OldCoin {
    displayName = "Тупой каменный нож";
    icon = "\dataM\Icons\bluntStoneKnife.paa";
    sellPrice = 26775;
    weight = 2;
    class Settings : Settings {};
};
class SharpStoneKnife : OldCoin {
    displayName = "Острый каменный нож";
    icon = "\dataM\Icons\sharpStoneKnife.paa";
    sellPrice = 66937;
    weight = 2;
    class Settings : Settings {};
};
class FossilisedBone : OldCoin {
    displayName = "Окаменелая кость";
    icon = "\dataM\Icons\fossilisedBone.paa";
    sellPrice = 32595;
    weight = 3;
    class Settings : Settings {};
};
class UnidentifiedSkull : OldCoin {
    displayName = "Неопознанный череп";
    sellPrice = 65850;
    weight = 4;
    class Settings : Settings {};
};
class IdentifiedSkull : UnidentifiedSkull {
    displayName = "Идентифицированный череп";
    icon = "\dataM\Icons\unidentifiedSkull.paa";
    sellPrice = 1439000;
    class Settings : Settings {};
};
/// Необычные награды
class PetrifiedShield : OldCoin {
    displayName = "Окаменевший щит";
    icon = "\dataM\Icons\petrifiedShield.paa";
    sellPrice = 72300;
    weight = 9;
    class Settings : Settings {};
};
class WeatheredSculpture : OldCoin {
    displayName = "Обветренная скульптура";
    icon = "\dataM\Icons\weatheredSculpture.paa";
    sellPrice = 96750;
    weight = 7;
    class Settings : Settings {};
};
class AncientAmber : OldCoin {
    displayName = "Древний янтарь";
    icon = "\dataM\Icons\ancientAmber.paa";
    sellPrice = 100927;
    class Settings : Settings {};
};
class ReligiousTotem : OldCoin {
    displayName = "Религиозный тотем";
    icon = "\dataM\Icons\religiousTotem.paa";
    sellPrice = 133950;
    weight = 13;
    class Settings : Settings {};
};
class StrongMetalRing : OldCoin {
    displayName = "Крепкое металлическое кольцо";
    icon = "\dataM\Icons\strongMetalRing.paa";
    sellPrice = 138900;
    class Settings : Settings {};
};
class DiamondRing : OldCoin {
    displayName = "Бриллиантовое кольцо";
    icon = "\dataM\Icons\diamondRing.paa";
    sellPrice = 206100;
    class Settings : Settings {};
};
/// Редкие награды
class EmeraldAmulet : OldCoin {
    displayName = "Изумрудное ожерелье";
    icon = "\dataM\Icons\emeraldAmulet.paa";
    sellPrice = 260625;
    weight = 2;
    class Settings : Settings {};
};
class AncientLedger : OldCoin {
    displayName = "Древняя книга учета";
    icon = "\dataM\Icons\ancientLedger.paa";
    sellPrice = 367237;
    weight = 8;
    class Settings : Settings {};
};
class HandSmoothedRunestone : OldCoin {
    displayName = "Обработанный рунный камень вручную";
    icon = "\dataM\Icons\handSmoothedRunestone.paa";
    sellPrice = 279037;
    weight = 15;
    class Settings : Settings {};
};
class JeweledNecklace : OldCoin {
    displayName = "Украшенное ожерелье";
    icon = "\dataM\Icons\jeweledNecklace.paa";
    sellPrice = 282337;
    weight = 3;
    class Settings : Settings {};
};
class BrokenTimepiece : OldCoin {
    displayName = "Сломанный временной механизм";
    icon = "\dataM\Icons\brokenTimepiece.paa";
    sellPrice = 308475;
    weight = 2;
    class Settings : Settings {};
};
};