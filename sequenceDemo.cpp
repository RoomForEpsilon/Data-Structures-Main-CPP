#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "sequence.h"
#include <set>
#include <cassert>

using namespace main_savitch_3;

// double average(std::multiset<double> const x);

int main() {
    
    sequence s;

    // s.attach(3);
    // s.attach(3);
    // s.attach(2);
    // s.attach(3);
    // s.attach(1);
    // s.attach(0);

    // for (s.start(); s.is_item(); s.advance()) {
    //     printf("%lf\n", s.current());
    // }

    // printf("\n");
    // s.remove(3);
    
    // for (s.start(); s.is_item(); s.advance()) {
    //     printf("%lf\n", s.current());
    // }

    // std::cout << toupper('a') << "\n";
    // printf("%d\n", toupper('+'));

    // std::multiset<int> ages;
    // std::multiset<int>::iterator it;

    // ages.insert(4);
    // ages.insert(12);
    // ages.insert(18);
    // ages.insert(12);

    // for (it = ages.begin(); it != ages.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }

    for (size_t i=0; i < 10; ++i) {
        s.attach((double) i);
    }

    for (size_t i=0; i < 10; ++i) {
        assert (s[i] == (double) i);
        printf("s[%d] = %lf\n", (int) i, (double) i);
    }

    return EXIT_SUCCESS;
}

// double average(const std::multiset<double>& x) {

//     double sum = 0;
//     for (auto it = x.cbegin(); it != x.cend(); ++it) {
//         sum += *it;
//     }
//     return sum / x.size();
// }