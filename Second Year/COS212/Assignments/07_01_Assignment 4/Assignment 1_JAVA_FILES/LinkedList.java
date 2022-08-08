public class LinkedList<T extends Comparable<T>> extends LinearStructure<T>{

    private Node<T> head = null;

    private int size() {
        int elements = 0;
        if (this.head != null) {
            Node<T> nodePtr = this.head;
            while (nodePtr.next != null) {
                elements++;
                nodePtr = nodePtr.next;
            }
            elements++;
        }
        return elements;
    }

    public LinkedList() {

    }

    public LinkedList(LinkedList<T> other) {
        LinkedList<T> newList = other.clone();
        this.head = newList.head;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public void clear() {
        head = null;
    }

    public Node<T> getLeader() {
        return head;
    }

    public void insert(int index, T element) {
        int s = size();
        if (index > s + 1) {
            //throw here
        }
        Node<T> newNode = new Node<T>(element);
        if ((index == 0) && (this.head != null)) {
            newNode.next = head;
            head = newNode;
        } else if (index == 0) {
            head = newNode;
        } else if (this.head != null) {
            Node<T> nodePtr = this.head;
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
        if (this.head != null) {
            Node<T> nodePtr = head;
            while (nodePtr != null) {
                os += nodePtr.element;
                if (nodePtr.next != null) {
                    os += ",";
                }
                nodePtr = nodePtr.next;
            }
        }
        os += "]";
        return os;
    }

    @Override
    public LinkedList<T> clone() {
        LinkedList<T> newList = new LinkedList<T>();
        if (this.head != null) {
            Node<T> otherPtr = this.head;
            Node<T> nodePtr = new Node<T>(otherPtr.element);
            newList.head = nodePtr;

            otherPtr = otherPtr.next;
            while (otherPtr != null) {
                Node<T> temp = new Node<T>(otherPtr.element);
                nodePtr.next = temp;
                nodePtr = temp;
                otherPtr = otherPtr.next;
            }
        }
        return newList;
    }

    public T remove(int index) throws RemoveException {
        if (!((0 <= index) && (index < size())) || size() == 0) {
            throw new RemoveException("empty structure");
        }
        Node<T> nodePtr = this.head;
        if ((index == 0) && (head.next != null)) {
            head = nodePtr.next;
            return nodePtr.element;
        }
        else if (index == 0) {
            head = null;
            return nodePtr.element;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                nodePtr = nodePtr.next;
            }
            Node<T> temp = nodePtr.next; //item to delete;
            if (nodePtr.next.next == null) {
                nodePtr.next = null;
            }
            else {
                nodePtr.next = temp.next; //skips item to next;
            }
            return temp.element;
        }
    }


}