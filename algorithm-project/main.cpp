#include <chrono>
#include <iomanip>
#include <string>
#include "main.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Graph.h"


typedef float (*Func)(Graph* graph ,int s, int t);
void shortestPathWithMeasure(Graph* graph, int s, int t, const char* fileName, Func algorithm, const char* algorithmName);


int main(int argc, char *argv[]){
    ifstream infile(argv[1], ios::binary);
    ofstream outfile(argv[2], ios::binary);
    if (!infile) {
        throw invalid_argument("Error with infile");
    }

    int numVertices, s, t;
    infile >> numVertices >> s >> t;

    AdjacencyMatrixGraph matrixGraph(numVertices);
    //matrixGraph.toString();
    matrixGraph.load(infile);
    //cout << endl << endl;
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

    shortestPathWithMeasure(&listGraph, s, t, argv[2], Func(Dijkstra::dijkstraWithHeap), "Dijkstra heap");
    shortestPathWithMeasure(&listGraph, s, t, argv[2], Func(Dijkstra::dijkstraWithArray), "Dijkstra array");
    shortestPathWithMeasure(&listGraph, s, t, argv[2], Func(BellmanFord::bellmanFord), "Bellman Ford ");
    shortestPathWithMeasure(&matrixGraph, s, t, argv[2], Func(Dijkstra::dijkstraWithHeap),"Dijkstra heap");
    shortestPathWithMeasure(&matrixGraph, s, t, argv[2], Func(Dijkstra::dijkstraWithArray), "Dijkstra array");
    shortestPathWithMeasure(&matrixGraph, s, t, argv[2], Func(BellmanFord::bellmanFord), "Bellman Ford ");
}

//this function get graph, source , destination , file name, and algorithm function
//print to the screen the shortest path and to the file name the measure
void shortestPathWithMeasure(Graph* graph, int s, int t, const char* fileName, Func algorithm, const char* algorithmName)
{
    const string typeAndFunc = graph->getType() + " " + algorithmName + " ";
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.     
    ios_base::sync_with_stdio(false);
    float result = algorithm(graph, s, t); // Here you put the name of the function you wish to measure

    auto end = chrono::high_resolution_clock::now();

    cout << typeAndFunc << result << endl;

    // Calculating total time taken by the program. 
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    ofstream myfile(fileName, std::ofstream::out | std::ofstream::app); // The name of the file which is in argv[2]

    myfile << typeAndFunc << fixed
        << time_taken << setprecision(9);
    myfile << " sec" << endl;
    myfile.close();
}
