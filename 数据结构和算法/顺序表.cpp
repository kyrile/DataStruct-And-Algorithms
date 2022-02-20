#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
Status InitList(SqList* L) {
	if (L == NULL)
		return ERROR;
	L->length = 0;
	return OK;
}
//删
Status ClearList(SqList* L) {
	if (L == NULL)
		return ERROR;
	L->length = 0;
	return OK;
}
//查
Status IsListEmpty(SqList* L) {
	if (L == NULL)
		return TRUE;
	if (L->length == 0)
		return TRUE;
	return FALSE;
}
//查
int listLength(SqList* L) {
	return L->length;
}
//增
Status ListInsert(SqList* L, int index/*人类角度的下标*/, const ElemType e) {
	//1.插入的位置必须有效
	//2.不能超出顺序表的长度
	if ((index >= 1) && (L->length < MAXSIZE))
	{
		//第一次：插入的位置1 <= 0 不成立 
		//第二次：插入的位置1 <= 1 成立 
		if (index <= L->length) {
			//第二次第A次循环：k = 0, 0 >= 0 成立
			for (int k = L->length - 1; k >= index - 1; k--)
			{
				L->data[k + 1] = L->data[k];//数据迁移到后一个格子
			};
		}
		L->data[index - 1/*要插入的位置*/] = e/*数据*/;
		L->length++;
		return OK;
	}
	return ERROR;
}
//删
Status listDelete(SqList* L, int index/*人类思维的下标*/, ElemType* e) {
	//第一种情况：长度为零
	//第二种情况：要删除的位置不存在
	//第三种情况：要删除的下标 > 顺序表的长度
	if ((L->length == 0) || (index <= 0) || (index > L->length))
	{
		return ERROR;
	}
	*e = L->data[index - 1];//保存要删除的位置里面的数据
	//第一次：11 < 11，不成立
	//第二次：10 < 11，成立
	if (index < L->length)
	{
		//第二次第A次
		for (int k = index; k < L->length; k++) {
			L->data[k - 1] = L->data[k];//要删除的位置里面的数据 = 下一个格子里面的数据
		};
	}
	L->length--;
	return OK;
}

Status visit(ElemType e) {
	printf("%d → ", e);
	return OK;
}
//查
Status ListTraverse(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		visit(L->data[i]);
	}
	printf("\r\n");
	return OK;
}
//查
Status getElem(SqList* L, int index/*人类思维的查询位置*/, ElemType* e) {
	//第一种情况，长度等于0
	//第二种情况：查询的位置小于1
	//第三种情况：查询的位置大于顺序表的长度
	if ((L->length == 0) || (index < 1) || (index > L->length))
	{
		return ERROR;
	}
	*e = L->data[index - 1];
	return OK;
}
int main()
{
	SqList L{ 0 };
	ElemType e;
	Status ret;
	int j, k = 1;
	ret = InitList(&L);
	printf("初始化L后：L.length = %d\n", L.length);
	for (j = 1; j <= 5; j++)
		ret = ListInsert(&L, 1, j);
	ListTraverse(&L);
	ret = IsListEmpty(&L);
	printf("L 是否为空:%d(1: 空 0：否)\r\n", ret);
	ClearList(&L);
	ret = IsListEmpty(&L);
	printf("L 是否为空:%d(1: 空 0：否)\r\n", ret);
	for (j = 1; j <= 10; j++) {
		ret = ListInsert(&L, 1, j);
	}
	ListTraverse(&L);
	ListInsert(&L, 1, 0);
	getElem(&L, 5, &e);
	printf("第五元素是：%d\n", e);
	k = listLength(&L);
	for (j = k + 1; j >= k; j--)
	{
		ret = listDelete(&L, 9, &e);
		if (ret == ERROR) {
			printf("删除第 %d 个数据失败\r\n", j);
		}
		else
		{
			printf("删除第 %d 个数据成功：%d\r\n", j, e);
		}
	}
	ListTraverse(&L);
	listDelete(&L, 5, &e);
	printf("删除第 %d 个数据成功：%d\r\n", 5, e);
	ListTraverse(&L);
	return 0;
}