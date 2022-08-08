import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Counter {

    public volatile int counter;

    public Lock l;

    public Counter() {
        counter =0;
        l = new ReentrantLock();
    }

    public int incCounter() {
        int temp;
        l.lock();
        try {
            ++counter;
            temp = counter;
        }
        finally {
            l.unlock();
        }
        return temp;
    }

}