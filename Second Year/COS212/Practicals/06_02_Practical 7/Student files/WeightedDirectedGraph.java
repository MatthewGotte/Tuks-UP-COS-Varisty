import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class WeightedDirectedGraph {

    private List<Vertex> verticesList; //contains all vertices in this graph

    public WeightedDirectedGraph() {
        this.verticesList = new ArrayList<>();
    }

    public void addVertex(Vertex vertex) {
        this.verticesList.add(vertex);
    }

    ////// Implement the methods below this line //////

    public List<Vertex> getShortestPath(Vertex sourceVertex, Vertex targetVertex) {
        // your code goes here
        ArrayList<Vertex> notFound = new ArrayList<Vertex>();
        if (!(this.verticesList.contains(targetVertex))) {
            return notFound;
        }
        if (!(this.verticesList.contains(sourceVertex))) {
            return notFound;
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
        List<Vertex> copy = new ArrayList<>();
        for (Vertex vertex : verticesList) {
            copy.add(vertex);
        }

        int p = 0;
        for (p = 0; p < copy.size() - 1; p++)
            if (copy.get(p).equals(sourceVertex))
                break;

        Vertex top = copy.get(p);
        copy.remove(p);

        while (!copy.isEmpty() || top != null) {
            for (int i = 0; i < top.getAdjacenciesList().size(); i++) {
                Vertex nextEnd = top.getAdjacenciesList().get(i).getEndVertex();
                if (nextEnd.getDistance() > top.getDistance() + top.getAdjacenciesList().get(i).getWeight()) {
                    nextEnd.setPredecessor(top);
                    nextEnd.setDistance(top.getDistance() + top.getAdjacenciesList().get(i).getWeight());
                }

                if (nextEnd == targetVertex) {
                    if (nextEnd.getDistance() < min) {
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

        List<Vertex> output = new ArrayList<Vertex>();
        List<Vertex> temp = new ArrayList<Vertex>();

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

    }
}