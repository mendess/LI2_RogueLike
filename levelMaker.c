#define DEBUG

#include "levelMaker.h"

ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		i++;
		p.x= x;
		p.y= y;
		if (!pos_ocupada(e,p) && !isOnPath(p,pathSize,path)){
			placed=1;
			e.pedras[e.num_pedras].x=p.x;
			e.pedras[e.num_pedras].y=p.y;
			e.num_pedras++;
		}
	}
	return e;
}
ESTADO colocar_monstro (ESTADO e){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		i++;
		p.x= x;
		p.y= y;
		if (!pos_ocupada(e,p)){
			placed=1;
			e.monstros [e.num_monstros].x=p.x;
			e.monstros [e.num_monstros].y=p.y;
			e.monstros [e.num_monstros].monType=e.num_monstros;
			e.monstros [e.num_monstros].hp=30;
			e.num_monstros++;
		}
	}
	return e;
}
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]){
	if(!e.isInBossBattle){
		int i;
		for(i=0;i<MAX_PEDRAS;i++){
			e=colocar_pedra(e,pathSize,path);
		}
	}
	return e;
}
ESTADO colocar_monstros (ESTADO e){
	int i;
	for (i=1;i<MAX_MONSTROS;i++){
		e=colocar_monstro(e);
	}
	return e;
}
int getClassHp(int type){
	switch(type){
		case 1: return HP_WARRIOR;
		case 2: return HP_ARCHER;
		case 3: return HP_MAGE;
	}
	return -1;
}
int getClassMp(int type){
	switch(type){
		case 1: return MP_WARRIOR;
		case 2: return MP_ARCHER;
		case 3: return MP_MAGE;
	}
	return -1;
}
INVT initINVT(){
	INVT bag;
	int i;
	i=0;
	bag.gold=0;
	for (i = 0; i < INVT_SIZE; ++i)
	{
		bag.inv[i]=0;
	}
	#ifdef DEBUG
	bag.inv[0]=10;
	bag.inv[1]=6;
	bag.inv[2]=4;
	bag.inv[3]=3;
	bag.inv[4]=2;
	bag.inv[5]=2;
	#endif
	bag.weapon=0;
	bag.armour=0;
	return bag;
}
ITEM_U_DAT initComplexItem(){
	ITEM_U_DAT complexItem;
	complexItem.isBeingUsed=0;
	complexItem.type=0;
	complexItem.lastPickedTarget=-1;
	complexItem.isBeingCast=0;
	return complexItem;
}
void initDroppedItems(CHEST droppedItems[]){
	int i;
	for(i=0;i<MAX_DROPPED_ITEMS;i++){
		droppedItems[i].item=0;
	}
}
POSICAO calcularNovaPosicao(POSICAO jog, int act){
	int x[10]={5,-1, 0, 1,-1, 0, 1,-1, 0, 1};
	/*         0  1  2  3  4  5  6  7  8  9 */
	int y[10]={5, 1, 1, 1, 0, 0, 0,-1,-1,-1};

	if(act!=0 && act!=5){
		jog.x+=x[act];
		jog.y+=y[act];
	}
	return jog;
}
POSICAO calcularLesserTeleport(POSICAO jog, int act){
	int x[10]={5,-1, 0, 1,-1, 5, 1,-1, 0, 1};
	/*         0  1  2  3  4  5  6  7  8  9 */
	int y[10]={5, 1, 1, 1, 0, 5, 0,-1,-1,-1};

	if(act!=0 && act!=5){
		jog.x+=x[act-30]*3;
		jog.y+=y[act-30]*3;
	}
	return jog;
}
ESTADO inicializar(ESTADO e){
	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	srand(time(NULL));
	e.screen=5;							/* Ecra de jogo */
	e.hp=getClassHp(e.classe);			/* Vida do jogador */
	e.mp=getClassMp(e.classe);			/* Mana do jogador */
	e.world_lvl=1;						/* Nivel */
	e.score=0;							/* Score */
	e.turn=0;							/* Turno */
	e.direction=0;						/* Lado para que o jogador esta a olhar 0:drt e 1:esq */
	e.action=0;							/* Action */
	generateLoot(e.lootTable,e.world_lvl);/* Inicializar LootTable para o primeiro nivel */
	e.isInShop=0;						/* O jogador começa fora da loja logo começa a 0 */
	e.isDeletingItems=0;				/* O jogador começa sem estar neste modo logo 0 */
	e.feedback=0;						/* Inicializa o feedback da loja */
	e.complexItem=initComplexItem(); 	/* Inicializa os dados para uso de items complexos */
	e.bag=initINVT();					/* Inicializar o inventario */
	e.jog.x=path[0].x;					/* Posição do jogador (x) */
	e.jog.y=path[0].y;					/* Posição do jogador (y) */
	e.saida.x=path[n-1].x;				/* Posição da saida (x) */
	e.saida.y=path[n-1].y;				/* Posição da saida (y) */
	e.num_monstros=0;					/* Numero de Monstros */
	e.num_pedras=0;						/* Numero de pedras */
	e=colocar_pedras(e,n,path);			/* Posições da pedras */
	e=genMonsters(e);					/* Posições dos monstros */
	initDroppedItems(e.droppedItems); /* Limpa o chão de items */
	return e;
}
ESTADO newLevel(ESTADO e){

	POSICAO path[MAX_CAMINHO];
	int n;
	if(!(e.world_lvl % 5)){
		if(e.isInShop){
			e.screen=5;
			e.isInShop=0;
		}else{
			generateLoot(e.lootTable,e.world_lvl);
			e.screen=6;
			e.isInShop=1;
			e.feedback=0;
			return e;
		}
	}
	n=pathMaker(path);
	srand(time(NULL));
	/* Vida do jogador */
	if(e.hp>(getClassHp(e.classe)-NEW_LEVEL_HP_BONUS)){
		e.hp=getClassHp(e.classe);
	}else{
		e.hp+=NEW_LEVEL_HP_BONUS;
	}
	/* Mana do jogador */
	if(e.mp>(getClassMp(e.classe)-NEW_LEVEL_MP_BONUS)){
		e.mp=getClassMp(e.classe);
	}else{
		e.mp+=NEW_LEVEL_MP_BONUS;
	}
	e.world_lvl+=1;						/* Nivel */
	e.score+=NEW_LEVEL_SC_BONUS;		/* Score */
	e.turn=0;							/* Turno */
	e.direction=0;						/* Lado para que o jogador esta a olhar 0:direita e 1:esquerda */
	e.action=0;							/* Action */
	generateLoot(e.lootTable,e.world_lvl);/* Inicializar LootTable para o nivel */
	e.isDeletingItems=0;				/* Inicializa fora do modo de apagar items */
	e.jog.x=path[0].x;					/* Posição do jogador (x) */
	e.jog.y=path[0].y;					/* Posição do jogador (y) */
	e.saida.x=path[n-1].x;				/* Posição da saida (x) */
	e.saida.y=path[n-1].y;				/* Posição da saida (y) */
	e.num_monstros=0;					/* Numero de Monstros */
	e.num_pedras=0;						/* Numero de pedras */
	e=colocar_pedras(e,n,path);			/* Posições da pedras */
	e=genMonsters(e);					/* Posições dos monstros */
	initDroppedItems(e.droppedItems); 	/* Limpa o chão de items */
	return e;
}
