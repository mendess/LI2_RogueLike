#ifndef __ACTION_MAP__
#define __ACTION_MAP__
/**
@file actionMap.h
Definição do mapa de ações do jogador
*/
/** \brief Ação para voltar ao menu */
#define ACT_GOTO_MENU			e.action==0
/** \brief Ações para aceder aos sub menus de high scores ou ajuda */
#define ACT_MENU_SCORE_OR_HELP	e.action==54 || e.action==53
/** \brief Ação para começar o jogo */
#define ACT_MENU_PLAY			e.action==52
/** \brief Ação para escolher a classe */
#define ACT_CLASS_CHOICE		e.action>60 && e.action<70
/** \brief Ação para ligar ou desligar o modo de ajuda */
#define ACT_TOGGLE_INGAME_HELP	e.action==10
/** \brief Verifica se o jogador ainda esta no modo de ajuda */
#define ASKING_FOR_INGAME_HELP	e.isInIngameHelp==1
/** \brief Ação para o jogador se mover */
#define ACT_MOVE				e.action>0 && e.action<10
/** \brief Ação para o jogador usar o teleporte menor */
#define ACT_LESSER_TELEPORT		e.action>30 && e.action<40
/** \brief Ação de ataque */
#define ACT_ATACK				e.action>10 && e.action<30
/** \brief Ação para passar de nivel ou sair da loja */
#define ACT_EXIT				e.action==5
/** \brief Ação para escolher um item da loja */
#define ACT_SHOP_CHOICE			e.action>69 && e.action<80
/** \brief Verifica se o jogador esta virado para a esquerda */
#define PLR_FACING_LEFT			e.action==9 || e.action==6 || e.action==3
/** \brief Verifica se o jogador esta virado para a direita */
#define PLR_FACING_RIGHT		e.action==7 || e.action==4 || e.action==1
/** \brief Ação para usar um item */
#define ACT_USE_ITEM			e.action>39 && e.action<50
/** \brief Ação para o jogador atacar a distância */
#define ACT_RANGED_ATTACK		e.action>20 && e.action<30
/** \brief Ação para atacar o boss */
#define ACT_BOSS_ATTACK			e.action==30
/** \brief Ação para pegar num item do chão */
#define ACT_PICK_UP_ITEM		e.action>80 && e.action<90
/** \brief Ação para o jogador abrir uma chest */
#define ACT_OPEN_CHEST			e.action>90 && e.action<100
/** \brief Ação para ligar ou desligar o modo de apagar items do inventário */
#define ACT_TOGGLE_ITEM_MODE		e.action==80
/** \brief Ação para escolher o alvo de um item complexo */
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
	10 -> Toggle Ingame help
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
	80 -> Delete item mode
	81 -> Pick up item SE
	82 -> Pick up item S
	83 -> Pick up item SW
	84 -> Pick up item E
	85 -> Pick up item Center
	86 -> Pick up item W
	87 -> Pick up item NE
	88 -> Pick up item N
	89 -> Pick up item NW
	91 -> Open chest SE
	92 -> Open chest S
	93 -> Open chest SW
	94 -> Open chest E
	95 -> Open chest Center
	96 -> Open chest W
	97 -> Open chest NE
	98 -> Open chest N
	99 -> Open chest NW
	
	1XXYY -> usar item nas cordenadas XX e YY
*/

#endif