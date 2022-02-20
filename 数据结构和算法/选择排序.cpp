#include <stdio.h>
void show_data(int data[], size_t size) {
	for (size_t k = 0; k < size; k++)
	{
		printf(" %d", data[k]);
	}
	printf("\n");
}
void swap(int data[], int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void SelectSort(int data[], size_t size) {
	//С����
	int i, j, min = 0;
	for (i = 0; i < (int)size - 1; i++) {
		min = i;
		for (j = i + 1; j < (int)size; j++)
			if (data[j] < data[min]){
				min = j;
			}
		swap(data, i, min);
		show_data(data, size);
	}
}
int main() {
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	printf("ԭʼ���ݣ�\n");
	show_data(data, sizeof(data) / sizeof(int));
	SelectSort(data, sizeof(data) / sizeof(int));
	printf("���ս����\n");
	show_data(data, sizeof(data) / sizeof(int));
	return 0;
}