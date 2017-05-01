#ifndef ___ESTADO_H___
#define ___ESTADO_H___

#include <stdio.h>

#include "jogo.h"

#define MAX_BUFFER				10240

#define str(s)					#s
#define PRT_FIELD(f,e,field)	fprintf(f,str(field) ": %d\n",(int) e.field)
#define PRT_POSICAO(f,e,field)	fprintf(f,str(field) ": %d,%d\n",(int) e.field.x,(int) e.field.y);
#define PRT_MSTR(f,e,field)		fprintf(f,str(field) ": x=%d,y=%d,monType=%d,hp=%d\n",(int) e.field.x,(int) e.field.y,(int) e.field.monType,(int) e.field.hp);

#define SCAN_FIELD(f,e,field)	if(fscanf(f,str(field) ": %d\n", &e.field))
#define SCAN_POSICAO(f,e,field)	if(fscanf(f,str(field) ": %d,%d\n",&e.field.x,&e.field.y);
#define SCAN_MSTR(f,e,field)	if(fscanf(f,str(field) ": x=%d,y=%d,monType=%d,hp=%d\n",&e.field.x,&e.field.y,&e.field.monType,&e.field.hp);

char *estado2str(ESTADO e);
ESTADO str2estado(char *argumentos);

#endif


typedef struct monster{
    char x;
    char y;
    char monType;
    char hp;
}MSTR;