public class Problem2Seafood extends Problem2Food {
	public Problem2Seafood() {}
	Problem2Seafood(String n) {
		super(n);
	}
	public void prepare() {	
		System.out.println("Peel the " + name);
	}
}
