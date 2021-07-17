#include <bits/stdc++.h>
using namespace std;
  
// refrence Pepcoding  

void copySetBits(unsigned &x, unsigned y,
                 unsigned l, unsigned r)
{
    if (l < 1 || r > 32)
        return ;
    int maskLength = (1<<(r-l+1)) - 1;
    int mask = ((maskLength)<<(l-1)) & y ;
    x = x | mask;
}
  
// Driver code
int main()
{
   unsigned x = 10, y = 13, l = 2, r = 3;
   copySetBits(x, y, l, r);
   cout << "Modified x is " << x;
   return 0;
}