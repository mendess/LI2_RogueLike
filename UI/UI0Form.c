#include "UI0Form.h"

void imprimeForm(){
	printf("<form action=\"roguel\" method=\"GET\">\n");
	printf("<input type=\"text\" name=\"N\"/>\n");
	printf("<input type=\"submit\" value=\"Submit\"/>\n");
	printf("</form>\n");
}