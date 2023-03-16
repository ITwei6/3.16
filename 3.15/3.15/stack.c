#include "stact.h"
void STInit(ST* ps)//初始化
{
	assert(ps);
	//可以一开始给栈表初始化一些容量
	ps->a = (STData*)malloc(sizeof(STData) * 4);
	if (ps->a == NULL)
	{
		perror("malloc");
	}
	ps->capacity = 4;
	//注意top的大小是从0开始还是从1开始
	/*ps->top = -1;*///栈顶元素
	ps->top = 0;//栈顶元素的下一个位置
}
void STDestroy(ST* ps)//销毁
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void STpush(ST* ps, STData x)//压栈，压入一个数据，从栈顶压入
{
	//压栈之前要检查是否需要增容
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STData* tmp = (STData*)realloc(ps->a, sizeof(STData) * ps->capacity * 2);//增容
		
		if (tmp == NULL)
		{
			perror("realloc");
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;

		}
	}
	ps->a[ps->top] = x;
	ps->top++;

}
bool Empty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
void STpop(ST* ps)//出栈，弹出一个数据，从栈顶弹出。
{
	//不能一直减减
	assert(ps);
	assert(!Empty(ps));
	ps->top--;
}
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
STData STTop(ST* ps)//访问栈顶元素
{
	assert(ps);
	assert(!Empty(ps));
	return ps->a[ps->top - 1];
}