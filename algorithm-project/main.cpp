#include "main.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "Dijkstra.h"

int main(int argc, char *argv[]){
    ifstream infile(argv[1], ios::binary);
    ofstream outfile(argv[2], ios::binary);
    if (!infile) {
        throw invalid_argument("Error with outfile");
    }

    int numVertices, s, t;
    infile >> numVertices >> s >> t;

    AdjacencyMatrixGraph matrixGraph(numVertices);
    matrixGraph.toString();
    matrixGraph.load(infile);
    cout << endl << endl;
    matrixGraph.toString();

    AdjacencyListGraph listGraph(numVertices);
    infile.clear();
    infile.seekg(0);
    infile >> numVertices >> s >> t;
    listGraph.load(infile);
    cout << endl << endl;
    listGraph.toString();
    infile.close();
    outfile.close();

    cout<<Dijkstra::dijkstraWithHeap(&matrixGraph, s, t)<<endl;
    cout<<Dijkstra::dijkstraWithHeap(&listGraph, s, t);
    cout<<Dijkstra::dijkstraWithArray(&matrixGraph, s, t) << endl;
    
}