#include "tuple/tuple.c"

void main()
{
    const Tuple* tuple = createTuple(5,1,2,3,4,5);
    showTuple(*tuple);
    printf("%d\n",size(*tuple));
}