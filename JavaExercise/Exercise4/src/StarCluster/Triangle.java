package StarCluster;

public class Triangle
{
	private int sideA = 0,sideB = 0,sideC = 0;
	
	
	public Triangle(int sideA,int sideB,int sideC) throws Exception
	{
		if(!(sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA))
			throw new Exception("����������α߳�.");
		this.sideA = sideA;
		this.sideB = sideB;
		this.sideC = sideC;
	}
	
	
	//���ú��׹�ʽS=��p(p-a)(p-b)(p-c)�����������,pΪ���ܳ�
	public float Area()
	{
		float p = (float)Circumference() / 2;
		return (float)Math.sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
	}
	
	
	public int Circumference()
	{
		return sideA + sideB + sideC;
	}
}
