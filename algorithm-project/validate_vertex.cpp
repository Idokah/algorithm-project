#include "validate_vertex.h"

void validateVertexInRange(int v, int vertices) {
    if (v < 1 || v > vertices)
        throw std::invalid_argument("One of the vertex is invalid");
}
