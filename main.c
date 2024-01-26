#include "Vector.h"

int main() {
    Vector* vec = CreateVector();
    for (int i = 0; i < 20; i++) {
        VectorPush(vec, i+1);
        PrintVector(vec);
    }
    for (int i = 0; i < 20; i++) {
        VectorPop(vec);
        PrintVector(vec);
    }
    DeleteVector(&vec);
}
