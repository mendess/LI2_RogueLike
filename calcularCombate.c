#include "calcularCombate.h"

int samePos(POSICAO monPos, MSTR monster){
	return monPos.x == monster.x && monPos.y == monster.y;
}
void killMonster(int i, MSTR monstros[], char num_monstros){
	while(i<num_monstros){
		monstros[i]=monstros[i+1];
		i++;
	}
}
char calcPlayerDmg(char classe, INVT bag){
	int weaponDmg;
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
	int plrDmg;
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
ESTADO calcularCombate(ESTADO e){
	POSICAO mon = calculaNovaPosicao(e.jog,(int) e.action-10);
	int i=0, found=0;
	while(!found){
		if(samePos(mon,e.monstros[i])){
			found=1;
		}else{
			i++;
		}
	}
	char plrDmg = calcPlayerDmg(e.classe,e.bag);
	if(e.monstros[i].hp <= plrDmg){
		e.score+=updateScore(e.monstros[i].monType);
		e.num_monstros--;
		killMonster(i,e.monstros,e.num_monstros);
	}else{
		e.monstros[i].hp -= plrDmg;
	}
	return e;
}
