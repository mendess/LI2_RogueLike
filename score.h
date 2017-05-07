#ifndef ___SCORE_H___
#define ___SCORE_H___

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SB_SIZE 	10

int importScoreBoard(int scoreBoard[]);
int insertScore(int score, int scoreBoard[], int num_scores);
void exportScoreBoard(int scoreBoard[], int num_scores);
void updateScoreBoard(int score);

#endif