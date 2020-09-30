#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[] = {1, 5, 2, 8, 9, 0, 3, 2, 7, 0, 9, 8};
    for(int i = 0; i < sizeof a / sizeof a[0]; i++) {
        int x = a[i];
        int j = i - 1;
        while(a[j] > x && j >= 0) {
            if(a[j] > a[j + 1]) {
                swap(a[j + 1], a[j]);
                a[j] = x;
            }
            j--;
        }
    }
    for(auto i : a)
        cout << i << ' ';
}
