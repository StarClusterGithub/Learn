package com.github.StarCluster;

public class Program
{

	public static void main(String[] args)
	{
		Circle c1 = new Circle(new Point(10,10),10);
		Circle c2 = new Circle(new Point(30,20),5);
		if(Circle.isCircumscibe(c1, c2))
			System.out.println(c1+"��"+c2+"����Բ����");
		else
			System.out.println(c1+"��"+c2+"����Բ������");
		System.out.println(c1+"�������"+c1.area());
		System.out.println(c2+"�������"+Circle.area(c2));
	}

}
