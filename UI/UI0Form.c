#include "UI0Form.h"

void imprimeForm(){
	printf("<div style=\"background-image:url(%sScreenForm.png);width:800px;height:600px;\">\n",IMAGE_PATH);
	printf("\t<form action=\"roguel\" method=\"GET\" align=\"center\" style=\"padding-top: 300px;\">\n");
	printf("\t<input type=\"text\" name=\"N\" maxlength=\"13\" style=\"font-size:12pt;height:50px;width:200px\"><br><br>\n");
	printf("\t<input type=\"image\" src=\"%sbutton_form_submit.png\" alt=\"Submit Form\" value=\"Submit\" style=\"font-size:12pt;width:200pxheight:74px;\">\n",IMAGE_PATH);
	printf("\t</form>\n");
	printf("</div>\n");
}