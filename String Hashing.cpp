/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int mod = 1000000021, base = 907, sz = 1e6 + 5;
int tc, casee = 1;
ll Hash[sz], mp[sz], Hash1[sz];
string s, x, y, z;

void pre() {
    mp[0] = 1;
    for(int i = 1; i < sz; i++) {
        mp[i] = (mp[i - 1] * base) % mod;
    }
}

void compute_hash(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash[i + 1] = hash_val;
    }
}

ll compare(int l, int r) {
    ll rht = Hash[r], lft = (Hash[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

void compute_hash1(string s) {
    ll hash_val = 0;
    for(int i = 0; i < s.size(); i++) {
        hash_val = (hash_val * base + (s[i] - 'a' + 1)) % mod;
        Hash1[i + 1] = hash_val;
    }
}

ll compare1(int l, int r) {
    ll rht = Hash1[r], lft = (Hash1[l - 1] * mp[r - l + 1]) % mod;
    return (rht - lft + mod) % mod;
}

string call(string s, int l, int r) {
    string ans = "";
    while(l <= r)ans += s[l++];
    return ans;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    pre();
    cin >> tc;
    while(tc--) {
        x="", y="", z="";
        cin >> s;
        if(s.size() == 1) {
            cout << s << endl;
            continue;
        }
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            if(l == r) {
                x += s[l];
                l++, r--;
            } else if(s[l] == s[r]) {
                x += s[l], y += s[r];
                l++, r--;
            } else break;
        }
        z = "";
        while(l <= r)z += s[l++];
        s = z;
        reverse(z.begin(), z.end());
        compute_hash(s);
        compute_hash1(z);
        pair < int, int > fin = {-1, -1}, fin1 = {-1, -1};
        string temp = "", temp1 = "";
        int len = s.size();
        for(int i = 0; i < s.size(); i++) {
            if(compare(1, i + 1) == compare1((len - i), len)) {
                fin = {0, i};
            }
        }
        reverse(y.begin(), y.end());

        for(int i = 0; i < s.size(); i++) {
            if(compare1(1, i + 1) == compare((len - i), len)) {
                fin1 = {0, i};
            }
        }
        string mid="";
        if(fin.F != -1 && abs(fin.F - fin.S) >= abs(fin1.F - fin1.S))mid=call(s, fin.F, fin.S);
        else if(fin1.F != -1) mid=call(z, fin1.F, fin1.S);
        cout << x+mid+y<<endl;
        //cout<<fin.F<< " "<<fin.S<<endl;
    }

    return 0;
}
