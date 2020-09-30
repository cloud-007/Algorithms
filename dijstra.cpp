#include<bits/stdc++.h>
using namespace std;
vector < int > v[100];
int dis[100];
int cost[100][100];
void bfs(int b, int e) {
    priority_queue < pair < int, int > >q;
    q.push({0, b});
    dis[b] = 0;
    while(!q.empty()) {
        pair < int, int > x = q.top();
        int u = x.second;
        for(int i = 0; i < v[u].size(); i++) {
            int a = v[u][i];
            if(dis[u] + cost[u][a] < dis[a]) {
                dis[a] = dis[u] + cost[u][a];
                q.push({-dis[a], a});
            }
        }
        q.pop();
    }
}
int main() {
    int node, edge ;
    cin >> node >> edge;
    for(int i = 1; i <= edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        cost[a][b] = c;
    }
    memset(dis, INT_MAX, 100);
    int b, e;
    while(cin >> b >> e) {
        bfs(b, e);
        printf("%d\n", dis[e]);
        memset(dis, INT_MAX, 100);
    }
}

/*
INPUT
5 8
1 2 2
1 3 3
1 4 2
2 3 3
2 5 3
3 4 2
3 5 2
4 5 1
*/

