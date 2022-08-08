abstract class LinearStructure<T extends Comparable<? super T>> {

    @Override
    public abstract String toString();

    @Override
    public abstract LinearStructure<T> clone();

    public abstract void insert(int index, T element) throws RemoveException;

    public abstract T remove(int index) throws RemoveException;

    public abstract boolean isEmpty();

    public abstract void clear();


}