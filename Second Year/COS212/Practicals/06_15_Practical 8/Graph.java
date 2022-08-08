// Name: Matthew Gotte
// Student number: u20734621

import java.util.ArrayList;
import java.util.List;

public class Graph {

    private List<Vertex> verticesList;

    public Graph() {
        this.verticesList = new ArrayList<>();
    }

    public void addVertex(Vertex vertex) {
        this.verticesList.add(vertex);
    }

    public void reset() {
        for (Vertex vertex : verticesList) {
            vertex.setVisited(false);
            vertex.setPredecessor(null);
            vertex.setDistance(Double.POSITIVE_INFINITY);
        }
    }

    ////// Implement the methods below this line //////

    public List<Vertex> getShortestPath(Vertex sourceVertex, Vertex targetVertex) {
        List<Vertex> output = new ArrayList<Vertex>();
        List<Vertex> temp = new ArrayList<Vertex>();

        ArrayList<Vertex> none = new ArrayList<Vertex>();
        if (!(this.verticesList.contains(targetVertex))) {
            return none;
        }
        if (!(this.verticesList.contains(sourceVertex))) {
            return none;
        }

        if (sourceVertex == targetVertex) {
            List<Vertex> emptyList = new ArrayList<Vertex>();
            emptyList.add(sourceVertex);
            return emptyList;
        }

        for (Vertex vertex : verticesList) {
            vertex.setVisited(false);
            vertex.setPredecessor(null);
            vertex.setDistance(Double.MAX_VALUE);
        }

        sourceVertex.setDistance(0);
        double min = Double.MAX_VALUE;
        List<Vertex> copy = new ArrayList<>(verticesList);

        int p = 0;
        for (p = 0; p < copy.size() - 1; p++)
            if (copy.get(p).equals(sourceVertex))
                break;

        Vertex top = copy.get(p);
        copy.remove(p);

        while (!copy.isEmpty() || !checkTop(top)) {
            for (int i = 0; i < getsize(top); i++) {
                Vertex nextEnd = top.getAdjacenciesList().get(i).getEndVertex();
                if (nextEnd.getDistance() > calc(top, i)) {
                    nextEnd.setPredecessor(top);
                    nextEnd.setDistance(calc(top, i));
                }

                if (comparator(nextEnd, targetVertex)) {
                    if (dist(nextEnd, min)) {
                        min = nextEnd.getDistance();
                    }
                }
            }
            if (copy.size() == 0) {
                top = null;
            } else {
                top = copy.get(0);
                copy.remove(0);
            }
        }

        if (Double.MAX_VALUE == min)
            return temp;

        top = targetVertex;
        while (top != sourceVertex) {
            temp.add(top);
            Vertex swap = top.getPredecessor();
            top = swap;
        }

        temp.add(top);
        for (int i = temp.size() - 1; i >= 0; i--)
            output.add(temp.get(i));
        return output;
        // Your code here
    }

    public boolean dist(Vertex temp, double dis) {
        if (temp.getDistance() < dis)
            return true;
        return false;
    }

    public double calc(Vertex temp, int i) {
        return temp.getDistance() + temp.getAdjacenciesList().get(i).getWeight();
    }

    public boolean comparator(Vertex next, Vertex target) {
        return next == target;
    }

    public int getsize(Vertex temp) {
        return temp.getAdjacenciesList().size();
    }

    public boolean checkTop(Vertex top) {
        return top == null;
    }

    public double getShortestPathDistance(Vertex sourceVertex, Vertex targetVertex) {

        if (sourceVertex == targetVertex)
            return 0.0;

        if (!(this.verticesList.contains(targetVertex))) {
            return Double.POSITIVE_INFINITY;
        }
        if (!(this.verticesList.contains(sourceVertex))) {
            return Double.POSITIVE_INFINITY;
        }

        this.reset();
        sourceVertex.setDistance(0);
        double finalout = Double.POSITIVE_INFINITY;
        List<Vertex> copy = new ArrayList<>(verticesList);


        int p = 0;
        for (p = 0; p < copy.size() - 1; p++)
            if (copy.get(p).equals(sourceVertex))
                break;

        Vertex top = copy.get(p);
        copy.remove(p);

        while (!copy.isEmpty() || checkTop(top)) {
            for (int i = 0; i < top.getAdjacenciesList().size(); i++) {
                Vertex nextEnd = top.getAdjacenciesList().get(i).getEndVertex();
                if (nextEnd.getDistance() > calc(top, i)) {
                    nextEnd.setPredecessor(top);
                    nextEnd.setDistance(calc(top, i));
                }
                if (comparator(nextEnd, targetVertex)) {
                    if (nextEnd.getDistance() < finalout) {
                        finalout = nextEnd.getDistance();
                    }
                }
            }
            if (copy.size() == 0)
                top = null;
            else {
                top = copy.get(0);
                copy.remove(0);
            }
        }
        return finalout;
        // Your code here
    }

}