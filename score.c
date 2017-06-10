#include "score.h"

void add2List(SCORE *scB, char name[], int score){
	if(*scB==NULL){
		SCORE newSB;
		newSB = malloc(sizeof(struct score));
		strcpy(newSB -> name, name);
		newSB -> score = score;
		newSB -> prox = NULL;
		*scB = newSB;
	}else{
		while((*scB) -> prox!=NULL){
			scB = &((*scB) -> prox);
		}
		SCORE newSB;
		newSB = malloc(sizeof(struct score));
		strcpy(newSB -> name, name);
		newSB -> score = score;
		newSB -> prox = NULL;
		(*scB) -> prox = newSB;
	}
}
void importScoreBoard(SCORE *scB){
	FILE *scoreFile;
	scoreFile=fopen(SCORE_PATH,"r");
	if(!scoreFile){
		scoreFile=fopen(SCORE_PATH,"w");
		if(scoreFile==NULL){
			perror("Não consegui escrever o ficheiro de scores");
		}else{
			fclose(scoreFile);
		}
	}else{
		int flag = 0;
		while(flag!=-1){
			char name[20];
			int score;
			flag=fscanf(scoreFile,"%[^,],%d\n",name,&score);
			if(flag!=-1){
				add2List(scB, name, score);
			}
		}
		fclose(scoreFile);
	}
}
void insertOrd (SCORE *scB, char *name, int score){
    SCORE newSB = malloc(sizeof(struct score));
    strcpy(newSB -> name, name);
    newSB -> score = score;
    if(*scB==NULL){
        newSB -> prox = NULL;
        *scB = newSB;
    }else if((*scB) -> score < score){
        newSB -> prox = *scB;
        *scB = newSB;
    }else{
        SCORE prev, next;
        prev = *scB;
        next = prev -> prox;
        while(next != NULL && next -> score > score){
            prev = next;
            next = next -> prox;
        }
        newSB -> prox = next;
        prev -> prox = newSB;
    }
}
void exportScoreBoard(SCORE scB){
	FILE *scoreFile;
	scoreFile=fopen(SCORE_PATH,"w");
	if(scoreFile==NULL){
		perror("Não consegui escrever o ficheiro de scores");
	}else{
		while(scB!=NULL){
			fprintf(scoreFile,"%s,%d\n", scB -> name, scB -> score);
			scB = scB -> prox;
		}
		fclose(scoreFile);
	}
}
void freeScB(SCORE scB){
	while(scB!=NULL){
		SCORE tmp = scB;
		scB = scB -> prox;
		free(tmp);
	}
}
void updateScoreBoard(char *name, int score){
	SCORE scB=NULL;
	importScoreBoard(&scB);
	insertOrd(&scB,name,score);
	exportScoreBoard(scB);
	freeScB(scB);
}