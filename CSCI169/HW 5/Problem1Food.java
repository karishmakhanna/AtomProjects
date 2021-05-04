public class Problem1Food {
	public String name;
	public Problem1Food() {}
	Problem1Food(String n) {	
		name = n;
	}
	void prepare() {	
		System.out.println("Prepare the " + name);
	}
}
