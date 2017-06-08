/* #define DEBUG */

#include "score.h"

int importScoreBoard(SCORE scoreBoard[]){
	FILE *scoreFile;
	int i, flag;
	i=0;flag=0;
	scoreFile=fopen("/var/www/html/score/scoreBoard","r");
	if(!scoreFile){
		scoreFile=fopen("/var/www/html/score/scoreBoard","w");
		if(scoreFile==NULL){
			perror("Não consegui escrever o ficheiro de scores");
		}else{
			fclose(scoreFile);
		}
		return 0;
	}
	while(i<SB_SIZE && flag!=-1){
		flag=fscanf(scoreFile,"%[^,],%d\n",scoreBoard[i].name,&scoreBoard[i].score);
		if(flag!=-1){
			i++;
		}
	}
	fclose(scoreFile);
	return i;
}
int insertScore(char *name, int score, SCORE scoreBoard[], int num_scores){
	int i=0;
	SCORE newSC;
	strcpy(newSC.name,name);
	newSC.score=score;
	while(i<num_scores && score<scoreBoard[i].score){
		i++;
	}
	if(i==num_scores){
		if(num_scores<SB_SIZE){
			scoreBoard[num_scores++]=newSC;
		}
	}else{
		while(i<num_scores){
			SCORE tmp = scoreBoard[i];
			scoreBoard[i]=newSC;
			newSC=tmp;
			i++;
		}
		if(num_scores<SB_SIZE){
			scoreBoard[num_scores++]=newSC;
		}
	}
	return num_scores;
}
void exportScoreBoard(SCORE scoreBoard[], int num_scores){
	FILE *scoreFile;
	int i;
	scoreFile=fopen("/var/www/html/score/scoreBoard","w");
	if(scoreFile==NULL){
		perror("Não consegui escrever o ficheiro de scores");
	}else{
		for(i=0;i<num_scores;i++){
			fprintf(scoreFile,"%s,%d\n", scoreBoard[i].name, scoreBoard[i].score);
		}
		fclose(scoreFile);
	}
}
void updateScoreBoard(char *name, int score){
	SCORE scoreBoard[SB_SIZE];
	int num_scores;

	num_scores = importScoreBoard(scoreBoard);
	num_scores = insertScore(name, score, scoreBoard, num_scores);
	exportScoreBoard(scoreBoard, num_scores);
}

#ifdef DEBUG
void printSB(int scoreBoard[], int num_scores){
	int i=0;
	while(i < num_scores){
		printf("%d\n", scoreBoard[i++]);
	}
}
int main(){
	srand(time(NULL));
	int x = rand() % 20;
	printf("%d\n",x);
	updateScoreBoard(x);
	return 0;
}
#endif
