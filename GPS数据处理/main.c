#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>

int main() {

	int temp = 0, check = 0;//校验值
	char *ptr = NULL, c = '*';
	char string[100] = "";

	while (1) {

		gets(string);
		
		if (string[0] != '$')
			break;

		if (string[3] != 'R')
			continue;

		ptr = strchr(string, c);

		int length = strlen(string) - (int)(ptr - string + 1);

		for (int i = 1; i <= length; i++)
		{
			check += (string[ptr - string + i] - 48) * pow(16, length - i);
		}

		//printf("end check = %d\n", check);
		//计算校验值
		temp = string[1] ^ string[2];
		for (int i = 3; i < strlen(string) - 3; i++)
		{
			temp ^= string[i];
		}
		temp %= 65536;

		if (temp == check) {
			//printf("right,%c\n",string[18]);
			if (string[18] == 'A') {
				int a = (string[7] - 48) * 10 + string[8] - 48;
				if (a <= 16)
					a += 8;
				else if (a > 16)
					a -= 16;
				//a赋值给string[7],[8]
				string[7] = a / 10 + 48;
				string[8] = a % 10 + 48;
			}
		}
	}
	printf("%c%c:%c%c:%c%c", string[7], string[8], string[9], string[10], string[11], string[12]);
	
	return 0;
}