#include <stdio.h>
#include <math.h>
int main() {
	int currGrade, final, finalExam, finalGrade;
	double a;
	printf("What is your current grade? ");
	scanf("%d",&currGrade);
	printf("How much is the final worth? ");
	scanf("%d",&final);
	printf("What is your final exam score? ");
	scanf("%d",&finalExam);
	a = (double) ((currGrade * 0.01*(100.0 - final)) + (0.01*final)*finalExam);
	finalGrade = ceil(a);
	printf("Your final grade is %d%%", finalGrade);
	return 0;
}
