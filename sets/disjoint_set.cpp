//
// Created by Vinay Saini on 21/01/18.
//


#include <iostream>
using namespace std;

int Parent[10];
int Rank[10];

int find_set(int x) {
    if(Parent[x] != x) {
        Parent[x] = find_set(Parent[x]);
    }
    return Parent[x];
}

void make_set(int v) {
    Parent[v] = v;
}

void union_set(int x, int y) {
    int root_x = find_set(x);
    int root_y = find_set(y);
    if(Rank[root_x] > Rank[root_y]) {
        Parent[root_y] = root_x;
        Rank[root_x]++;
    } else {
        Parent[root_x] = root_y;
        Rank[root_y]++;
    }
}



int main() {
    //initialize
    int N = 10;
    for(int i = 0; i < N; i++) {
        make_set(i);
    }
    memset(Rank, 0, sizeof Rank);
    union_set(1 , 3);
    cout << "\n" << find_set(1) << " " << find_set(3);
    union_set(2 , 3);
    cout << "\n" << find_set(2) << " " << find_set(3);
    union_set(5 , 6);
    cout << "\n" << find_set(5) << " " << find_set(6);
    union_set(0 , 6);
    cout << "\n" << find_set(0) << " " << find_set(6);
    union_set(0 , 3);
    cout << "\n" << find_set(0) << " " << find_set(3);
    cout << "\n" << find_set(2) << " " << find_set(4);
    return 0;
}


