#include "calcularCombate.h"

int samePos(POSICAO monPos, MSTR monster){
	return mon.x == monster.x && mon.y == monster.y
}
void killMonster(POSICAO target, MSTR monstros[], char *num_monstros){
	int i=0;
	while(!samePos(target,monstros[i])){
		i++;
	}
	*num_monstros--;
	while(i<num_monstros){
		monstros[i]=monstros[i+1];
	}
}
char calcPlayerDmg(char classe, INVT bag){
	int weaponDmg;
	switch(bag.weapon){
		case 10: weaponDmg = SWORD_BRONZE_DMG;
		case 11: weaponDmg = SWORD_IRON_DMG;
		case 12: weaponDmg = SWORD_STEEL_DMG;
		case 13: weaponDmg = SWORD_PALLADIUM_DMG;
	}
	int plrDmg;
	switch(classe){
		case 0: plrDmg = WARRIOR_BASE_DMG;
		case 1: plrDmg = ARCHER_BASE_DMG;
		case 2: plrDmg = MAGE_BASE_DMG;
	}
	return (char) weaponDmg + plrDmg;
}
ESTADO calcularCombate(ESTADO e){
	POSICAO mon = calcularNovaPosicao(e.jog,e.action-10);
	int i=0, found=0;
	while(!found){
		if(samePos(mon,e.monstros[i])){
			found=1;
		}else{
			i++;
		}
	}
	char plrDmg = calcPlayerDmg(e.classe,e.bag);
	if(e.monstros[i].hp < plrDmg){
		killMonster(mon, e.monstros,&e.num_monstros);
	}else{
		e.monstros[i].hp -= plrDmg;
	}
	return e;
}
