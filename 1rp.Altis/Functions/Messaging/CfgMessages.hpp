class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Личное сообщение";
		sendTo[] = { "Police", "Medic", "Hato", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false;
		alertSound = true;
		canReply = true;
		confirmSend = true;
		sender = "%1";
		targets = "";
		condition = "true";
	};

	class StaffMessage : Message {
		displayName = "от персонала";
		ignoreStreamer = true;
		ignoreComms = true;
		sender = "Staff Member";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess";
	};

	class Reply : Message {
		displayName = "Ответить";
		condition = "false";
	};

	class StaffDispatch : Message {
		picture = "\dataM\UI\Messaging\staffDispatch.paa";
		displayName = "команде персонала";
		ignoreStreamer = true;
		ignoreComms = true;
		targets = "(allPlayers select { [_x] call ULP_fnc_onDuty })";
	};

	class PoliceEmergencyDispatch : Message {
		picture = "\dataM\UI\Messaging\999.paa";
		displayName = "Вызов полиции";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class HealthEmergencyDispatch : PoliceEmergencyDispatch {
		displayName = "Вызов медиков";
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class NonEmergnecyDispatch : PoliceEmergencyDispatch {
		picture = "\dataM\UI\Messaging\101.paa";
		displayName = "Вызов ГАИ (HATO)";
		targets = "[""Hato""] call ULP_fnc_allMembers";
	};

	class GovernmentAnnoucement : Message {
		picture = "\dataM\UI\Spawns\government.paa";
		displayName = "Правительство";
		ignoreStreamer = true;
		canReply = false;
		sender = "HM Government";
		targets = "0";
		condition = "[] call ULP_fnc_isGovernor || { [""Police_Main"", 10] call ULP_fnc_hasAccess } || { [""ULP_Staff"", 4] call ULP_fnc_hasAccess }";
	};

	class PublicAnnoucement : GovernmentAnnoucement {
		picture = "\dataM\UI\Messaging\publicAnnouncement.paa";
		displayName = "Объявление Всем";
		sender = "Staff Team";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess";
	};

	class EventsAnnoucement : PublicAnnoucement {
		picture = "\dataM\UI\Messaging\eventAnnouncement.paa";
		displayName = "Объявление о событии";
		sender = "Events Team";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess || { [""ULP_Event"", 1] call ULP_fnc_hasAccess }";
	};

	class OpenAirBroadcast : PublicAnnoucement {
		displayName = "Воздушное объявление";
		sender = "Altis Police Service";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Air'} })";
		condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
	};

	class OpenSeaBroadcast : OpenAirBroadcast {
		displayName = "Морское объявление";
		targets = "(allPlayers select { !(isNull (objectParent _x)) && { (vehicle _x) isKindOf 'Ship'} })";
	};

	class Dispute : Message {
		picture = "\dataM\UI\dispute.paa";
		displayName = "Спор";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};

	class MedicRequest : Dispute {
		displayName = "Запрос медика";
		confirmSend = false;
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class Panic : Dispute {
		displayName = "Кнопка паники";
		ignoreComms = false;
		alertSound = false;
		confirmSend = false;
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""panic_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal (name _sender); [15, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class Robbery : Panic {
		displayName = "Ограбление";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {};";
	};

	class BreakIn : Panic {
		displayName = "Взлом";
		onRecieved = "private _sender = _this select 0; if (isNull _sender || { _sender isEqualTo player }) exitWith {}; private _marker = createMarkerLocal [format[""breakin_marker_%1_%2"", time, name _sender], getPos _sender]; _marker setMarkerTypeLocal ""mil_warning""; _marker setMarkerColorLocal ""colorRed""; _marker setMarkerTextLocal ""Reported Break In""; [15, _marker, { deleteMarkerLocal _this }] call ULP_fnc_waitExecute;";
	};
};
