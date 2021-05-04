import java.util.Date;

public class Problem2Apple extends Problem2Fruit {
	public Problem2Apple() {}
	Problem2Apple(Date r) {	
		super("apple", r);
	}
	public void prepare() {
		System.out.println("Core the " + name);
	}
}