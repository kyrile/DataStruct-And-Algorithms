#include <stdio.h>
void show_data(int data[], size_t size) {
	for (size_t k = 0; k < size; k++)
	{
		printf(" %d", data[k]);
	}
	printf("\n");
}
void BubbleSort(int data[], size_t size/*线性表的长度 9 */) {
	for (size_t i = 0; i < size - 1/*还需要循环的次数*/; i++)
	{
		for (size_t j = 0; j < size - 1/*避免超出线性表的长度*/ - i/*每一次的循环都会使最后两个一定是[正序]*/; j++)
		{
			//[][][], 是不是反序？
			if (data[j] > data[j + 1]) {
				//交换顺序表里面两个格子的数据
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
		show_data(data, size);
	}
}
int main()
{
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	show_data(data, size);
	BubbleSort(data, size);
}




