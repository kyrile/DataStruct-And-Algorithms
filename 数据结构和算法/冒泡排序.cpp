#include <stdio.h>
void show_data(int data[], size_t size) {
	for (size_t k = 0; k < size; k++)
	{
		printf(" %d", data[k]);
	}
	printf("\n");
}
void BubbleSort(int data[], size_t size/*���Ա�ĳ��� 9 */) {
	for (size_t i = 0; i < size - 1/*����Ҫѭ���Ĵ���*/; i++)
	{
		for (size_t j = 0; j < size - 1/*���ⳬ�����Ա�ĳ���*/ - i/*ÿһ�ε�ѭ������ʹ�������һ����[����]*/; j++)
		{
			//[][][], �ǲ��Ƿ���
			if (data[j] > data[j + 1]) {
				//����˳��������������ӵ�����
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




