import java.util.Date;

public class Problem2MainClass {
	public static void main(String args[]) {
         Date d = new Date(2000000000);
         Problem2Food gum = new Problem2Food("gum");
         Problem2Food las = new Problem2Food("lasagna");
         Problem2Fruit pom  = new Problem2Fruit("pomegranate", d);
         Problem2Fruit app = new Problem2Apple(d);
         Problem2Orange o = new Problem2Orange(d);
         Problem2Shrimp sh = new Problem2Shrimp();       
         Problem2Seafood p = new Problem2Prawn();
         Problem2Seafood l = new Problem2Seafood("lobster");
         
         sh.prepare();
         app.prepare();
         pom.prepare();
         o.prepare();
         gum.prepare();
         p.prepare();
         l.prepare();
         las.prepare();

         las = app;
         las.prepare();

         o.ripeTime();
         pom.ripeTime();
    }

}
