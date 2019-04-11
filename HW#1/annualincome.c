#include <stdio.h>

int main() {
	double Result, salary;
	printf("What is your hourly wage? ");
	scanf("%lf", &salary);
	Result=salary * 2080;
	int intpart=(int)Result;
	int decpart = ((Result - intpart) * 100) + 0.5;
	printf("Your total income over a year is %d dollars and %d cents", intpart,decpart);
	return 0;
}
