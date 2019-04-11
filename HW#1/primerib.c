#include <stdio.h>
#include <math.h>
int main() {
	double rib, totalTime, ah, am, ami, as;
	int hours1, hours,min, sec;
	printf("How many pounds is your prime rib? ");
	scanf("%lf", &rib);
	totalTime = 5.0 * rib;
	ah = totalTime / 60.0;
	hours1 = (int)ah;
	hours = hours1 + 2.0;
	am = ah - hours1;
	ami = am * 60.0;
	min = (int) ami;
	as = ((ami - min) * 60.0);
	sec =  ceil(as - 0.01);
	printf("Your rib will be in the oven for %d hours, %d minutes, and %d seconds.", hours, min, sec);
	return 0;
}
