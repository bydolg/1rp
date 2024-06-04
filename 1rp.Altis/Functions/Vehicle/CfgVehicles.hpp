class CfgVehicles {
retrievalPerc = 0.02;
chopKeepChance = 80;
chopPerc = 0.35;
chopTime = 300;

class Base {
	virtualSpace = 0;
	garageLimit = 4;
	isHouse = false;
	canTransfer = true;
	conditions = "true";
	blacklistedItems[] = { "StolenCargo", "FreightCargo" };
	class Textures {};
};

// LIGHTS --------------------------------------------------------------------------------------
class PoliceColour {
	leftColour[] = {0.1, 0.1, 20};
	rightColour[] = {0.1, 0.1, 20};
};
class MedicColour {
	leftColour[] = {0.1, 0.1, 20};
	rightColour[] = {0.1, 0.1, 20};
};
class HatoColour {
	leftColour[] = {10, 5, 0};
	rightColour[] = {10, 5, 0};
};

// TEXTURES --------------------------------------------------------------------------------------
class BaseTexture {
		displayName = "Default";
	buyPrice = 0;
		factions[] = { "Civilian" };
	textures[] = {};
	locked = false;
	conditions = "true";
};

class PoliceTexture : BaseTexture {
		factions[] = { "Police" };
	remoteGates = true;
	class Siren {
		SFX[] = { "Police_One", "Police_Two", "Police_Three" };
	};
	class Lights : PoliceColour {};
	class Actions {
		class PNC {
			actionTitle = "Полицейский национальный компьютер";
			actionCode = "[] call ULP_fnc_openPNC";
			params[] = {};
			priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { ([player, [""Police""]] call ULP_fnc_isFaction) || ((driver _this) isEqualTo _target) }";
			radius = 25;
		};
	};
};

class MedicTexture : BaseTexture {
		factions[] = { "Medic" };
	remoteGates = true;
	class Siren {
		SFX[] = { "Police_One" };
	};
	class Lights : MedicColour {};
};

class HatoTexture : BaseTexture {
		factions[] = { "Hato" };
	remoteGates = true;
	class Siren {};
	class Lights : HatoColour {};
};

class BaseChromeGreen : BaseTexture {
	displayName = "Зеленый хром";
	materials[] = { "\dataM\Textures\Vehicles\Global\Chrome\green.rvmat" };
	locked = true;
};
class BaseChromeBlue : BaseChromeGreen {
	displayName = "Синий хром";
	materials[] = { "\dataM\Textures\Vehicles\Global\Chrome\blue.rvmat" };
};
class BaseChromeRed : BaseChromeGreen {
	displayName = "Красный хром";
	materials[] = { "\dataM\Textures\Vehicles\Global\Chrome\red.rvmat" };
};
class BaseChromeSilver : BaseChromeGreen {
	displayName = "Серебряный хром";
	materials[] = { "\dataM\Textures\Vehicles\Global\Chrome\silver.rvmat" };
};
class BaseChromeGold : BaseChromeGreen {
	displayName = "Золотой хром";
	materials[] = { "\dataM\Textures\Vehicles\Global\Chrome\gold.rvmat" };
};

// CARS --------------------------------------------------------------------------------------
class C_Kart_01_Blu_F : Base {
	description = "Карт - это маленький четырехколесный транспорт, который движется за счет гравитации, газа или электричества. У него 4-тактный двигатель мощностью до 20 л.с. и его не должны водить водители младше 18 лет.";
	buyPrice = 2500;
	virtualSpace = 0;
	garageLimit = 1;
};
class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{};
class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};
class C_Kart_01_black_F : C_Kart_01_Blu_F{};
class C_Kart_01_white_F : C_Kart_01_Blu_F{};
class C_Kart_01_green_F : C_Kart_01_Blu_F{};
class C_Kart_01_orange_F : C_Kart_01_Blu_F{};
class C_Kart_01_yellow_F : C_Kart_01_Blu_F{};

class C_Quadbike_01_F : Base {
	description = "Квадроцикл - это вседорожное транспортное средство с низким давлением в шинах и рулевым управлением. Военные используют квадроциклы для разведки и доступа к местности, труднодоступной для более тяжелых транспортных средств.";
	buyPrice = 11300;
	virtualSpace = 15;
	class Textures {
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa" }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa" }; 
		};
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa" }; 
		};
		class Tan : BaseTexture { 
			displayName = "Бежевый";
			textures[] = { "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa" }; 
		};
	};
};

class C_Hatchback_01_F : Base {
	description = "Четырехместный хэтчбек, массово выпускаемый на Дальнем Востоке, чтобы удовлетворить растущий спрос на семейные автомобили. Также доступен в спортивной версии.";
	buyPrice = 21450;
	virtualSpace = 25;
	class Textures {
		class PoliceWhite : PoliceTexture { 
			displayName = "Общий отклик";
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\hatchback_white.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.458496,1.77002,-0.899953};
				rightPos[] = {-0.52002,1.75732,-0.94257};
			};
		};
		class PoliceBlack : PoliceWhite { 
			displayName = "Вооруженный отклик";
			conditions = "[] call ULP_fnc_donatorLevel > 0";
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\hatchback_black.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.458496,1.77002,-0.899953};
				rightPos[] = {-0.52002,1.75732,-0.94257};
			};
		};
		class PoliceANPR : PoliceWhite { 
			displayName = "ANPR Интерсептор";
			conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
			anpr = true;
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\hatchback_ANPR.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.458496,1.77002,-0.899953};
				rightPos[] = {-0.52002,1.75732,-0.94257};
			};
		};
		class UnmarkedBlack : PoliceTexture {
			displayName = "Черный";
			conditions = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
			class Lights : PoliceColour {
				leftPos[] = {0.458496,1.77002,-0.899953};
				rightPos[] = {-0.52002,1.75732,-0.94257};
			};
		};
		class UnmarkedBlackWhiteSport : UnmarkedBlack {
			displayName = "Черно-белый спорт";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
			class Lights : Lights {};
		};
		class UnmarkedGrey : UnmarkedBlack {
			displayName = "Серый";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
			class Lights : Lights {};
		};
		class UnmarkedWhite : UnmarkedBlack {
			displayName = "Белый";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" };
			class Lights : Lights {}; 
		};
		class UnmarkedBeige : UnmarkedBlack {
			displayName = "Бежевый";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
			class Lights : Lights {};
		};
		class UnmarkedBeigeSport : UnmarkedBlack {
			displayName = "Бежевый спорт";
			textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
			class Lights : Lights {};
		};
class UnmarkedRedSport : UnmarkedBlack {
	displayName = "Красный Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" };
	class Lights : Lights {}; 
};
class UnmarkedBlue : UnmarkedBlack {
	displayName = "Синий";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
	class Lights : Lights {};
};
class UnmarkedBlueSport : UnmarkedBlack {
	displayName = "Синий Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
	class Lights : Lights {};
};
class UnmarkedDarkBlue : UnmarkedBlack {
	displayName = "Темно-синий";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
	class Lights : Lights {};
};
class UnmarkedDarkBlueSport : UnmarkedBlack {
	displayName = "Темно-синий Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
	class Lights : Lights {};
};
class UnmarkedGreen : UnmarkedBlack {
	displayName = "Зеленый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" };
	class Lights : Lights {};
};
class UnmarkedGreenSport : UnmarkedBlack {
	displayName = "Зеленый Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
	class Lights : Lights {};
};
class UnmarkedYellow : UnmarkedBlack {
	displayName = "Желтый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
	class Lights : Lights {};
};
class UnmarkedOrangeSport : UnmarkedBlack {
	displayName = "Оранжевый Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
	class Lights : Lights {};
};
class Medic : MedicTexture { 
	textures[] = { "\dataM\Textures\Vehicles\Land\Medic\hatchback.paa" }; 
	class Lights : MedicColour {
		leftPos[] = {0.458496,1.77002,-0.899953};
		rightPos[] = {-0.52002,1.75732,-0.94257};
	};
};
class Hato : HatoTexture { 
	textures[] = { "\dataM\Textures\Vehicles\Land\Hato\hatchback.paa" }; 
	class Lights : HatoColour {
		leftPos[] = {0.458496,1.77002,-0.899953};
		rightPos[] = {-0.52002,1.75732,-0.94257};
	};
};
class Black : BaseTexture {
	displayName = "Черный";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
};
class BlackWhiteSport : BaseTexture {
	displayName = "Черно-белый Спорт"; 
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
};
class Grey : BaseTexture {
	displayName = "Серый"; 
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
};
class White : BaseTexture { 
	displayName = "Белый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" }; 
};
class Beige : BaseTexture { 
	displayName = "Бежевый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
};
class BeigeSport : BaseTexture { 
	displayName = "Бежевый Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
};
class RedSport : BaseTexture { 
	displayName = "Красный Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" }; 
};
class Blue : BaseTexture { 
	displayName = "Синий";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
};
class BlueSport : BaseTexture { 
	displayName = "Синий Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
};
class DarkBlue : BaseTexture { 
	displayName = "Темно-синий";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
};
class DarkBlueSport : BaseTexture { 
	displayName = "Темно-синий Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
};
class Green : BaseTexture { 
	displayName = "Зеленый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" }; 
};
class GreenSport : BaseTexture { 
	displayName = "Зеленый Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
};
class Yellow : BaseTexture { 
	displayName = "Желтый";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
};
class OrangeSport : BaseTexture { 
	displayName = "Оранжевый Спорт";
	textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
};
		};
	};
class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 276500; };

class C_Offroad_01_F : Base {
	description = "Пикап 4x4 от Generic Motors обладает прочной рамой, мощным двигателем и разработан для преодоления сложной местности Средиземья.";
	buyPrice = 42800;
	virtualSpace = 60;
	class Textures {
		class White : BaseTexture {
			displayName = "Белый"; 
			textures[] = { 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa", 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa" 
			}; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa", 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa" 
			}; 
		};
		class DarkRed : BaseTexture { 
			displayName = "Темно-красный";
			textures[] = { 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa", 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa" 
			}; 
		};
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa", 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa" 
			}; 
		};
		class BlueWhite : BaseTexture { 
			displayName = "Синий/Белый";
			textures[] = { 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa", 
				"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa" 
			}; 
		};
		class Ridge : BaseTexture { 
			displayName = "Ridge";
			locked = true;
			textures[] = { "\dataM\Textures\Vehicles\Land\Civilian\Offroad\ridge.paa" }; 
		};
	};
};
class B_G_Offroad_01_armed_F : C_Offroad_01_F { buyPrice = 4280000; };
class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};
class C_IDAP_Offroad_01_F : C_Offroad_01_F {
	class Textures {
		class IDAP : BaseTexture {
			displayName = "IDAP"; 
			textures[] = { 
				"\a3\soft_f_orange\Data\Offroad_01_ext_IDAP_CO.paa"
			}; 
		};
	};
};
class C_Offroad_01_covered_F : C_Offroad_01_F {
	buyPrice = 49100;
	virtualSpace = 75;
	class Textures {
		class Hato : HatoTexture { 
			displayName = "HATO"; 
			textures[] = { "\dataM\Textures\Vehicles\Land\Hato\offroad.paa" }; 
		};
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = {
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_blk_co.paa"
			}; 
		};
		class Green : BaseTexture { 
			displayName = "Зеленый";
			textures[] = { 
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
				"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_grn_co.paa"
			}; 
		};
	};
};
class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 54450; };
class C_Offroad_01_repair_F : C_Offroad_01_covered_F { buyPrice = 132400; };

class C_Offroad_02_unarmed_F : Base {
	description = "MB 4WD - современное четырёхколесное внедорожное транспортное средство с характерной конструкцией, мощным двигателем, прочной рамой и отличной маневренностью.";
	buyPrice = 38750;
	virtualSpace = 55;
	class Textures {
		class Medic : MedicTexture { 
			textures[] = { "\dataM\Textures\Vehicles\Land\Medic\MB4.paa" }; 
			class Lights : MedicColour {
				leftPos[] = {0.757324,1.83252,-0.379596};
				rightPos[] = {-0.844727,1.82861,-0.379596};
			};
		};
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa" }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa" }; 
		};
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
		};
		class Orange : BaseTexture { 
			displayName = "Оранжевый";
			textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
		};
		class Ridge : BaseTexture { 
			displayName = "Ridge";
			locked = true;
			textures[] = { "\dataM\Textures\Vehicles\Land\Civilian\MB4_WD\ridge.paa" }; 
		};
	};
};
class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {
	class Textures {
		class IDAP : BaseTexture {
			displayName = "IDAP"; 
			textures[] = { 
				"\a3\soft_f_orange\Data\Offroad_02_ext_IDAP_CO.paa"
			}; 
		};
	};
};
class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { buyPrice = 670300; };

class C_SUV_01_F : Base {
	description = "Полноразмерный кроссовер класса люкс, не особенно подходящий для бездорожья, но обладающий хорошей дорожной проходимостью. Его мощный двигатель и полный привод способствуют комфортным поездкам на высоких скоростях.";
	buyPrice = 71200;
	virtualSpace = 45;
	class Textures {
		class PoliceWhite : PoliceTexture { 
			displayName = "Общественный порядок";
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\SUV_white.paa" };
			class Lights : PoliceColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			};
		};
		class PoliceBlack : PoliceWhite { 
			displayName = "Вооруженный отклик";
			conditions = "[] call ULP_fnc_donatorLevel > 0";
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\SUV_black.paa" };
			class Lights : PoliceColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			}; 
		};
		class PoliceANPR : PoliceWhite { 
			displayName = "ANPR Интерсептор";
			conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
			anpr = true;
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\SUV_ANPR.paa" };
			class Lights : PoliceColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			}; 
		};
		class UnmarkedBlack : PoliceTexture {
			displayName = "Черный";
			conditions = "[""Police_NCA"", 1] call ULP_fnc_hasAccess || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			};
		};
		class UnmarkedSilver : UnmarkedBlack {
			displayName = "Серебряный";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
			class Lights : Lights {};
		};
		class UnmarkedRed : UnmarkedBlack {
			displayName = "Красный";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" };  
			class Lights : Lights {};
		};
		class UnmarkedOrange : UnmarkedBlack {
			displayName = "Оранжевый";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" }; 
			class Lights : Lights {};
		};
		class Medic : MedicTexture { 
			textures[] = { "\dataM\Textures\Vehicles\Land\Medic\SUV.paa" }; 
			class Lights : MedicColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			};
		};
		class Hato : HatoTexture { 
			textures[] = { "\dataM\Textures\Vehicles\Land\Hato\SUV.paa" }; 
			class Lights : HatoColour {
				leftPos[] = {0.370605,2.22021,-0.531462};
				rightPos[] = {-0.396484,2.22119,-0.531462};
			};
		};
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
		};
		class Silver : BaseTexture { 
			displayName = "Серебряный";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" }; 
		};
		class Orange : BaseTexture { 
			displayName = "Оранжевый";
			textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" };
		};
	};
};

class C_Van_02_transport_F : Base {
	description = "Этот фургон может использоваться для различных практических целей. Благодаря длинной грузовой платформе и отличной высоте крыши, он способен перевозить пассажиров, грузы и маленькие транспортные средства.";
	buyPrice = 88000;
	virtualSpace = 90;
	class Textures {
		class PoliceWhite : PoliceTexture { 
			displayName = "Публичный порядок";
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\van.paa" }; 
		};
		class UnmarkedBlack : PoliceTexture {
			displayName = "Черный";
			conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
		};
		class UnmarkedWhite : UnmarkedBlack {
			displayName = "Белый";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
		};
		class UnmarkedRed : UnmarkedBlack {
			displayName = "Красный";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
		};
		class UnmarkedOrange : UnmarkedBlack {
			displayName = "Оранжевый";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
		};
		class Medic : MedicTexture { 
			displayName = "Скорая помощь"; 
			conditions = "[""Medic_Main"", 1] call ULP_fnc_hasAccess";
			textures[] = { "\dataM\Textures\Vehicles\Land\Medic\van.paa" }; 
		};
		class Hato : HatoTexture { 
			displayName = "HATO"; 
			conditions = "[""Hato_Main"", 1] call ULP_fnc_hasAccess";
			textures[] = { "\dataM\Textures\Vehicles\Land\Hato\van.paa" }; 
		};
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
		};
		class Orange : BaseTexture { 
			displayName = "Оранжевый";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
		};
		class Press : BaseTexture { 
			displayName = "Пресса";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_AAN_CO.paa" }; 
		};
	};
};

class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
class C_Van_02_medevac_F : C_Van_02_transport_F {};
class C_IDAP_Van_02_transport_F : C_Van_02_transport_F {
	class Textures {
		class IDAP : BaseTexture { 
			displayName = "IDAP";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
		};
	};
};

class C_Van_02_vehicle_F : C_Van_02_transport_F {
	buyPrice = 96650;
	virtualSpace = 110;
};

class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};

class C_IDAP_Van_02_vehicle_F : C_Van_02_vehicle_F {
	class Textures {
		class IDAP : BaseTexture { 
			displayName = "IDAP";
			textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
		};
	};
};

class C_Van_02_service_F : C_Van_02_vehicle_F {};

class B_CTRG_LSV_01_light_F : Base {
	description = "Prowler - это маневренное, легкобронированное транспортное средство, использующее скорость, маневренность и мобильность вне дорог для избегания угроз.";
	buyPrice = 580000;
	virtualSpace = 50;
	garageLimit = 3;
	class Textures {
		class Police : PoliceTexture { 
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\prowler.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.75293,1.99902,-0.930151};
				rightPos[] = {-0.681152,2.01074,-0.930151};
			};
		};
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { 
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_black_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_black_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_black_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_black_co.paa" 
			}; 
		};
		class Sand : BaseTexture { 
			displayName = "Песочный";
			textures[] = { 
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
			}; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
				"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
			}; 
		};
		class ChromeGreen : BaseChromeGreen {};
		class ChromeBlue : BaseChromeBlue {};
		class ChromeRed : BaseChromeRed {};
		class ChromeSilver : BaseChromeSilver {};
		class ChromeGold : BaseChromeGold {};
	};
};
	class B_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 675000; };

class O_LSV_02_unarmed_F : Base {
	description = "Qilin обеспечивает безопасную и быструю скорость при выдающейся мобильности и маневренности. Он адаптирован для суровых и ограничительных террейнов.";
	buyPrice = 800000;
	virtualSpace = 50;
	garageLimit = 3;
	class Textures {
		class Police : PoliceTexture { 
			textures[] = { "\dataM\Textures\Vehicles\Land\Police\qilin.paa" }; 
			class Lights : PoliceColour {
				leftPos[] = {0.615234,2.03467,-0.40501};
				rightPos[] = {-0.943359,2.02881,-0.398304};
			};
		};
		class Black : BaseTexture { 
			displayName = "Черный";
			textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_black_CO.paa", }; 
		};
		class Hex : BaseTexture { 
			displayName = "Хекс";
			textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa", }; 
		};
		class ChromeGreen : BaseChromeGreen {};
		class ChromeBlue : BaseChromeBlue {};
		class ChromeRed : BaseChromeRed {};
		class ChromeSilver : BaseChromeSilver {};
		class ChromeGold : BaseChromeGold {};
	};
};
class O_LSV_02_armed_black_F : O_LSV_02_unarmed_F { 
	buyPrice = 6590000; 
	garageLimit = 1;
};

class B_MRAP_01_F : Base {
	description = "Hunter - это бронированное машинное транспортное средство, способное выдержать легкое оружие и оснащенное мощным двигателем.";
	buyPrice = 9800000;
	virtualSpace = 65;
	garageLimit = 1;
	garageDelay = 15;
	repairTime = 20;
	crushTime = 60;
	chopKeepChance = 95;
	chopTime = 300;
	class Textures {
		class Police : PoliceTexture {
			textures[] = {
				"\dataM\Textures\Vehicles\Land\Police\hunter_01.paa",
				"\dataM\Textures\Vehicles\Land\Police\hunter_02.paa"
			}; 
			class Lights : PoliceColour {
				leftPos[] = {0.95459,-2.73975,0.559029};
				rightPos[] = {-0.94873,-2.73975,0.557981};
			};
		};
	};
};

class O_MRAP_02_F : Base {
	description = "Ifrit - бронированное машинное транспортное средство, разработанное и произведенное в России. Его преимущества заключаются в надежности в экстремальных погодных условиях и защите экипажа.";
	buyPrice = 7500000;
	virtualSpace = 65;
	garageLimit = 2;
	garageDelay = 15;
	repairTime = 20;
	crushTime = 60;
	chopKeepChance = 90;
	chopTime = 300;
	canTransfer = false;
	turrets[] = { { "SmokeLauncher" } };
	conditions = "[""Ifrits""] call ULP_fnc_hasGroupPerk";
	class Textures {
		class Hex : BaseTexture { 
			displayName = "Хекс";
			textures[] = { 
				"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa", 
				"\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa"
			}; 
		};
		class GoldLine : BaseTexture { 
			displayName = "Золотая линия";
			buyPrice = 450000;
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
			textures[] = { 
				"\dataM\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_01.paa",
				"\dataM\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_02.paa"
			}; 
		};
		class Oil : GoldLine { 
			displayName = "Нефтяное пятно";
			buyPrice = 315700;
			textures[] = { 
				"\dataM\Textures\Vehicles\Land\Civilian\Ifrit\oil_01.paa",
				"\dataM\Textures\Vehicles\Land\Civilian\Ifrit\oil_02.paa"
			}; 
		};
		class ChromeGreen : BaseChromeGreen {
			materials[] = { 
				"\dataM\Textures\Vehicles\Global\Chrome\green.rvmat",
				"\dataM\Textures\Vehicles\Global\Chrome\green.rvmat"
			};
		};
		class ChromeBlue : BaseChromeBlue {
			materials[] = { 
				"\dataM\Textures\Vehicles\Global\Chrome\blue.rvmat",
				"\dataM\Textures\Vehicles\Global\Chrome\blue.rvmat"
			};
		};
		class ChromeRed : BaseChromeRed {
			materials[] = { 
				"\dataM\Textures\Vehicles\Global\Chrome\red.rvmat",
				"\dataM\Textures\Vehicles\Global\Chrome\red.rvmat"
			};
		};
		class ChromeSilver : BaseChromeSilver {
			materials[] = { 
				"\dataM\Textures\Vehicles\Global\Chrome\silver.rvmat",
				"\dataM\Textures\Vehicles\Global\Chrome\silver.rvmat"  
			};
		};
		class ChromeGold : BaseChromeGold {
			materials[] = { 
				"\dataM\Textures\Vehicles\Global\Chrome\gold.rvmat",
				"\dataM\Textures\Vehicles\Global\Chrome\gold.rvmat"  
			};
		};
	};
};

class I_MRAP_03_F : Base {
	description = "Strider - это среднее вседорожное транспортное средство с амфибийной способностью и улучшенной защитой экипажа, разработанное для рекогносцировки и транспортировки войск.";
	buyPrice = 5750000;
	virtualSpace = 65;
	garageLimit = 2;
	garageDelay = 15;
	repairTime = 20;
	crushTime = 60;
	chopKeepChance = 90;
	chopTime = 300;
	class Textures {
		class Tan : BaseTexture { 
			displayName = "Песочный";
			textures[] = { 
				"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa", 
				"\A3\data_f\vehicles\turret_co.paa"
			}; 
		};
		class Asiimov : BaseTexture { 
			displayName = "Асимов";
			locked = true;
			textures[] = { "\dataM\Textures\Vehicles\Land\Civilian\Strider\asiimov.paa" }; 
		};
		class ChromeGreen : BaseChromeGreen {};
		class ChromeBlue : BaseChromeBlue {};
		class ChromeRed : BaseChromeRed {};
		class ChromeSilver : BaseChromeSilver {};
		class ChromeGold : BaseChromeGold {};
	};
};

// ГРУЗОВИКИ --------------------------------------------------------------------------------------
class C_Tractor_01_F : Base {
	description = "Обычный трактор можно найти в аграрных хозяйствах по всему миру. Это надежное высококрутное инженерное транспортное средство, используемое для буксировки прицепов и многих других сельскохозяйственных задач.";
	buyPrice = 23150;
	virtualSpace = 10;
	garageLimit = 3;
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class Red : BaseTexture {
			displayName = "Красный"; 
			textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_red_co.paa" }; 
		};
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_blue_co.paa" }; 
		};
		class Green : BaseTexture { 
			displayName = "Зеленый";
			textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_green_co.paa" }; 
		};
	};
};

class C_Van_01_transport_F : Base {
	description = "Гражданский грузовик 4x4 - это высоко настраиваемый грузовик с возможностью передвижения по бездорожью. Он основан на ретро-дизайне, но использует современный двигатель и электронику.";
	buyPrice = 190500;
	virtualSpace = 100;
	garageLimit = 3;
	enableRope = false;
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
		};
		class Brown : BaseTexture { 
			displayName = "Коричневый";
			textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
		};
		class Aldsa : BaseTexture {
			displayName = "Aldsa"; 
			locked = true;
			textures[] = { 
				"\dataM\Textures\Vehicles\Land\Civilian\Truck\aldsa_01.paa", 
				"\dataM\Textures\Vehicles\Land\Civilian\Truck\aldsa_02.paa"
			}; 
		};
	};
};
class C_Van_01_box_F : C_Van_01_transport_F {
	buyPrice = 245000;
	virtualSpace = 150;
};
class C_Van_01_fuel_F : C_Van_01_transport_F {
	buyPrice = 210500;
	virtualSpace = 120;
	class Textures {
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
		};
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
		};
		class Brown : BaseTexture { 
			displayName = "Коричневый";
			textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
		};
	};
};

class I_Truck_02_transport_F : Base {
	description = "Тяжелый грузовик Zamak - 6x6 транспортное средство, используемое для транспортировки и утилизации. Оснащенный мощным V8 двигателем, эти грузовики надежны даже в суровых условиях.";
	buyPrice = 505000;
	virtualSpace = 280;
	garageLimit = 2;
	enableRope = false;
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class Orange : BaseTexture {
			displayName = "Оранжевый"; 
			textures[] = { 
				"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa", 
				"\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
			}; 
		};
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { 
				"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
				"\a3\soft_f_beta\truck_02\data\truck_02_kuz_co.paa",
				"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
			};
		}; 
	};
};
class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {
	class Textures {
		class IDAP : BaseTexture {
			displayName = "IDAP"; 
			textures[] = { 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
			 }; 
		};
	};
};
class I_Truck_02_covered_F : I_Truck_02_transport_F {
	buyPrice = 560000;
	virtualSpace = 350;
};
class C_IDAP_Truck_02_F : I_Truck_02_covered_F {
	class Textures {
		class IDAP : BaseTexture {
			displayName = "IDAP"; 
			textures[] = { 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
			 }; 
		};
	};
};
class I_Truck_02_fuel_F : I_Truck_02_transport_F {
	buyPrice = 435000;
	virtualSpace = 200;
};
class C_IDAP_Truck_02_water_F : I_Truck_02_fuel_F {
	class Textures {
		class IDAP : BaseTexture {
			displayName = "IDAP"; 
			textures[] = { 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
				"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
			 }; 
		};
	};
};

class O_Truck_03_transport_F : Base {
	description = "Темпест - это 6x6 транспортное средство с майн-резистентной конструкцией. Модульное проектирование позволяет создавать несколько транспортных версий.";
	buyPrice = 615500;
	virtualSpace = 370;
	garageLimit = 2;
	enableRope = false;
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class BrownHex : BaseTexture {
			displayName = "Коричневый Хекс"; 
			textures[] = { 
				"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
				"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
				"\a3\soft_f_epc\truck_03\data\truck_03_cargo_co.paa"
			 }; 
		};
		class GreenHex : BaseTexture { 
			displayName = "Зеленый Хекс";
			textures[] = { 
				"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
				"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
				"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa",
				"\a3\soft_f_exp\truck_03\data\truck_03_cover_ghex_co.paa"
			};
		}; 
	};
};
class O_Truck_03_covered_F : O_Truck_03_transport_F {
	buyPrice = 670500;
	virtualSpace = 410;
};
class O_Truck_03_repair_F : O_Truck_03_transport_F {
	buyPrice = 728000;
	virtualSpace = 485;
};
class O_Truck_03_ammo_F : O_Truck_03_transport_F {
	buyPrice = 710000;
	virtualSpace = 460;
};
class O_Truck_03_fuel_F : O_Truck_03_transport_F {
	buyPrice = 590500;
	virtualSpace = 350;
};
class O_Truck_03_device_F : O_Truck_03_transport_F {
	buyPrice = 1150000;
	virtualSpace = 150;
};

class B_Truck_01_mover_F : Base {
	description = "Тяжелый расширяемый тактический мобильный грузовик - это 8x8 дизельное внедорожное транспортное средство. Существует несколько версий, покрывающих основные функции транспортировки.";
	buyPrice = 334000;
	virtualSpace = 10;
	garageLimit = 2;
	enableRope = false;
	canTransfer = false;
	conditions = "[""HEMTTs""] call ULP_fnc_hasGroupPerk || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class Hato : HatoTexture { 
			displayName = "HATO";
			textures[] = { 
				"\dataM\textures\vehicles\land\HATO\hemtt_1.paa",
				"\dataM\textures\vehicles\land\HATO\hemtt_2.paa",
				"\dataM\textures\vehicles\land\HATO\hemtt_primer.paa"
			};
			class Lights : HatoColour {
				leftPos[] = {0.814453,5.87402,-0.947113};
				rightPos[] = {-0.736816,5.86328,-0.947113};
			};
		}; 
	};
};
class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
	buyPrice = 376000;
	virtualSpace = 10;
	class Textures {
		class Hato : HatoTexture { 
			displayName = "HATO";
			textures[] = { 
				"\dataM\textures\vehicles\land\HATO\hemtt_1.paa",
				"\dataM\textures\vehicles\land\HATO\hemtt_2.paa",
				"\dataM\textures\vehicles\land\HATO\hemtt_flatbed.paa"
			};
			class Lights : HatoColour {
				leftPos[] = {0.814453,5.87402,-0.947113};
				rightPos[] = {-0.736816,5.86328,-0.947113};
			};
		}; 
	};
};
class B_Truck_01_cargo_F : B_Truck_01_mover_F {
	buyPrice = 690500;
	virtualSpace = 450;
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_co.paa",
				"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_pacific_co.paa",
				"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_pacific_co.paa"
			};
		}; 
	};
};
class B_Truck_01_transport_F : B_Truck_01_mover_F {
	buyPrice = 795000;
	virtualSpace = 535;
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa"
			};
		}; 
	};
};
class B_Truck_01_covered_F : B_Truck_01_mover_F {
	buyPrice = 865000;
	virtualSpace = 590;
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_cover_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_cover_olive_co.paa"
			};
		}; 
	};
};
class B_Truck_01_ammo_F : B_Truck_01_mover_F {
	buyPrice = 905000;
	virtualSpace = 650;
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_gamma\truck_01\data\truck_01_ammo_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa"
			};
		}; 
	};
};
class B_Truck_01_fuel_F : B_Truck_01_mover_F {
	buyPrice = 880000;
	virtualSpace = 500;
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_gamma\truck_01\data\truck_01_fuel_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_fuel_olive_co.paa"
			};
		}; 
	};
};
class B_Truck_01_box_F : Base {
	buyPrice = 995000;
	virtualSpace = 800;
	garageLimit = 3;
	garageDelay = 30;
	repairTime = 15;
	crushTime = 30;
	chopKeepChance = 85;
	chopTime = 120;
	canTransfer = false;
	conditions = "[""HEMTTs""] call ULP_fnc_hasGroupPerk";
	blacklistedItems[] = { "StolenCargo" };
	class Textures {
		class Sand : BaseTexture {
			displayName = "Песчаный"; 
			textures[] = { 
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
				"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
				"\a3\soft_f_gamma\truck_01\data\truck_01_mprimer_co.paa",
				"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
			 }; 
		};
		class Olive : BaseTexture { 
			displayName = "Оливковый";
			textures[] = { 
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
				"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa",
				"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
			};
		}; 
		class Ridge : BaseTexture { 
			displayName = "Гребень";
			locked = true;
			textures[] = { 
				"\dataM\textures\vehicles\land\civilian\ridge_hemtt_1.paa",
				"\dataM\textures\vehicles\land\civilian\ridge_hemtt_2.paa",
				"\dataM\textures\vehicles\land\civilian\ridge_hemtt_3.paa",
				"\dataM\textures\vehicles\land\civilian\ridge_hemtt_4.paa"
			};
		}; 
	};
};

// Лодки и катера
class C_Scooter_Transport_01_F : Base {
	description = "Личное водное средство типа скутер. Мощный двигатель и отличная маневренность делают это средство идеальным для веселья.";
	buyPrice = 14300;
	virtualSpace = 5;
	class Textures {
		class Black : BaseTexture {
			displayName = "Черный"; 
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_black_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_black_co.paa"
			 }; 
		};
		class White : BaseTexture { 
			displayName = "Белый";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_White_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_White_co.paa"
			};
		}; 
		class Grey : BaseTexture { 
			displayName = "Серый";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Grey_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Grey_co.paa"
			};
		}; 
		class Red : BaseTexture { 
			displayName = "Красный";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Red_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Red_co.paa"
			};
		}; 
		class Blue : BaseTexture { 
			displayName = "Синий";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_blue_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_blue_co.paa"
			};
		}; 
		class Green : BaseTexture { 
			displayName = "Зеленый";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Green_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Green_co.paa"
			};
		}; 
		class Yellow : BaseTexture { 
			displayName = "Желтый";
			textures[] = { 
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Yellow_co.paa",
				"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Yellow_co.paa"
			};
		}; 
	};
};

class C_Rubberboat : Base {
	description = "Надувная лодка, часто называемая 'резиновой уточкой', легкая лодка, изготовленная из трубок с сжатым газом.";
	buyPrice = 4150;
	virtualSpace = 50;
};

class C_Boat_Civil_01_F : Base {
	description = "Роскошная моторная лодка с одним двигателем, используемая полицией и самыми богатыми жителями Альтиса.";
	buyPrice = 153200;
	virtualSpace = 75;
	class Textures {
		class Civilian : BaseTexture {}; 
		class Police : PoliceTexture { textures[] = { "\dataM\Textures\Vehicles\Sea\Police\motorboat.paa" }; };
		class Medic : MedicTexture { textures[] = { "\dataM\Textures\Vehicles\Sea\Medic\motorboat.paa" }; };
	};
};
class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

class C_Boat_Transport_02_F : Base {
	description = "Быстрый надувной катер для специальных операций и перевозки команды восьми человек и трех членов экипажа.";
	buyPrice = 297600;
	virtualSpace = 150;
	class Textures {
		class Civilian : BaseTexture {}; 
		class Police : PoliceTexture {
			textures[] = { 
				"\dataM\Textures\Vehicles\Sea\Police\RHIB_01.paa",
				"\dataM\Textures\Vehicles\Sea\Police\RHIB_02.paa"
			}; 
		};
	};
};

class B_Boat_Armed_01_minigun_F : Base {
	description = "Эта лодка отличается скоростью и маневренностью и используется для охраны береговой линии и специальных операций.";
	buyPrice = 14360500;
	virtualSpace = 80;
	garageLimit = 1;
	repairTime = 15;
	crushTime = 30;
	chopKeepChance = 85;
	chopTime = 120;
	turrets[] = { { "GMG_40mm" } };
	class Textures {
		class Police : PoliceTexture {
			textures[] = { 
				"\dataM\Textures\Vehicles\Sea\Police\speedboat_01.paa", 
				"\dataM\Textures\Vehicles\Sea\Police\speedboat_02.paa"
			};
		};
	};
};

class B_SDV_01_F : Base {
	description = "SDV - это пилотируемое подводное средство, используемое для транспортировки команды дайверов на длинные расстояния под водой с помощью собственного оборудования для дайвинга.";
	buyPrice = 389500;
	virtualSpace = 5;
};

// Вертолеты
class B_UAV_01_F : Base {
	description = "Darter AR-2 - это миниатюрный дистанционно управляемый квадрокоптер, идеально подходящий для разведки и наблюдения.";
	buyPrice = 98700;
	virtualSpace = 0;
};
class C_UAV_06_medical_F : B_UAV_01_F {
	description = "Этот коммерческий грузовой беспилотник использует 6 роторов для транспортировки небольших грузов во внешнем грузовом отсеке.";
	buyPrice = 109700;
};

class C_Heli_Light_01_civil_F : Base {
	description = "Легкий однодвигательный вертолет, используемый спецназом армии США с времен Вьетнамской войны.";
	buyPrice = 565000;
	virtualSpace = 5;
	garageLimit = 2;
	blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
	class Textures {
		class Police : PoliceTexture { textures[] = { "\dataM\Textures\Vehicles\Air\Police\hummingbird.paa" }; };
		class Medic : MedicTexture { textures[] = { "\dataM\Textures\Vehicles\Air\Medic\hummingbird.paa" }; };
		class TotalRed : BaseTexture {
			displayName = "Полностью красный"; 
				factions[] = { "Civilian", "Police" };
			textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa" }; 
		};
			class TotalBlue : TotalRed { 
				displayName = "Total Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa" };
			}; 
			class Sheriff : TotalRed { 
				displayName = "Sheriff";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa" };
			}; 
			class Blueline : TotalRed { 
				displayName = "Blueline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa" };
			}; 
			class Elliptical : TotalRed { 
				displayName = "Elliptical";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa" };
			}; 
			class Furious : TotalRed { 
				displayName = "Furious";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa" };
			}; 
			class JeansBlue : TotalRed { 
				displayName = "Jeans Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa" };
			}; 
			class SpeedyRedline : TotalRed { 
				displayName = "Speedy Redline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa" };
			}; 
			class Sunset : TotalRed { 
				displayName = "Sunset";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa" };
			}; 
			class Vrana : TotalRed { 
				displayName = "Vrana";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa" };
			}; 
			class WavesBlue : TotalRed { 
				displayName = "Waves Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" };
			}; 
			class Shadow : TotalRed { 
				displayName = "Shadow";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_shadow_co.paa" };
			}; 
			class GrayWatcher : TotalRed { 
				displayName = "Gray Watcher";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_graywatcher_co.paa" };
			}; 
			class Wasp : TotalRed { 
				displayName = "Wasp";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa" };
			}; 
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
	};
};
class B_Heli_Light_01_F : C_Heli_Light_01_civil_F { buyPrice = 780000; };

class O_Heli_Light_02_unarmed_F : Base {
    description = "ПО-30 Орка - транспортный и утилитарный вертолет, в первую очередь разработанный для Российской авиации.";
    buyPrice = 2350000;
    virtualSpace = 25;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    turrets[] = { { "CMFlareLauncher" } };
    class Textures {
        class Police : PoliceTexture { textures[] = { "\dataM\Textures\Vehicles\Air\Police\orca.paa" }; };
        class Medic : MedicTexture { textures[] = { "\dataM\Textures\Vehicles\Air\Medic\orca.paa" }; };
        class Black : BaseTexture {
            displayName = "Черный"; 
            textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_CO.paa" }; 
        };
        class BlackWhite : BaseTexture {
            displayName = "Черно-белый"; 
            textures[] = { "\a3\air_f_heli\heli_light_02\data\heli_light_02_ext_opfor_v2_co.paa" }; 
        };
        class WhiteBlue : BaseTexture { 
            displayName = "Бело-синий";
            textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
        }; 
    };
};

class I_Heli_light_03_unarmed_F : Base {
    description = "WY-55 Hellcat - многоцелевой вертолет, наиболее подходящий для транспорта и ограниченных транспортных задач.";
    buyPrice = 2130000;
    virtualSpace = 20;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    turrets[] = { { "CMFlareLauncher" } };
    class Textures {
        class Police : PoliceTexture {
            textures[] = { "\dataM\Textures\Vehicles\Air\Police\hellcat.paa" };
            turrets[] = { { "missiles_DAR", "CMFlareLauncher" } };
        };
        class Black : BaseTexture {
            displayName = "Черный"; 
            textures[] = { "#(rgb,8,8,3)color(0.03,0.03,0.03,1)" }; 
        };
        class Green : BaseTexture {
            displayName = "Зеленый"; 
            textures[] = { "\a3\air_f_epb\Heli_Light_03\data\Heli_Light_03_base_CO.paa" }; 
        };
    };
};
class I_Heli_light_03_F : I_Heli_light_03_unarmed_F {
    buyPrice = 23450000;
    turrets[] = { { "M134_minigun", "missiles_DAR", "CMFlareLauncher" } };
};

class B_Heli_Transport_01_F : Base {
    description = "UH-80 Ghost Hawk - средний утилитарный вертолет со стелс-дизайном.";
    buyPrice = 19450000;
    virtualSpace = 30;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    turrets[] = { { "LMG_Minigun_Transport", "LMG_Minigun_Transport2", "CMFlareLauncher" } };
    class Textures {
        class Police : PoliceTexture { turrets[] = { { "CMFlareLauncher" } }; };
        class Civilian : BaseTexture {};
    };
};

class I_Heli_Transport_02_F : Base {
    description = "CH-49 Mohawk - преемник широко распространенного вертолета Мерлин, предназначенный в первую очередь для транспорта с различными вариациями, эффективно выполняющий задачи эвакуации, антисубмаринной войны или вооруженной воздушной поддержки.";
    buyPrice = 13240000;
    virtualSpace = 55;
    garageLimit = 1;
    chopKeepChance = 85;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    turrets[] = { { "CMFlareLauncher" } };
    class Textures {
        class Medic : MedicTexture {
            textures[] = { 
                "\dataM\Textures\Vehicles\Air\Medic\mohawk_01.paa",
                "\dataM\Textures\Vehicles\Air\Medic\mohawk_02.paa",
                "\dataM\Textures\Vehicles\Air\Medic\mohawk_03.paa"
            }; 
        };
        class Ion : BaseTexture {
            displayName = "Ион"; 
            textures[] = { 
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_ion_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_ion_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_ion_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
             }; 
        };
        class Dahoman : BaseTexture {
            displayName = "Дахоман"; 
            textures[] = { 
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_dahoman_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_dahoman_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_dahoman_co.paa",
                "\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa" 
            }; 
        };
    };
};
class C_IDAP_Heli_Transport_02_F : I_Heli_Transport_02_F {
    class Textures {
        class IDAP : BaseTexture {
            displayName = "IDAP"; 
            textures[] = { 
                "\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_1_IDAP_CO.paa",
                "\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_2_IDAP_CO.paa",
                "\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_3_IDAP_CO.paa",
                "\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_int_02_IDAP_CO.paa" 
            }; 
        };
    };
};

class O_Heli_Transport_04_black_F : Base {
    description = "Mi-290 Taru - тяжелый утилитарный вертолет с коаксиальными роторами и уникальной модульной конструкцией. Различные модули позволяют Taru выполнять различные задачи.";
    buyPrice = 11350000;
    virtualSpace = 0;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    chopKeepChance = 85;
    chopPerc = 0.20;
    chopTime = 60;
    turrets[] = { { "CMFlareLauncher" } };
};
class O_Heli_Transport_04_bench_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 11176500;
    virtualSpace = 0;
};
class O_Heli_Transport_04_covered_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 12670000;
    virtualSpace = 35;
};
class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 28900500;
    virtualSpace = 70;
};
class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 29460000;
    virtualSpace = 80;
};
class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 13640000;
    virtualSpace = 50;
};
class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_black_F {
    buyPrice = 11983000;
    virtualSpace = 40;
    class Textures {
        class Medic : MedicTexture {
            textures[] = { 
                "\dataM\Textures\Vehicles\Air\Medic\taru_01.paa", 
                "\dataM\Textures\Vehicles\Air\Medic\taru_02.paa", 
                "\dataM\Textures\Vehicles\Air\Medic\taru_03.paa", 
                "\dataM\Textures\Vehicles\Air\Medic\taru_04.paa"
            }; 
        };
    };
};

class B_Heli_Transport_03_unarmed_F : Base {
    description = "Тяжелый вертолет с двумя двигателями и тандемным ротором. Его основная задача - транспортировка войск, техники и грузов.";
    buyPrice = 33400750;
    virtualSpace = 100;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    chopKeepChance = 95;
    chopPerc = 0.20;
    chopTime = 300;
    turrets[] = { { "CMFlareLauncher" } };
    class Textures {
        class Black : BaseTexture {
            displayName = "Черный"; 
            factions[] = { "Civilian", "Police" };
            textures[] = { 
                "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_black_co.paa",
                "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
            }; 
        };
        class Olive : BaseTexture {
            displayName = "Оливковый"; 
            textures[] = { 
                "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
                "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
            }; 
        };
    };
};

class B_Heli_Attack_01_F : Base {
    description = "Двухместный разведывательный и целеуказательный вертолет, используемый для поиска целей для боевых вертолетов.";
    buyPrice = 146560000;
    virtualSpace = 0;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    chopKeepChance = 97;
    chopPerc = 0.20;
    chopTime = 600;
    turrets[] = { { "CMFlareLauncher", "gatling_20mm", "missiles_DAGR", "missiles_ASRAAM" } };
};
class O_Heli_Attack_02_F : B_Heli_Attack_01_F {
    description = "Многоцелевой преемник Ми-24, Ми-48 Кайман (прозвище 'Шершень') - крупный боевой вертолет с возможностью перевозки 8 пассажиров";
    buyPrice = 212340000;
    virtualSpace = 30;
    turrets[] = { { "CMFlareLauncher", "gatling_30mm", "missiles_SCALPEL", "rockets_Skyfire", "Laserdesignator_mounted" } };
};

// САМОЛЕТЫ --------------------------------------------------------------------------------------
class C_Plane_Civil_01_F : Base {
    description = "Самолет Caesar BTT - один из самых быстрых маломестных самолетов с фиксированным шасси и одним двигателем, способный развивать скорость до 235 узлов (435 км/ч) на высоте 25 000 футов (7 600 м).";
    buyPrice = 1256000;
    virtualSpace = 5;
    garageLimit = 2;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
};
class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};

class B_T_VTOL_01_infantry_F : Base {
    description = "V-44X Blackfish с технологией VTOL третьего поколения позволяет этому долгосрочному летательному аппарату удобно использовать широкий спектр аэродромов и взлетно-посадочных полос.";
    buyPrice = 75500000;
    virtualSpace = 175;
    garageLimit = 1;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    retrievalPerc = 0.01;
    chopKeepChance = 95;
    chopPerc = 0.15;
    chopTime = 180;
    turrets[] = { { "CMFlareLauncher_Triples" } };
};
class B_T_VTOL_01_vehicle_F : B_T_VTOL_01_infantry_F {
    buyPrice = 85750000;
    virtualSpace = 225;
};

class O_T_VTOL_02_infantry_F : B_T_VTOL_01_infantry_F {
    description = "Самый перспективный прототип, разработанный инженерами CSAT, представляет собой крайне передовой дизайн с множеством уникальных характеристик и передовых технологий.";
    buyPrice = 115650000;
    virtualSpace = 80;
    blacklistedItems[] = { "StolenCargo", "FreightCargo", "UnmarkedGold", "MarkedGold", "UraniumOre", "UraniumBar", "EphedrineBarrel" };
    turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
};
class O_T_VTOL_02_vehicle_F : O_T_VTOL_02_infantry_F {
    buyPrice = 125530000;
    virtualSpace = 95;
    turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
};

class I_Plane_Fighter_03_CAS_F : Base {
    description = "A-143 Buzzard - одноместный, легкий, универсальный боевой самолет, способный нести широкий ассортимент вооружения.";
    buyPrice = 73350000;
    virtualSpace = 0;
    garageLimit = 1;
    retrievalPerc = 0.01;
    chopKeepChance = 99;
    chopPerc = 0.10;
    chopTime = 300;
    turrets[] = { { "CMFlareLauncher", "Twin_Cannon_20mm", "missiles_SCALPEL", "missiles_ASRAAM", "GBU12BombLauncher_Plane_Fighter_03_F" } };
};
class I_Plane_Fighter_04_F : I_Plane_Fighter_03_CAS_F { 
    description = "A-149 Gryphon - четвертого поколения, одноместный, однодвигательный, всепогодный тактический истребитель.";
    buyPrice = 75500000; 
    turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
};
class B_Plane_CAS_01_F : I_Plane_Fighter_03_CAS_F { 
    description = "A-164 Wipeout - одноместный самолет, используемый для ближней авиационной поддержки и воздушного вмешательства.";
    buyPrice = 90500000; 
    turrets[] = { { "CMFlareLauncher", "Gatling_30mm_Plane_CAS_01_F", "Missile_AA_04_Plane_CAS_01_F", "Missile_AGM_02_Plane_CAS_01_F", "Rocket_04_HE_Plane_CAS_01_F", "Rocket_04_AP_Plane_CAS_01_F", "Bomb_04_Plane_CAS_01_F" } };
};
class B_Plane_Fighter_01_F : I_Plane_Fighter_03_CAS_F { 
    description = "F/A-181 Black Wasp II - истребитель пятого поколения с одним местом, двумя двигателями и всепогодными характеристиками.";
    buyPrice = 105500000; 
    turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
};
class B_Plane_Fighter_01_Stealth_F : B_Plane_Fighter_01_F { 
    buyPrice = 115600000; 
    turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
};
class O_Plane_CAS_02_F : I_Plane_Fighter_03_CAS_F { 
    description = "To-199 Neophron - новое пополнение в авиации CSAT. Легкий одноместный самолет для ближней авиационной поддержки и борьбы с воздушными угрозами.";
    buyPrice = 86500000; 
    turrets[] = { { "CMFlareLauncher", "Cannon_30mm_Plane_CAS_02_F", "Missile_AA_03_Plane_CAS_02_F", "Missile_AGM_01_Plane_CAS_02_F", "Rocket_03_HE_Plane_CAS_02_F", "Rocket_03_AP_Plane_CAS_02_F", "Bomb_03_Plane_CAS_02_F" } };
};
class O_Plane_Fighter_02_F : I_Plane_Fighter_03_CAS_F { 
    description = "To-201 Shikra - истребитель пятого поколения с одним местом, двумя двигателями и всепогодными характеристиками.";
    buyPrice = 115500000;
    turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
};
class O_Plane_Fighter_02_Stealth_F : O_Plane_Fighter_02_F {
    buyPrice = 130500000; 
    turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
};
// КОНТЕЙНЕРЫ --------------------------------------------------------------------------------------
class B_Slingload_01_Cargo_F : Base {
    description = "";
    buyPrice = 0;
    virtualSpace = 250;
    garageLimit = 1;
};
class B_Slingload_01_Fuel_F : B_Slingload_01_Cargo_F {
    description = "";
    buyPrice = 0;
    virtualSpace = 100;
};

class Land_Pod_Heli_Transport_04_box_black_F : B_Slingload_01_Cargo_F {
    description = "";
    buyPrice = 0;
    virtualSpace = 125;
};
class Land_Pod_Heli_Transport_04_fuel_black_F : B_Slingload_01_Cargo_F {
    description = "";
    buyPrice = 0;
    virtualSpace = 50;
};

// ВРЕМЕННЫЕ --------------------------------------------------------------------------------------
class Land_Bodybag_01_black_F : Base {
    virtualSpace = 0;
    garageLimit = 0;
    tempStorage = true;
};

// ЖИЛЬЕ --------------------------------------------------------------------------------------
class Land_WoodenCrate_01_F : Base {
    virtualSpace = 500;
    garageLimit = 0;
    isHouse = true;
};
class Land_PlasticCase_01_large_gray_F : Land_WoodenCrate_01_F { virtualSpace = 1000; };
class CargoNet_01_box_F : Land_WoodenCrate_01_F { virtualSpace = 3000; };
class Land_Cargo20_white_F : Land_WoodenCrate_01_F { virtualSpace = 5000; };
class C_IDAP_supplyCrate_F : Land_WoodenCrate_01_F { virtualSpace = 8500; };
class Land_Cargo20_grey_F : Land_WoodenCrate_01_F { virtualSpace = 20000; };

class Land_CargoBox_V1_F : Land_Bodybag_01_black_F {
    requireItems = true;
};
class Land_PortableServer_01_black_F : Land_CargoBox_V1_F {};

// ЗВУКИ --------------------------------------------------------------------------------------
class Police_One {
    sound = "Police_One";
};

class Police_Two {
    sound = "Police_Two";
};

class Police_Three {
    sound = "Police_Three";
};
};
