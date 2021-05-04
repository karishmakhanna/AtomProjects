import java.util.Date;

public class Problem2Fruit extends Problem2Food {
	public Date ripe;
	public Problem2Fruit() {}
	public Problem2Fruit(String n, Date r) {
		super(n);
		ripe = r;
	}
	public void ripeTime() {	
		System.out.println("You can eat it on " + ripe);
	}
}