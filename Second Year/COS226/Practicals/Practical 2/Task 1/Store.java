import java.util.concurrent.locks.Lock;
import java.util.concurrent.ThreadLocalRandom;

// Name: Matthew Gotte
// Student Number: u20734621

public class Store
{
	Lock l = new Filter(4);

	public void enterStore(){

		l.lock();
		try {
			int rand = ThreadLocalRandom.current().nextInt(200, 1000 + 1);
			//rand = 0;
			Thread.sleep(rand);
			System.out.println(Thread.currentThread().getName() + " has entered the store.");
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			l.unlock();
		}

	}
}
