public class Counter {

    public volatile int counter;

    public Counter() {
        counter = 0;
    }

    public int incCounter() {
        return ++counter;
    }

}