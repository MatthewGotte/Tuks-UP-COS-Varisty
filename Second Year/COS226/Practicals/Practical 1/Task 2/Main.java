public class Main {
    public static void main(String[] args) {
        Counter c = new Counter();
        Thread t1 = new threadcounter(c);
        Thread t2 = new threadcounter(c);
        t1.start();
        t2.start();
    }
}