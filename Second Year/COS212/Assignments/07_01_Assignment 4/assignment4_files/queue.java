/**
 * Name: Matthew Gotte
 * Student Number: u20734621
 */

public class queue {

    public int size;
    public Vertex[] q;

    public queue(int r, int c) {
        size = 0;
        this.q = new Vertex[r * c];
    }

    public void add(Vertex v) {
        this.q[size++] = v;
    }

    public Vertex getAt(int i) {
        if (i >= size) return null;
        return this.q[i];
    }

    public Vertex remove() {
        //if (size == 0) return null;
        Vertex output = this.q[0];
        for (int i = 0; i < this.size; i++) {
            q[i] = q[i + 1];
        }
        this.q[size - 1] = null;
        size--;
        return output;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public Vertex peek() {
        return this.q[0];
    }

    public int getBack() {
        for (int i = 0; i < this.q.length; i++) {
            if (this.q[i] == null)
                return i;
        }
        return this.q.length;
    }

}
