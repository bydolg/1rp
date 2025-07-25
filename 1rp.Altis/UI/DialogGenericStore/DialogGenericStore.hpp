#define UI_X 0.324687
#define UI_X_INNER (UI_X + MARGIN_X)
#define UI_WIDTH 0.350625
#define INNER_UI_WIDTH (UI_WIDTH - (MARGIN_X * 2))
#define BODY_HEIGHT 0.407
#define CONTENT_W HORIZONTAL_GRID_W(INNER_UI_WIDTH, 3)

class DialogGenericStore {
    idd = 3100;
    name= "DialogGenericStore";
    movingEnable = 1;
    enableSimulation = 1;

    class ControlsBackground {
		class Header : Life_RscText {
            idc = 3101;
            colorBackground[] = HEADER_COLOUR;
            text = $STR_DIALOGGENERICSTORE_HEADER;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.269);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
        };

		class Body : Life_RscText {
            idc = -1;
            colorBackground[] = BODY_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.291);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
        };

		class ItemInfoBackground : Life_RscText {
            idc = -1;
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 1));
            SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H((BODY_HEIGHT - (MARGIN_Y * 2)) - ((BUTTON_H + BUTTON_MARGIN_Y) * 2));
        };

		class Footer : Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.698);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
        };
	};

	class Controls {

        class ClothesTypeTools : Life_RscToolbox {
            idc = 3102;
            style = 2 + 48 + 2048;
            colorBackground[] = NO_COLOUR;
            colorSelectedBg[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 0));
            SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(MARGIN_Y * 2);
            columns = 5;
            strings[] = {
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\uniform_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\headgear_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\goggles_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\vest_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\backpack_ca.paa"
            };
            tooltips[] = {
                $STR_DIALOGGENERICSTORE_UNIFORMS,
                $STR_DIALOGGENERICSTORE_HEADGEAR,
                $STR_DIALOGGENERICSTORE_GLASSES,
                $STR_DIALOGGENERICSTORE_VESTS,
                $STR_DIALOGGENERICSTORE_BACKPACKS
            };
        };

        class ItemTypeTools : Life_RscToolbox {
            idc = 3113;
            style = 2 + 48 + 2048;
            colorBackground[] = NO_COLOUR;
            colorSelectedBg[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 0));
            SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(MARGIN_Y * 2);
            columns = 5;
            strings[] = {
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\primaryweapon_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\handgun_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemacc_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargomagall_ca.paa",
                "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\nvgs_ca.paa"
            };
            tooltips[] = {
                $STR_DIALOGGENERICSTORE_PRIMARY,
                $STR_DIALOGGENERICSTORE_SECONDARY,
                $STR_DIALOGGENERICSTORE_ATTACHMENTS,
                $STR_DIALOGGENERICSTORE_MAGAZINES,
                $STR_DIALOGGENERICSTORE_ITEMS_LABEL
            };
        };

		class ItemsList : Life_RscListBox {
            idc = 3103;
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 0));
            SAFEZONE_Y(0.291 + (MARGIN_Y * 3));
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 4));
        };

        class ItemPicture : Life_RscPictureKeepAspect {
            idc = 3104;
            text = "";
            SAFEZONE_X((HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 1)) + MARGIN_X);
            SAFEZONE_Y(0.291 + (MARGIN_Y * 2));
			SAFEZONE_W(CONTENT_W - (MARGIN_X * 2));
			SAFEZONE_H((CONTENT_W * 1.5) - (MARGIN_Y * 2));
        };

        class ItemCartInfo : Life_RscStructuredText {
            idc = 3105;
            text = "";
            colorBackground[] = NO_COLOUR;
            SAFEZONE_X((HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 1)));
            SAFEZONE_Y((0.291 + (MARGIN_Y * 2)) + ((CONTENT_W * 1.5) - (MARGIN_Y * 2)));
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H((BODY_HEIGHT - (MARGIN_Y * 4)) - ((CONTENT_W * 1.5) - (MARGIN_Y * 2)));
        };

        class TextureList : Life_RscCombo {
            idc = 3106;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 1));
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - (BUTTON_H * 2) - BUTTON_MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BUTTON_H);
        };

        class AddCartButton : Life_RscButtonCenter {
            idc = 3108;
            text = $STR_DIALOGGENERICSTORE_ADD;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 1));
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BUTTON_H);
        };

        #define CART_LIST_Y (0.291 + MARGIN_Y)
        #define CART_LIST_H ((BODY_HEIGHT - (MARGIN_Y * 2)) - ((BUTTON_H + BUTTON_MARGIN_Y) * 2))

		class CartList : Life_RscListBox {
            idc = 3107;
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2));
            SAFEZONE_Y(CART_LIST_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(CART_LIST_H - BUTTON_H);
        };

        class CartButton : Life_RscButtonCenter {
            idc = 3109;
            text = $STR_DIALOGGENERICSTORE_REMOVE;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2));
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - (BUTTON_H * 2) - BUTTON_MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BUTTON_H);
        };

        class OverrideText : Life_RscStructuredText {
            idc = -1;
            text = $STR_DIALOGGENERICSTORE_OVERRIDE;
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2));
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BUTTON_H);
        };

        class OverrideCB : Life_Checkbox {
            idc = 3114;
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2));
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(MARGIN_X * 2);
			SAFEZONE_H(BUTTON_H);
        };

        #define CART_ACTION_W (CONTENT_W / 4)

        class SaveNewCartButton: ULP_RscButtonIcon {
            idc = 3115;
            text = "\a3\3den\Data\Displays\Display3DEN\ToolBar\new_ca.paa";
            tooltip = $STR_DIALOGGENERICSTORE_SAVE_NEW_TOOLTIP;
            onButtonClick = "_this call ULP_fnc_newSavedCart;";
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2));
            SAFEZONE_Y((CART_LIST_Y + CART_LIST_H) - BUTTON_H);
			SAFEZONE_W(CART_ACTION_W);
			SAFEZONE_H(BUTTON_H);
            offsetPressedX = 0.003;
            tooltipColorText[] = {1,1,1,1};
            tooltipColorBox[] = {1,1,1,1};
            tooltipColorShade[] = {0,0,0,0.65};
        };

        class LoadCartButton : SaveNewCartButton {
            idc = 3116;
            text = "\a3\3den\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
            tooltip = $STR_DIALOGGENERICSTORE_OPEN_TOOLTIP;
            onButtonClick = "_this call ULP_fnc_loadSavedCart;";
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2) + CART_ACTION_W);
        };

        class SaveCartButton : LoadCartButton {
            idc = 3117;
            text = "\a3\3den\Data\Displays\Display3DEN\ToolBar\saveas_ca.paa";
            tooltip = $STR_DIALOGGENERICSTORE_SAVE_TOOLTIP;
            onButtonClick = "[ctrlParent (_this select 0)] call ULP_fnc_saveCart;";
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2) + (CART_ACTION_W * 2));
        };

        class DeleteCartButton : LoadCartButton {
            idc = 3118;
            text = "\a3\3den\Data\Cfg3DEN\History\deleteItems_ca.paa";
            tooltip = $STR_DIALOGGENERICSTORE_DELETE_TOOLTIP;
            onButtonClick = "[ctrlParent (_this select 0)] call ULP_fnc_deleteSavedCart;";
            SAFEZONE_X(HORIZONTAL_GRID_X(UI_X_INNER, CONTENT_W, 2) + (CART_ACTION_W * 3));
        };

        class BuyButton : Life_RscButtonCenter {
            idc = 3110;
            text = $STR_DIALOGGENERICSTORE_BUY;
            SAFEZONE_X((UI_X + UI_WIDTH) - CONTENT_W - MARGIN_X);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(CONTENT_W);
			SAFEZONE_H(BUTTON_H);
        };
	};
};