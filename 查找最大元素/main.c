#include <stdio.h>

int main(void) {
	int i;
	char str[101], max = 'a';
	while (scanf("%s", str) != EOF) {
		max = 'a';

		for (i = 0; i < strlen(str); i++) {
			if (str[i] > max)
				max = str[i];
		}

		for (i = 0; i < strlen(str); i++) {
			printf("%c", str[i]);
			if (str[i] == max)
				printf("(max)");
		}

		printf("\n");
	}
	return 0;
}