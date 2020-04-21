#include<stdio.h>

int min(int a, int b);

/*int main(void) {
	int fenzi,fenmu,i;

	scanf("%d/%d", &fenzi, &fenmu);
	i = min(fenzi, fenmu);
	while (i > 1) {
		if (fenzi % i == 0 && fenmu % i == 0) {
			fenzi /= i;
			fenmu /= i;
			i++;
		}
		i--;
	}

	printf("%d/%d", fenzi, fenmu);
	return 0;
}

int min(int a, int b) {
	if (a > b)return b;
	else return a;
}*/


#include<stdio.h>    
#include<string.h>  
#include <stdlib.h>    
	int main()
	{
		char s[100] = "";
		char k[20] = "";
		charchar *p = s;
		int hh, mm, ss, sum, b;
		do
		{
			scanf("%s", s);
			if (strstr(s, "$GPRMC") && strstr(s, ",A,"))
			{
				int i = 1;
				sum = s[1];
				for (i = 2;s[i] != '*';i++)
				{
					sum ^= s[i];
				}
				sprintf(k, "%X", sum % 65536);
				p = strchr(s, '*') + 1;
				if (strcmp(k, p) == 0)
				{
					p = strchr(s, ',') + 1;
					int b = atoi(strncpy(k, p, 6));
					hh = b / 10000;
					mm = b % 10000 / 100;
					ss = b % 100;
					if (hh >= 16)
						hh -= 16;
					else
						hh += 8;
				}
			}
		} while (strcmp(s, "END"));
		printf("%02d:%02d:%02d", hh, mm, ss);
	}
