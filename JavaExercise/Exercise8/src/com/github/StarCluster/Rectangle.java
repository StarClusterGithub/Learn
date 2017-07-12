package com.github.StarCluster;

public class Rectangle implements IShape
{
	private int length = 0, width = 0;
	
	
	public Rectangle(int length,int width)
	{
		this.length = length<0 ? -1*length : length;
		this.width = width<0 ? -1*width :width;
	}
	
	
	public String toString()
	{
		return "��Ϊ"+length+"��Ϊ"+width+"�ľ���";
	}
	

	public double size()
	{
		return length*width;
	}

}
