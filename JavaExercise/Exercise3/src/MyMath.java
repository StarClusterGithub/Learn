
public class MyMath
{
	public static boolean Prime(int number)
	{
		if(number == 1 || number >= 10 &&(number%10 != 1 && number%10 != 3 && number%10 !=7 && number%10 != 9))//10���ϵ���������1��3��7��9��β
			return false;
		for(int factor = 2,sqrtNum = (int)Math.sqrt(number);factor <= sqrtNum; ++factor)
		{
			if(number%factor == 0)
				return false;
		}
		return true;
	}
}
