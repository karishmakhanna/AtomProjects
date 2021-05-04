import java.util.Date;

public class Problem1Fruit extends Problem1Food {
	public Date ripe;
	public Problem1Fruit() {}
	public Problem1Fruit(String n, Date r) {
		super(n);
		ripe = r;
	}
	public void ripeTime() {	
		System.out.println("You can eat it on " + ripe);
	}
}