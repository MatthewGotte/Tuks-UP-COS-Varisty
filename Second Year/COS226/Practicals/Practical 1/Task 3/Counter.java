import java.util.concurrent.locks.Lock;

public class Counter {

    public volatile int counter;

    public Lock l;

    public Counter() {
        l = new petersonlock();
        counter = 0;
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