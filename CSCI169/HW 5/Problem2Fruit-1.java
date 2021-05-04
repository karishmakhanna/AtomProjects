import java.util.Date;

public class Problem2Fruit extends Problem2Food implements Comparable<Problem2Fruit> {
	public Date ripe;
	public Problem2Fruit() {}
	public Problem2Fruit(String n, Date r) {
		super(n);
		ripe = r;
	}
	public void ripeTime() {	
		System.out.println("You can eat it on " + ripe);
	}
	
	@Override
	public int compareTo(Problem2Fruit other) {
		return this.ripe.compareTo(other.ripe);
	}
}