class CfgWarrants {
    NoteLength = 128;
    
    class CommonLaw {
        displayName = "Общее право";
        
        class EscapeEscort {
            displayName = "Побег из закрытого учреждения или защищенной эскортировки";
            allowManual = true;
            bounty = 200000;
        };
        class PervertingJustice : EscapeEscort {
            displayName = "Искажение хода правосудия";
            bounty = 50000;
        };
    };

    class AccessoriesAndAbettors {
        displayName = "Закон о соучастниках и пособниках 1861 года";

        class AidingAndAbetting {
            displayName = "Помощь и пособничество";
            allowManual = true;
            bounty = 75000;
        };
    };

    class PublicOrder {
        displayName = "Закон об общественном порядке 1986 года";

        class Section1 {
            displayName = "Беспорядки";
            allowManual = true;
            bounty = 75000;
        };
        class Section2 : Section1 {
            displayName = "Нарушение общественного порядка";
            bounty = 80000;
        };
        class Section4 : Section1 {
            displayName = "Угроза или провокация насилия";
            bounty = 55000;
        };
    };

    class Treason {
        displayName = "Закон о государственной измене 1351 года";

        class Treason { 
            displayName = "Государственная измена";
            allowManual = true;
            bounty = 200000; 
        };
    };

    class ProtectionFromHarassment {
        displayName = "Закон о защите от домогательств 1997 года";

        class Section2 {
            displayName = "Домогательство";
            allowManual = true;
            bounty = 25000;
        };
        class Section2A : Section2 {
            displayName = "Преследование";
            bounty = 30000;
        };
    };

    class Fraud {
        displayName = "Закон о мошенничестве 2006 года";

        class Section2 {
            displayName = "Ложное представление";
            allowManual = true;
            bounty = 40000;
        };
        class Section3 : Section2 {
            displayName = "Утаивание информации";
            bounty = 20000;
        };
        class Section4 : Section2 {
            displayName = "Злоупотребление положением";
            bounty = 75000;
        };
        class Section6 : Section2 {
            displayName = "Владение предметами, используемыми для мошенничества";
            bounty = 5000;
        };
    };

    class OffencesAgainstThePerson {
        displayName = "Закон о преступлениях против личности 1861 года";

        class Section1 { 
            displayName = "Убийство"; 
            allowManual = true;
            bounty = 200000;
        };
        class Section4 : Section1 {
            displayName = "Заговор или подстрекательство к убийству";
            bounty = 160000;
        };
        class Section5 : Section1 { displayName = "Умышленное убийство"; };
        class Section16 : Section1 { displayName = "Угрозы убийством"; };
        class Section18 : Section1 { displayName = "Стрельба или попытка стрельбы, или ранение с целью нанести вред"; };
        class Section20 : Section4 { displayName = "Причинение телесных повреждений с оружием или без него"; };
    };

    class CriminalAttempts {
        displayName = "Закон о преступных попытках 1981 года";

        class Section1 {
            displayName = "Попытка совершения преступления";
            allowManual = true;
            bounty = 30000;
        };
    };

    class Prison {
        displayName = "Закон о тюрьмах 1952 года";

        class AssistingEscape { 
            displayName = "Помощь заключенному в побеге"; 
            allowManual = true;
            bounty = 200000;
        };
        class SmugglingIntoPrison : AssistingEscape {
            displayName = "Контрабанда в тюрьму/из тюрьмы";
            bounty = 30000;
        };
    };

    class TakingOfHostages {
        displayName = "Закон о захвате заложников 1982 года";

        class HostageTaking { 
            displayName = "Захват заложников"; 
            allowManual = true;
            bounty = 200000;
        };
    };

    class Theft {
        displayName = "Закон о краже 1968 года";

        class Section7 {
            displayName = "Кража";
            allowManual = true;
            bounty = 20000;
        };
        class Section8 : Section7 {
            displayName = "Грабеж";
            bounty = 100000;
        };
        class Section9 : Section7 {
            displayName = "Кража со взломом";
            bounty = 70000;
        };
        class Section12 : Section7 {
            displayName = "Угон транспортного средства";
            bounty = 75000;
        };
        class Section25 : Section7 {
            displayName = "Подготовка к краже";
            bounty = 15000;
        };
    };

    class Firearms {
        displayName = "Закон о оружии 1968 года";

        class Section1 {
            displayName = "Покупка или владение оружием или боеприпасами без лицензии";
            allowManual = true;
            bounty = 45000;
        };
        class Section5 : Section1 {
            displayName = "Владение оружием, подлежащим общему запрету";
            bounty = 65000;
        };
        class Section18 : Section1 {
            displayName = "Перевозка оружия с преступным умыслом";
            bounty = 55000;
        };
        class Section19 : Section1 {
            displayName = "Перевозка оружия в общественном месте";
            bounty = 20000;
        };
        class Section21 : Section1 {
            displayName = "Незаконное снабжение оружием или боеприпасами";
            bounty = 45000;
        };
    };
class Terrorism {
    displayName = "Закон о терроризме 2000 года";

    class MembershipProscribed { 
        displayName = "Членство в запрещенной организации"; 
        allowManual = true;
        bounty = 200000;
    };
    class SupportProscribed : MembershipProscribed {
        displayName = "Поддержка запрещенной организации";
        bounty = 80000;
    };
};

class MisuseOfDrugs {
    displayName = "Закон о недобросовестном использовании наркотиков 1971 года";

    class Section4 {
        displayName = "Производство и поставка запрещенных веществ";
        allowManual = true;
        bounty = 150000;
    };
    class Section5 : Section4 {
        displayName = "Владение запрещенными веществами";
        bounty = 50000;
    };
};

class CivilAviation {
    displayName = "Закон о гражданской авиации 1982 года";

    class DangerousFlying {
        displayName = "Опасное воздушное движение";
        allowManual = true;
        bounty = 20000;
    };
    class ViolationOfNoiseControl : DangerousFlying {
        displayName = "Нарушение контроля над шумом";
        bounty = 15000;
    };
    class ViolationOfRestrictedSites : DangerousFlying {
        displayName = "Нарушение правил доступа к ограниченным зонам";
        bounty = 15000;
    };
};

class RoadTraffic {
    displayName = "Закон о дорожном движении 1988 года";

    class Section1 { 
        displayName = "Причинение смерти при опасном вождении";
        allowManual = true;
        bounty = 200000; 
    };
    class Section2 : Section1 {
        displayName = "Опасное вождение";
        bounty = 80000;
    };
    class Section3 : Section1 {
        displayName = "Беспечное и неосмотрительное вождение";
        bounty = 45000;
    };
    class Section4 : Section1 {
        displayName = "Вождение или нахождение в состоянии алкогольного или наркотического опьянения";
        bounty = 35000;
    };
    class Section34 : Section1 {
        displayName = "Вождение механических транспортных средств вне дорог.";
        bounty = 15000;
    };
    class Section35 : Section1 {
        displayName = "Обязанности водителей в соответствии с указаниями органов управления движением";
        bounty = 15000;
    };
    class Section87 : Section1 {
        displayName = "Вождение, несовместимое с лицензией";
        bounty = 20000;
    };
    class Section168 : Section1 {
        displayName = "Не предоставление/или предоставление ложных имени или адреса";
        bounty = 5000;
    };
    class Speeding : Section1 {
        displayName = "Превышение скорости";
        bounty = 15000;
    };
    class VehicleProhibition : Section1 {
        displayName = "Вождение/владение транспортным средством, подпадающим под общий запрет";
        bounty = 50000;
    };
};

class Other {
    displayName = "Другое";

    class Note {
        displayName = "Добавленная заметка";
        allowManual = true;
        bounty = 0; 
    };
};
};
