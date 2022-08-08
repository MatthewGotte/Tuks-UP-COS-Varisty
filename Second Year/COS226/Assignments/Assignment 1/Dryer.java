//Matthew Gotte
//u20734621
import java.util.Random;
public class Dryer extends Thread {
    CarWash current;

    Dryer(CarWash carWash) {
        current = carWash;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " is ready to wash a car.");
        while (current.toWash()) {
            //exists a car to wash:
            current.wash();
            //break [50-100]
        }
    }
}