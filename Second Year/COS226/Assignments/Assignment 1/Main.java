//Matthew Gotte
//u20734621

import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        //make 5x washers & 5x dryers
        Washer[] washers = new Washer[5];
        Dryer[] dryers = new Dryer[5];

        CarWash carWash = new CarWash();

        for (int i = 0; i < 5; i++) {
            washers[i] = new Washer(carWash);
            dryers[i] = new Dryer(carWash);
        }

        //start washers
        for (Washer w : washers)
            w.start();

        //start dryers
        for (Dryer d : dryers)
            d.start();

    }
}
