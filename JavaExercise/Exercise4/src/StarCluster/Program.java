package StarCluster;

public class Program
{

	public static void main(String[] args)
	{
		try 
		{
			Triangle demo1 = new Triangle(3,4,5);
			Triangle demo2 = new Triangle(7,8,9);
			System.out.println("�߳�Ϊ3,4,5�������ε��ܳ���"+demo1.Circumference()+",�����"+demo1.Area());
			System.out.println("�߳�Ϊ7,8,9�������ε��ܳ���"+demo2.Circumference()+",�����"+demo2.Area());
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

}
