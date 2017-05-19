#include "scripts.h"

void wolf_scripts(){
	START_SCRIPT;
	printf("function wolfDescription(){\n");
	printf("\t<p>Teste</p>;\n");
	printf("}\n");
	END_SCRIPT;
}

void imprime_scripts(){
	wolf_scripts();
}