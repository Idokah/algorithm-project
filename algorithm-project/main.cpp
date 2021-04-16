#include "main.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

int main(int argc, char *argv[]){
    ifstream infile(argv[1], ios::binary);
    ofstream outfile(argv[2], ios::binary);
    if (!infile) {
        throw invalid_argument("Error with outfile");
    }

    int numVertices, s, t;
    infile.read(rcastc(&numVertices), sizeof(numVertices));
    infile.read(rcastc(&s), sizeof(s));
    infile.read(rcastc(&t), sizeof(t));

    AdjacencyMatrixGraph matrixGraph(numVertices);
    matrixGraph.load(infile);

    AdjacencyListGraph listGraph(numVertices);
    listGraph.load(infile);

    infile.close();
    outfile.close();
}