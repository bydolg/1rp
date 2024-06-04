class CfgGroups {
    tax[] = { 0, 25 };

    class Tag {
        MinLength = 1;
        MaxLength = 5;
        Blacklisted[] = { "APC", "APS", "NHS", "AAS", "HATO" };
    };

    class Name {
        MinLength = 6;
        MaxLength = 30;
        Blacklisted[] = { "Altis Police Contabulary", "Altis Police Service", "Altis Police", "National Health Service", "Altis Ambulance Service", "Highways Agency", "Civilian" };
    };

    ranks[] = {
        "PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"
    };

    class Permissions {
        deposit = 3;
        withdraw = 3;
        rank = 4;
        invite = 4;
        kick = 4;
    };

    class Types {
        class Criminal {
            displayName = "Criminal";

            class Perks {
                class Hideout {
                    displayName = "Захват укрытия";
                    icon = "\dataM\UI\GroupPerks\hideout.paa";
                    description = "У вас есть возможность захвата укрытий банды.";
                    level = 1;
                };

                class Blackmarket {
                    displayName = "Черный рынок";
                    icon = "\dataM\UI\GroupPerks\blackmarket.paa";
                    description = "У вас есть доступ к Черному рынку.";
                    level = 2;
                };

                class Ifrits {
                    displayName = "Водители Ifrit";
                    icon = "\dataM\UI\GroupPerks\ifrits.paa";
                    description = "У вас есть доступ к Ifrits в Черном рынке.";
                    level = 3;
                };

                class Governor {
                    displayName = "Губернаторство";
                    icon = "\dataM\UI\GroupPerks\governor.paa";
                    description = "Ваши члены могут баллотироваться на пост губернатора.";
                    level = 4;
                };

                class DMT {
                    displayName = "Собственность DMT";
                    icon = "\dataM\UI\GroupPerks\DMT.paa";
                    description = "Ваши члены могут приобрести DMT.";
                    level = 5;
                };
            };
        };

        class Corporate {
            displayName = "Компания";

            class Perks {
                class Freight {
                    displayName = "Грузовые миссии";
                    icon = "\dataM\UI\GroupPerks\freight.paa";
                    description = "Предоставляет вашим членам доступ к грузовым миссиям.";
                    level = 1;
                };

                class HEMTTs {
                    displayName = "Грузовики HEMTT";
                    icon = "\dataM\UI\GroupPerks\HEMTTs.paa";
                    description = "Предоставляет вашим членам доступ ко всем вариантам грузовиков HEMTT.";
                    level = 2;
                };

                class Governor {
                    displayName = "Губернаторство";
                    icon = "\dataM\UI\GroupPerks\governor.paa";
                    description = "Ваши члены могут баллотироваться на пост губернатора.";
                    level = 3;
                };

                class SecurityContactors {
                    displayName = "Охранники-контракторы";
                    icon = "\dataM\UI\GroupPerks\securityContactors.paa";
                    description = "Предоставляет вашим членам доступ к становлению охранниками внутри вашей компании.";
                    level = 4;
                };

                class MilitaryOffices {
                    displayName = "Собственность офисов";
                    icon = "\dataM\UI\GroupPerks\officeBuilding.paa";
                    description = "Ваши члены могут приобрести заброшенное военное здание.";
                    level = 5;
                };
            };
        };

        class Party {
            displayName = "Политическая партия";

            class Perks {
                class Governor {
                    displayName = "Губернаторство";
                    icon = "\dataM\UI\GroupPerks\governor.paa";
                    description = "Ваши члены могут баллотироваться на пост губернатора.";
					level = 1;
				};

				class PersonalProtection {
					displayName = "Телохранители";
					icon = "\dataM\UI\GroupPerks\personalProtection.paa";
					description = "Члены группы могут иметь телохранителей.";
					level = 2;
				};

				class GovernmentSafehouses {
					displayName = "Провительственный бункер";
					icon = "\dataM\UI\GroupPerks\governmentSafehouses.paa";
					description = "Члены группы имеют доступ к правительственному бункеру.";
					level = 3;
				};

				class OfficeBuilding {
					displayName = "Личный офис";
					icon = "\dataM\UI\GroupPerks\officeBuilding.paa";
					description = "Члены группы могут покупать здания под личные офисы.";
					level = 4;
				};

				class PollRigging {
					displayName = "Poll Rigging";
					icon = "\dataM\UI\GroupPerks\pollRigging.paa";
					description = "Your members have the ability to rig polling boothes.";
					level = 5;
				};
			};
		};
	};

	class Leveling {
		baseXp = 2500;
		xpMultiplier = 1.35;
		maxLevel = 5;

		class XP {
			class Cartel { amount = 10; };
			class Popup : Cartel {};
			class Airdrop : Cartel {};
			class Shipwreck : Cartel {};
			class Freight { amount = 10; };
			class Election { amount = 500; }; // TODONOW
			class Rigging { amount = 35; };
			class Hideout : Cartel {};
			class BaseBid : Election {}; // TODONOW
			class Contraband : Freight {}; // TODONOW
			class CommunityGoals : Freight {}; // TODO
			class MedicalAid { amount = 3; };
			class Robbery : Freight {};
		};
	};

	class Buffs {
		class Missions {
			displayName = "Увеличены выплаты в миссиях";
			icon = "\dataM\UI\GroupBuffs\missions.paa";
			max = 0.25;
		};
		class Lockpicking : Missions {
			displayName = "Увеличена скорость работы с инструментом";
			icon = "\dataM\UI\GroupBuffs\lockpicking.paa";
		};
		class Boltcutting : Missions {
			displayName = "Увеличена скорость болтореза";
			icon = "\dataM\UI\GroupBuffs\boltcutting.paa";
		};
		class Hacking : Missions {
			displayName = "Увеличена скорость взлома";
			icon = "\dataM\UI\GroupBuffs\hacking.paa";
		};
		class Surveying : Missions {
			displayName = "Увеличена выживаемость";
			icon = "\dataM\UI\GroupBuffs\surveying.paa";
		};
		class Digging : Missions {
			displayName = "Увеличена скорость раскопок";
			icon = "\dataM\UI\GroupBuffs\digging.paa";
		};
	};
};
