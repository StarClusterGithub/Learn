import java.util.Scanner;
public class Program
{

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int number = input.nextInt(), high = 0,low = 0;
		boolean judgement = true;//�����λ��Ĭ��Ϊtrue 
		for(;number > 10;)//��numberֻʣ����λ��ʱhigh��low�պý������һ�αȽ�
		{
			low = number % 10;
			number /= 10;
			high = number % 10;
			if(high < low)//���ָ�λ��С�ڵ�λ����judgment��Ϊfalse����ֹѭ��
			{
				judgement = false;
				break;
			}
		}
		System.out.println(judgement);
		input.close();
	}

}
