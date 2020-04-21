#include<stdio.h>
#include<string.h>

int main()
{
	int temp = 0;
	char str[1000] = "";
	gets(str);
	for (int i = 0; i < 1000; i++)
	{
		if (i == strlen(str) - 1) {
			if(temp != 0) printf("%d\n", temp);
			break;
		}
		else if (isspace(str[i])) {
			if (temp != 0) printf("%d ", temp);
			temp = 0;
		}
		else{
			temp++;
		}
	}
	return 0;
}