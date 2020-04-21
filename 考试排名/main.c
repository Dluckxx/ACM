#include<stdio.h>
#include<string.h>

int main(void) {

	int problem, fen, length, temp = 0, i = 0, j = 0, k = 0, l = 0;
	char name[1000][11] = { 0 };
	char str[1000] = { 0 };
	char number[1000] = { 0 };
	char copy[1000] = { 0 };
	int ac[1000] = { 0 };
	int score[1000] = { 0 };
	char *ptr = NULL;

	scanf("%d %d", &problem, &fen);

	while (scanf("%s", name[i]) != EOF) {
		while (j < problem) {
			scanf("%s", str);
			length = strlen(str);
			//记载AC
			if (str[0] != '-' && str[0] != '0') {
				ac[i]++;
				//找到()并获得中间的值
				if (str[length - 1] == ')') {
					temp = 1;
					while (str[length - 2] != '(') {
						score[i] += temp*(str[length - 2] - 48)*fen;
						temp *= 10;
						length--;
					}
					strcpy(number, strtok(str, "("));
					length = strlen(str);
					temp = 1;
					while (length--) {
						score[i] += temp*(number[length] - 48);
						temp *= 10;
					}
				}
				else{
					temp = 1;
					while (length--) {
						score[i] += temp*(str[length] - 48);
						temp *= 10;
					}
				}
			}
			else if (str[0] == '-' || str[0] == '0') {
				j++;
				continue;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//排序按AC
	j = 0;
	k = 0;
	while (j++ < i) {
		while (++k < i) {
			if (ac[k - 1] < ac[k]) {
				temp = ac[k - 1];
				ac[k - 1] = ac[k];
				ac[k] = temp;
				temp = score[k - 1];
				score[k - 1] = score[k];
				score[k] = temp;
				strcpy(copy, name[k - 1]);
				strcpy(name[k - 1], name[k]);
				strcpy(name[k], copy);
				if (ac[k - 1] == ac[k]) {
					//排序按分数
					if (score[k - 1] > score[k]) {
						temp = ac[k - 1];
						ac[k - 1] = ac[k];
						ac[k] = temp;
						temp = score[k - 1];
						score[k - 1] = score[k];
						score[k] = temp;
						strcpy(copy, name[k - 1]);
						strcpy(name[k - 1], name[k]);
						strcpy(name[k], copy);
						//排序按name	
						if (score[k - 1] == score[k]) {
							if (name[k - 1][0] > name[k][0]) {
								temp = ac[k - 1];
								ac[k - 1] = ac[k];
								ac[k] = temp;
								temp = score[k - 1];
								score[k - 1] = score[k];
								score[k] = temp;
								strcpy(copy, name[k - 1]);
								strcpy(name[k - 1], name[k]);
								strcpy(name[k], copy);
							}
						}
					}
				}
			}
		}
	}
	//输出结果
	while (l < i) {
		printf("%-10s ", name[l]);
		printf("%2d ", ac[l]);
		printf("%4d\n", score[l]);
		l++;
	}
	return 0;
}