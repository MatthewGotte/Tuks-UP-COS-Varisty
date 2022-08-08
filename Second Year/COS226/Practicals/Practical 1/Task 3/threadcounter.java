import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class threadcounter extends Thread {
    public Counter count;

    public threadcounter(Counter c) {
        count = c;
    }

    public void run() {
        for (int i = 0; i < 5; i++)
            System.out.println(String.format("%s Counter: " + count.incCounter(), this.getName()));
//            count.incCounter();
    }
}