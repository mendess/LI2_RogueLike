#include "html4ScoreBoard.h"

void imprime_score(int score, int index){
	int digitPos=0;
	while(score){
		int digit = score % 10;
		char filepath[15];
		score = score / 10;
		sprintf(filepath,"Numero_%d.png",digit);
		IMAGEM(680-(33*digitPos),155+(41*index),33,33,filepath);
		digitPos++;
	}
}
void imprime_name(char name[], int index){
	int i=0;
	while(name[i]){
		char filepath[15];
		if(name[i]>96 && name[i]<123){
			sprintf(filepath,"Letra_%c%c.png",name[i],name[i]);	// minusculas
		}else if(name[i]>64 && name[i]<91){
			sprintf(filepath,"Letra_%c.png",name[i]);	// maiusculas
		}else if(name[i]>47 && name[i]<58){
			sprintf(filepath,"Letra_%d.png",(int) name[i]-48);	// numeros
		}
		IMAGEM(130+(30*i),155+(41*index),33,33,filepath);
		i++;
	}
}
void imprime_place(int place, int index){
	int digitPos=0;
	while(place){
		int digit = place % 10;
		char filepath[15];
		place = place / 10;
		sprintf(filepath,"Numero_%d.png",digit);
		IMAGEM(90-(33*digitPos),155+(41*index),33,33,filepath);
		digitPos++;
	}
}
void i_scoreBoardNormal(){
	SCORE scB=NULL;
	int i=0;
	importScoreBoard(&scB);
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenScoreBoard.png");
	while(scB!=NULL && i<10){
		imprime_place(i+1,i);
		imprime_name(scB -> name,i);
		imprime_score(scB-> score,i);
		i++;
		scB = scB -> prox;
	}
	free(scB);
}
void i_scoreBoardFiltered(char *name){
	SCORE scB=NULL;
	int i=0;
	int place=1;
	importScoreBoard(&scB);
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenScoreBoard.png");
	while(scB!=NULL && i<10){
		if(strcmp(scB->name,name)==0){
			imprime_place(place,i);
			imprime_name(scB -> name,i);
			imprime_score(scB-> score,i);
			i++;
		}
		place++;
		scB = scB -> prox;
	}
	free(scB);
}
void imprimeScoreBoard(char *name, int filtered){
	ABRIR_SVG;
	if(filtered){
		i_scoreBoardFiltered(name);
	}else{
		i_scoreBoardNormal();
	}
	ABRIR_LINK(name,"50");
	printf("<rect x=740 y=540 width=60 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK(name,"0");/* back */
	printf("<rect x=0 y=540 width=60 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	FECHAR_SVG;
}
