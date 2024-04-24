#include<iostream>
#include "Template.h"
using namespace std;
int compare_ints(int x, int y) {
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    if (x == y)
        return 0;
}

int main() {
    Vector<int> v;

    // index, element
    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);
    v.insert(3, 30);
    v.insert(4, 7);

    v.sort(compare_ints);
  

    v.print();
}
