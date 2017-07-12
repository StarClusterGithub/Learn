package com.github.StarCluster;

public class Circle implements IShape
{
	private int radius = 0;
	
	
	public Circle(int radius)
	{
		this.radius = radius<0 ? -1*radius : radius;
	}
	
	
	public String toString()
	{
		return "�뾶Ϊ"+radius+"��Բ";
	}
	
	
	public static double area(int radius)
	{
		return Math.PI*radius*radius;
	}
	

	public double size()
	{
		return area(radius);
	}
	
}
