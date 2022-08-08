public class Queue<T extends Comparable<T>> extends OrderedContainer<T> {

    public Queue(LinearStructure<T> c){
        super(c);
    }

    @Override
    public Queue<T> clone() {
        return new Queue<T>(this.dataStructure);
    }

    public Queue(Queue<T> other) {
        super(other.dataStructure);
    }

    public T remove() {
        T temp = null;
        try {
            temp = this.getImplementation().remove(0);
        } catch (RemoveException e) {
            e.printStackTrace();
        }
        return temp;
    }

    public T next() {
        T temp = null;
        try {
            temp = this.dataStructure.remove(0);
            this.dataStructure.insert(0, temp);
        }
        catch (RemoveException ignored) {

        }
        return temp;
    }

    public void insert(T el) {
        //Get back:
        int pos = 0;
        while (true) {
            try {
                T temp = this.dataStructure.remove(pos);
                this.dataStructure.insert(pos, temp);
                pos++;
            }
            catch (RemoveException e) {
                break;
            }

        }
        try {
            this.dataStructure.insert(pos, el);
        } catch (RemoveException ignored) {

        }
    }

}