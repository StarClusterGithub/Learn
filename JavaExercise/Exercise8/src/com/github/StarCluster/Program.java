package com.github.StarCluster;

public class Program
{

	public static void main(String[] args)
	{
		IShape foobar[] = {new Rectangle(3,4),new Circle(5),new Cylinder(6,7)};
		System.out.println("�ӿ���ϰ���������:");
		for(IShape item : foobar)
		{
			System.out.println(item.toString()+"size:\t"+item.size());
		}
		System.out.println("�����������.");
	}

}
