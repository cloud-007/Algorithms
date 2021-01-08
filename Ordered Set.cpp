/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int a[sz], n, q, l, r, casee = 1, tc;
ll tree[sz], x;

void update(int idx, int val, int n) {
    while(idx <= n) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

ll query(int idx) {
    ll sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}//in main function while taking input update(i, value, range);


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, a[i], n);
    }

    cout << query(n) - query(1) << endl;


    return 0;
}
