import java.util.Date;

public class Problem1Orange extends Problem1Fruit {
	public Problem1Orange() {}
	Problem1Orange(Date r) {	
		super("orange", r);
	}
	public void prepare() {
		System.out.println("Peel the " + name);
	}
}