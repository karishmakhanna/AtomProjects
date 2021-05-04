public class Problem2Food {
	public String name;
	public Problem2Food() {}
	Problem2Food(String n) {	
		name = n;
	}
	void prepare() {	
		System.out.println("Prepare the " + name);
	}
}
