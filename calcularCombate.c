#include "calcularCombate.h"

int samePos(POSICAO monPos, MSTR monster){
	return monPos.x == monster.x && monPos.y == monster.y;
}
void killMonster(int i, MSTR monstros[], char num_monstros){
	monstros[i]=monstros[(int) num_monstros];
}
char calcPlayerDmg(char classe, INVT bag){
	int weaponDmg;
	int plrDmg;
	plrDmg=weaponDmg=0;
	switch(bag.weapon){
		case 10: weaponDmg = SWORD_BRONZE_DMG;
			 break;
		case 11: weaponDmg = SWORD_IRON_DMG;
			 break;
		case 12: weaponDmg = SWORD_STEEL_DMG;
			 break;
		case 13: weaponDmg = SWORD_PALLADIUM_DMG;
			 break;
	}
	switch(classe){
		case 0: plrDmg = WARRIOR_BASE_DMG;
			break;
		case 1: plrDmg = ARCHER_BASE_DMG;
			break;
		case 2: plrDmg = MAGE_BASE_DMG;
			break;
	}
	return (char) weaponDmg + plrDmg;
}
int updateScore(char type){
	int scoreGain=0;
	switch(type){
		case 0: scoreGain = WOLF_SCORE;
			break;
		case 1: scoreGain = BAT_SCORE;
			break;
		case 2: scoreGain = OGRE_SCORE;
			break;
		case 3: scoreGain = ARCHER_SCORE;
			break;
	}
	return scoreGain;
}
POSICAO calculaArcherAtackPos(POSICAO p,int act){
	int x[10]={5,-1, 0, 1,-2, 5, 2,-1, 0, 1};
	/*         0  1  2  3  4  5  6  7  8  9 */
	int y[10]={5, 1, 2, 1, 0, 5, 0,-1,-2,-1};

	if(act!=0 && act!=5){
		p.x+=x[act];
		p.y+=y[act];
	}
	return p;
}
ESTADO calcularCombate(ESTADO e){
	POSICAO mon;
	char plrDmg;
	int i, found;
	if(e.action<20){
		mon = calculaNovaPosicao(e.jog,e.action-10);	
	}else /*if(e.action<30)*/{
		mon = calculaArcherAtackPos(e.jog,e.action-20);
	}
	plrDmg = calcPlayerDmg(e.classe,e.bag);
	i=found=0;
	while(!found){
		if(samePos(mon,e.monstros[i])){
			found=1;
		}else{
			i++;
		}
	}
	if(e.monstros[i].hp <= plrDmg){
		e.score+=updateScore(e.monstros[i].monType);
		e.num_monstros--;
		killMonster(i,e.monstros,e.num_monstros);
	}else{
		e.monstros[i].hp -= plrDmg;
	}
	return e;
}
