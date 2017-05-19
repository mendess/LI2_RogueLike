//#define DEBUG

#include "score.h"

int importScoreBoard(int scoreBoard[]){
	FILE *scoreFile;
	scoreFile=fopen("/var/www/html/score/scoreBoard","r");
	if(!scoreFile){
		scoreFile=fopen("/var/www/html/score/scoreBoard","w");
		fclose(scoreFile);
		return 0;
	}
	int i=0, flag=0;
	while(i<SB_SIZE && flag!=-1){
		flag=fscanf(scoreFile,"%d\n",&scoreBoard[i++]);
	}

	fclose(scoreFile);

	return i-1;
}
int insertScore(int score, int scoreBoard[], int num_scores){
	int i=0;
	while(i<num_scores && score<scoreBoard[i]){
		i++;
	}
	if(i==num_scores){
		if(num_scores<SB_SIZE){
			scoreBoard[num_scores++]=score;
		}
	}else{
		while(i<num_scores){
			int tmp = scoreBoard[i];
			scoreBoard[i]=score;
			score=tmp;
			i++;
		}
		if(num_scores<SB_SIZE){
			scoreBoard[num_scores++]=score;
		}
	}
	return num_scores;
}
void exportScoreBoard(int scoreBoard[], int num_scores){
	FILE *scoreFile;
	scoreFile=fopen("/var/www/html/score/scoreBoard","w");
	int i;
	for(i=0;i<num_scores;i++){
		fprintf(scoreFile,"%d\n", scoreBoard[i]);
	}
	fclose(scoreFile);
}
void updateScoreBoard(int score){
	int scoreBoard[SB_SIZE];
	int num_scores;

	num_scores = importScoreBoard(scoreBoard);
	num_scores = insertScore(score, scoreBoard, num_scores);
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
