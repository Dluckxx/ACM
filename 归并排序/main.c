#include<stdio.h>

#define SIZE 10

//合并数组的前半部分和后半部分， 前提就是前后两个子数组分别都已经排好序了
void mergeArray(int a[], int first, int mid, int last) {

	int i, j, m, n;
	i = first, m = mid;
	j = mid + 1, n = last;
	int k = 0;
	int temp[SIZE];

	while (i <= m && j <= n) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}

	while (i <= m) temp[k++] = a[i++];
	while (j <= n) temp[k++] = a[j++];

	for (i = 0; i<k; i++) {
		a[first + i] = temp[i];
	}

}
//归并排序
void merge_sort(int a[], int start, int end) {
	int mid = (start + end) / 2;
	if (start<end) {
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		mergeArray(a, start, mid, end);
	}
}




int main() {
	int a[SIZE];
	int i;
	printf("Please input the num:\n");
	for (i = 0; i<SIZE; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("before the sort:\n");
	for (i = 0; i<SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	merge_sort(a, 0, SIZE - 1);

	printf("after the sort:\n");
	for (i = 0; i<SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}