#include "estado.h"

/**
\brief Converto o estado numa string para ser usado no url 
@param e O estado do jogo
*/
char *estado2str(ESTADO e) {
	static char buffer[MAX_BUFFER];
	char *p = (char *) &e;
	int i;

	buffer[0] = 0;

	for(i = 0; i < sizeof(ESTADO); i++)
		sprintf(buffer, "%s%02x", buffer, p[i]);

	return buffer;
}

/**
\brief Converte uma query num estado
@param argumentos Query a ser convertida
*/
ESTADO str2estado(char *argumentos) {
	ESTADO e;
	char *p = (char *) &e;
	int i;

	for(i = 0; i < sizeof(ESTADO); i++, argumentos += 2) {
		int d;
		sscanf(argumentos, "%2x", &d);
		p[i] = (char) d;
	}

	return e;
}
