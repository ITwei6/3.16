#include "stact.h"
void STInit(ST* ps)//��ʼ��
{
	assert(ps);
	//����һ��ʼ��ջ���ʼ��һЩ����
	ps->a = (STData*)malloc(sizeof(STData) * 4);
	if (ps->a == NULL)
	{
		perror("malloc");
	}
	ps->capacity = 4;
	//ע��top�Ĵ�С�Ǵ�0��ʼ���Ǵ�1��ʼ
	/*ps->top = -1;*///ջ��Ԫ��
	ps->top = 0;//ջ��Ԫ�ص���һ��λ��
}
void STDestroy(ST* ps)//����
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void STpush(ST* ps, STData x)//ѹջ��ѹ��һ�����ݣ���ջ��ѹ��
{
	//ѹջ֮ǰҪ����Ƿ���Ҫ����
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STData* tmp = (STData*)realloc(ps->a, sizeof(STData) * ps->capacity * 2);//����
		
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
void STpop(ST* ps)//��ջ������һ�����ݣ���ջ��������
{
	//����һֱ����
	assert(ps);
	assert(!Empty(ps));
	ps->top--;
}
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
STData STTop(ST* ps)//����ջ��Ԫ��
{
	assert(ps);
	assert(!Empty(ps));
	return ps->a[ps->top - 1];
}