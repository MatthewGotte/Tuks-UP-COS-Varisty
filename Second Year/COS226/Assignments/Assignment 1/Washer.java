//Matthew Gotte
//u20734621
import java.util.Random;
public class Washer extends Thread {
    CarWash current;

    Washer(CarWash carWash) {
        current = carWash;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " is ready to dry a car.");
        while (current.toDry()) {
            //keep washing:
        }
    }
}