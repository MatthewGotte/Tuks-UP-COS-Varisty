// Name: Matthew Gotte
// Student Number: u20734621

import java.util.concurrent.ThreadLocalRandom;

public class Main {

    public static void main(String[] args) {

        //set 4 queues = 4 doors
	    Queue[] queues = new Queue[4];

	    //make a store
        Store store = new Store();

        //set queue array to new queue and pass store to constructor
        for(int i = 0; i < 4; i++)
            queues[i] = new Queue(store);

        //start all threads
        for(Queue queue : queues)
            queue.start();

    }
}
