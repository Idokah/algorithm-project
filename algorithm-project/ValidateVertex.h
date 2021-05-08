#pragma once
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool loadEdge(istream& in, int& i, int& j, float& weight);
void getNumofVertexSourceAndTarget(istream& in, int& n, int& s, int& t);
void validateVertexInRange(int v, int vertices);
void prepareFileToNextLoad(istream& in);