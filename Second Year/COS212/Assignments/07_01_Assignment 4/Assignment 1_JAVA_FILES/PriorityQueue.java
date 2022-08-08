public class PriorityQueue<T extends Comparable<T>> extends OrderedContainer<T> {

    public PriorityQueue(LinearStructure<T> c) {
        super(c);
    }

    public PriorityQueue(PriorityQueue<T> other) {
        super(other.dataStructure);
    }

    @Override
    public PriorityQueue<T> clone() {
        return new PriorityQueue<T>(this.dataStructure);
    }

    public T remove() {
        /*int pos = 0;
        T priority = null;
        try {
            priority = next();
        } catch (RemoveException ignored) {

        }
        while (true) {
            try {
                T temp = this.dataStructure.remove(pos);
                if (temp == priority) {
                    break;
                }
                else this.dataStructure.insert(pos, temp);
                pos++;
            }
            catch (RemoveException e) {
                break;
            }
        }
        return priority;*/

        T temp = null;
        try {
            temp = this.getImplementation().remove(0);
        } catch (RemoveException ignored) {

        }
        return temp;
    }

    public T next() throws RemoveException {
        /*int pos = 0;
        T highest = null;
        try {
            highest = this.dataStructure.remove(0);
            this.dataStructure.insert(0, highest);
            while (true) {
                try {
                    T temp = this.dataStructure.remove(pos);
                    this.dataStructure.insert(pos, temp);
                    if (temp.compareTo(highest) > 0)
                        highest = temp;
                    pos++;
                }
                catch (RemoveException e) {
                    break;
                }
            }
            return highest;
        }
        catch (RemoveException ignored) {

        }
        return highest;*/

        T temp = null;
        try {
            temp = this.getImplementation().remove(0);
            this.getImplementation().insert(0, temp);
        }
        catch (RemoveException ignored) {

        }
        return temp;
    }

    public void insert(T el) {
        int i = 0;
        while (true) {
            try {
                T temp = this.getImplementation().remove(i);
                this.getImplementation().insert(i, temp);
                if (temp.compareTo(el) < 0) {
                    break;
                } else {
                    i++;
                }
            }
            catch (RemoveException e) {
                break;
            }
        }
        try {
            this.getImplementation().insert(i, el);
        } catch (RemoveException e) {
            //e.printStackTrace();
        }
    }
}