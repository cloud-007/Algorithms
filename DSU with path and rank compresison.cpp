/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e6 + 5;
int n, u, v, Par[sz];
ll cnt, ans, mx, Rank[sz];

void make_set(int v) {
    Par[v] = v;
    Rank[v] = 1;
}

int find_set(int v) {
    if(v == Par[v])
        return v;
    return Par[v] = find_set(Par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        ans -= (Rank[b] * (Rank[b] - 1)) / 2;
        ans -= (Rank[a] * (Rank[a] - 1)) / 2;
        Par[b] = a;
        Rank[a] += Rank[b];
        ans += (Rank[a] * (Rank[a] - 1)) / 2;
    }
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= sz; i++)make_set(i);
    while(n--) {
        cin >> u >> v;
        if(u > v)swap(u, v);
        union_sets(u, v);
        cout << ans << endl;
    }

    return 0;
}
