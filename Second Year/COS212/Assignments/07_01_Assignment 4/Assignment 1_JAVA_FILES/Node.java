public class Node<T extends Comparable<T>> {
    public T element;
    public Node<T> next;

    public Node() {
        this(null,null);
    }

    public Node(T el) {
        this(el,null);
    }

    public Node(T el, Node<T> ptr) {
        element = el; next = ptr;
    }
}
