#include <stdio.h>

int teacher_calc(int x, int y, int z, int loops) {
	int i;
	for (i = 0; i < loops; i++) 
		x = x * y - z;
	if (loops <= 2) x = x / 2;
	return x;
}

//You have to write this in assembly that will do the same thing as teacher_calc
int student_calc(int x, int y, int z, int loops);

int main() {
	int x,y,z,loops;
	printf("Please enter x,y,z,loops:\n");
	scanf("%i %i %i %i",&x,&y,&z,&loops);
	int retval1 = teacher_calc(x,y,z,loops);
	int retval2 = student_calc(x,y,z,loops);
	printf("Retval1: %i\nRetval2: %i\n",retval1,retval2);
}
