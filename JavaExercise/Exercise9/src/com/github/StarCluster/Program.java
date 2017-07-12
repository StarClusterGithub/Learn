package com.github.StarCluster;

import java.util.Scanner;

public class Program
{
	
	public static void main(String[] args) throws NumberFormatException
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter a hexadecimal number:");
		try
		{
			String hex = input.nextLine();
			if (!hex.matches("[A-Fa-f0-9]+"))// ��������ʽ�ж��Ƿ����ʮ�����Ƹ�ʽ(��ֻ�����ֺ�a-f��ĸ)
				throw new NumberFormatException();
			System.out.println(Integer.parseInt(hex, 16));
		}
		catch (NumberFormatException e)
		{
			System.out.println("Number format exception!");
		}
		finally
		{
			input.close();
		}
		
	}
	
}
