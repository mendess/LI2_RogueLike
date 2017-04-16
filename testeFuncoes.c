#include <stdio.h>
#include <math.h>

int main(){
	FILE *fp;
	fp=fopen("result.txt","w");
	int i=0;
	printf("\tTier 1\tTier 2\tTier 3\tTier 4\tSUM\n");
	fprintf(fp,"\tTier 1\tTier 2\tTier 3\tTier 4\tSUM\n");
	for (i = 0; i < 50; ++i){
		float bronze,iron,steel,Palladium;
		bronze=(-(90 / (1 + 79*exp(-(0.25*i)))))+91.125;
		iron=90*exp(-pow(((i-13.333333) / 8.343280258),2));
		steel=90*exp(-pow(((i-26.66666666) / 13.66773488),2));
		Palladium=90/(1 + 79*exp(-0.25*i));
		printf("lvl %d:\t%3.f\t%3.f\t%3.f\t%3.f\t%3.f\n",i,bronze,iron,steel,Palladium,bronze+iron+steel+Palladium);
		fprintf(fp,"lvl %d:\t%3.f\t%3.f\t%3.f\t%3.f\t%3.f\n",i,bronze,iron,steel,Palladium,bronze+iron+steel+Palladium);
	}
	fclose(fp);
	return 0;
}