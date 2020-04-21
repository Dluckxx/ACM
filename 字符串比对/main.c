#include<stdio.h>
#include<string.h>

int main(void) {
	char str1[10001] = { 0 }, str2[10001] = { 0 };
	char *ptr;

	gets(str1);
	gets(str2);

	ptr = strstr(str2, str1);
	if (ptr == NULL) {
		printf("-1");
		exit(0);
	}

	while (1) {
		ptr = strstr(str2, str1);
		if(ptr != NULL) {
			*ptr += 1;
			printf("%d ", ptr - str2);
		}
		else break;
	}
	return 0;
}