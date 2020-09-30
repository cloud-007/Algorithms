#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz = 1e5 + 50;
int k, ans[sz], sum = 0, a[sz];

struct query {
    int index, l, r;
    ll val;
    bool operator< (const query &other)const {
        int block_own = l / k;
        int block_other = other.l / k;
        if(block_own == block_other)
            return r < other.r;
        return block_own < block_other;
    }
} q[sz];

void add(int idx) {
    sum += a[idx];
}

void remove(int idx) {
    sum -= a[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    k = sqrt(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
        q[i].val =  x;
    }
    sort(q, q + m);
    int l = 0, r = -1;
    memset(ans, 0, sizeof ans);
    for(int i = 0; i < m; i++) {
        while(r < q[i].r)add(++r);
        while(l < q[i].l)remove(l++);
        while(r > q[i].r)remove(r--);
        while(l > q[i].l)add(--l);
        ans[q[i].index] = sum;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << endl;
}
