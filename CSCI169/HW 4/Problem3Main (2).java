import java.util.Scanner;

public class Problem3Main {
	public static void main(String args[]) {
		int c, n, search, value, array[];
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		array = new int[n];
		
		System.out.println("Enter " + n + " integers: ");
		for(c=0; c<n; c++) {
			array[c] = in.nextInt();
		}
		
		Problem3SortedList test = new Problem3SortedList(array, array.length);
		System.out.println("Your sorted array is: ");
		test.print(array);
		
		System.out.println("Enter a value to find: ");
		search = in.nextInt();
		int key = test.binarySearch(search);
		if(key == -1) {
			System.out.println(search + " is not present in the list.");
		} else {
			System.out.println(search + " was found at location " + key + " .");
		}
		System.out.println("Enter a value to insert into the list: ");
		value = in.nextInt();
		int[] result = test.insertion(value);
		test.print(result);
		in.close();
	}
}
