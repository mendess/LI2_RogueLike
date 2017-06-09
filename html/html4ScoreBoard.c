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
		IMAGEM(110+(30*i),155+(41*index),33,33,filepath);
		i++;
	}
}
void imprimeScoreBoard(char *name){
	ABRIR_SVG;

	SCORE scoreBoard[SB_SIZE];
	int i;
	int num_scores = importScoreBoard(scoreBoard);
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenScoreBoard.png");
	for (i = 0; i < num_scores; ++i){
		imprime_name(scoreBoard[i].name,i);
		imprime_score(scoreBoard[i].score,i);
	}
	ABRIR_LINK(name,"0");/* back */
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;
}
