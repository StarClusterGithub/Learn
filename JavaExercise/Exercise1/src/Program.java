import java.util.Scanner;
public class Program
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("�����������¶�C:");
		float C = input.nextFloat(),F = (9.0f/5.0f)*C+32;
		System.out.println("�����¶�"+C+"��C��Ӧ�Ļ����¶�Ϊ"+F+"��F");
		input.close();
	}

}