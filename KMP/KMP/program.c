#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *target, char *pattern);
static void makeNext(char *pattern, int next[]);

int main(int argc, char **argv)
{
	char target[1000001] = "", pattern[1001] = "";
	fgets(target, 1000001, stdin);
	fgets(pattern, 1001, stdin);
	fprintf(stdout, "%d\n", KMP(target, pattern));
	system("pause");
	return 0;
}

///	<summary>
///	���ڸ����ַ���target,����������ģʽ��pattern,������pattern��target�е�����
///	</summary>
///	<param name="target">Ŀ���ַ���</param>
///	<param name="pattern">Ҫ�������ַ���</param>
int KMP(char *target, char *pattern)
{
	int tlen = strlen(target), plen = strlen(pattern);
	int *next = (int*)malloc(plen * sizeof(int));
	makeNext(pattern, next);

	int count = 0;
	//	iΪtarget�±�,matchΪ��ƥ���ַ��ĳ���(ͬʱҲ���±�)
	for (int i = 0, match = 0;i < tlen;++i)
	{
		for (;target[i] != pattern[match] && match != 0;)
		{
			match = next[match - 1];
		}
		if (target[i] == pattern[match])
		{
			match += 1;
		}
		if (match == plen)
		{
			match = 0;
			count += 1;
		}
	}

	free(next);
	return count;
}

///	<summary>
///	���ڸ����ַ���pattern,����ÿһλ����󹫹�����,������next����
///	����"abaabcaba"�õ��Ľ��Ϊ001120123
///	</summary>
///	<param name="pattern">��������󹫹����ȵ��ַ���</param>
///	<param name="next">�����󹫹����ȵ�����</param>
static void makeNext(char *pattern, int next[])
{
	next[0] = 0;//�ַ���pattern�ĵ�0λ����󹫹����ȱض�Ϊ0

	//	i���ַ���pattern���±�,i��1��ʼֱ��������pattern
	//	k��ʾ�ַ���pattern�ڵ�i-1λ����󹫹�����,���,[0,k-1]���ַ�����[i-1-(k-1),i-1]��[i-k,i-1]���ַ������
	for (int i = 1, k = 0;pattern[i] != '\0';++i)
	{
		//�����iλ���kλ��ͬ,����ǰѰ��ֱ���ҵ���ͬ�Ļ���ȷ����ȫ��ͬ(���˵�next[0])Ϊֹ
		for (;k > 0 && pattern[k] != pattern[i];)
			k = next[k - 1];

		//�����iλ���kλ��ͬ,��ô��iλ��ֵΪ��kλ��ֵ��1
		//�����forѭ�����������Ϊ���˵�next[0]������,��ô������ͻ���k����1
		if (pattern[k] == pattern[i])
			k += 1;

		//����next[i]
		next[i] = k;
	}
}
