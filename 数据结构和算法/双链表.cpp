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
	printf("请输入节点的数据，输入-1，表示终止\n");
	L = InitList();
	printf("双链表的长度：%d\n", ListLength(L));
	print(L);
	printf("请输入想要知道的第几个位置:");
	scanf("%d", &e);
	GetElemByIndex(L, index, &e);
	printf("该位置上的数为：%d\n", e);
	printf("请输入想知道链表中是否存在该元素的值：");
	scanf("%d", &e);
	GetElem(L, e);

	printf("请输入你想在第几个位置插入元素：");
	scanf("%d", &index);
	printf("请输入你想插入的元素值：");
	scanf("%d", &e);
	ListInsert(L, index, e);
	print(L);

	printf("请输入你想删除的节点位置：");
	scanf("%d", &index);
	ListDelete(L, index);
	print(L);
	
	ListClear(&L);
	printf("双链表的长度：%d\n", ListLength(L));
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
	printf("请输入节点值（输入-1表示输入完成）");//界面交互
	size = 0;
	printf("当前链表的大小：%d\n", size);
	while (true)
	{
		if (scanf("%d", &data) != 1) break;
		if (data == -1) break;
		p = (DouLinkList)malloc(sizeof(DouNode));
		if (p == NULL)
		{
			printf("内存不足，终止操作\n");
			break;
		}
		p->data = data;
		Last->next = p;
		p->prior = Last;
		p->next = NULL;
		Last = p;
	}
	Last->next = NULL;
	return L;//返回头节点
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
			printf("找到一个节点，位置在：%d\n", index);
			found = 1;
		}
		L = L->next;
		index++;
	} while (L);
	if (found == 0)
	{
		printf("指定值的节点，一个也没有找到");
		return ERROR;
	}
	return OK;
}

int GetElemByIndex(DouLinkList L, int index, ElemType* e)
{
	int i = 0;//机器思维的下标
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
	//局部变量：inserted index length
	//参数: L i e
	//返回值：
	DouLinkList inserted;//要插入的节点
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
