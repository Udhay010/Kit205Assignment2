#ifndef HEAP_H
#define HEAP_H

#define MAX_HEAP_SIZE 100

typedef struct MinHeap {
    int size;
    int arr[MAX_HEAP_SIZE];
} MinHeap;

MinHeap* create_minheap();
void insert_heap(MinHeap* heap, int key);
int extract_min(MinHeap* heap);
void heapify(MinHeap* heap, int i);
void print_heap(MinHeap* heap);

#endif // HEAP_H
