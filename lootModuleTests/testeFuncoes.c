#include <stdio.h>
#include <math.h>

int main(){
	FILE *fp;
	fp=fopen("result.txt","w");
	int i=0;
	printf("\tTier 1\tTier 2\tTier 3\tTier 4\tSUM\n");
	fprintf(fp,"\tTier 1\tTier 2\tTier 3\tTier 4\tSUM\n");
	for (i = 0; i < 50; ++i){
		double tier1,tier2,tier3,tier4;
		double tierShift;
		tier1=((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000;
		tier4=(89/(1 + 99999999*exp(-0.5*i)))*1000+1;
		double tmp=100000-tier1-tier4;
		tierShift=0.9/(1+170*exp(-0.25*i));
		tier3=tmp*tierShift;
		tier2=tmp-tier3;

		printf("lvl %d:\t%1.f\t%1.f\t%1.f\t%1.f\t%1.f\n",i,tier1,tier2,tier3,tier4,tier1+tier2+tier3+tier4);
		fprintf(fp,"lvl %d:\t%3.f\t%3.f\t%3.f\t%3.f\t%3.f\n",i,tier1,tier2,tier3,tier4,tier1+tier2+tier3+tier4);
	}
	fclose(fp);
	return 0;
}


/*

0  = 10
50 = 90
*/
