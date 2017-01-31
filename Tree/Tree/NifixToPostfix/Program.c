/******************************************************************
***	File name:		Program.c									***
***	Description:	��ջʵ����׺���ʽת��׺���ʽ�����		***
***					��������ֻ�����Ӽ��˳�,�������ź�����		***
***					����ϰ����,���˸���û��ʲô���õĶ���		***
***	Author:			Star Cluster								***
***	Proprietor:		Star Cluster								***
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"


int expression(char input[]);//���ʽ�Ϸ����ж�
void nifixTOpostfix(const char *input, char *output);//��׺ת��׺��Ĭ���ַ�������С��1024


int main(int argc, char *argv[])
{
	for (char choice = 'y';choice == 'y';system("cls"))
	{
		char input[1024] = "", output[1024] = "";
		fprintf(stdout, "��������׺���ʽ:\n");
		fgets(input, 1024, stdin);
		if (expression(input))
		{
			nifixTOpostfix(input, output);
			int count = 0;
			Tree root, lchild, rchild, rootStack[1024];
			for (int i = 0, num = 0;output[i] != '\0';++i)
			{
				if (output[i] == ' ')
					continue;
				if ('0' <= output[i] && '9' >= output[i])
				{
					for (;'0' <= output[i] && '9' >= output[i];++i)
						num = num * 10 + output[i] - '0';
					root = treeInit(treeCreat(), NUMTYPE, &num);
					rootStack[count++] = root;
					num = 0;
				}
				if (output[i] == '+' || output[i] == '-' || output[i] == '*' || output[i] == '/')
				{
					num = output[i];
					root = treeInit(treeCreat(), SIGNTYPE, &num);
					rchild = rootStack[--count];
					lchild = rootStack[--count];
					rootStack[count++] = treeMerge(root, lchild, rchild);
					num = 0;
				}
			}
			fprintf(stdout, "ǰ׺���ʽ:");
			treeFirstOrder(root);fputc('\n', stdout);
			fprintf(stdout, "��׺���ʽ:");
			treePostOrder(root);fputc('\n', stdout);
			treeDestroy(root);
		}
		else
		{
			fprintf(stderr, "���ʽ�������\n");
		}
		for (ungetc('\0', stdin);(choice = fgetc(stdin)) != 'y'&&choice != 'n';)
			fprintf(stdout, "����y����,����n�˳�\n");
		for (int clearbuf;(clearbuf = fgetc(stdin)) != '\n'&&clearbuf != EOF;);
	}

	return 0;
}


//���ʽ�Ϸ����ж�
int expression(char input[])
{
	char except = 'n';//��ʾ�ǲ��Ǵ�����ʽ,����Ϊy����Ϊn
	int lbracket = 0, rbracket = 0, sign = 0, before = 0;//����������,��������,ǰһλ���ַ�
	for (int i = 0;input[i] != '\n'&&except != 'y'&&i < 1024;before = input[i++])
	{
		if ('0' <= input[i] && '9' >= input[i])
			continue;
		switch (input[i])
		{
		case '(':++lbracket;break;
		case ')':++rbracket;break;
		case '*':
		case '/':
		case '+':
		case '-':
			++sign;
			if (before == '+' || before == '-' || before == '*' || before == '/')//ǰһ�������ڵ��ַ���Ϊ����
			{
				if (input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '*' || input[i + 1] == '/')//������������
				{
					except = 'y';break;
				}
				if (input[i] == '*' || input[i] == '/' || input[i] == ')')//?*��?/�����
				{
					except = 'y';break;
				}
				if (before == '-'&&input[i] == '-')
				{
					input[i - 1] = ' ';
					input[i] = '+';
					break;
				}
				if (before == '+'&&input[i] == '-')
					input[i - 1] = ' ';
				if (input[i] == '+')
					input[i] = ' ';
			}
			break;
		default:except = 'y';break;
		}
	}
	if (except != 'y' && (input[0] == '*' || input[0] == '/' || before == '+' || before == '-' || before == '*' || before == '/' || lbracket != rbracket || sign == 0))
	{
		except = 'y';
	}
	return except == 'n';
}


void nifixTOpostfix(const char *input, char *output)//��׺ת��׺��Ĭ���ַ�������С��1024
{
	Stack symbol;//����ջ
	int i = 0, j = 0;//�±�
	char before = '+';
	symbol = stackCreate();
	symbol = stackInit(symbol);
	for (i = 0, j = 0;input[i] != '\n';before = input[i++])
	{
		if ((before == '+' || before == '-' || before == '*' || before == '/' || before == '(') && input[i] == '-')
		{
			output[j++] = input[i];
			continue;
		}
		if (('0' <= before&&'9' >= before) && !('0' <= input[i] && '9' >= input[i]))
			output[j++] = ' ';
		switch (input[i])
		{
		default://����,���
			output[j++] = input[i];
			break;
		case ' ':break;

		case '('://�����źͳ˳���,��ջ
		case '*':
		case '/':
			stackPush(symbol, input[i]);
			break;

		case '+'://�Ӽ�,�ж�ջ����û�����ȼ����ߵ������,���򵯳�����ջ,û����ֱ����ջ
		case '-':
			if (stackGetTop(symbol) == '*' || stackGetTop(symbol) == '/')
			{
				for (; !stackEmpty(symbol) && stackGetTop(symbol) != '(';)
					output[j++] = stackPop(symbol);
			}
			stackPush(symbol, input[i]);
			break;

		case ')'://����������,�򵯳�ֱ������������
			for (;stackGetTop(symbol) != '(';)
				output[j++] = stackPop(symbol);
			stackPop(symbol);//����������
			break;
		}
	}
	for (;!stackEmpty(symbol) && stackGetTop(symbol) != '(';)//��ջ��ʣ�µ���������
		output[j++] = stackPop(symbol);
	output[++j] = '\0';
	stackDestroy(symbol);//����ջ
}
