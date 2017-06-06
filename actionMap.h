#ifndef __ACTION_MAP__
#define __ACTION_MAP__

#define ACT_GOTO_MENU			e.action==0
#define ACT_MENU_SCORE_OR_HELP	e.action==54 || e.action==53
#define ACT_MENU_PLAY			e.action==52
#define ACT_CLASS_CHOICE		e.action>60 && e.action<70
#define ACT_MOVE				e.action>0 && e.action<10
#define ACT_LESSER_TELEPORT		e.action>30 && e.action<40
#define ACT_ATACK				e.action>10 && e.action<30
#define ACT_EXIT				e.action==5
#define ACT_SHOP_CHOICE			e.action>69 && e.action<82
#define PLR_FACING_LEFT			e.action==9 || e.action==6 || e.action==3
#define PLR_FACING_RIGHT		e.action==7 || e.action==4 || e.action==1
#define ACT_USE_ITEM			e.action>39 && e.action<50
#define ACT_RANGED_ATTACK		e.action>20 && e.action<30
#define ACT_BOSS_ATTACK			e.action==30
#define PICKING_ITEM_TGT		e.action>9999
/*
	0 -> MainMenu
	1 -> SW
	2 -> S
	3 -> SE
	4 -> W
	5 -> NextLevel
	6 -> E
	7 -> NW
	8 -> N
	9 -> NE
	11 -> atack SW
	12 -> atack S
	13 -> atack SE
	14 -> atack W
	15 -> atack Boss
	16 -> atack E
	17 -> atack NW
	18 -> atack N
	19 -> atack NE
	21 -> archer atack SW
	22 -> archer atack S
	23 -> archer atack SE
	24 -> archer atack W
	25 -> archer atack Boss
	26 -> archer atack E
	27 -> archer atack NW
	28 -> archer atack N
	29 -> archer atack NE
	30 -> atack boss
	32 -> mage lesser teleport S
	34 -> mage lesser teleport W
	36 -> mage lesser teleport E
	38 -> mage lesser teleport N
	40 -> Use Item 0
	41 -> Use Item 1
	42 -> Use Item 2
	43 -> Use Item 3
	44 -> Use Item 4
	45 -> Use Item 5
	51 -> Go to CharSelect
	52 -> Go to Help
	53 -> Go to ScoreBoard
	61 -> Pick Warrior
	62 -> Pick Archer
	63 -> Pick Mage
	70 -> BuyShopItem 0
	71 -> BuyShopItem 1
	72 -> BuyShopItem 2
	73 -> BuyShopItem 3

	1XXYY -> usar item nas cordenadas XX e YY
*/

#endif