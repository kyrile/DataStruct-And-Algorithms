#ifdef WIN32
#define  _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <memory>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct DouNode
{
	struct DouNode* prior;
	ElemType data;
	struct DouNode* next;
}DouNode, * DouLinkList;

DouLinkList InitList();
int ListLength(DouLinkList L);
int GetElem(DouLinkList L, ElemType e);
ElemType GetElemByIndex(DouLinkList L, int index, ElemType* e);
Status ListInsert(DouLinkList L, int i, ElemType e); 
Status ListDelete(DouLinkList L, int i);
void ListClear(DouLinkList* L);
void print(DouLinkList L);

int main(int count, char* argv[]) {
	DouLinkList L;
	ElemType e = 0;
	int index = 0;
	printf("������ڵ�����ݣ�����-1����ʾ��ֹ\n");
	L = InitList();
	printf("˫����ĳ��ȣ�%d\n", ListLength(L));
	print(L);
	printf("��������Ҫ֪���ĵڼ���λ��:");
	scanf("%d", &e);
	GetElemByIndex(L, index, &e);
	printf("��λ���ϵ���Ϊ��%d\n", e);
	printf("��������֪���������Ƿ���ڸ�Ԫ�ص�ֵ��");
	scanf("%d", &e);
	GetElem(L, e);

	printf("�����������ڵڼ���λ�ò���Ԫ�أ�");
	scanf("%d", &index);
	printf("��������������Ԫ��ֵ��");
	scanf("%d", &e);
	ListInsert(L, index, e);
	print(L);

	printf("����������ɾ���Ľڵ�λ�ã�");
	scanf("%d", &index);
	ListDelete(L, index);
	print(L);
	
	ListClear(&L);
	printf("˫����ĳ��ȣ�%d\n", ListLength(L));
	return 0;
}

DouLinkList InitList()
{
	int data, size;
	DouLinkList L, Last, p;
	L = (DouLinkList)malloc(sizeof(DouNode));
	L->prior = NULL;
	L->next = NULL;
	Last = L;
	printf("������ڵ�ֵ������-1��ʾ������ɣ�");//���潻��
	size = 0;
	printf("��ǰ����Ĵ�С��%d\n", size);
	while (true)
	{
		if (scanf("%d", &data) != 1) break;
		if (data == -1) break;
		p = (DouLinkList)malloc(sizeof(DouNode));
		if (p == NULL)
		{
			printf("�ڴ治�㣬��ֹ����\n");
			break;
		}
		p->data = data;
		Last->next = p;
		p->prior = Last;
		p->next = NULL;
		Last = p;
	}
	Last->next = NULL;
	return L;//����ͷ�ڵ�
}

int ListLength(DouLinkList L)
{
	int length = 0;
	if (L == NULL) return 0;
	if (L->next == NULL) return 0;
	while (L->next)
	{
		L = L->next;
		length++;
	}
	return length;
}

int GetElem(DouLinkList L, ElemType e)
{
	int found = 0;
	int index = 1;
	if (L == NULL) return ERROR;
	if (L->next == NULL) return ERROR;
	L = L->next;
	do 
	{
		if (L->data == e)
		{
			printf("�ҵ�һ���ڵ㣬λ���ڣ�%d\n", index);
			found = 1;
		}
		L = L->next;
		index++;
	} while (L);
	if (found == 0)
	{
		printf("ָ��ֵ�Ľڵ㣬һ��Ҳû���ҵ�");
		return ERROR;
	}
	return OK;
}

int GetElemByIndex(DouLinkList L, int index, ElemType* e)
{
	int i = 0;//����˼ά���±�
	if ((L == NULL) || (L->next == NULL) || (index < 1))
	{
		return ERROR;
	}
	while (L->next && i < index)
	{
		L = L->next;
		i++;
	}
	if (i == index)
	{
		*e = L->data;
		return OK;
	}
	return ERROR;
}

Status ListInsert(DouLinkList L, int i, ElemType e)
{
	//�ֲ�������inserted index length
	//����: L i e
	//����ֵ��
	DouLinkList inserted;//Ҫ����Ľڵ�
	int index = 0;
	int length = ListLength(L);
	if ((L == NULL) || (i > length + 1) || (i <= 0)) {
		return ERROR;
	}
	while ((L->next != NULL) && (index < i))
	{
		L = L->next;
		index++;
	}
	inserted = (DouLinkList)malloc(sizeof(DouNode));
	inserted->data = e;
	inserted->next = L->next;
	inserted->prior = L;
	if (L->next)
	{
		L->next->prior = inserted;
	}
	L->next = inserted;
	return OK;
}

Status ListDelete(DouLinkList L, int i)
{
	int index = 0;
	int length = ListLength(L);
	if ((i <= 0) || (i > length) || (L == NULL) || (L->next == NULL))
	{
		return ERROR;
	}
	while (L->next && index < i)
	{
		L = L->next;
		index++;
	}
	L->prior->next = L->next;
	if (L->next)
	{
		L->next->prior = L->prior;
	}
	free(L);
	return OK;
}

void ListClear(DouLinkList* L)
{
	DouLinkList p = *L;
	while (p->next)
	{
		p = p->next;
		free(p->prior);
	}
	free(p);
	*L = NULL;
}

void print(DouLinkList L)
{
	int index = 0;
	while (L->next)
	{
		L = L->next;
		if (index > 0) printf("->");
		printf("%d", L->data);
		index++;
	}
	printf("\n");
}
