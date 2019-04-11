#include <stdio.h>
#include <math.h>
int main() {
	int num, i, step;
	double res, guess;

	printf("Enter the integer you wish to find the square root of: \n");
	scanf("%d", &num);
	printf("Enter your first guess and number of steps: \n");
	scanf("%lf %d", &guess, &step);
 	
	i = 1;
	while (i <= step) 
	{
	
	res  = (double) num / guess;
	guess = (double) (guess + res) / 2.0;
	i = i + 1;
	}
	printf("The square root of %d is approximately %0.5lf\n", num, guess);

	return 0;
}	
