import java.util.Date;

public class Problem1Apple extends Problem1Fruit {
	public Problem1Apple() {}
	Problem1Apple(Date r) {	
		super("apple", r);
	}
	public void prepare() {
		System.out.println("Core the " + name);
	}
}