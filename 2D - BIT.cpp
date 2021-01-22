/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2005;
int tc, n, m, q, a, x, y, val, ty, casee = 1;
ll bit[sz][sz];

void update(int x, int y, int val) {
    for(; x < sz; x += x & -x)
        for(int j = y; j < sz; j += j & -j)
            bit[x][j] += val;
}

ll get(int x, int y) {
    ll ans = 0;
    for(; x > 0 ; x -= x & -x)
        for(int j = y ; j > 0 ; j -= j & -j)
            ans += bit[x][j];
    return ans ;

}

ll get(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1
            - 1) + get(x1 - 1, y1 - 1) ;
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a;
            update(i, j, a);
        }
    }
    while(q--) {
        cin >> ty;
        if(ty == 1) {
            cin >> x >> y >> val;
            update(x, y, val);
        } else {
            int x1, y1;
            cin >> x >> y >> x1 >> y1;
            cout << get(x, y, x1, y1) << endl;
        }
    }


    return 0;
}
