/**
 * Name: Matthew Gotte
 * Student Number: u20734621
 */

//import java.io.File;
//import java.util.Scanner;

import java.io.File;
import java.util.Scanner;

/**
 * You may add your own classes and function, but you may not modify any of
 * the given attribute names or given method signatures.
 */
@SuppressWarnings("unchecked")
public class DungeonGraph {

    /** 
     * =============================
     * ===        TASK 1         ===
     * =============================
     */
    char [][] map;
    int rows = 0, cols = 0;
    boolean [][] visited;

    public DungeonGraph() {
        // TODO: Your code here...
        rows = 0;
        cols = 0;
    }

    /**
     * Create a new graph to represent the given dungeon.
     */
    public void createGraph(String filename) {
        // TODO: Your code here...
        try {
            Scanner read = new Scanner(new File(filename));
            while (read.hasNextLine()) {
                String line = read.nextLine();
                if (line.equals("")) continue;
                cols = 0;
                for (; cols < line.length(); cols++);
                rows++;
            }
            setMap(rows, cols);
            setVisited(rows, cols);
            read = new Scanner(new File(filename));
            for (int i = 0; i < rows; i++) {
                String line = read.nextLine();
                if (line.equals("")) {
                    i--;
                    continue;
                };
                for (int j = 0; j < cols; j++) {
                    map[i][j] = line.charAt(j);
                }
            }
        } catch (Exception ignored) { }
    }

    public void setMap(int rows, int cols) {
        map = new char[rows][cols];
    }

    public void setVisited(int rows, int cols) {
        visited = new boolean[rows][cols];
    }

    public void resetVisited() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                visited[i][j] = false;
    }

    /**
     * Return the vertex with the given coordinates (row, col)
     * If the vertex does not exist, return null.
     * If the coordinates are out of bounds, return null.
     */
    public Vertex getVertex(Integer row, Integer col) {
        // TODO: Your code here...
        if ((row < 0) || (row >= rows) || (col < 0) || (col >= cols)) {
            return null;
        }
        if (this.map[row][col] == '#') {
            return null;
        }
        Vertex output = new Vertex();
        output.coords = new Coordinates(row, col);
        return output;
    }
    
    /**
     * Return a string representing a depth-first traversal of the graph. 
     * The traversal must start from the Entrance vertex. For each tile, 
     * visit the adjacent vertices in the following order: left, up, right, down. 
     * For each vertex, output its coordinates (comma-separated).
     */
    public String toString() {
        // TODO: Your code here...
        Vertex temp = getDoor();
        int rowE = temp.coords.row;
        int colE = temp.coords.col;
        resetVisited();
        String output = DFS(rowE, colE);
        resetVisited();
        return output;
    }

    public String DFS(int r, int c) {
        visited[r][c] = true;
        if (validN(r, c - 1)) {
            if (!visited[r][c - 1])
            return "(" + r + "," + c + ")," + DFS(r, c - 1);
        }
        if (validN(r - 1, c)) {
            if (!visited[r - 1][c])
            return "(" + r + "," + c + ")," + DFS(r - 1, c);
        }
        if (validN(r, c + 1)) {
            if (!visited[r][c + 1])
            return "(" + r + "," + c + ")," + DFS(r, c + 1);
        }
        if (validN(r + 1, c)) {
            if (!visited[r + 1][c])
            return "(" + r + "," + c + ")," + DFS(r + 1, c);
        }
        return "(" + r + "," + c + ")";
    }

    public boolean validN(int r, int c) {
        if (r < 0) return false;
        if (r >= this.rows) return false;
        if (c < 0) return false;
        if (c >= this.cols) return false;
        if (map[r][c] == ' ') return false;
        return this.map[r][c] != '#';
    }

    /**
     * Return the vertices adjacent to the given vertex.
     * The vertices in the returned array must be sorted in 
     * the following order: left, top, right, bottom.
     * Return an empty array if there are no adjacent vertices.
     */
    public Vertex[] getAdjacentVertices(Vertex vertex) {
        // TODO: Your code here...
        int s = adjacentCounter(vertex.coords.row, vertex.coords.col);
        int r = vertex.coords.row;
        int c = vertex.coords.col;
        Vertex [] output = new Vertex[s];
        int pos = 0;
        if (inbounds(r, c - 1)) {
            if (map[r][c-1] != '#') {
                output[pos] = makeV(r, c - 1);
                pos++;
            }
        }
        if (inbounds(r - 1, c)) {
            if (map[r - 1][c] != '#') {
                output[pos] = makeV(r - 1, c);
                pos++;
            }
        }
        if (inbounds(r, c + 1)) {
            if (map[r][c + 1] != '#') {
                output[pos] = makeV(r, c + 1);
                pos++;
            }
        }
        if (inbounds(r + 1, c)) {
            if (map[r + 1][c] != '#') {
                output[pos] = makeV(r + 1, c);
                pos++;
            }
        }
        return output;
    }

    public Vertex makeV(int r, int c) {
        Vertex output = new Vertex();
        output.coords = new Coordinates(r, c);
        return output;
    }

    public int adjacentCounter(int r, int c) {
        int output = 0;
        if (inbounds(r, c - 1)) {
            if (map[r][c-1] != '#')
                output++;
        }
        if (inbounds(r - 1, c)) {
            if (map[r - 1][c] != '#')
                output++;
        }
        if (inbounds(r, c + 1)) {
            if (map[r][c + 1] != '#')
                output++;
        }
        if (inbounds(r + 1, c)) {
            if (map[r + 1][c] != '#')
                output++;
        }
        return output;
    }

    public boolean inbounds(int r, int c) {
        return (r >= 0) && (r < rows) && (c >= 0) && (c < cols);
    }
    /**
     * Return the vertex corresponding to the dungeon entrance.
     */
    public Vertex getDoor() {
        // TODO: Your code here...
        Vertex output = new Vertex();
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                if (this.map[i][j] == 'E') {
                    output.coords = new Coordinates(i, j);
                    break;
                }
            }
        }
        return output;
    }

    /**
     * Return the vertex corresponding to the key tile.
     */
    public Vertex getKey() {
        // TODO: Your code here...
        Vertex output = new Vertex();
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                if (this.map[i][j] == 'K') {
                    output.coords = new Coordinates(i, j);
                    break;
                }
            }
        }
        return output;
    }

    /**
     * Return the vertex corresponding to the treasure tile.
     */    
    public Vertex getTreasure() {
        // TODO: Your code here...
        Vertex output = new Vertex();
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                if (this.map[i][j] == 'T') {
                    output.coords = new Coordinates(i, j);
//                    output.coords.row = i;
//                    output.coords.col = j;
                    break;
                }
            }
        }
        return output;
        //return null; // Stub line, you can safely remove when required
    }

    /** 
     * =============================
     * ===        TASK 2         ===
     * =============================
     */

    /**
     * Return the vertices along the shortest path fro m the start vertex
     * to the end vertex, as identified by the given coordinates. The start 
     * and the end vertex must be included. If no path exists, return an empty array.
     */
    public Vertex[] getShortestPath(Coordinates start, Coordinates end) {
        // TODO: Your code here...
        //Vertex[] output = new Vertex[];
        queue push = new queue(this.rows, this.cols);
        int sRow = start.row;
        int sCol = start.col;
        int eRow = end.row;
        int eCol = end.col;

        if ((map[sRow][sCol] == '#') || (map[eRow][eCol] == '#')) {
            Vertex [] output = new Vertex[0];
            return output;
        }

        resetVisited();

        visited[sRow][sCol] = true;

        Vertex[][] vertmap = new Vertex[this.rows][this.cols];
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                vertmap[i][j] = new Vertex(this.map[i][j], i, j);
            }
        }

        queue que = new queue(this.rows, this.cols);
        que.add(vertmap[sRow][sCol]);

        while (!que.isEmpty()) {
            Vertex temp = que.remove();
            Coordinates pt = temp.coords;

            if (pt.col == eCol && pt.row == eRow)
                push.add(temp);

            for (int i = 0; i < rows * cols; i++)
            {
                int row = pt.row;
                int col = pt.col;

                if (inbounds(row, col) && map[row][col] != '#' && !visited[row][col])
                {
                    visited[row][col] = true;
                    Vertex cell = new Vertex(vertmap[row][col].val, row, col);
                    que.add(cell);
                    System.out.println(cell.val);
                    push.add(cell);
                }
            }
            //break;
        }
        /*for (int i =0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                System.out.print(vertmap[i][j].val);
            }
            System.out.println();
        }*/

        for (int i = 0; i < push.size; i++) {
            System.out.println(push.q[i].val);
            System.out.println(".");
        }
        System.out.println(".");

        return null; // Stub line, you can safely remove when required
    }


    public boolean safe(int r, int c) {
        return (this.map[r][c] != '#' || !this.visited[r][c]);
    }

    public boolean bounded(int r, int c) {
        if (r < 0) return false;
        if (r >= this.rows) return false;
        if (c < 0) return false;
        return c < this.cols;
    }

    /**
     * Return an array of vertices that make up the shortest path from the entrance 
     * to the key to the treasure and back to the entrance, in order from start to end.
     * The starting and the ending vertex (entrance) should be included in the path.
     * If there is no path, return an empty array.
     */
    public Vertex[] getShortestPath() {
        // TODO: Your code here...
        return null; // Stub line, you can safely remove when required
    }


    /**
     * Return the length of the shortest path from the given starting vertex coordinates, 
     * to the end vertex coordinates. The start and end vertices should be part of the path.
     * If no path exists, return null.
     */
    public Integer getShortestPathLength(Coordinates start, Coordinates end) {
        // TODO: Your code here...
        return null; // Stub line, you can safely remove when required
    }


    /**
     * Return the string representing the shortest path from start vertex to end vertex by 
     * indicating the succession of steps (left, right, up, down) that need to be taken. 
     * The words must be comma-separated, with a space after each comma, and a full stop at the end. 
     * Left-up-right-down movement preference applies.
     */
    public String getShortestPathString(Coordinates start, Coordinates end) {
        // TODO: Your code here...
        return null; // Stub line, you can safely remove when required
    }


    /**
     * This method has the same functionality as getShortestPathString(Coordinates start, Coordinates end), 
     * but should return the text representation of the shortest path from entrance 
     * to key to treasure and back to the entrance.
     */
    public String getShortestPathString() {
        // TODO: Your code here...
        return null; // Stub line, you can safely remove when required
    }

    /** 
     * =============================
     * ===        TASK 3         ===
     * =============================
     */

    /**
     * No additional methods need to be implemented, but you must expand your code to work with traps and teleports.
     */

}
