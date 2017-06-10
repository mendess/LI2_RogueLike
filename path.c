/* #define DEBUG */
#include "path.h"

int pathMaker(POSICAO path[]){
	int plrX;
	int decision, i;
	i=0;

	srand(time(NULL));
	plrX=rand() % 10;
	path[0].x= plrX;
	path[0].y= 9;

	decision=2;
	while(path[i].y!= 0 && i<MAX_CAMINHO){
		i++;
		switch(decision){
			/* esquerda */
			case 0: if(path[i-1].x!=0){
						decision=rand() % 2;
						switch(decision){
							/* esquerda */
							case 0: path[i].x=path[i-1].x-1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		/* cima */
							case 1: path[i].x=path[i-1].x;
									path[i].y=path[i-1].y-1;
					 				break;
						}
					}else{
						path[i].x=path[i-1].x;
						path[i].y=path[i-1].y-1;
					}
					break;
			/* direita */
			case 1: if(path[i-1].x!= SIZE-1){
						decision=rand() % 2;
						switch(decision){
							/* direita */
							case 0: path[i].x=path[i-1].x+1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		/* cima */
					 		case 1: path[i].x=path[i-1].x;
					 				path[i].y=path[i-1].y-1;
					 				break;
					 		}
					}else{
						path[i].x=path[i-1].x;
						path[i].y=path[i-1].y-1;
					}
					break;
			/* cima */
			case 2: if(path[i-1].x==0){
						decision=rand() % 2;
						switch(decision){
							/* direita */
							case 0: path[i].x=path[i-1].x+1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		/* cima */
					 		case 1: path[i].x=path[i-1].x;
					 				path[i].y=path[i-1].y-1;
					 				break;
						}
						break;
					}
					if(path[i-1].x==SIZE-1){
						decision=rand() % 2;
						switch(decision){
							/* esquerda */
							case 0: path[i].x=path[i-1].x-1;
					 				path[i].y=path[i-1].y;
					 				break;
					 		/* cima */
							case 1: path[i].x=path[i-1].x;
									path[i].y=path[i-1].y-1;
					 				break;
						}
						break;
					}
					decision=rand () % 3;
					switch(decision){
						/* esquerda */
						case 0: path[i].x=path[i-1].x-1;
				 				path[i].y=path[i-1].y;
					 			break;
						/* direita */
						case 1: path[i].x=path[i-1].x+1;
				 				path[i].y=path[i-1].y;
					 			break;
						/* cima */
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
		printf("%d,%d\n",path[i].x,path[i].y);
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