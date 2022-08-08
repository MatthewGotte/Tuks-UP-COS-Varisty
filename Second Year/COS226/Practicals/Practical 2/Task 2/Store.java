import java.util.concurrent.locks.Lock;
import java.util.concurrent.ThreadLocalRandom;

// Name: Matthew Gotte
// Student Number: u20734621

public class Store
{
	Lock l = new Bakery(4);

	public void enterStore(){

		l.lock();
		try {
			int rand = ThreadLocalRandom.current().nextInt(200, 1000 + 1);
			System.out.printf("%s has entered the store.%n", Thread.currentThread().getName());
			Thread.sleep(rand);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			System.out.printf("%s has left the store.%n", Thread.currentThread().getName());
			l.unlock();
		}

	}
}
