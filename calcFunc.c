#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define START_VALUE	81
#define END_VALUE	100

int main()
{
	int lvl;
	float t1,t2,t3,t4;
	float t1Value,t2Value,t3Value,t4Value;
	FILE *fp;
	fp=fopen("resultsCalcFunc_81-100.txt","w");
	fprintf(fp,"VERSION: START_VALUE=%d END_VALUE=%d\n-------------------------------------\n",START_VALUE,END_VALUE);
	for (t1 = START_VALUE; t1 < END_VALUE; t1+=0.001){
		for (t2 = START_VALUE; t2 < END_VALUE; t2+=0.001){
			for (t3 = START_VALUE; t3 < END_VALUE; t3+=0.001){
				for (t4 = START_VALUE; t4 < END_VALUE; t4+=0.001){
					int flag=1;
					printf("\n\nt1:%f\nt2:%f\nt3:%f\nt4:%f\n\n",t1,t2,t3,t4);
					for (lvl = 0; lvl < 50 && flag; ++lvl){
						t1Value=(-(90 / (1 + t1*exp(-(0.25*lvl)))))+91.125;
						t2Value=90*exp(-pow(((lvl-13.33333333) / t2),2));
						t3Value=90*exp(-pow(((lvl-26.66666666) / t3),2));
						t4Value=90/(1 + t4*exp(-0.25*lvl));
						if(t1Value+t2Value+t3Value+t4Value>102 || t1Value+t2Value+t3Value+t4Value<98){
							flag=0;
						}
					}
					system("cls");
					if(flag){
						printf("Victory:\n\tt1:%f\n\tt2:%f\n\tt3:%f\n\tt4:%f\n", t1,t2,t3,t4);
						fprintf(fp,"Victory:\n\tt1:%f\n\tt2:%f\n\tt3:%f\n\tt4:%f\n", t1,t2,t3,t4);
					}
				}
			}
		}
	}
	printf("No more results\n");
	fprintf(fp,"No more results\n");
	fclose(fp);
	return 0;
}