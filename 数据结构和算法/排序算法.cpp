#include <stdio.h>
void show_data(int data[], size_t size) {
	for (size_t k = 0; k < size; k++)
	{
		printf(" %d", data[k]);
	}
	printf("\n");
}
void BubbleSort(int data[], size_t size/*线性表的长度 9 */) {
	printf("算法思想：两两if(相邻记录的关键字)，if(反序) {交换}，while(没有反序的记录为止);");
	for (size_t i = 0; i < size - 1/*还需要循环的次数*/; i++)//8
	{
		for (size_t j = 0; j < size - 1/*避免超出线性表的长度*/ - i/*每一次的循环都会使最后两个一定是[正序]*/; j++)
		{
			//[][][], 是不是反序？
			if (data[j] > data[j + 1]) {//大→小（正序）
				//交换顺序表里面两个格子的数据
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}	
		}
		show_data(data, size);
	}
}
void BubbleTest() {
	printf("------------冒泡排序-------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("原始数据：\n");
	show_data(data, size);
	BubbleSort(data, size);
	printf("最终结果：");
	show_data(data, size);
}
void swap(int data[], int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void SelectSort(int data[], size_t size) {
	printf("算法思想：通过n-i次关键字间的比较，从n-i＋1个记录中选出关键字最小的记录，并和第i（1≤i≤n）个记录交换之。");
	//小→大
	int i/*总的循环次数*/, j/*每一次循环的总次数*/, min = 0;/*最小的小标*/
	for (i = 0; i < (int)size - 1; i++) {
		min = i;
		for (j = i + 1; j < (int)size; j++)
			if (data[j] < data[min]) {
				min = j;
			}
		swap(data, i, min);
		show_data(data, size);
	}
}
void SelectTest() {
	printf("-----------选择排序---------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("原始数据：\n");
	show_data(data, size);
	SelectSort(data, size);
	printf("最终结果：");
	show_data(data, size);
}

void InsertSort(int data[], size_t size) {
	printf("算法思想：将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表");
	for (size_t i = 1; i < size; i++)//总的循环次数
	{
		for (size_t j = i; j > 0; j--)//每一次的循环次数
		{
			if (data[j] < data[j - 1])
				swap(data, j, j - 1);
			else
				break;
		}
		show_data(data, size);
	}
}
void InsertTest() {
	printf("------------插入排序---------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("原始数据：\n");
	show_data(data, size);
	InsertSort(data, size);
	printf("最终结果：");
	show_data(data, size);
};
int main()
{
	BubbleTest();
	SelectTest();
	InsertTest();
	return 0;
}




