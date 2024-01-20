# Vector-in-C

An integer vector implementation in C.
Automatically allocates and deallocates memory during runtime according to the amount of data stored in it.

Note: It is better to use these provided methods instead of directly accessing the vector's data, because these methods perform appropriate validity and error checking.

Functions:
1. CreateVector: create a empty vector and return it.
2. GetLength: returns the length of the vector (number of elements in it).
3. Push: append an integer to the end of the vector.
4. Pop: remove an integer from the end of the vector and return it.
5. Get: get an element from the vector from the specified index.
6. Set: change the value of an element in the vector at the specified index to the specified value.
7. InsertAt: insert an element into the vector at the specified index, elements at or after that index are moved forward. 
8. RemoveAt: remove an element from the vector at the specified index, elements after that index are moved back.
9. Find: find the index of the first instance specified int in the vector and return the index.
10. RemoveFirst: remove the first instance of a specified int from the vector.
11. Print: print the length, size and contents of the vectors, if the vector pointer is null, prints accordingly
12. Grow: grow the vector to double its size (called automatically by the other functions when needed, it is recommended to not use this function unless you know what you are doing)
13. Shrink: shrink the vector to half its size (called automatically by the other functions when needed, it is recommended to not use this function unless you know what you are doing)

