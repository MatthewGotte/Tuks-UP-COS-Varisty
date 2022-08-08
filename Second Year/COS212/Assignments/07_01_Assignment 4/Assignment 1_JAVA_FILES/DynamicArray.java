public class DynamicArray<T extends Comparable<T>> extends LinearStructure<T> {

    private int size;
    private int numElements;

    private Object[] elements;

    private void resize(int howMuch) {
        int newSize = size + howMuch;
        Object[] temp = new Object[newSize];
        for (int i = 0; i < newSize; i++) {
            temp[i] = null;
        }
        for (int i = 0; i < size; i++) {
            if (elements[i] != null) {
                temp[i] = elements[i];
                elements[i] = null;
            }
        }
        elements = temp;
        size = newSize;
    }

    public DynamicArray(int s) {
        elements = new Object[s];
        size = s;
        numElements = 0;
        for (int i = 0; i < s; i++)
            elements[i] = null;
    }

    public DynamicArray(DynamicArray<T> other) {
        this.size = other.size;
        this.numElements = other.numElements;

        //Construct Array:
        this.elements = new Object[size];
        for (int i = 0; i < size; i++)
            this.elements[i] = null;

        for (int i = 0; i < size; i++) {
            if (other.elements[i] != null)
                this.elements[i] = other.elements[i];
        }
    }

    @Override
    public String toString() {
        String os = "";
        os += "[";
        for (int i = 0; i < size; i++) {
            if (elements[i] == null) {
                os += "*";
            }
            else {
                os += elements[i];
            }
            if (i < size - 1) {
                os += ",";
            }
        }
        os += "]";
        return os;
    }

    public void insert(int index, T element) {
        if ((0 <= index) && (index < size)) {
            //Exists in range
            if (elements[index] == null) {
                elements[index] = element;
            }
            else {
                //value exists there:
                if (elements[size - 1] != null)
                    resize(1);
                //Shift:
                for (int i = size - 1; i >= index + 1; i--) {
                    elements[i] = elements[i - 1];
                }
                elements[index] = element;
            }
            numElements++;
        } else if (index == size) {
            //Size by 1
            resize(1);
            elements[index] = element;
            numElements++;
        } else {
            //Resize formula:
            // (index + 1) - size = no. needed spaces
            resize((index + 1) - size);
            elements[index] = element;
            numElements++;
        }
    }

    @SuppressWarnings("unchecked")
    public T remove(int index) throws RemoveException {
        if (index == size) {
            throw new RemoveException("Null Element");
        }
        if (elements[index] == null) {
            throw new RemoveException("Null Element");//CHECK THIS LINE!
        }

        if (!(index < size)) {
            throw new RemoveException("Null Element");
        }

        Object temp = elements[index];
        for (int i = index; i < size - 1; i++) {
            if (elements[i + 1] != null) {
                elements[i] = null;
                elements[i] = elements[i + 1];
            }
            else {
                elements[i] = null;
            }
        }
        elements[size - 1] = null;
        numElements--;
        return (T) temp;
    }

    public boolean isEmpty() {
        return numElements == 0;
    }

    @Override
    public DynamicArray<T> clone() {
        DynamicArray<T> temp = new DynamicArray<T>(this.size);
        temp.elements = new Object[this.size];
        for (int i = 0; i < this.size; i++) {
            if (this.elements[i] != null) {
                temp.elements[i] = elements[i];
            }
            else {
                temp.elements[i] = null;
            }
        }
        return temp;
    }

    public void clear() {
        for (int i = 0; i < size; i++)
            elements[i] = null;
        numElements = 0;
    }
}