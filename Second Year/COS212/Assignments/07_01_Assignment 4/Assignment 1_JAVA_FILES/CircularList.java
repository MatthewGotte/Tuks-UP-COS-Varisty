public class CircularList<T extends Comparable<T>> extends LinearStructure<T> {

    private Node<T> tail;

    private int size() {
        int numElements = 0;
        if (tail != null) {
            Node<T> nodePtr = tail;
            numElements++;
            while (nodePtr.next != tail) {
                numElements++;
                nodePtr = nodePtr.next;
            }
        }
        return numElements;
    }

    public CircularList() {

    }

    public CircularList(CircularList<T> other) {
        CircularList<T> newList = other.clone();
        this.tail = newList.tail;
    }

    public boolean isEmpty() {
        return tail == null;
    }

    public void clear() {
        tail = null;
    }

    public Node<T> getLeader() {
        return tail;
    }

    public void insert(int index, T element) throws RemoveException {
        int s = size();
        if (!((0 <= index) && (index <= s))) {
            throw new RemoveException("invalid index");
        }

        Node<T> newNode = new Node<T>(element);
        Node<T> nodePtr;

        if ((tail == null) && (index == 0)) {
            tail = newNode;
            newNode.next = tail;
        }
        else if ((tail != null) && (index == 0)) {
            newNode.next = tail.next;
            tail.next = newNode;
        }
        else if ((tail != null) && (index == s)) {
            newNode.next = tail.next;
            tail.next = newNode;
            tail = newNode;
        }
        else if (tail != null) {
            nodePtr = tail.next;//head
            for (int i = 0; i < index - 1; i++) {
                nodePtr = nodePtr.next;
            }
            newNode.next = nodePtr.next;
            nodePtr.next = newNode;
        }
    }

    @Override
    public String toString() {
        String os = "";
        os += "[";
        if (this.tail != null) {
            Node<T> nodePtr = tail.next;
            while (nodePtr != null) {
                if (nodePtr.next == tail.next) {
                    os += nodePtr.element;
                    break;
                }
                else {
                    os += nodePtr.element;
                    os += ",";
                    nodePtr = nodePtr.next;
                }
            }
        }
        os += "]";
        return os;
    }

    @Override
    public CircularList<T> clone() {
        CircularList<T> newList = new CircularList<T>();
        if (this.tail != null) {
            Node<T> otherNode = this.tail;
            Node<T> newNode = new Node<T>(otherNode.element);
            newList.tail = newNode;

            otherNode = this.tail;
            otherNode = otherNode.next;
            Node<T> prevNode = newList.tail;

            while (otherNode.next != this.tail.next) {
                newNode = new Node<T>(otherNode.element);
                prevNode.next = newNode;
                prevNode = newNode;
                otherNode = otherNode.next;
            }
            newNode.next = newList.tail;
        }

        return newList;
    }

    public T remove(int index) throws RemoveException {
        int s = size();
        if (!((0 <= index) && (index < s))) {
            throw new RemoveException("empty structure");
        }

        Node<T> nodePtr;
        Node<T> prevPtr = null;

        if ((index == 0) && s == 1) {
            nodePtr = tail;
            this.tail = null;
        }
        else if (index == 0) {
            nodePtr = tail.next;
            tail.next = nodePtr.next;
        }
        else {
            nodePtr = tail.next;
            for (int i = 0; i < index; i++) {
                prevPtr = nodePtr;
                nodePtr = nodePtr.next;
            }
            if (index == size() - 1) {
                prevPtr.next = nodePtr.next;
                tail = prevPtr;
            }
            else {
                prevPtr.next = nodePtr.next;
            }
        }
        return nodePtr.element;
    }
}