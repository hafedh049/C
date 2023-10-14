#include "set/set.h"

bool isEven(int a)
{return a % 2;}

void main()
{
   Set* set = createSet();
   add(set,1);
   add(set,1);
   add(set,1);
   add(set,1);
   add(set,2);
   add(set,3);
   powerSet(*set,3);
}