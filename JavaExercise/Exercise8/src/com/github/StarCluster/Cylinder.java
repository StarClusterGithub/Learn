package com.github.StarCluster;

public class Cylinder implements IShape
{
	private int radius = 0,height = 0;
	
	
	public Cylinder(int radius,int height)
	{
		this.radius = radius<0 ? -1*radius : radius;
		this.height = height<0 ? -1*height : height;
	}
	
	
	public String toString()
	{
		return "����뾶Ϊ"+radius+"��Ϊ"+height+"��Բ����";
	}
	

	public double size()
	{
		return Circle.area(radius)*height;
	}

}
