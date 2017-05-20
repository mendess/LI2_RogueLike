#include "loot.h"

char generatePotion(){
	int r = rand() % 3;
	if(r<2){
		return HEALTH_POTION;
	}else{
		return MANA_POTION;
	}
}
char generateScroll(){
	int r = rand() % 3;
	switch(r){
		case 0: return SCROLL_FIRE;

		case 1: return SCROLL_LIGHTNING;

		case 2: return SCROLL_TELEPORT;
	}
	return SCROLL_FIRE;
}
char generateSword(char world_lvl){
	int r = rand() % 100000;
	double tier1=TIER1_ODDS(world_lvl);
	double tier4=TIER4_ODDS(world_lvl);
	double tmp=100000-tier1-tier4;
	double tier3=tmp*TIER_SHIFT(world_lvl);
	double tier2=tmp-tier3;

	if(r<tier1){
		return SWORD_BRONZE;
	}
	if(r<tier1+tier2){
		return SWORD_IRON;
	}
	if(r<tier1+tier2+tier3){
		return SWORD_STEEL;
	}
	return SWORD_PALLADIUM;
}
char generateArmour(char world_lvl){
	int r = rand() % 100000;
	double tier1=TIER1_ODDS(world_lvl);
	double tier4=TIER4_ODDS(world_lvl);
	double tmp=100000-tier1-tier4;
	double tier3=tmp*TIER_SHIFT(world_lvl);
	double tier2=tmp-tier3;

	if(r<tier1){
		return ARMOUR_BRONZE;
	}
	if(r<tier1+tier2){
		return ARMOUR_IRON;
	}
	if(r<tier1+tier2+tier3){
		return ARMOUR_STEEL;
	}
	return ARMOUR_PALLADIUM;
}
void generateLoot(char lootTable[], int world_lvl){
	int i;
	srand(time(NULL));
	for(i=0;i<LOOT_TABLE_SIZE;i++){
		int r = rand() % 100;
		if(r<40){
			lootTable[i]=generatePotion();
		}
		if(r>39 && r<70){
			lootTable[i]=generateScroll();
		}
		if(r>69 && r<85){
			lootTable[i]=generateSword(world_lvl);
		}
		if(r>84 && r<100){
			lootTable[i]=generateArmour(world_lvl);
		}
	}
}