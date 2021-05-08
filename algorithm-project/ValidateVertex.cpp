#include "ValidateVertex.h"

void validateVertexInRange(int v, int vertices) {
    if (v < 1 || v > vertices)
        throw std::invalid_argument("One of the verteices is invalid");
}

//this function skips the first 3 rows .
void prepareFileToNextLoad(istream& in)
{
    string line;
    in.clear();
    in.seekg(0);
    getline(in, line);
    getline(in, line);
    getline(in, line);
}


bool loadEdge(istream& in, int& i, int& j, float& weight)
{
    int count = 0;
    char check;
    string line;
    getline(in, line);
    stringstream ss(line);
    if (ss >> i) count++;
    if (ss >> j) count++;
    if (ss >> weight) count++;
    if ((count != 3 && count != 0) || ss >> check) //check if we get 3 numbers from this line,
                                                  //check if there is another char in the line - if there is : invalid input structure.
        throw invalid_argument("invalid input structure");
    return (count != 0); //if count==0 then we finish reading the file
}

void getNumofVertexSourceAndTarget(istream& in, int& n, int& s, int& t)
{
    string line;
    getline(in, line);
    stringstream ss(line);
    n = s = t = INFINITY;
    ss >> n;
    getline(in, line);
    ss.str(line);
    ss >> s;
    getline(in, line);
    ss.str(line);
    ss >> t;
    if (n < 0)
    {
        throw invalid_argument("n is invalid");
    }
    validateVertexInRange(s, n);
    validateVertexInRange(t, n);
}
