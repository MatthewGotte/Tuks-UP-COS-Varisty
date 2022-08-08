import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Matthew Gotte
// Student Number: u20734621

public class Filter implements Lock
{
	AtomicInteger[] level;
	AtomicInteger[] victim;
	private final int n;

	public Filter( int n ) {
		level = new AtomicInteger[n];
		victim = new AtomicInteger[n];
		for (int i = 0; i < n; i++) {
			level[i] = new AtomicInteger();
			victim[i] = new AtomicInteger();
		}
		this.n = n;
	}
	/////
	@Override
	public void lock() {
		int me = (int) (Thread.currentThread().getId() % n);
		for (int i = 1; i < n; i++) {
			level[me].set(i);
			victim[i].set(me);
			for (int j = 0; j < n; j++) {
				while ((j != me) && (level[j].get() >= i) && (victim[i].get() == me)) {}
			}
		}
	}

	@Override
	public void unlock() {
		int me = (int) (Thread.currentThread().getId() % n);
		level[me].set(0);
	}
	/////

	public void lockInterruptibly() throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock()
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock(long time, TimeUnit unit) throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public Condition newCondition()
	{
		throw new UnsupportedOperationException();
	}

}
