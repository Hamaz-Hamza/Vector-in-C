#include "Vector.h"

int main() {
    Vector* vec = CreateVector();
    for (int i = 0; i < 20; i++) {
        Push(vec, i+1);
        Print(vec);
    }
    for (int i = 0; i < 20; i++) {
        Pop(vec);
        Print(vec);
    }
    free(vec);
}
