//Brian Kernighan’s Algorithm:
#include <iostream>
using namespace std;

unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
/* Program to test function countSetBits */
int main()
{
    int i = 9;
    cout << countSetBits(i);
    return 0;
}