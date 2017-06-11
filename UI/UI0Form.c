#include "UI0Form.h"

void imprimeForm(){
	printf("<div style=\"background-image:url(%sScreenForm.png);width:800px;height:600px;\">\n",IMAGE_PATH);
	printf("\t<form action=\"roguel\" method=\"GET\" style=\"padding-top: 300px;text-align: center;\">\n");
	printf("\t<input type=\"text\" name=\"N\" style=\"font-size:20pt;height:50px;width:200px;text-align: center;\" maxlength=\"13\"><br><br>\n");
	printf("\t<button type=\"submit\" style=\"background:url(%sbutton_form_submit.png);width:200px;height:74px;border-width: 0px;\"></button>\n",IMAGE_PATH);
	printf("\t</form>\n");
	printf("</div>\n");
}