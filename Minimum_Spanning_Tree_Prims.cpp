#include<bits/stdc++.h>
using namespace std;
int main() {
    int node, edge, cost[100][100];
    vector < pair < int, int >> vp;
    cin >> node >> edge;
    vector < int > x[node + 5];
    for(int i = 0; i < edge; i++) {
        int u, v, cos;
        cin >> u >> v >> cos;
        x[u].push_back(v);
        x[v].push_back(u);
        cost[u][v] = cos;
        cost[v][u] = cos;
    }
    int vis[node + 5];
    memset(vis, 0, sizeof vis);
    priority_queue< pair < int, int >> pq;
    pq.push({0, 6});
    int total_cost = 0;
    while(!pq.empty()) {
        pair < int, int > t = pq.top();
        int u = t.second;
        pq.pop();
        if(vis[u] == 1)
            continue;
        else {
            vis[u] = 1;
            total_cost += (-t.first);
        }
        for(int i = 0; i < x[u].size(); i++) {
            int v = x[u][i];
            if(!vis[v]) {
                pq.push({-cost[u][v], v});
            }
        }

    }
    printf("%d\n", total_cost);
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
