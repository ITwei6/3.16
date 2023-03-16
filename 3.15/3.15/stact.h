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
void STInit(ST *ps);//��ʼ��
void STDestroy(ST* ps);//����
void STpush(ST* ps,STData x);//ѹջ��ѹ��һ�����ݣ���ջ��ѹ��
void STpop(ST* ps);//��ջ������һ�����ݣ���ջ��������
STData STTop(ST* ps);//����ջ��Ԫ��
bool Empty(ST* ps);
