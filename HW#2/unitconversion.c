#include <stdio.h>

int main(void){
	double initial;
	char ini, des, o, g, p ,c, q;
	int res;

	printf("Enter your current measurement and unit of volume: ");
	scanf("%lf %c", &initial, &ini);
	
	if (initial > 0 || ini == 'o' || ini == 'p' || ini == 'g' || ini == 'c' || ini == 'q' ) {
	}
	else {
		printf("Error! You entered a negative number.\n Error! Enter one of 'g' for gallons, 'q' for quarts, 'p' for pints, 'c' for cups, or 'o' for ounces.\n");
	return 0;
	}
	if (initial > 0) {
	} 
	else {
		printf("Error! You entered a negative number.\n");
	return 0;
	}

	if (ini == 'o' || ini == 'p' || ini == 'g' || ini == 'c' || ini == 'q') {
	}
	else {
		printf("Error! Enter one of 'g' for gallons, 'q' for quarts, 'p' for pints, 'c' for cups, or 'o' for ounces.\n");
		return 0;
	}

	printf(" Enter your desired unit of volume: ");
	scanf(" %c", &des);
	
	o = (des == 'o');
	g = (des == 'g');
	p = (des == 'p');
	c = (des == 'c');
	q = (des == 'q');

	if (o || p || c || q || g) {
	}
	else {
		printf("Error! Enter one of 'g' for gallons, 'q' for quarts, 'p' for pints, 'c' for cups, or 'o' for ounces.");
	}

	if ( o && ini == 'o') {
	res = (int) initial;
	printf("You have %d ouncess of liquid.", res);
	}
 	if ( o && ini == 'c') {
        res = (int) initial * 8 + 0.5;
        printf("You have %d ouncess of liquid.", res);
        }
        if ( o && ini == 'p') {
	res = (int) initial * 16 + 0.5;
	printf("You have %d ounces of liquid.", res);
	}
        if ( o && ini == 'q') {
        res = (int) initial * 32 + 0.5;
	printf("You have %d ounces of liquid.", res);
        }
        if ( o && ini == 'g') {
        res = (int) initial * 128 + 0.5;
	printf("You have %d ounces of liquid.", res);
	}


	if ( c && ini == 'o') {
	res = (int) initial / 8 + 0.5 ;
	printf("You have %d cups of liquid.", res);
	}
 	if ( c && ini == 'c') {
        res = (int) initial + 0.5;
        printf("You have %d cups of liquid.", res);
        }
        if ( c && ini == 'p') {
	res = (int) initial * 2 + 0.5;
	printf("You have %d cups of liquid.", res);
	}
        if ( c && ini == 'q') {
        res = (int) initial * 4 + 0.5;
	printf("You have %d cups of liquid.", res);
        }
if ( c && ini == 'g') {
        res = (int) initial * 16 + 0.5;
	printf("You have %d cups of liquid.", res);
	}

	if ( p && ini == 'o') {
	res = (int) initial / 8 + 0.5;
	printf("You have %d pints of liquid.", res);
	}
 	if ( p && ini == 'c') {
        res = (int) initial / 2 + 0.5;
        printf("You have %d pints of liquid.", res);
        }
        if ( p && ini == 'p') {
	res = (int) initial + 0.5;
	printf("You have %d pints of liquid.", res);
	}
        if ( p && ini == 'q') {
        res = (int) initial * 2 + 0.5;
	printf("You have %d pints of liquid.", res);
        }
        if ( p && ini == 'g') {
        res = (int) initial * 8 + 0.5;
	printf("You have %d pints of liquid.", res);
	}


	if ( q && ini == 'o') {
	res = (int) initial / 32  + 0.5;
	printf("You have %d quarts of liquid.", res);
	}
 	if ( q && ini == 'c') {
        res = (int) initial / 4 + 0.5;
        printf("You have %d quarts of liquid.", res);
        }
        if ( q && ini == 'p') {
	res = (int) initial / 2 + 0.5;
	printf("You have %d quarts of liquid.", res);
	}
        if ( q && ini == 'q') {
        res = (int) initial + 0.5;
	printf("You have %d quarts of liquid.", res);
        }
        if ( q && ini == 'g') {
        res = (int) initial * 4 + 0.5;
	printf("You have %d quarts of liquid.", res);
	}


	if ( g && ini == 'o') {
	res = (int) initial / 64 + 0.5;
	printf("You have %d gallons of liquid.", res);
	}
 	if ( g && ini == 'c') {
        res = (int) initial / 16 + 0.5;
        printf("You have %d gallons of liquid.", res);
        }
        if ( g && ini == 'p') {
	res = (int) initial / 8 + 0.5;
	printf("You have %d gallons of liquid.", res);
	}
        if ( g && ini == 'q') {
        res = (int) initial / 4 + 0.5;
	printf("You have %d gallons of liquid.", res);
        }
        if ( g && ini == 'g') {
        res = (int) initial + 0.5;
	printf("You have %d gallons of liquid.", res);
	}

	return 0;
}	

