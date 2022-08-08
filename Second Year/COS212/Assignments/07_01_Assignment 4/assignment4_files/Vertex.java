/**
 * Name: Matthew Gotte
 * Student Number: u20734621
 */

public class Vertex {
   
    public Coordinates coords;
    public char val;
    
    public Vertex() {
        // TODO: Your code here...
    }

    public String CoordsToString() {
        return "(" + this.coords.row + "," + this.coords.col + ")";
    }

    public Vertex(int row, int col) {
        this.coords = new Coordinates(row, col);
    }
    public Vertex(char val, int row, int col) {
        this.coords = new Coordinates(row, col);
        this.val = val;
    }
}
