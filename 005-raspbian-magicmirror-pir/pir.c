#include <stdio.h>
#include <wiringPi.h>
  
int main (void)
{
	int status = 0;

	if(wiringPiSetup() == -1)
	{
		printf("setup failed!");
		return -1;
	}

	printf("start\n");

	pinMode (7, INPUT) ;

	for(int i=0 ; i<5 ; i++)
	{
		if(digitalRead(7) == 1)
		{
			printf("detected!\n");
			return 1;
		}

		delay(1000);
	}
	printf("nobody!\n");
	return 0;
}
