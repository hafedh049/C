#include "heap/maxHeap.c"

int main() {
    MaxHeap *mh = createMaxHeap(10);
    insert(mh,10);
    insert(mh,10);
    insert(mh,10);
    insert(mh,-1);
    insert(mh,100);
    toString(mh);
    printf("%d\n", extractMax(mh));
    delete(mh,-1);
    toString(mh);
    decreaseKey(mh,0,20);
    toString(mh);
    return 0;
}
