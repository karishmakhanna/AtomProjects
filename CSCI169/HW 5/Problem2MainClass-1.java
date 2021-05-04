import java.util.Date;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Problem2MainClass {
	public static void main(String args[]) {
         Date one = new Date(10000000);
         Date two = new Date(20000000);
         Date three = new Date(30000000);
         
         Problem2Fruit a = new Problem2Fruit("Apple", one);
         Problem2Fruit b = new Problem2Fruit("Banana", two);
         Problem2Fruit c = new Problem2Fruit("Cherry", three);
         
         // initialize fruit array
         ArrayList<Problem2Fruit> fruits = new ArrayList<Problem2Fruit>(Arrays.asList(b, a, c));
         
         // print fruit array nicely
         System.out.println("List of fruits before sorting: ");
         for(Problem2Fruit i: fruits) {
        	 	System.out.print(i.name+"; ");
        	 	i.ripeTime();
         }
         System.out.println();
         
         // sort fruit array
         Collections.sort(fruits);
         
         // print sorted fruit array nicely
         System.out.println("List of fruits after sorting by ripe date (soonest to latest): ");
         for(Problem2Fruit i: fruits) {
        	 	System.out.print(i.name+"; ");
        	 	i.ripeTime();
         }
         System.out.println();
    }
}
