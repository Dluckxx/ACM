//
//  main.c
//  c yuyan
//
//  Created by anzhongyin on 2016/11/29.
//  Copyright © 2016年 anzhongyin. All rights reserved.
//

#include <stdio.h>
//#include <math.h>

int main(int argc, const char * argv[]) {
	// insert code here...
	// TODO Auto-generated method stub
	int a, b;

	int number[101] = { 0 };
	for (int i = 0;i<2;i++)
	{
		do
		{
			scanf("%d %d", &a, &b);
			number[a] += b;
		} while (a);
	}
	int c = 1;
	for (int i = 101 - 1;i >= 2;i--)
	{
		if (c)
		{
			if (number[i] == 1 || number[i] == -1)
			{
				printf("x%d", i);
				c = 0;
			}
			else if (number[i] != 0)
			{
				printf("%dx%d", number[i], i);
				c = 0;
			}
		}
		else
		{
			if (number[i] == 1)
			{
				printf("+x%d", i);

			}
			else if (number[i] == -1)
			{
				printf("x%d", i);

			}

			else if (number[i]>0)
			{

				printf("+%dx%d", number[i], i);
			}
			else if (number[i]<0)
			{
				printf("%dx%d", number[i], i);
			}

		}

		
	}
	if (c)
	{
		if (number[1] == 1 || number[1] == -1)
		{
			printf("x");
			c = 0;
		}
		else if (number[1] != 0)
		{
			printf("%dx", number[1]);
			c = 0;
		}

		if (number[0] != 0)
		{
			printf("%d", number[0]);
			c = 0;
		}
	}
	else
	{
		if (number[1] == 1)
		{

			printf("+x");
		}
		else if (number[1] == -1)
		{

			printf("x");
		}
		else if (number[1]>0)
		{
			printf("+%dx", number[1]);

		}
		else if (number[1]<0)
		{
			printf("%dx", number[1]);

		}

		if (number[0]>0)
		{
			printf("+%d", number[0]);

		}
		else if (number[0]<0)
		{
			printf("%d", number[0]);

		}

	}

	if (c) {
		printf("0");
	}
	printf("\n");
	return 0;
}