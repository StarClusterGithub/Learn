/******************************************************************
***	File name:		stack.c										***
***	Description:	Stack ADT implementation					***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//Create a stack
Stack stackCreate(void)
{
	return (struct StackStruct *)malloc(sizeof(struct StackStruct));
}


//Stack Initialize
Stack stackInit(Stack stack)
{
	if (stack == NULL)
		return NULL;
	stack->Capacity = 1024;
	stack->TopOfStack = -1;
	stack->Array = (StackElement*)malloc(sizeof(StackElement)*stack->Capacity);
	if (stack->Array == NULL)
	{
		fprintf(stderr, "No enough memory space...Press any key exit...");
		getchar();
		exit(1);
	}
	for (int i = 0;i < stack->Capacity;++i)
		stack->Array[i] = '\0';
	return stack;
}


//Stack empty
int stackEmpty(Stack stack)
{
	return stack->TopOfStack == -1;
}


//Stack full
int stackFull(Stack stack)
{
	return stack->TopOfStack == stack->Capacity - 1;
}


//Stack length
int stackLength(Stack stack)
{
	return stack->TopOfStack + 1;
}


//...get top element
int stackGetTop(Stack stack)
{
	return stackEmpty(stack) ? -1 : stack->Array[stack->TopOfStack];
}


//push~~ջ������-1��������ջ������elem
int stackPush(Stack stack, StackElement elem)
{
	if (stackFull(stack))
		return -1;
	stack->Array[++stack->TopOfStack] = elem;
	return elem;
}


//...pop~~~ջ�շ���-1,���յ���ջ��Ԫ��
int stackPop(Stack stack)
{
	return stackEmpty(stack) ? -1 : stack->Array[stack->TopOfStack--];
}


//stack destroy
int stackDestroy(Stack stack)
{
	if (stack == NULL || stack->Array == NULL)
		return -1;
	free(stack->Array);
	free(stack);
	return 0;
}
