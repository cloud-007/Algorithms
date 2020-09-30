#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int min = a[0], max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int cnt[max + 1];
    memset(cnt, 0, sizeof cnt);
    int k = 0;
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
    for(int i = min; i <= max; i++)
        for(int j = 1; j <= cnt[i]; j++) {
            a[k] = i;
            k++;
        }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}
