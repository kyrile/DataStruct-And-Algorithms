#include <stdio.h>
void show_data(int data[], size_t size) {
	for (size_t k = 0; k < size; k++)
	{
		printf(" %d", data[k]);
	}
	printf("\n");
}
void BubbleSort(int data[], size_t size/*���Ա�ĳ��� 9 */) {
	printf("�㷨˼�룺����if(���ڼ�¼�Ĺؼ���)��if(����) {����}��while(û�з���ļ�¼Ϊֹ);");
	for (size_t i = 0; i < size - 1/*����Ҫѭ���Ĵ���*/; i++)//8
	{
		for (size_t j = 0; j < size - 1/*���ⳬ�����Ա�ĳ���*/ - i/*ÿһ�ε�ѭ������ʹ�������һ����[����]*/; j++)
		{
			//[][][], �ǲ��Ƿ���
			if (data[j] > data[j + 1]) {//���С������
				//����˳��������������ӵ�����
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}	
		}
		show_data(data, size);
	}
}
void BubbleTest() {
	printf("------------ð������-------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("ԭʼ���ݣ�\n");
	show_data(data, size);
	BubbleSort(data, size);
	printf("���ս����");
	show_data(data, size);
}
void swap(int data[], int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void SelectSort(int data[], size_t size) {
	printf("�㷨˼�룺ͨ��n-i�ιؼ��ּ�ıȽϣ���n-i��1����¼��ѡ���ؼ�����С�ļ�¼�����͵�i��1��i��n������¼����֮��");
	//С����
	int i/*�ܵ�ѭ������*/, j/*ÿһ��ѭ�����ܴ���*/, min = 0;/*��С��С��*/
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
	printf("-----------ѡ������---------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("ԭʼ���ݣ�\n");
	show_data(data, size);
	SelectSort(data, size);
	printf("���ս����");
	show_data(data, size);
}

void InsertSort(int data[], size_t size) {
	printf("�㷨˼�룺��һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�һ���µġ���¼����1�������");
	for (size_t i = 1; i < size; i++)//�ܵ�ѭ������
	{
		for (size_t j = i; j > 0; j--)//ÿһ�ε�ѭ������
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
	printf("------------��������---------------\n");
	int data[] = { 12, 5, 2, 9, 7, 13, 7, 11, 1 };
	int size = sizeof(data) / sizeof(int);
	printf("ԭʼ���ݣ�\n");
	show_data(data, size);
	InsertSort(data, size);
	printf("���ս����");
	show_data(data, size);
};
int main()
{
	BubbleTest();
	SelectTest();
	InsertTest();
	return 0;
}




