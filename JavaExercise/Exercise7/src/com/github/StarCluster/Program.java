package com.github.StarCluster;

import java.util.Scanner;

public class Program
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("������Ҫ���ܵ�����:");
		StringBuffer encryption = new StringBuffer(input.nextLine());//�˴���Ӧ����next,��Ϊnext�Կո���Ϊ�ָ���,����������
		for(int i = 0, len = encryption.length(), ch = 0; i < len; ++i)
		{
			ch = (int)encryption.charAt(i);
			if(ch >= 'a' && ch <= 'z')
				ch = ch + 4 > 'z' ? ch + 4 - 'z' + 'a' - 1 : ch + 4;
			else if(ch >= 'A' && ch <= 'Z')
				ch = ch + 4 > 'Z' ? ch + 4 - 'Z' + 'A' - 1 : ch + 4;
			encryption.setCharAt(i,(char)ch);
		}
		System.out.println("���ܺ������Ϊ:\n" + encryption);
		
		input.close();
	}

}
