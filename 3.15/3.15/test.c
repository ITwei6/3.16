//#include <stdio.h>
//int main()
//{
//	int arr[10], i;
//	for (i = 0; i < 11; i++)
//	{
//		arr[i] = 0;
//	}
//	return 0;
//}
#include "stact.h"
void test()
{
	ST p;
	STInit(&p);
	STpush(&p, 1);
	STpush(&p, 2);
	printf("%d ", STTop(&p));
	STpop(&p);
	STpush(&p, 3);
	STpush(&p, 4);
	STpush(&p, 5);
	//后进先出
	while (!Empty(&p))
	{
		printf("%d ", STTop(&p));
		STpop(&p);
	}

	STDestroy(&p);

}

int main()
{
	test();
	return 0;
}
