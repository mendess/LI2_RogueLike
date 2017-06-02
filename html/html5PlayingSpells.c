#include "html5PlayingSpells.h"
void i_cTarget(int type,POSICAO p){
	char *targetMolds[] = TARGET_MOLDS;
	SQUARE(TAM*(p.x+1),TAM*(p.y+1),"black",0.0,targetMolds[type-3],1.0,TAM);
}
int cTgt2Int(POSICAO p){
	return 10000+(p.x*100)+p.y;
}
int isRepeat(POSICAO *picked,int N,POSICAO p){
	int i;
	int repeat=0;
	for (i = 0; i < N && !repeat; ++i){
		if(picked[i].x==p.x && picked[i].y==p.y){
			repeat=1;
		}
	}
	return repeat;
}
int nearPlayer(POSICAO jog, POSICAO p){
	int near=0;
	int i,j;
	for (i = -2; i < 3 && !near; ++i){
		for (j = -2; j < 3 && !near; ++j){
			if(jog.x+i==p.x || jog.y+j==p.y){
				near=1;
			}
		}
	}
	return near;
}
/* RED ZONE */
void i_castTargetsRed(ESTADO *e){
	POSICAO castTargets[] = RED_CAST_TARGETS(e->jog);
	int i;
	for(i=0;i<37;i++){
		if(!outOfBounds(castTargets[i]) && !com_pedras(*e,castTargets[i])){
			char query[4];
			sprintf(query,"%d",cTgt2Int(castTargets[i]));
			ABRIR_LINK(e->name,query);
			i_cTarget(e->complexItem.type,castTargets[i]);
			FECHAR_LINK;
		}
	}
}
void i_confirmCastRed(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int pXmax=p.x+2;
	int pYmax=p.y+2;
	for(p.x=pXmax-3;p.x<pXmax;p.x++){
		for (p.y=pYmax-3;p.y < pYmax; p.y++){
			if(!outOfBounds(p) && !com_pedras(*e,p)){
				SQUARE(TAM*(p.x+1),TAM*(p.y+1),"black",0.3,"red",0.0,TAM);
			}
		}
	}
}
void i_CastRed(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int pXmax=p.x+2;
	int pYmax=p.y+2;
	for(p.x=pXmax-3;p.x<pXmax;p.x++){
		for (p.y=pYmax-3;p.y < pYmax; p.y++){
			if(!outOfBounds(p) && !com_pedras(*e,p)){
				IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,FIRE_IMAGE);
			}
		}
	}
}
/* YELLOW ZONE */
void i_castTargetsYellow(ESTADO *e){
	POSICAO p = e->jog;
	int pXmax = e->jog.x+3;
	int pYmax = e->jog.y+3;
	for(p.x=pXmax-5; p.x < pXmax; ++p.x){
		for(p.y=pYmax-5; p.y < pYmax; ++p.y){
			if(com_monstros(*e,p)){
				char query[4];
				sprintf(query,"%d",cTgt2Int(p));
				ABRIR_LINK(e->name,query);
				CIRCLE((p.x+1)*TAM,(p.y+1)*TAM,TAM/2,"black",0.0,"yellow",1.0,TAM);
				FECHAR_LINK;
			}
		}
	}
}
void i_confirmCastYellow(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	CIRCLE((p.x+1)*TAM,(p.y+1)*TAM,TAM/2,"black",0.3,"yellow",1.0,TAM);
}
void i_CastYellow(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int plrCx = e->jog.x+1;
	int plrCy = e->jog.y+2;
	int rotX = ((e->jog.x+1)*TAM)+TAM/2;
	int rotY = ((e->jog.y+1)*TAM)+TAM/2;

	int height = sqrt((pow(p.x-e->jog.x,2)+pow(p.y-e->jog.y,2)));
	p.x-=e->jog.x;
	p.y-=e->jog.y;
	double angle;
	if(p.y==0){
		angle=p.x<0 ? 90 : -90;
	}else if(p.x==0){
		angle=p.y<0 ? 180 : 0;
	}else{
		angle=atan((double)p.y/(double)p.x)*(180/M_PI)+(p.x<0 ? 90 : -90);
	}
	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none transform=\"rotate(%f %d %d)\" xlink:href=%sSpell_Lightning.png />\n",
			  plrCx*TAM,plrCy*TAM,TAM,height*TAM                                         ,angle,rotX,rotY,  IMAGE_PATH);

}
/* BLUE ZONE */
void i_castTargetsBlue(ESTADO *e){
	srand(e->turn);
	int i=0,placed=0;
	POSICAO picked[5];
	while(i<5){
		POSICAO p;
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		p.x= x;
		p.y= y;
		if (!pos_ocupada(*e,p) && !nearPlayer(e->jog,p) && !isRepeat(picked,i,p) /*&& !com_chest(e,p)*/){
			placed=1;
			char query[4];
			sprintf(query,"%d",cTgt2Int(p));
			ABRIR_LINK(e->name,query);
			//i_cTarget(e->complexItem.type,p);
			CIRCLE((p.x+1)*TAM,(p.y+1)*TAM,TAM/2,"white",0.0,"blue",1.0,TAM);
			FECHAR_LINK;
			picked[i]=p;
		}
		if (placed){
			i++;
			placed=0;
		}
	}
}
void i_confirmCastBlue(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	CIRCLE((p.x+1)*TAM,(p.y+1)*TAM,TAM/2,"black",0.3,"blue",1.0,TAM);
}
void i_CastBlue(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	SQUARE(TAM*(p.x+1),TAM*(p.y+1),"black",0.0,"blue",1.0,TAM);
}
void imprime_castSpell(ESTADO *e){
	switch(e->complexItem.type){
		case 3: i_CastRed(e);
				break;
		case 4: i_CastYellow(e);
				break;
		/*case 5: i_CastGreen(e):
				break;*/
		case 6: i_CastBlue(e);
				break;
	}
}
void imprime_confirmCast(ESTADO *e){
	switch(e->complexItem.type){
		case 3: i_confirmCastRed(e);
				break;
		case 4: i_confirmCastYellow(e);
				break;
		/*case 5: i_confirmCastGreen(e):
				break;*/
		case 6: i_confirmCastBlue(e);
				break;
	}
}
void imprime_castTargets(ESTADO *e){
	if(e->complexItem.lastPickedTarget>9999){
		imprime_confirmCast(e);
	}
	switch(e->complexItem.type){
		case 3: i_castTargetsRed(e);
				break;
		case 4: i_castTargetsYellow(e);
				break;
		/*case 5: i_castTargetsGree(e);
				break;*/
		case 6: i_castTargetsBlue(e);
				break;
	}
}