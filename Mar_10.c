#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void * ret = NULL;

void bug()
{
	int a;
	int *p = &a;
	printf("I am a bug!!!\n");
	p += 4;

	*p =(int)ret;
	Sleep(3000);
}

int fun(int a, int b)
{
	int first = 0;
	int *p = &a;
	p--;
	ret = *p;
	*p = bug;
	printf("hehe\n");
	return a + b;
}

int main()
{
	int a = 0;
	int b = 1;
	//fun_1();
	fun(a, b);
	printf("Programm run to here \n");
	printf("哈哈哈哈~ \n");
	_asm
	{
		sub esp, 4;
	}
	system("pause");
	return 0;
}