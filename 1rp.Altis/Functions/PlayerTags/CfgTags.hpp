class CfgTags {
	baseColour[] = { 1, 1, 1, 1 };
	friendColour[] = { 0, 0.901, 0.074, 1 };

	class Tags {
		class Whitelisting {
			class Police {
				Main[] = {
					"PolicePCSO",
					"PolicePCSO",
					"PolicePPC",
					"PoliceSC",
					"PolicePC",
					"PolicePS",
					"PolicePI",
					"PoliceCI",
					"PoliceSU",
					"PoliceCSU",
					"PoliceDCC",
					"PoliceCC"
				};
			};

			class Medic {
				Main[] = {
					"MedicTechnician",
					"MedicTechnician",
					"MedicParamedic",
					"MedicSenior",
					"MedicDoctor",
					"MedicCommander",
					"MedicHead",
					"MedicDeputy",
					"MedicDirector"
				};
			};

			class Hato {
				Main[] = {
					"HatoTO",
					"HatoTO",
					"HatoSTO",
					"HatoIC",
					"HatoOM"
				};
			};
		};
	};

	class Icons {
		class IconBase {
			icon = "";
			subtitle = "";
			condition = "true";
		};

		class Admin {
			icon = "\dataM\Tags\logo.paa";
			subtitle = "Staff On-Duty";
			condition = "false";
		};

		class Governor {
			icon = "\dataM\Tags\governor.paa";
			displayName = "Governor";
			condition = "[] call ULP_fnc_isGovernor";
		};

		class Protection {
			icon = "\dataM\Tags\protection.paa";
			displayName = "Governor Protection";
			condition = "[] call ULP_fnc_isProtection && { !([] call ULP_fnc_isGovernor) }";
		};

		// Altis Police Service
		class PoliceCC {
			icon = "\dataM\Tags\Ranks\Police\CC.paa";
			subtitle = "Chief Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 11] call ULP_fnc_hasAccess }";
		};
		class PoliceDCC {
			icon = "\dataM\Tags\Ranks\Police\DCC.paa";
			subtitle = "Deputy Chief Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class PoliceCSU {
			icon = "\dataM\Tags\Ranks\Police\CSU.paa";
			subtitle = "Chief Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
		};
		class PoliceSU {
			icon = "\dataM\Tags\Ranks\Police\SU.paa";
			subtitle = "Superintendent";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class PoliceCI {
			icon = "\dataM\Tags\Ranks\Police\CI.paa";
			subtitle = "Chief Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class PolicePI {
			icon = "\dataM\Tags\Ranks\Police\PI.paa";
			subtitle = "Police Inspector";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class PolicePS {
			icon = "\dataM\Tags\Ranks\Police\PS.paa";
			subtitle = "Police Sergeant";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class PolicePC  {
			icon = "\dataM\Tags\Ranks\Police\PC.paa";
			subtitle = "Police Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class PoliceSC  {
			icon = "\dataM\Tags\Ranks\Police\SC.paa";
			subtitle = "Special Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class PolicePPC  {
			icon = "\dataM\Tags\Ranks\Police\PC.paa";
			subtitle = "Probationary Police Constable";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PolicePCSO  {
			icon = "\dataM\Tags\Ranks\Police\PCSO.paa";
			subtitle = "Police Community Support Officer";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 1] call ULP_fnc_hasAccess }";
		};

		// Altis Ambulance Service
		class MedicDirector {
			icon = "\dataM\Tags\Ranks\Medic\director.paa";
			subtitle = "Director";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class MedicDeputy {
			icon = "\dataM\Tags\Ranks\Medic\deputyDirector.paa";
			subtitle = "Deputy Director";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class MedicHead {
			icon = "\dataM\Tags\Ranks\Medic\head.paa";
			subtitle = "Head of Department";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class MedicCommander {
			icon = "\dataM\Tags\Ranks\Medic\commander.paa";
			subtitle = "Incident Commander";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class MedicDoctor {
			icon = "\dataM\Tags\Ranks\Medic\doctor.paa";
			subtitle = "Emergency Doctor";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class MedicSenior {
			icon = "\dataM\Tags\Ranks\Medic\senior.paa";
			subtitle = "Senior Paramedic";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class MedicParamedic {
			icon = "\dataM\Tags\Ranks\Medic\paramedic.paa";
			subtitle = "Paramedic";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class MedicTechnician {
			subtitle = "Medical Technician";
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};

		// Highways Agency
		class HatoOM {
			icon = "\dataM\Tags\Ranks\Hato\OM.paa";
			subtitle = "Operations Manager";
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction && { [""Hato_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class HatoIC {
			icon = "\dataM\Tags\Ranks\Hato\IC.paa";
			subtitle = "Incident Coordinator";
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction && { [""Hato_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class HatoSTO {
			icon = "\dataM\Tags\Ranks\Hato\STO.paa";
			subtitle = "Senior Traffic Officer";
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction && { [""Hato_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class HatoTO {
			icon = "\dataM\Tags\Ranks\Hato\TO.paa";
			subtitle = "Traffic Officer";
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction && { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
		};

		// Civilian Donators
		/// Animals
		class Alligator  {
			icon = "\dataM\Tags\Donator\Animals\alligator.paa";
			displayName = "Alligator";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class Elephant : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\elephant.paa";
			displayName = "Elephant";
		};
		class Flamingo : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\flamingo.paa";
			displayName = "Flamingo";
		};
		class Octopus : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\octopus.paa";
			displayName = "Octopus";
		};
		class Pig : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\pig.paa";
			displayName = "Pig";
		};
		class Turtle : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\turtle.paa";
			displayName = "Turtle";
		};
		class Unicorn : Alligator  {
			icon = "\dataM\Tags\Donator\Animals\unicorn.paa";
			displayName = "Unicorn";
		};

		/// Flags
		class Canada : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\canada.paa";
			displayName = "Canada";
		};
		class Denmark : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\denmark.paa";
			displayName = "Denmark";
		};
		class England : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\england.paa";
			displayName = "England";
		};
		class Finland : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\finland.paa";
			displayName = "Finland";
		};
		class France : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\france.paa";
			displayName = "France";
		};
		class Germany : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\germany.paa";
			displayName = "Germany";
		};
		class Greece : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\greece.paa";
			displayName = "Greece";
		};
		class Netherlands : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\netherlands.paa";
			displayName = "Netherlands";
		};
		class NorthKorea : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\northkorea.paa";
			displayName = "North Korea";
		};
		class Norway : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\norway.paa";
			displayName = "Norway";
		};
		class Scotland : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\scotland.paa";
			displayName = "Scotland";
		};
		class Spain : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\spain.paa";
			displayName = "Spain";
		};
		class Sweden : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\sweden.paa";
			displayName = "Sweden";
		};
		class UK : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\unitedKingdom.paa";
			displayName = "UK";
		};
		class USA : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\usa.paa";
			displayName = "USA";
		};
		class USSR : Alligator  {
			icon = "\dataM\Tags\Donator\Flags\ussr.paa";
			displayName = "USSR";
		};

		/// Letters
		class A : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\a.paa";
			displayName = "A";
		};
		class B : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\b.paa";
			displayName = "B";
		};
		class C : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\c.paa";
			displayName = "C";
		};
		class D : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\d.paa";
			displayName = "D";
		};
		class E : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\e.paa";
			displayName = "E";
		};
		class F : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\f.paa";
			displayName = "F";
		};
		class G : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\g.paa";
			displayName = "G";
		};
		class H : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\h.paa";
			displayName = "H";
		};
		class I : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\i.paa";
			displayName = "I";
		};
		class J : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\j.paa";
			displayName = "J";
		};
		class K : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\k.paa";
			displayName = "K";
		};
		class L : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\l.paa";
			displayName = "L";
		};
		class M : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\m.paa";
			displayName = "M";
		};
		class N : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\n.paa";
			displayName = "N";
		};
		class O : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\o.paa";
			displayName = "O";
		};
		class P : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\p.paa";
			displayName = "P";
		};
		class Q : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\q.paa";
			displayName = "Q";
		};
		class R : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\r.paa";
			displayName = "R";
		};
		class S : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\s.paa";
			displayName = "S";
		};
		class T : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\t.paa";
			displayName = "T";
		};
		class U : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\u.paa";
			displayName = "U";
		};
		class V : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\v.paa";
			displayName = "V";
		};
		class W : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\w.paa";
			displayName = "W";
		};
		class X : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\x.paa";
			displayName = "X";
		};
		class Y : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\y.paa";
			displayName = "Y";
		};
		class Z : Alligator  {
			icon = "\dataM\Tags\Donator\Letters\z.paa";
			displayName = "Z";
		};

		/// Movies
		class Avatar : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\avatar.paa";
			displayName = "Avatar";
		};
		class C3PO : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\C3PO.paa";
			displayName = "C3PO";
		};
		class Disney : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\disney.paa";
			displayName = "Disney";
		};
		class Flash : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\flash.paa";
			displayName = "Flash";
		};
		class Joker : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\joker.paa";
			displayName = "Joker";
		};
		class Morty : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\morty.paa";
			displayName = "Morty";
		};
		class Pennywise : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\pennywise.paa";
			displayName = "Pennywise";
		};
		class Pixar : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\pixar.paa";
			displayName = "Pixar";
		};
		class Rick : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\rick.paa";
			displayName = "Rick";
		};
		class StarTrek : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\startrek.paa";
			displayName = "StarTrek";
		};
		class Superman : Alligator  {
			icon = "\dataM\Tags\Donator\Movies\superman.paa";
			displayName = "Superman";
		};

		/// Political
		class ConservativeUnionistParty : Alligator  {
			icon = "\dataM\Tags\Donator\Political\conservativeUnionistParty.paa";
			displayName = "Conservative and Unionist Party";
		};
		class LabourParty : Alligator  {
			icon = "\dataM\Tags\Donator\Political\labourParty.paa";
			displayName = "Labour Party";
		};
		class LiberalDemocrats : Alligator  {
			icon = "\dataM\Tags\Donator\Political\liberalDemocrats.paa";
			displayName = "Liberal Democrats";
		};
		class GreenParty : Alligator  {
			icon = "\dataM\Tags\Donator\Political\greenparty.paa";
			displayName = "Green Party";
		};
		class ReformUK : Alligator  {
			icon = "\dataM\Tags\Donator\Political\reformUK.paa";
			displayName = "ReformUK";
		};

		// Investor
		class FreddieDavis : Alligator { // ICON
			icon = "\dataM\Tags\Donator\Movies\superman.paa";
			displayName = "Freddie Davis";
		};
		class BoughNoggeye : Alligator {
			icon = "\dataM\Tags\Donator\Investor\boughNoggeye.paa";
			displayName = "Bough Noggeye";
		};
		class KitKnight : Alligator { // ICON
			icon = "\dataM\Tags\Donator\Movies\superman.paa";
			displayName = "Kit Knight";
		};
		class Hector : Alligator {
			icon = "\dataM\Tags\Donator\Investor\hector.paa";
			displayName = "Hector";
		};

		/// Other
		class Alien : Alligator  {
			icon = "\dataM\Tags\Donator\Other\alien.paa";
			displayName = "Alien";
		};
		class Astronaut : Alligator  {
			icon = "\dataM\Tags\Donator\Other\astronaut.paa";
			displayName = "Astronaut";
		};
		class Commet : Alligator  {
			icon = "\dataM\Tags\Donator\Other\commet.paa";
			displayName = "Commet";
		};
		class Crown : Alligator  {
			icon = "\dataM\Tags\Donator\Other\crown.paa";
			displayName = "Crown";
		};
		class Diamond : Alligator  {
			icon = "\dataM\Tags\Donator\Other\diamond.paa";
			displayName = "Diamond";
		};
		class DNA : Alligator  {
			icon = "\dataM\Tags\Donator\Other\dna.paa";
			displayName = "DNA";
		};
		class Doughnut : Alligator  {
			icon = "\dataM\Tags\Donator\Other\doughnut.paa";
			displayName = "Doughnut";
		};
		class Eggplant : Alligator  {
			icon = "\dataM\Tags\Donator\Other\eggplant.paa";
			displayName = "Eggplant";
		};
		class Fighter : Alligator  {
			icon = "\dataM\Tags\Donator\Other\fighter.paa";
			displayName = "Fighter";
		};
		class Hamburger : Alligator  {
			icon = "\dataM\Tags\Donator\Other\hamburger.paa";
			displayName = "Hamburger";
		};
		class Heart : Alligator  {
			icon = "\dataM\Tags\Donator\Other\heart.paa";
			displayName = "Heart";
		};
		class Mars : Alligator  {
			icon = "\dataM\Tags\Donator\Other\mars.paa";
			displayName = "Mars";
		};
		class Moon : Alligator  {
			icon = "\dataM\Tags\Donator\Other\moon.paa";
			displayName = "Moon";
		};
		class Salt : Alligator  {
			icon = "\dataM\Tags\Donator\Other\salt.paa";
			displayName = "Salt";
		};
		class Satellite : Alligator  {
			icon = "\dataM\Tags\Donator\Other\satellite.paa";
			displayName = "Satellite";
		};
		class Saturn : Alligator  {
			icon = "\dataM\Tags\Donator\Other\saturn.paa";
			displayName = "Saturn";
		};
		class Server : Alligator  {
			icon = "\dataM\Tags\Donator\Other\server.paa";
			displayName = "Server";
		};
		class Shuttle : Alligator  {
			icon = "\dataM\Tags\Donator\Other\shuttle.paa";
			displayName = "Shuttle";
		};
		class Skull : Alligator  {
			icon = "\dataM\Tags\Donator\Other\skull.paa";
			displayName = "Skull";
		};
		class UN : Alligator  {
			icon = "\dataM\Tags\Donator\Other\UN.paa";
			displayName = "UN";
		};
		class Weed : Alligator  {
			icon = "\dataM\Tags\Donator\Other\weed.paa";
			displayName = "Weed";
		};
		class World : Alligator  {
			icon = "\dataM\Tags\Donator\Other\world.paa";
			displayName = "World";
		};
	};

	class Categories {
		class Positions {
			icons[] = { "Governor" };
		};
		class Animals {
			icons[] = { "Alligator", "Elephant", "Flamingo", "Octopus", "Pig", "Turtle", "Unicorn" };
		};
		class Flags {
			icons[] = { "Canada", "Denmark", "England", "Finland", "Germany", "Greece", "LGBT", "Netherlands", "NorthKorea", "Norway", "Scotland", "Spain", "Sweden", "UK", "USA", "USSR" };
		};
		class Letters {
			icons[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
		};
		class Movies {
			icons[] = { "Avatar", "C3PO", "Disney", "Flash", "Joker", "Morty", "Pennywise", "Pixar", "Rick", "StarTrek", "Superman" };
		};
		class Political {
			icons[] = { "ConservativeUnionistParty", "LabourParty", "LiberalDemocrats", "GreenParty", "ReformUK" };
		};
		class Investor {
			icons[] = { "FreddieDavis", "BoughNoggeye", "KitKnight", "Hector" };
		};
		class Other {
			icons[] = { "Alien", "Astronaut", "Commet", "Crown", "Diamond", "DNA", "Doughnut", "Eggplant", "Fighter", "Hamburger", "Heart", "Mars", "Moon", "Salt", "Satellite", "Saturn", "Server", "Shuttle", "Skull", "UN", "Weed", "World" };
		};
	};
};