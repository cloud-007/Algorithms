#include<bits/stdc++.h>
using namespace std;

int p[100];

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

int main() {
    int node, edge, cost[100][100];
    priority_queue < pair < int, pair <int, int> >> vp;
    cin >> node >> edge;
    for(int i = 0; i <= node; i++) {
        p[i] = i;
    }
    for(int i = 0; i < edge; i++) {
        int u, v, cos;
        cin >> u >> v >> cos;
        vp.push({-cos, {u, v}});
    }
    int tot = 0;
    while(!vp.empty()) {
        int x = find(vp.top().second.first);
        int y = find(vp.top().second.second);

        if(x != y) {
            tot += (-vp.top().first);
            p[y] = x;
        }
        vp.pop();
    }
    cout << tot << endl;
}
/*
8 11
1 5 2
1 4 10
1 2 4
2 4 8
2 3 18
5 4 5
3 4 11
4 7 11
4 8 9
7 6 1
8 6 2*/

