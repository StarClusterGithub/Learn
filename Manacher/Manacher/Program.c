#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* manacher(char* str);

int main(int argc, char **argv)
{
	fprintf(stdout, "%s%c",manacher("abcabcdeedcbabcde"),'\n');
	system("pause");
	return 0;
}

#ifdef MIN
#undef MIN
#endif
#define MIN(x,y) ((x)<(y)?(x):(y))
//	��manacher�㷨��������ַ�������Ļ����Ӵ�
//	����ַ������ж����Ļ����Ӵ�,ֻ�᷵�ص�һ��,���Ҫȫ��������Ҫ������߶���,����Ū,���Ծ�������
char* manacher(char* str)
{
	int oldStrLen = strlen(str);//Դ�ַ�������
	int len = oldStrLen * 2 + 1;//��manacher�㷨�����ַ�����Ҫ�ĳ���
	char *s = (char*)malloc(len * sizeof(char));//���Դ�ַ����������ַ���

	//	��Դ�ַ���ÿ���ַ��������һ��'#',��abc -> #a#b#c#
	for (int i = 0;i < oldStrLen;++i)
		s[2 * i] = '#', s[2 * i + 1] = str[i];
	s[len - 1] = '#';

	int *radiusLen = (int *)malloc(len * sizeof(int));//��¼�Ե�ǰλ��Ϊ���ĵĻ����ַ����İ뾶����,�������ַ�
	int position = 0, maxRight = 0;//position��maxRight�ǻ����Ӵ����ĺ�����λ��
	int maxRadiusLenPosition = 0;//��¼radiusLen�����ֵ���±�
	for (int i = 0;i < len;++i)
	{
		if (i < maxRight)
			radiusLen[i] = MIN(radiusLen[2 * position - i], maxRight - i);
		else
			radiusLen[i] = 1;
		//	������չ�����Ӵ�
		for (;(i - radiusLen[i] >= 0 && i + radiusLen[i] < len) && (s[i - radiusLen[i]] == s[i + radiusLen[i]]);)
			++radiusLen[i];
		//	����position��maxRight
		if (radiusLen[i] + i - 1 > maxRight)
		{
			position = i;
			maxRight = i + radiusLen[i] - 1;
		}
		if (radiusLen[i] > radiusLen[maxRadiusLenPosition])
			maxRadiusLenPosition = i;
	}

	char *maxSubStr = (char*)malloc((radiusLen[maxRadiusLenPosition]) * sizeof(char));//���������Ӵ�
	strncpy_s(maxSubStr, (radiusLen[maxRadiusLenPosition]) * sizeof(char), str + (maxRadiusLenPosition- radiusLen[maxRadiusLenPosition] + 1) / 2, radiusLen[maxRadiusLenPosition] - 1);//��ȡ�Ӵ�
	return maxSubStr;
}
