public class Stack<T extends Comparable<T>> extends OrderedContainer<T> {

    public Stack(LinearStructure<T> c) {
        super(c);
    }

    public Stack(Stack<T> other) {
        super(other.dataStructure);
    }

    @Override
    public Stack<T> clone() {
        return new Stack<T>(this.dataStructure);
    }

    public T remove () {
        T temp = null;
        try {
            temp = this.getImplementation().remove(0);
        }
        catch (RemoveException ignored) {

        }
        return temp;
    }
    
    public T next() throws RemoveException {
        if (this.getImplementation().isEmpty())
        throw new RemoveException("empty structure");
        T temp = this.getImplementation().remove(0);
        this.getImplementation().insert(0, temp);
        return temp;
    }

    public void insert(T el) {
        try {
            this.getImplementation().insert(0, el);
        } catch (RemoveException ignored) {

        }
    }

}