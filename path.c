//#define DEBUG

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "jogo.h"
#include "path.h"

/* Creates a path to be avoided when generating the map to make sure there is at least one path to the exit.
This also sets the players starting position and the exit*/
int pathMaker(POSICAO path[]){
	int plrX;
	srand(time(NULL));
	plrX=rand() % 10;
	path[0].x=(char) plrX;
	path[0].y=(char) 9;

	int decision,i=0;
	decision=2;
	while(path[i].y!=(char) 0 && i<MAX_CAMINHO){
		i++;
		srand(time(NULL));
		switch(decision){
			//esquerda
			case 0: if(path[i-1].x!=(char) 0){
						decision=rand() % 2;
						switch(decision){
							//esquerda
							case 0: path[i].x=path[i-1].x-1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		//cima
							case 1: path[i].x=path[i-1].x;
									path[i].y=path[i-1].y-1;
					 				break;
						}
					}else{
						path[i].x=path[i-1].x;
						path[i].y=path[i-1].y-1;
					}
					break;
			//direita
			case 1: if(path[i-1].x!=(char) MAP_SIZE-1){
						decision=rand() % 2;
						switch(decision){
							//direita
							case 0: path[i].x=path[i-1].x+1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		//cima
					 		case 1: path[i].x=path[i-1].x;
					 				path[i].y=path[i-1].y-1;
					 				break;
					 		}
					}else{
						path[i].x=path[i-1].x;
						path[i].y=path[i-1].y-1;
					}
					break;
			//cima
			case 2: if(path[i-1].x==(char) 0){
						decision=rand() % 2;
						switch(decision){
							//direita
							case 0: path[i].x=path[i-1].x+1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		//cima
					 		case 1: path[i].x=path[i-1].x;
					 				path[i].y=path[i-1].y-1;
					 				break;
						}
						break;
					}
					if(path[i-1].x==(char) MAP_SIZE-1){
						decision=rand() % 2;
						switch(decision){
							//esquerda
							case 0: path[i].x=path[i-1].x-1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		//cima
							case 1: path[i].x=path[i-1].x;
									path[i].y=path[i-1].y-1;
					 				break;
						}
						break;
					}
					decision=rand () % 3;
					switch(decision){
						//esquerda
						case 0: path[i].x=path[i-1].x-1;
				 				path[i].y=path[i-1].y;
					 			break;
						//direita
						case 1: path[i].x=path[i-1].x+1;
				 				path[i].y=path[i-1].y;
					 			break;
						//cima
						case 2: path[i].x=path[i-1].x;
				 				path[i].y=path[i-1].y-1;
					 			break;
					}
					break;
		}
	}
	return i+1;
}

#ifdef DEBUG
void printPath(int n, POSICAO path[]){
	int i;
	for (i = 0; i < n; ++i){
		printf("%d,%d\n", (int) path[i].x,(int) path[i].y);
	}
	printf("%d\n", i);
}
int main(){
	POSICAO path[MAX_CAMINHO];
	int n;
	n=pathMaker(path);
	printPath(n,path);
	return 0;
}
#endif