import java.util.Arrays;
import java.util.Date;
import java.util.ArrayList;

public class Problem1MainClass {
	
	public static ArrayList<Object> newArrFunc(ArrayList<Object> input) {
		ArrayList<Object> output = new ArrayList<Object>();
		
		for(int i=0; i<input.size(); i++) {
			if(input.get(i).equals("Food")) { // all options for Food object
				if( (i+1<input.size()) && !( (input.get(i+1)=="Orange")||(input.get(i+1)=="Apple")||(input.get(i+1)=="Fruit")||(input.get(i+1)=="Food") ) ) {
					output.add(new Problem1Food((String)input.get(i+1))); // if "Food" has a name after it
					i=i+1;
				}
				else {
					output.add(new Problem1Food());
				}
			} // end of Food object options
			
			else if(input.get(i).equals("Fruit")) { // all options for Fruit object
				if( (i+2<input.size()) && !( (input.get(i+1)=="Orange")||(input.get(i+1)=="Apple")||(input.get(i+1)=="Fruit")||(input.get(i+1)=="Food") ) ) {
					if(input.get(i+2)=="now") { // if the date is "now" and Fruit has name
						Date now = new Date();
						output.add(new Problem1Fruit((String)input.get(i+1), now));
					}
					else { // if the date has an input and Fruit has name
						Date other = new Date((Integer) input.get(i+2));
						output.add(new Problem1Fruit((String)input.get(i+1), other));
					}
					i=i+2;
				}
				else {
					output.add(new Problem1Fruit());
				}
			} // end of Fruit object options
			
			else if(input.get(i).equals("Apple")) { // all options for Apple object
				if( (i+1<input.size()) && !( (input.get(i+1)=="Orange")||(input.get(i+1)=="Apple")||(input.get(i+1)=="Fruit")||(input.get(i+1)=="Food") ) ) {
					if(input.get(i+1)=="now") { // if the date is "now"
						Date now = new Date();
						output.add(new Problem1Apple(now));
					}
					else { // if the date has an input
						Date other = new Date((Integer) input.get(i+1));
						output.add(new Problem1Apple(other));
					}
					i=i+1;
				}
				else {
					output.add(new Problem1Apple());
				}
			} // end of Apple object options
			
			else if(input.get(i).equals("Orange")) { // all options for Orange object
				if( (i+1<input.size()) && !( (input.get(i+1)=="Orange")||(input.get(i+1)=="Apple")||(input.get(i+1)=="Fruit")||(input.get(i+1)=="Food") ) ) {
					if(input.get(i+1)=="now") { // if the date is "now"
						Date now = new Date();
						output.add(new Problem1Orange(now));
					}
					else { // if the date has an input
						Date other = new Date((Integer) input.get(i+1));
						output.add(new Problem1Orange(other));
					}
					i=i+1;
				}
				else {
					output.add(new Problem1Orange());
				}
			} // end of Orange object options
			
			else {} // if the input item is not one of the above, do nothing
		}
		return output; // after for loop is over, return output array of objects
	} // end of new array function
	
	public static void main(String args[]) {
		// created for class comparison
         Problem1Food food = new Problem1Food();
         Problem1Food fruit = new Problem1Fruit();
         Problem1Food apple = new Problem1Apple();
         Problem1Food orange = new Problem1Orange();
         
         // input
         ArrayList<Object> test = new ArrayList<Object>(Arrays.asList("Food", 
        		 "Orange", "Fruit", "Papaya", 3932728, "Apple", "now", "Food", "Sandwich"));
         
         // printing input
         System.out.println("Input array list of strings and integers: ");
         for(Object i: test) { // prints all items in input array
        	 	System.out.print(i+" ");
         }
         System.out.println();
         
         // creating output
         System.out.println("Creating objects in the new array...");
         System.out.println();
         ArrayList<Object> testresult = new ArrayList<Object>();
         testresult = newArrFunc(test); // see this function above the main
         
         // printing output
         System.out.println("Output array list of objects: ");
         for(Object i: testresult) { // prints all items in input array
     	 	if(i.getClass()==food.getClass()) {
     	 		System.out.print("Food ");
     	 	}
     	 	if(i.getClass()==fruit.getClass()) {
     	 		System.out.print("Fruit ");
     	 	}
     	 	if(i.getClass()==apple.getClass()) {
     	 		System.out.print("Apple ");
     	 	}
     	 	if(i.getClass()==orange.getClass()) {
     	 		System.out.print("Orange ");
     	 	}
         }
         System.out.println();
    } // end of main function
} // end of main class
