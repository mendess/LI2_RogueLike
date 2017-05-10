#include <stdio.h>
#include "IA.h"

ESTADO estrat_ogre (ESTADO e,int i,POSICAO p){
   if (existe_jogador(e,p)){
        e.hp+=-OGRE_DMG;
   } 
   return e;
}