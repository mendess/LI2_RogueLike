#include "estado.h"

/**
\brief Converto o estado numa string para ser usado no url 
@param e O estado do jogo
*/
void estado2str(ESTADO e, FILE *fp) {
	/*static char buffer[MAX_BUFFER];
	char *p = (char *) &e;
	int i;

	buffer[0] = 0;

	for(i = 0; i < sizeof(ESTADO); i++)
		sprintf(buffer, "%s%02x", buffer, p[i]);

	return buffer;*/
	PRT_FIELD(fp,e,screen);
	PRT_FIELD(fp,e,classe);
	PRT_FIELD(fp,e,hp);
	PRT_FIELD(fp,e,mp);
	PRT_FIELD(fp,e,world_lvl);
	PRT_FIELD(fp,e,score);
	PRT_FIELD(fp,e,turn);
	PRT_FIELD(fp,e,direction);
	PRT_FIELD(fp,e,action);
	PRT_POSICAO(fp,e,jog);
	PRT_POSICAO(fp,e,saida);
	PRT_FIELD(fp,e,num_monstros);
	PRT_FIELD(fp,e,num_pedras);
	int i=0;
	fprintf(fp,"[*");
	while(i++<num_monstros){
		PRT_MSTR(fp,e,monstros);
	}
	fprintf(fp,"*]");
	i=0;
	fprintf(fp,"[*");
	while(i++<num_pedras){
		PRT_POSICAO(fp,e,pedras[i])
	}
	fprintf(fp,"*]");
}

/**
\brief Converte uma query num estado
@param argumentos Query a ser convertida
*/
ESTADO str2estado(char *argumentos) {
	/*ESTADO e;
	char *p = (char *) &e;
	int i;

	for(i = 0; i < sizeof(ESTADO); i++, argumentos += 2) {
		int d;
		sscanf(argumentos, "%2x", &d);
		p[i] = (char) d;
	}

	return e;*/
	
}
