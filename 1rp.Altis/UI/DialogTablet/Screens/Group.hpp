class GroupPages : Life_RscToolbox {
	idc = 23061;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_group;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 3;
	fade = 0;
        strings[] = {
                "$STR_TABLETGROUP_OVERVIEW",
                "$STR_TABLETGROUP_PROGRESS",
                "$STR_TABLETGROUP_SETTINGS"
        };
        tooltips[] = {
                "$STR_TABLETGROUP_OVERVIEW",
                "$STR_TABLETGROUP_PROGRESS",
                "$STR_TABLETGROUP_SETTINGS"
        };
};

class GroupMemberBackground : Life_RscText {
	idc = 23065;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - (0.022 * 3)) - (MARGIN_Y * 4));
};

class GroupMemberHeaderBackground : Life_RscText {
	idc = 23064;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
};

class GroupMemberListHeader: Life_RscListNBox {
	idc = 23063;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
                class Member {
                        text = $STR_TABLETGROUP_MEMBER;
                        value = 0;
                };
                class Rank {
                        text = $STR_TABLETGROUP_RANK;
                        value = -1;
                        data = "data";
                };
	};
};

class GroupMemberList: Life_RscListNBox {
	idc = 23062;
	colorBackground[] = INNER_BODY_COLOUR;
	onLBSelChanged = "((ctrlParent (_this select 0)) displayCtrl 23068) lbSetCurSel ((_this select 0) lnbValue [(_this select 1), 1])";
	rowHeight = 0.09;
	sizeEx = 0.033;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - (0.022 * 3)) - (MARGIN_Y * 4));
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};

        class GroupFunds : Life_RscStructuredText {
                idc = 23066;
                text = $STR_TABLETGROUP_FUNDS;
                colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (0.022 * 2));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((0.022 * 2));
};

        class ChangeRank : ULP_RscButtonClean {
                idc = 23067;
                text = $STR_TABLETGROUP_CHANGERANK;
                onButtonClick = "_this call ULP_fnc_changeRank;";
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class GroupRankSelectList : Life_RscCombo {
	idc = 23068;
	onLBSelChanged = "";
	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) + MARGIN_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

        class TransferOwnership : ChangeRank {
                idc = 23079;
                text = $STR_TABLETGROUP_TRANSFER;
	onButtonClick = "_this call ULP_fnc_transferOwner;";
	SAFEZONE_Y((UI_Y + (0.022 * 2)) + (MARGIN_Y * 3) + ((MARGIN_Y / 2)));
};

        class Kick : ChangeRank {
                idc = 23080;
                text = $STR_TABLETGROUP_KICK;
	onButtonClick = "_this call ULP_fnc_kickMember;";
	SAFEZONE_Y((UI_Y + (0.022 * 3)) + (MARGIN_Y * 3) + ((MARGIN_Y / 2) * 2));
};

        class Invite : ChangeRank {
                idc = 23089;
                text = $STR_TABLETGROUP_INVITE;
	onButtonClick = "_this call ULP_fnc_inviteMember;";
	SAFEZONE_Y((UI_Y + (0.022 * 4)) + (MARGIN_Y * 4) + ((MARGIN_Y / 2) * 3));
};

        class LeaveGroup : ULP_RscButtonClean {
                idc = 23081;
                text = $STR_TABLETGROUP_LEAVE;
	onButtonClick = "[] call ULP_fnc_leaveGroup;";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

        class DisbandGroup : LeaveGroup {
                idc = 23076;
                text = $STR_TABLETGROUP_DISBAND;
	onButtonClick = "[] call ULP_fnc_disbandGroup;";
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3) + (MARGIN_Y / 2));
};

class XPBarBackground : Life_RscText {
	idc = 23082;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class XPBar : Life_RscProgress {
	idc = 23083;
	colorBar[] = { 0.451, 0, 0.902, 1 };
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class XPText: Life_RscStructuredText {
	idc = 23084;
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class LeftView : Life_RscControlsGroup {
    idc = 23085;
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));

    class Controls {};
};

class RightView : Life_RscControlsGroup {
    idc = 23086;
	colorBackground[] = INNER_BODY_COLOUR;
   	SAFEZONE_X((UI_X + ((UI_WIDTH - 0.01) / 2)) + (MARGIN_X * 2));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));

    class Controls {};
};

class ChangeTax : ULP_RscButtonClean {
        idc = 23087;
        text = $STR_TABLETGROUP_CHANGETAX;
	onButtonClick = "_this call ULP_fnc_changeTax;";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};

class GroupTaxText : Life_RscStructuredText {
        idc = 23088;
        text = $STR_TABLETGROUP_TAXTEXT;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W((((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2)) / 2);
	SAFEZONE_H(0.022);
};
