#include "html3ScoreBoard.h"

void imprime_score(int score, int index){
	int digitPos=0;
	while(score){
		int digit = score % 10;
		score = score / 10;
		char filepath[15];
		sprintf(filepath,"Number%d.png",digit);
		IMAGEM(472-(TAM*digitPos),90+(TAM*index),TAM,TAM,filepath);
		digitPos++;
	}
}
void imprimeScoreBoard(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenScoreBoard.png");
	int scoreBoard[SB_SIZE];
	int num_scores = importScoreBoard(scoreBoard);
	int i;
	for (i = 0; i < num_scores; ++i){
		imprime_score(scoreBoard[i],i);
	}
	ABRIR_LINK("0");//back
	printf("<rect x=5 y=526 width=103 height=70 style=opacity:0;></rect>\n");
	FECHAR_LINK;
}