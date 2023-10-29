#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int SLDataType;

// 动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;      // 表示数组中存储了多少个数据
	int capacity;  // 数组实际能存数据的空间容量是多大 
}SL;


// 接口函数 -- 命名风格是跟着STL走的，建议大家也跟着我们上课走，方便后续学习STL
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);

void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
// ...

// 找到了返回x位置下标，没有找打返回-1
int SeqListFind(SL* ps, SLDataType x);
// 指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);
// 删除pos位置的数据
void SeqListErase(SL* ps, int pos);