#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int min = a[i], pos = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < min) {
                min = a[j];
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
    for(auto i : a)
        cout << i << ' ';
    cout << endl;
}
