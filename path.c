//#define DEBUG
#include "path.h"

/**
\brief Cria um caminho a ser evitado quando o mapa está a ser gerado 
	   para garantir que há pelo menos um caminho possivel para chegar a saida.
	   Esta função também define a posição inicial do jogador e de saida
@param Array de posições do caminho a ser evitado
*/
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
			case 1: if(path[i-1].x!=(char) SIZE-1){
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
					if(path[i-1].x==(char) SIZE-1){
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