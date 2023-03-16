#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int STData;
typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}ST;
void STInit(ST *ps);//初始化
void STDestroy(ST* ps);//销毁
void STpush(ST* ps,STData x);//压栈，压入一个数据，从栈顶压入
void STpop(ST* ps);//出栈，弹出一个数据，从栈顶弹出。
STData STTop(ST* ps);//访问栈顶元素
bool Empty(ST* ps);
