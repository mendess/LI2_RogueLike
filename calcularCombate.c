#include "calcularCombate.h"

int samePos(POSICAO monPos, MSTR monster){
	return monPos.x == monster.x && monPos.y == monster.y;
}
void killMonster(int i, MSTR monstros[], int num_monstros){
	monstros[i]=monstros[num_monstros];
}
int calcPlayerDmg(int classe, INVT bag){
	int weaponDmgs[] = WEAPON_DMG_ARRAY;
	int plrDmgs[] = BASE_DMG_ARRAY;
	return weaponDmgs[bag.weapon-9] + plrDmgs[classe];
}
int updateScore(int type){
	int scores[] = SCORE_GAIN_ARRAY;
	return scores[type];
}
int goldDrop(int type){
	int goldGains[] = GOLD_DROP_ARRAY;
	return goldGains[type];
}
POSICAO calculaRangedAtackPos(POSICAO p,int act){
	act-=20;
	int x[10]={5,-1, 0, 1,-2, 5, 2,-1, 0, 1};
	/*         0  1  2  3  4  5  6  7  8  9 */
	int y[10]={5, 1, 2, 1, 0, 5, 0,-1,-2,-1};

	if(act!=0 && act!=5){
		p.x+=x[act];
		p.y+=y[act];
	}
	return p;
}
int getMonstro(ESTADO e,POSICAO p){
	int i, found;
	i=found=0;
	while(!found && i<e.num_monstros){
		if(samePos(p,e.monstros[i])){
			found=1;
		}else{
			i++;
		}
	}
	return i;
}
ESTADO calcularCombate(ESTADO e){
	POSICAO mon = {-1,-1};
	char plrDmg;
	int i;
	if(e.action<20){
		mon = calculaNovaPosicao(e.jog,e.action-10);	
	}else if(e.action<30){
		mon = calculaRangedAtackPos(e.jog,e.action);
	}
	plrDmg = calcPlayerDmg(e.classe,e.bag);

	i = getMonstro(e,mon);
	if(e.monstros[i].hp <= plrDmg){
		e.score+=updateScore(e.monstros[i].monType);
		e.bag.gold+=goldDrop(e.monstros[i].monType);
		e.num_monstros--;
		killMonster(i,e.monstros,e.num_monstros);
	}else{
		e.monstros[i].hp -= plrDmg;
	}
	return e;
}
