#include "binomial_heap/BinominalHeap.h"

#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    int cnt1 = 0;
    BinomialHeap hp1;
    while (x != 0) {
        if (x > 0){
            BinomialHeap tmp;
            tmp.insert(x);
            hp1.meld(tmp);
        }
        cin >> x;
        cnt1++;
    }
    BinomialHeap hp2;
    int cnt2 = 0;
    cin >> x;
    while (x != 0) {
        if (x > 0){
            BinomialHeap tmp;
            tmp.insert(x);
            hp2.meld(tmp);
        }
        cin >> x;
        cnt2++;
    }
    hp1.meld(hp2);
    for (int i = 0; i < cnt1 + cnt2; ++i) {
        cout << hp1.extract_min() << endl;
    }
    return 0;
}