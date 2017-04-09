#include "score.h"

int updateScoreBoard(int score, int scoreBoard[], int num_scores){
	int i=0;
	while(i<num_scores && score<scoreBoard[i]){
		i++;
	}
	while(0 < i--){
		printf("%d\n", scoreBoard[i]);		
	}
	fclose(scoreFile);
	return 0;
}
int importScoreBoard(int scoreBoard[]){
	FILE *scoreFile;
	scoreFile=fopen("score/scoreBoard","r+");
	if(!scoreFile){
		scoreFile=fopen("score/scoreBoard","w+");
		return 0;
	}
	int i=0, flag=0;
	do{
		flag=fscanf(scoreFile,"%d\n",&scoreBoard[i]);

	}while(++i<SB_SIZE && flag);

	return i;
}

int main(){
	FILE * fp;
	fp = fopen("score/scoreBoard","w+");
	int i;
	for(i=0;i<10;i++){
		fprintf(fp,"%d\n", 123456789-(i*100));		
	}
	fclose(fp);

	int scoreBoard[SB_SIZE];
	int num_scores = importScoreBoard(scoreBoard);
	updateScoreBoard('0', scoreBoard);
	return 0;
}