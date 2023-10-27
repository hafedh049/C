#include "heap/maxHeap.c"

int main() {
    MaxHeap *mh = createMaxHeap(10);
    toString(mh);
    
    return 0;
}
