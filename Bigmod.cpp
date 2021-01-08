/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

ll tc, x, y, mod;

ll bigmod(ll a, ll p, ll m) {
    ll res = 1;
    ll x = a;
    while(p) {
        if(p & 1)res = (res * x) % m;
        x = (x * x) % m;
        p /= 2;
    }

    return res;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> x >> y >> mod) {
        cout << bigmod(x, y, mod) << endl;
    }

    return 0;
}
