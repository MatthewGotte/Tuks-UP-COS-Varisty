import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class petersonlock implements Lock {

    private volatile boolean[] flag = new boolean[2];
    private volatile int victim;

    private int currentID() {
        return (int) (Thread.currentThread().getId() % 2);
    }

    @Override
    public void lock() {
        int i = currentID();
        int j = 1 - i;
        flag[i] = true;
        victim = i;
        while (flag[j] && victim == i) {};
    }

    @Override
    public void unlock() {
        int i = currentID();
        flag[i] = false;
        victim = i;
    }

    @Override
    public void lockInterruptibly() throws InterruptedException {

    }

    @Override
    public boolean tryLock() {
        return false;
    }

    @Override
    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        return false;
    }

    @Override
    public Condition newCondition() {
        return null;
    }
}