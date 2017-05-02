#include "IA.h"


// falta persegue -> ogre protege objeto raro e poderoso

ESTADO estrat_ogre (ESTADO e,int i,POSICAO p){
   int flag=1;;
   if (existe_jogador(e,p)){
       	e.hp-=OGRE_DMG;
   		flag=0;
   } 
   /* // J M →ŧ
   if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
     e=defO1(e,i,p);
     flag=0;
   } // J M←ŧ
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
     e= defO2(e,i,p);
     flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
     e=defO3(e,i,p);
     flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
     e=defO4(e,i,p);
     flag=0;
   }
   // na persegue dá-se primasia as diagonais
   if(flag) e=persegueO(e,i,p);
   return e;
}
*/
