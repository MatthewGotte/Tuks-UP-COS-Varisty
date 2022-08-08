import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: Matthew Gotte
// Student Number: u20734621

public class Bakery implements Lock
{
	private AtomicBoolean[] flag;
	private AtomicInteger[] label;
	private int n;

	public Bakery(int n) {
		this.n = n;
		label = new AtomicInteger[n];
		flag = new AtomicBoolean[n];
		for (int i = 0; i < n; i++) {
			label[i] = new AtomicInteger();
			flag[i] = new AtomicBoolean();
		}
	}

	/////
	@Override
	public void lock() {
		int i = (int) (Thread.currentThread().getId() % n);
		flag[i].set(true);

//		label[i].set(max(label) + 1);
		int m = Integer.MIN_VALUE;
		for (AtomicInteger element : label) {
			if (element.get() > m) {
				m = element.get();
			}
		}
		label[i].set(m + 1);

		for (int j = 0; j < n; j++) {
			while((j != i) && flag[j].get() && ((label[j].get() < label[i].get())) || ((label[j].get() == label[i].get() && j < i))) {};
		}
	}

	private int max(AtomicInteger[] elementArray) {
		int m = Integer.MIN_VALUE;
		for (AtomicInteger element : elementArray) {
			if (element.get() > m) {
				m = element.get();
			}
		}
		return m;
	}

	@Override
	public void unlock() {
		flag[(int) Thread.currentThread().getId() % n].set(false);
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
