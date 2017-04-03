#ifndef ___ESTADO_H___
#define ___ESTADO_H___

#include <stdio.h>

#include "jogo.h"

#define MAX_BUFFER		10240

char *estado2str(ESTADO e);
ESTADO str2estado(char *argumentos);

#endif