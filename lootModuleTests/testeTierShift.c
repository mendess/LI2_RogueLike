#include <stdio.h>
#include <math.h>

int main(){
	FILE *fp;
	fp=fopen("resultTS.txt","w");
	int i=0;
	printf("\tTierShift\n");
	fprintf(fp,"\tTierShift\n");
	for (i = 0; i < 100; ++i){
		double tierShift;
		tierShift=0.9/(1+500*exp(-0.25*i));

		printf("lvl %d:\t%f\n",i,tierShift);
		fprintf(fp,"lvl %d:\t%3.f\n",i,tierShift*10000);
	}
	fclose(fp);
	return 0;
}


/*

0  = 10
50 = 90
*/
