#include "IAdragon.h"

ESTADO fireCone(ESTADO e){
	if(e.jog.x>=((e.dragon.pos.x+1)-((e.jog.y-e.dragon.pos.y)/2)) && e.jog.x<=((e.dragon.pos.x+2)+(e.jog.y-e.dragon.pos.y)/2) && e.jog.y>e.dragon.pos.y+3 ) {
		e.hp-=5;
	}
	return e;
}
ESTADO wing_attack (ESTADO e){
	if(e.jog.x>=1 && e.jog.x<=8 && e.jog.y>=(e.dragon.pos.y+4) && e.jog.y<(e.dragon.pos.y+6)){
		e.hp-=10;
		if(e.jog.y+3<10){
			e.jog.y+=3;
		}
		if(e.jog.y+3>9){
			e.jog.y=9;
		}
	}
	return e;
}
ESTADO fireball_damage (ESTADO e){
 int i;
	for(i=0;i<e.dragon.num_fireballs;i++){
		if(e.dragon.fireballCenters[i].x==e.jog.x && e.dragon.fireballCenters[i].y==e.jog.y){
			e.hp-=15;
		}
	}
	return e;
}
ESTADO fireball_attack (ESTADO e){
	int i,x,y;
	y=e.dragon.pos.y+3;// minimo
	i=(rand() % 8)+8;
	e.dragon.num_fireballs=i;
	POSICAO b;
	e.dragon.fireballCenters[0].x=e.jog.x;
	e.dragon.fireballCenters[0].y=e.jog.y;
	for(x=1;x<i;x++){
		do{
			b.x=(rand() % 10);
			b.y=(rand() % 10);
		}while(outOfBounds(b) || com_boss(e,b) || b.y<y);	//b1<y||b1>y+3||(b2<e.jog.x-2)|| b2>(e.jog.x+2)|| b2>9 || b2<0);
		e.dragon.fireballCenters[x].x=b.x;
		e.dragon.fireballCenters[x].y=b.y;
	}
	return e;
}
ESTADO dragon_movement (ESTADO e){
	int flag=1;
	POSICAO p;
	p.x=e.dragon.pos.x;
	p.y=e.dragon.pos.y;
	if (e.jog.x<=p.x+1 && p.x>0){
		e.dragon.pos.x-=1;
		flag=0;
	}
	if(flag && e.jog.x>=p.x+2 && p.x+3<9){
		e.dragon.pos.x+=1;
	}
	if(e.dragon.attack==1 && abs(e.jog.y-p.y)>1){
		e.dragon.pos.y+=1;
	}
	if(e.dragon.attack==2 && abs(e.jog.y-p.y)==1 && p.y>0){
		e.dragon.pos.y-=1;
	}
	if(e.dragon.attack==2 && abs(e.jog.y-p.y)>3 && p.y){
		e.dragon.pos.y+=1;
	}
	if(p.y>1){
		e.dragon.pos.y-=1;
	}
	return e;
}
// 1-fireball;2-wingAttack;3-fireCone
ESTADO estrat_dragon (ESTADO e){
	if(e.dragon.hp>0){
		e=dragon_movement(e);
		if(e.turn%2!=0){
			srand(time(NULL));
			e.dragon.attack=(rand() % 3)+1;
			if(e.dragon.attack==1){
				e=fireball_attack(e);
			}
		}
		if(e.turn !=0 && e.turn%2==0){
			if(e.dragon.attack==1){
				e=fireball_damage(e);
			}
			if(e.dragon.attack==2){
				e=wing_attack(e);
			}
			if(e.dragon.attack==3){
				e=fireCone(e);
			}
		}
	}
	return e;
}