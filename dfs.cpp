#include<bits/stdc++.h>
using namespace std;

vector < int > v[10];
int vis[10];
bool ok;

int dfs(int b, int e) { //basic dfs;
    memset(vis, false, sizeof vis);
    stack < int > s;
    vis[b] = true;
    s.push(b);
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        if(x == e)
            return 1;
        for(int i = 0; i < v[x].size(); i++) {
            if(vis[v[x][i]] == 0) {
                vis[v[x][i]] = 1;
                s.push(v[x][i]);
            }
        }
    }
    return 0;
}

void dfs1(int b, int e) {
    if(b == e)ok = true;
    vis[b] = 1;
    for(auto i : v[b]) {
        if(!vis[b])
            dfs(i, e);
    }

}


int main() {
    int node, edge ;
    cin >> node >> edge;
    for(int i = 1; i <= edge; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);///for directed graph only the first line
    }
    int b, e;
    while(cin >> b >> e) {
        ok = false;
        dfs(b, e) ? printf("YES\n") : printf("NO\n");
        memset(vis, false, sizeof false);
        dfs1(b, e);
        puts(ok ? "YES" : "NO");
    }
}
