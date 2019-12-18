#include "binomial_heap/BinominalHeap.h"

#include <iostream>
#include "leftist_heap/LeftistHeap.h"

using namespace std;

int main(){
    int x;
    cin >> x;
    LeftistHeap hp;
    while (x != 0) {
        if (x > 0)
            hp.insert(x);
        if (x == -1) {
            cout << hp.get_min() << endl;
        }
        if (x == -2)
        {
            cout << hp.extract_min() << endl;
        }
        cin >> x;
    }
    return 0;
}