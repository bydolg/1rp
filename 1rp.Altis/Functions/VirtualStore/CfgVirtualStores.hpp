class CfgVirtualStores {
	class Police {
		storeName = "Магазин личного снаряжения полиции";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			//class Breathalyser {};
			class PanicButton {};
			class Stinger {};
			class Blindfold {};
			class Lockpick {};
			class BigRedKey {};
			//class Painkillers {};
			class FieldDressing {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
			//class TargetP_Inf4_F {};
			//class TargetP_Civ_F {};
			//class TargetP_Civ3_F {};
		};
	};

	class Medic {
		storeName = "Магазин личного снаряжения медика";
		conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class Sweetie {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			//class Painkillers {};
			class FieldDressing {};
			class Elastic {};
			class Packing {};
			class QuickClot {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
		};
	};
	class Hato {
		storeName = "Магазин личного снаряжения HATO";
		conditions = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			class VehicleClamp {};
			class FieldDressing {};
			class BloodBag {};
			//class Morphine {};
			//class Epinephrine {};
			class FirstAidKit {};
			class MediKit {};
			class AutomatedExternalDefibrillator {};
			class TapeSign_F {};
			//class PlasticBarrier_02_yellow_F {};
			//class PlasticBarrier_02_grey_F {};
			//class PlasticBarrier_03_orange_F {};
			//class PlasticBarrier_03_blue_F {};
			//class RoadBarrier_small_F {};
			//class RoadBarrier_F {};
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
		};
	};

	class Civilian {
		storeName = "Городской рынок";
		conditions = "true";
		class Items {
			class FreshApple {};
			class Apple {};
			class FreshPeach {};
			class Peach {};
			class Bacon {};
			class Water {};
			class Pickaxe {};
			class LumberAxe {};
            class Extractor {};
			class Shovel {};
			//class FishingNet {};
			class FuelCan {};
			class Lighter {};
			class Lockpick {};
			class Toolbox {};
		};
	};

	class Government {
		storeName = "Рынок правительства";
		conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class PanicButton {};
			class Painkillers {};
			class FieldDressing {};
			class BloodBag {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Hideout {
		storeName = "Скрытый рынок";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Rebel {
		storeName = "Рынок повстанцев";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Blackmarket {
		storeName = "Черный рынок";
		conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Base : Rebel {
		storeName = "Рынок банды";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			//class Painkillers {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

class Burger {
	storeName = "Редбургер";
	conditions = "true";
	class Items {
		class Burger {};
		class Hotdog {};
		class Chips {};
		class Water {};
		class Redbull {};
	};
};

class Tea {
	storeName = "Чайная комната";
	conditions = "true";
	class Items {
		class Doughnut {};
		class Coffee {};
		class Tea {};
	};
};

class Pub {
	storeName = "Местный паб";
	conditions = "true";
	class Items {
		class Beer {};
		class Schnapps {};
		class Gin {};
		class Whiskey {};
	};
};

class Medical {
	storeName = "Медицинские припасы";
	conditions = "true";
	class Items {
		class Painkillers {};
		class Bandage {};
		class FieldDressing {};
		class Elastic {};
		class Packing {};
		class QuickClot {};
		class BloodBag {};
		class Morphine {};
		class Epinephrine {};
		class FirstAidKit {};
		class AutomatedExternalDefibrillator {};
	};
};

class Fish {
	storeName = "Рыбный рынок";
	conditions = "true";
	class Items {
		class Salema_F_Raw {};
		class CookedSalema {};
		class Ornate_random_F_Raw {};
		class CookedOrnate {};
		class Mackerel_F_Raw {};
		class CookedMackerel {};
		class Tuna_F_Raw {};
		class CookedTuna {};
		class Mullet_F_Raw {};
		class CookedMullet {};
		class CatShark_F_Raw {};
		class CookedCatshark {};
    class Rabbit_F_Raw {};
    class Goat_random_F_Raw {};
    class Sheep_random_F_Raw {};
	};
};

class Turtle {
	storeName = "Торговец черепахами";
	conditions = "true";
	class Items {
		class Turtle_F_Raw {};
	};
};

class Cigarette {
	storeName = "Торговец сигаретами";
	conditions = "true";
	class Items {
		class Lighter {};
		class Cigarette {};
	};
};

class Cigar {
	storeName = "Торговец сигарами";
	conditions = "true";
	class Items {
		class Lighter {};
		class Cigar {};
	};
};

class Coal {
	storeName = "Торговец углем";
	conditions = "true";
	class Items {
		class Coal {};
	};
};

class Coral {
	storeName = "Торговец кораллами";
	conditions = "true";
	class Items {
		class Coral {};
	};
};

class Glass {
	storeName = "Торговец стеклом";
	conditions = "true";
	class Items {
		class Glass {};
	};
};

class Salt {
	storeName = "Торговец солью";
	conditions = "true";
	class Items {
		class RefinedSalt {};
	};
};

class Diamond {
	storeName = "Торговец алмазами";
	conditions = "true";
	class Items {
		class CutDiamond {};
	};
};

class Oil {
	storeName = "Торговец маслом";
	conditions = "true";
	class Items {
		class ProcessedOil {};
	};
};

class Metal {
	storeName = "Экспорт металла Алтиса";
	conditions = "true";
	class Items {
		class CopperBar {};
		class SilverBar {};
		class IronBar {};
	};
};

class Uranium {
	storeName = "Торговец ураном";
	conditions = "true";
	class Items {
		class UraniumBar {};
	};
};

class Gold {
	storeName = "Покупатель золота";
	conditions = "true";
	class Items {
		class MakredGold {};
		class UnmakredGold {};
	};
};

class Secrets {
	storeName = "Покупатель секретов";
	conditions = "true";
	class Items {
		class SpaceCapsuleDataDrive {};
		class EncryptedDrive {};
		class DecryptedDrive {};
	};
};

class Contraband {
	storeName = "Торговец контрабандой";
	conditions = "true";
	class Items {
		class SeizedContraband {};
	};
};

class Dispensary {
	storeName = "Распределитель метамфетамина";
	conditions = "true";
	class Items {
		class EphedrineBarrel {};
	};
};

class Art {
	storeName = "Торговец искусством";
	conditions = "true";
	class Items {
		//class SmallGalleryPiece {};
		//class MediumGalleryPiece {};
		//class LargeGalleryPiece {};
	};
};

class Drug {
	storeName = "Дилер наркотиков";
	conditions = "true";
	class Items {
		class ProcessedWeed {};
		class PurifiedWeed {};
		class ProcessedHeroin {};
		class PurifiedHeroin {};
		class ProcessedCocaine {};
		class PurifiedCocaine {};
		class ProcessedMeth {};
		class PurifiedMeth {};
		class Moonshine {};
		class PurifiedMoonshine {};
		class Ecstasy {};
	};
};

class HMP {
	storeName = "Тюрьма HMP";
	conditions = "ULP_Imprisioned";
	class Items {
		class RationPack {};
		class Water {};
		class Pickaxe {};
		class Rock {};
	};
};

class Archaeology {
	storeName = "Археологи";
	class Items {
		class CommonMap {};
		class UncommonMap {};
		class RareMap {};
		class SurveyingEquipment {};
		class ArchaeologistsEquipment {};
	};
};

class Artifact {
	storeName = "Торговец артефактами";
	class Items {
		class CommonMapFragment {};
		class UncommonMapFragment {};
		class RareMapFragment {};
		class OldCoin {};
		class CoinBundle {};
		class BrokenPot {};
		class RestoredPot {};
		class BluntStoneKnife {};
		class SharpStoneKnife {};
		class FossilisedBone {};
		class UnidentifiedSkull {};
		class IdentifiedSkull {};
		class PetrifiedShield {};
		class WeatheredSculpture {};
		class AncientAmber {};
		class ReligiousTotem {};
		class StrongMetalRing {};
		class DiamondRing {};
		class EmeraldAmulet {};
		class AncientLedger {};
		class HandSmoothedRunestone {};
		class JeweledNecklace {};
		class BrokenTimepiece {};
	};
};
};