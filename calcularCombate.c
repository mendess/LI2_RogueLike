#include "calcularCombate.h"

int samePos(POSICAO monPos, MSTR monster){
	return monPos.x == monster.x && monPos.y == monster.y;
}
void killMonster(int i, MSTR monstros[], int num_monstros){
	monstros[i]=monstros[num_monstros];
}
int calcPlayerDmg(int classe, INVT bag){
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
	return weaponDmg + plrDmg;
}
int updateScore(int type){
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
int goldDrop(int type){
	int goldGain=0;
	switch(type){
		case 0: goldGain = WOLF_GOLD;
			break;
		case 1: goldGain = BAT_GOLD;
			break;
		case 2: goldGain = OGRE_GOLD;
			break;
		case 3: goldGain = ARCHER_GOLD;
			break;
	}
	return goldGain;
}
ESTADO calcularCombate(ESTADO e){
	POSICAO mon;
	int plrDmg;
	int i, found;
	mon = calculaNovaPosicao(e.jog, e.action-10);
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
		e.bag.gold+=goldDrop(e.monstros[i].monType);
		e.num_monstros--;
		killMonster(i,e.monstros,e.num_monstros);
	}else{
		e.monstros[i].hp -= plrDmg;
	}
	return e;
}
