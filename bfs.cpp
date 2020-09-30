#include<bits/stdc++.h>
using namespace std;

vector < int > v[10];

int bfs(int b, int e) {
    int visited[10] = {0}; ///size will be the number of node;
    queue< int > q;
    ///memset(visited,0,sizeof vis); another function of visited[10]={0}
    q.push(b);
    visited[b] = 1;
    while(!q.empty()) {
        int x = q.front();
        if(x == e) {
            //cout<<"Possible\n";
            return 1;
        }
        for(int i = 0; i < v[x].size(); i++) {
            if(visited[v[x][i]] == 0) {
                visited[v[x][i]] = 1;
                q.push(v[x][i]);
            }
        }
        q.pop();
    }
    return 0;
    ///  printf("Not Possible\n");
}

int main() {
    // vector < int > v[10];
    int node, edge ;
    cin >> node >> edge;
    for(int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);///for directed graph only the first line
    }
    //queue < int > q;
    int b, e;
    while(cin >> b >> e) {

        if(bfs(b, e)) {
            printf("Yes\n");
        } else
            printf("No\n");
        //if(v)
    }
}
