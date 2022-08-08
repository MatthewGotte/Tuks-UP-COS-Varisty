abstract class OrderedContainer<T extends Comparable<T>> {

    OrderedContainer(LinearStructure<T> c) {
        this.dataStructure = c.clone();
    }

    OrderedContainer(OrderedContainer<T> other) {
        this.dataStructure = other.dataStructure.clone();
    }

    @Override
    public OrderedContainer<T> clone() {
        OrderedContainer<T> temp = null;
        temp.dataStructure = this.dataStructure.clone();
        return temp;
    }

    public abstract T remove();

    public abstract T next() throws RemoveException;

    public abstract void insert(T el);

    public boolean isEmpty() {
        return this.dataStructure.isEmpty();
    }

    public LinearStructure<T> getImplementation() {
        return this.dataStructure;
    }

    protected LinearStructure<T> dataStructure;

}