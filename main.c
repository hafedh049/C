#include "array/array.c"

int main() {
    Array *arr = createArray();
    pushMany(arr,3,1,2,3);
    removeAll(arr,1);
    unshift(arr,1);
    toString(arr);
    return 0;
}
