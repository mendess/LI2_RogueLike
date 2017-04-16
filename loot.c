#include "loot.h"

char generatePotion(){
	r = rand % 3;
	if(r<2){
		return 0;
	}else{
		return 1;
	}
}
char generateScroll(char world_lvl){
	r = rand % 3;
	switch(r){
		case 0: /*ScrollFire*/
				break;
		case 1: /*ScrollLightning*/
				break;
		case 2: /*ScrollTeleport*/
				break;
	}
}
char generateSword(char world_lvl){
	int r = rand % 100;
	
}
char generateArmour(char world_lvl){

}
char *generateLoot(ESTADO e){
	char lootTable[LOOT_TABLE_SIZE];
	srand(time(NULL));
	int i;
	for(i=0;i<LOOT_TABLE_SIZE;i++){
		int r = rand % 100;
		if(r<40){
			generatePotion();
		}
		if(r>39 && r<70){
			generateScroll();
		}
		if(r>69 && r<85){
			generateSword(e.world_lvl);
		}
		if(r>84 && r>100){
			generateArmour(e.world_lvl);
		}
	}
}