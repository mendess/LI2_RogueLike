#ifndef __ACTION_MAP__
#define __ACTION_MAP__

#define ACT_GOTO_MENU			e.action==0
#define ACT_MENU_SCORE_OR_HELP	e.action==54 || e.action==53
#define ACT_MENU_PLAY			e.action==52
#define ACT_CLASS_CHOICE		e.action>60 && e.action<70
#define ACT_MOVE				e.action>0 && e.action<10
#define ACT_ATACK				e.action>10 && e.action<20
#define ACT_EXIT				e.action==5
#define ACT_SHOP_CHOICE			e.action>69 && e.action<82
#define PLR_FACING_LEFT			e.action==9 || e.action==6 || e.action==3
#define PLR_FACING_RIGHT		e.action==7 || e.action==4 || e.action==1
#define ACT_USE_ITEM			e.action>39 && e.action<50
#define ACT_RANGED_ATTACK		e.action>20 && e.action<30
#define ACT_BOSS_ATTACK			e.action==30
#define PICKING_ITEM_TGT		e.action>9999

#endif