#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int vectorMinimumSize = 10;

typedef struct {
    int* data;
    int length;
    int size;
} Vector;

Vector* CreateVector() {
    Vector* newVector = NULL;
    while (newVector == NULL) { newVector = malloc(sizeof(Vector)); }
    newVector->data = malloc(sizeof(int) * vectorMinimumSize);
    newVector->length = 0;
    newVector->size = vectorMinimumSize;
    return newVector;
};

void Grow(Vector* vector) {
    vector->size *= 2;
    int* newData = malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) newData[i] = vector->data[i];
    free(vector->data);
    vector->data = newData;
}

void Shrink(Vector* vector) {
    if (vector->size == vectorMinimumSize) return;
    vector->size /= 2;
    int* newData = malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) newData[i] = vector->data[i];
    free(vector->data);
    vector->data = newData;
}

int GetLength(Vector* vector) {
    if (vector == NULL) {
        printf("Warning: trying to get length but vector is null");
        return INT_MIN;
    } else return vector->length;
}

void Push(Vector* vector, int num) {
    if (vector == NULL) {
        printf("Warning: trying to push but vector uninitialized\n");
        return;
    } else {
        vector->data[vector->length++] = num;
        if (vector->length == vector->size) Grow(vector);
    }
};

int Pop(Vector* vector) {
    if (vector == NULL) {
        printf("Warning: trying to pop but vector uninitialized\n");
        return INT_MIN;
    } else if (vector->length == 0) {
        printf("Warning: trying to pop but vector is empty\n");
        return INT_MIN;
    } else {
        int num = vector->data[--vector->length];
        if (vector->length <= vector->size/3) Shrink(vector);
        return num;
    }
}

int Get(Vector* vector, int index) {
    if (vector == NULL) {
        printf("Warning: trying to get value but vector uninitialized\n");
        return INT_MIN;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to get value but index out of bounds\n");
        return INT_MIN;
    } else return vector->data[index];
};

bool Set(Vector* vector, int index, int value) {
    if (vector == NULL) {
        printf("Warning: trying to set value but vector uninitialized\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to set value but index out of bounds\n");
        return false;
    } else {
        vector->data[index] = value;
        return true;
    }
}

bool InsertAt(Vector* vector, int value, int index) {
    if (vector == NULL) {
        printf("Warning: trying to insert value but vector uninitialized\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to insert value but index out of bounds\n");
        return false;
    } else {
        for (int i = vector->length; i > index; i--) 
            vector->data[i] = vector->data[i-1];
        vector->data[index] = value;
        if (++vector->length == vector->size) Grow(vector);
        return true;
    }
}

bool RemoveAt(Vector* vector, int index) {
    if (vector == NULL) {
        printf("Warning: trying to remove value but vector uninitialized\n");
        return false;
    } else if (vector->length == 0) {
        printf("Warning: trying to remove value but vector is empty\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to remove value but index out of bounds\n");
        return false;
    } else {
        while (index < vector->length - 1) {
            vector->data[index] = vector->data[index + 1];
            index++;
        }
        vector->length--;
        if (vector->length <= vector->size/3) Shrink(vector);
        return true;
    }
}

int Find(Vector* vector, int value) {
    if (vector == NULL) {
        printf("Warning: trying to find value but vector uninitialized\n");
        return -1;
    } else {
        for (int i = 0; i < vector->length; i++) 
            if (vector->data[i] == value) return i;
        return -1;
    }
}

bool RemoveFirst(Vector* vector, int value) {
    if (vector == NULL) {
        printf("Warning: trying to remove value but vector uninitialized\n");
        return false;
    } else if (vector->length == 0) {
        printf("Warning: trying to remove value but vector is empty\n");
        return false;
    } else return RemoveAt(vector, Find(vector, value));
}

void Print(Vector* vector) {
    if (vector == NULL) printf("vector: { Uninitialized Vector }\n");
    else {
        printf("vector: { length: %d, size: %d, data: { ", vector->length, vector->size);
        for (int i = 0; i < vector->length; i++) printf("%d, ", vector->data[i]);
        printf("} }\n");
    }
}
