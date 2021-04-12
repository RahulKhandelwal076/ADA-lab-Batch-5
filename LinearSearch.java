import java.util.Scanner;

public class LinearSearch{

	public static int search(int [] array, int key){
		for(int i = 0; i<array.length; i++){
			if(array[i] == key)
				return i;
		}
		return -1;
		

	}
	public static void main(String [] args){
		int n;
		System.out.println("Enter the value u want to search between 1 to 10 :");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		int [] arr = {1,2,3,4,5,6,7,8,9,10};
		System.out.println("The element is found at position: " +search(arr,n));

	}
}