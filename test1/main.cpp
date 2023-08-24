#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include "Solutions.h"
using namespace std;

class A_type {
    int a_;
public:
    explicit A_type(int a_): a_(a_) {}
    bool operator<(const A_type& rhs) const {
        return a_ < rhs.a_;
    }
    bool operator>(const A_type& rhs) const {
        return a_ > rhs.a_;
    }
    [[nodiscard]] int get() const {
        return a_;
    }
};

class Comp{
public:
    bool operator()(const A_type& lhs, const A_type& rhs) const {
        return lhs.get() < rhs.get();
    }
};

int main() {
    priority_queue<A_type, vector<A_type>, less<>> pq;
    int i = 5;
    while (i--) {
        pq.emplace(rand() % (10));
    }
    while (!pq.empty()) {
        cout << pq.top().get() << endl;
        pq.pop();
    }

    return 0;
}