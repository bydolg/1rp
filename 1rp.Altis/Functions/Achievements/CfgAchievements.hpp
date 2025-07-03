class CfgAchievements {
	class FirstSpawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "Первые шаги";
		description = "Впервые заспавнился.";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Впервые выпил
	class FirstDrink {
		icon = "\dataM\UI\Achievements\firstDrink.paa";
		displayName = "Большой глоток";
		description = "Выпил свой первый алкогольный напиток.";
		onUnlocked = "[""FirstDrink""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Впервые опробовал наркотики
	class FirstDrug {
		icon = "\dataM\UI\Achievements\firstDrug.paa";
		displayName = "Наркоман";
		description = "Пережил свой первый опыт с наркотиками.";
		onUnlocked = "[""FirstDrug""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Получил алмаз
	class GirlsBestFriend {
		icon = "\dataM\UI\Achievements\girlsBestFriend.paa";
		displayName = "Лучший друг девушки";
		description = "Получил тщательно отточенный алмаз.";
		onUnlocked = "[""GirlsBestFriend""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Переносил много соли
	class Salty {
		icon = "\dataM\UI\Achievements\salty.paa";
		displayName = "Чрезвычайно соленый";
		description = "Держал огромное количество соли при себе.";
		onUnlocked = "[""Salty""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Посетил командный мостик корабля
	class Captain {
		icon = "\dataM\UI\Achievements\captain.paa";
		displayName = "Капитан корабля";
		description = "Посетил командный мостик корабля HMS Liberty.";
		onUnlocked = "[""Captain""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Провел археологическую раскопку
	class Archaeologist {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Waypoint_ca.paa";
		displayName = "Археолог";
		description = "Провел свою первую археологическую раскопку.";
		onUnlocked = "[""Archaeologist""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Присоединился к восстанию
	class JoinRebel {
		icon = "\dataM\UI\Achievements\rebel.paa";
		displayName = "Восстание";
		description = "Присоединился к восстанию. Надежда.";
		onUnlocked = "[""JoinRebel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Присоединился к группе
	class JoinGroup {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Член группы";
		description = "Присоединился к группе в первый раз.";
		leveling[] = { 50, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Присоединился к команде персонала
	class JoinStaff {
		icon = "\dataM\UI\Achievements\staff.paa";
		displayName = "Команда персонала";
		description = "Вы присоединились к команде персонала сообщества.";
		onUnlocked = "[""JoinStaff""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Достижение разблокировано", 100 };
		isMystery = false;
	};

	// Присоединился к полиции Альтис
	class JoinAPC {
		icon = "\dataM\UI\Achievements\APC.paa";
		displayName = "Констебль";
		description = "Присоединился к полиции.";
		leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinCOL {
    icon = "\dataM\UI\Achievements\COL.paa";
    displayName = "Инструктор колледжа полиции";
    description = "Присоединился к колледжу полиции.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinNPAS {
    icon = "\dataM\UI\Achievements\NPAS.paa";
    displayName = "Пилот полиции";
    description = "Присоединился к службе воздушной поддержки полиции.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinSCO19 {
    icon = "\dataM\UI\Achievements\SCO.paa";
    displayName = "Офицер по стрелковому оружию";
    description = "Присоединился к SCO19 (специальный отряд по стрелковому оружию).";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinNCA {
    icon = "\dataM\UI\Achievements\NCA.paa";
    displayName = "Офицер разведки";
    description = "Присоединился к Национальному агентству по преступлениям.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinMPU {
    icon = "\dataM\UI\Achievements\MPU.paa";
    displayName = "Морской полицейский";
    description = "Присоединился к морской полиции.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinRPU {
    icon = "\dataM\UI\Achievements\RPU.paa";
    displayName = "Специалист по преследованию";
    description = "Присоединился к полиции по преследованию.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinSFO {
    icon = "\dataM\UI\Achievements\SFO.paa";
    displayName = "Запутанный AFO";
    description = "Прошел обучение как полицейский по специальному вооружению и обучению.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinUC {
    icon = "\dataM\UI\Achievements\UC.paa";
    displayName = "Тайный сержант";
    description = "Прошел обучение как тайный полицейский.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class FirstTicket {
    icon = "\dataM\UI\Achievements\firstTicket.paa";
    displayName = "Инспектор по штрафам";
    description = "Выписал предупреждение об уплате штрафа индивиду.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class FirstArrest {
    icon = "\dataM\UI\Achievements\firstArrest.paa";
    displayName = "Законопослушный";
    description = "Приговорил индивида к тюремному заключению.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinNHS {
    icon = "\dataM\UI\Achievements\NHS.paa";
    displayName = "Парамедик";
    description = "Присоединился к службе скорой помощи.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinHR {
    icon = "\dataM\UI\Achievements\HR.paa";
    displayName = "Офисный работник";
    description = "Присоединился к отделу кадров Национальной службы здравоохранения.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinAA {
    icon = "\dataM\UI\Achievements\AA.paa";
    displayName = "Спаситель в воздухе";
    description = "Присоединился к авиационной службе скорой помощи.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class LifeSaver {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
    displayName = "Спаситель жизни";
    description = "Успешно возродил другого человека.";
    onUnlocked = "[""LifeSaver""] call ULP_fnc_unlockTitle;";
    leveling[] = { 350, "Достижение разблокировано", 100 };
    isMystery = false;
};

class JoinHATO {
    icon = "\dataM\UI\Achievements\HATO.paa";
    displayName = "Дорожный полицейский";
    description = "Присоединился к Агентству по скоростным дорогам.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class FirstImpound {
    icon = "\dataM\UI\Achievements\firstImpound.paa";
    displayName = "Уборщик улиц";
    description = "Впервые арестовал транспортное средство.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class FirstCrush {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Use_ca.paa";
    displayName = "Ликвидатор автомобилей";
    description = "Первый раз уничтожил/переработал автомобиль.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class Governor {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
    displayName = "Губернатор";
    description = "Выиграйте выборы и станьте губернатором.";
    onUnlocked = "[""Governor""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = false;
};

class Employment {
    icon = "\dataM\UI\Achievements\employment.paa";
    displayName = "Трудоустройство";
    description = "Успешно устроился на работу.";
    onUnlocked = "[""Employment""] call ULP_fnc_unlockTitle;";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class Convict {
    icon = "\dataM\UI\Achievements\convict.paa";
    displayName = "Преступник";
    description = "Был отправлен в тюрьму полицейским.";
    onUnlocked = "[""Convict""] call ULP_fnc_unlockTitle;";
    leveling[] = { 10, "Достижение разблокировано", 100 };
    isMystery = false;
};

class SuccessfulRobber {
    icon = "\dataM\UI\Achievements\successfulRobber.paa";
    displayName = "Успешный грабитель";
    description = "Успешно провел ограбление на объекте.";
    onUnlocked = "[""SuccessfulRobber""] call ULP_fnc_unlockTitle;";
    leveling[] = { 10, "Достижение разблокировано", 100 };
    isMystery = false;
};

class TaskMaster {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
    displayName = "Мастер по заданиям";
    description = "Впервые выполнил задание.";
    onUnlocked = "[""TaskMaster""] call ULP_fnc_unlockTitle;";
    leveling[] = { 75, "Достижение разблокировано", 100 };
    isMystery = false;
};

class CartelLord {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
    displayName = "Лорд картеля";
    description = "Успешно получил выплату от картеля.";
    onUnlocked = "[""Cartel""] call ULP_fnc_unlockTitle;";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class BuyVehicle {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Driving_ca.paa";
    displayName = "Первая поездка";
    description = "Купил свое первое транспортное средство.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class BuyHouse {
    icon = "\dataM\UI\Achievements\house.paa";
    displayName = "Первый дом";
    description = "Купил свой первый дом.";
    leveling[] = { 50, "Достижение разблокировано", 100 };
    isMystery = false;
};

class BuyWarehouse {
    icon = "\dataM\UI\Achievements\warehouse.paa";
    displayName = "Первый склад";
    description = "Купил свой первый склад.";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class OneMillion {
    icon = "\dataM\UI\Achievements\money1.paa";
    displayName = "$1,000,000";
    description = "Имел на счету общую сумму $1,000,000.";
    onUnlocked = "[""OneMillion""] call ULP_fnc_unlockTitle;";
    leveling[] = { 100, "Достижение разблокировано", 100 };
    isMystery = false;
};

class TenMillion {
    icon = "\dataM\UI\Achievements\money10.paa";
    displayName = "$10,000,000";
    description = "Имел на счету общую сумму $10,000,000.";
    leveling[] = { 200, "Достижение разблокировано", 100 };
    isMystery = false;
};

class HundredMillion {
    icon = "\dataM\UI\Achievements\money100.paa";
    displayName = "$100,000,000";
    description = "Имел на счету общую сумму $100,000,000.";
    leveling[] = { 300, "Достижение разблокировано", 100 };
    isMystery = false;
};

// MYSTERY ---------------------------------------------------------
class Barrel {
    icon = "\dataM\UI\Achievements\barrel.paa";
    displayName = "Бочка";
    description = "Нашел таинственную скрытую бочку.";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Prestige {
    icon = "\dataM\UI\Achievements\prestige.paa";
    displayName = "Престиж";
    description = "Впервые увеличил престиж.";
    onUnlocked = "[""Prestige""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

// TODO
class FanGirl {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\PilotingQuadrotor_ca.paa";
    displayName = "Поклонница";
    description = "Вы обнаружили удовольствие в Belle Delphine.";
    onUnlocked = "[""FanGirl""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Uncharted {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Map_ca.paa";
    displayName = "Исследователь";
    description = "Вы решили покинуть этот остров, но вернулись.";
    onUnlocked = "[""Uncharted""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Radiation {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
    displayName = "Прощай, отцовство";
    description = "Почувствовали последствия облучения.";
    onUnlocked = "[""Radiation""] call ULP_fnc_unlockTitle;";
    leveling[] = { 200, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Protest {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Voice_ca.paa";
    displayName = "Протестующий";
    description = "Вы довели обычный протест до крайней степени...";
    onUnlocked = "[""Protest""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class MileHighClub {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\TakeOff_ca.paa";
    displayName = "Клуб миля высоты";
    description = "Вы летели на высоте ровно 1 мили или выше.";
    onUnlocked = "[""MileHighClub""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class DeepSeaDiver {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicDive_ca.paa";
    displayName = "Дайвер глубоких вод";
    description = "Вы ходили по дну моря.";
    onUnlocked = "[""DeepSeaDiver""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class DeathWish {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Targets_ca.paa";
    displayName = "Смертельное желание";
    description = "Вы путешествовали в самое сердце красной зоны.";
    onUnlocked = "[""DeathWish""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class NLRPC {
    icon = "\dataM\UI\Achievements\nlrpc.paa";
    displayName = "NLRPC";
    description = "Вы обнаружили остаток Северного Лондона.";
    onUnlocked = "[""NLRPC""] call ULP_fnc_unlockTitle;";
    leveling[] = { 500, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Stonehenge {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Direction_ca.paa";
    displayName = "Стоунхендж";
    description = "Вы обнаружили Стоунхендж.";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Sub {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\SDV_ca.paa";
    displayName = "Подводная лодка";
    description = "Вы ходили по палубе HMS Proteus.";
    onUnlocked = "[""Sub""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class PirateDen {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Death_ca.paa";
    displayName = "Пиратское убежище";
    description = "Вы обнаружили Пиратское убежище.";
    onUnlocked = "[""PirateDen""] call ULP_fnc_unlockTitle;";
    leveling[] = { 2000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Atlantis {
    icon = "\dataM\UI\Achievements\atlantis.paa";
    displayName = "Атлантида";
    description = "Вы обнаружили Атлантиду.";
    onUnlocked = "[""Atlantis""] call ULP_fnc_unlockTitle;";
    leveling[] = { 3000, "Достижение разблокировано", 100 };
    isMystery = true;
};

// ЛИЧНЫЕ ДОСТИЖЕНИЯ
class Scarso {
    icon = "\dataM\UI\Achievements\scarso.paa";
    displayName = "Рабочее пространство";
    description = "Вы обнаружили рабочее пространство админа.";
    onUnlocked = "[""Scarso""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Lewis {
    icon = "\dataM\UI\Achievements\lewis.paa";
    displayName = "Bushmaker";
    description = "Вы поднялись на статую Льюиса 'Bushmaker' Холлоуэя.";
    onUnlocked = "[""Lewis""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Oliver {
    icon = "\dataM\UI\Achievements\oliver.paa";
    displayName = "Националист";
    description = "Вы посетили метропольный центр Севера. Дом Оливера Лоусона.";
    onUnlocked = "[""Oliver""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Ace {
    icon = "\dataM\UI\Achievements\ace.paa";
    displayName = "Норвежский отступ";
    description = "Вы обнаружили скрытый отступ Эйса Бойдена.";
    onUnlocked = "[""Ace""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Jetan {
    icon = "\dataM\UI\Achievements\jetan.paa";
    displayName = "Лодка Бой";
    description = "Вы сели на дом Jetan Holo.";
    onUnlocked = "[""Jetan""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Brick {
    icon = "\dataM\UI\Perks\firstAider.paa";
    displayName = "Больница Брик";
    description = "Вы нашли второй дом Брик Хауса.";
    onUnlocked = "[""Brick""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class James {
    icon = "\dataM\UI\Perks\improvedMetabolism.paa";
    displayName = "Uber Eats Лодка";
    description = "Вы выявили ежедневную доставку еды Джеймса Джонсона.";
    onUnlocked = "[""James""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Fulton {
    icon = "\dataM\UI\GroupBuffs\hacking.paa";
    displayName = "ОДИН НОЛЬ АЛЬФА НОЯБРЬ";
    description = "Вы посмотрели на ЦПУ Фултона.";
    onUnlocked = "[""Fulton""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};

class Freddie {
    icon = "\dataM\UI\Perks\muscleman.paa";
    displayName = "Обвалка курицы";
    description = "Вы стали свидетелем последствий обвалки Фредди цыпленка.";
    onUnlocked = "[""Freddie""] call ULP_fnc_unlockTitle;";
    leveling[] = { 1000, "Достижение разблокировано", 100 };
    isMystery = true;
};
};
