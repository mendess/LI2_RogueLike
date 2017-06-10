#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IAbat.h"

int livre (ESTADO e,int x,int y){
	int flag;
	POSICAO pos;
	pos.x=x;
	pos.y=y;
	flag=1;
	if(inBounds(pos)!=1){
		flag=0;
	}
	if(com_monstros(e,pos)) flag=0;
	return flag;
}
POSICAO buscaBat1 (ESTADO e,int a[SIZE][SIZE]){
	int x,y,flag;
	POSICAO intersect;
	flag=1;
	for(y=0;y<10;y++){
		for(x=9;x>=0;x--){
			if(a[x][y] == 0 && livre(e,x,y) && flag){
				intersect.x=x;
				intersect.y=y;
				flag=0;
			}
		}
	}
	return intersect;
}
POSICAO buscaBat2 (ESTADO e,int a[SIZE][SIZE]){
	int x,y,flag;
	POSICAO intersect;
	flag=1;
	for(y=9;y>=0;y--){
		for(x=0;x<10;x++){
			if(a[x][y] == 0 && livre(e,x,y) && flag){
				intersect.x=x;
				intersect.y=y;
				flag=0;
			}
		}
	}
	return intersect;
}
POSICAO buscaBat3 (ESTADO e,int a[SIZE][SIZE]){
	int x,y,flag;
	POSICAO intersect;
	flag=1;
	for(y=0;y<10;y--){
		for(x=0;x<10;x++){
			if(a[x][y] == 0 && livre(e,x,y) && flag){
				intersect.x=x;
				intersect.y=y;
				flag=0;
			}
		}
	}
	return intersect;
}
POSICAO buscaBat4 (ESTADO e,int a[SIZE][SIZE]){
	int x,y,flag;
	POSICAO intersect;
	flag=1;
	for(y=9;y>=0;y--){
		for(x=9;x>=0;x--){
			if(a[x][y] == 0 && livre(e,x,y) && flag){
				intersect.x=x;
				intersect.y=y;
				flag=0;
			}
		}
	}
	return intersect;
}// previsão da posição em que o jogador estará daqui a tantas jogadas
// como metade da distancia em x e y entre monstro e jogador
POSICAO mapa3 (ESTADO e,POSICAO p,int num){
	int d,x,y;
	int a[SIZE][SIZE];
	POSICAO intersect;
	d=(abs(e.jog.x-p.x)+abs(e.jog.y-p.y))/2-1;
	for(y=0;y<10;y++){
		for(x=0;x<10;x++){
			if (abs(x-e.jog.x)>=abs(y-e.jog.y)){
				a[y][x]=abs(x-e.jog.x)-d;
			}
			if (abs(y-e.jog.y)>abs(x-e.jog.x)){
				a[y][x]=abs(y-e.jog.y)-d;
			}
		}
	}
	if(num==1) intersect=buscaBat1(e,a);
	if(num==2) intersect=buscaBat2(e,a);
	if(num==3) intersect=buscaBat3(e,a);
	if(num==4) intersect=buscaBat4(e,a);
	return intersect;
}
ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect){
	POSICAO p;
	int flag=1;
	p.x=e.monstros[i].x;
	p.y=e.monstros[i].y;
	if (flag && p.x > intersect.x && p.y > intersect.y && livre(e,p.x-1,p.y-1)){
		e.monstros[i].x+=-1;
		e.monstros[i].y+=-1;
		flag=0;
	}
	if (flag && p.x > intersect.x && p.y < intersect.y && livre(e,p.x-1,p.y+1)){
		e.monstros[i].x+=-1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (flag && p.x < intersect.x && p.y > intersect.y && livre(e,p.x+1,p.y-1)){
		e.monstros[i].x+=1;
		e.monstros[i].y+=-1;
		flag=0;
	}
	if (flag && p.x < intersect.x && p.y < intersect.y && livre(e,p.x+1,p.y+1)){
		e.monstros[i].x+=1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (flag && p.y == intersect.y && p.x < intersect.x && livre(e,p.x+1,p.y)){
		e.monstros[i].x+=1;
		flag=0;
	}
	if (flag && p.x == intersect.x && p.y > intersect.y && livre(e,p.x,p.y-1)){
		e.monstros[i].y+=-1;
		flag=0;
	}
	if (flag && p.y == intersect.y && p.x > intersect.x && livre(e,p.x-1,p.y)){
		e.monstros[i].x+=-1;
		flag=0;
	}
	if (flag && p.x == intersect.x && p.y<intersect.y && livre(e,p.x,p.y-1)){
		e.monstros[i].y+=1;
		flag=0;
	}
	return e;
}
ESTADO defesaBat (ESTADO e, int i,POSICAO p,int num){
	POSICAO intersect;
	intersect= mapa3(e,p,num);
	e=estrat_bat1(e,i,intersect);
	return e;
}// ve se o monstro está entre o jogador e a saida e em que quadrante está.
ESTADO estrat_bat(ESTADO e,int i,POSICAO p){
	int flag=1;
	if (existe_jogador(e,p)){
		e.hp-=BAT_DMG;
		flag=0;
	} // J M →ŧ
	if(flag && e.jog.x<p.x && e.jog.y>p.y && e.saida.x>p.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y){
		e=defesaBat(e,i,p,1);
		flag=0;
	} // J M←ŧ
	if(flag && e.jog.x>p.x && e.jog.y>p.y && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y){
		e= defesaBat(e,i,p,2);
		flag=0;
	} // J M←↓
	if(flag && e.jog.x>p.x && e.jog.y<p.y && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y){
		e=defesaBat(e,i,p,3);
		flag=0;
	} // J M→↓
	if(flag && e.jog.x<p.x && e.jog.y<p.y && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y){
		e=defesaBat(e,i,p,4);
		flag=0;
	}
	if(flag) e=estrat_bat1(e,i,e.jog);
	return e;
}
