#include<bits/stdc++.h>
using namespace std;
void knapSack(int S, int n, int val[], int wt[]);

int main() {
    printf("Enter the no. of item: ");
    int a;
    scanf("%d", &a);
    int val[a + 1], wt[a + 1];
    printf("Give input weight vs value :\n");
    for(int i = 1; i <= a; i++) {
        cin >> wt[i] >> val[i];
    }
    int S;
    printf("Enter the size of knapsack :");
    cin >> S;
    knapSack(S, a, val, wt);
    return 0;
}

void knapSack(int S, int n, int val[], int wt[]) {
    int i, w;
    int v[n + 1][S + 1]; ///as it is 1 based

    for(w = 0; w <= S; w++) {
        v[0][w] = 0; ///fill the row i=0 with value 0
    }

    for(i = 0; i <= n; i++) {
        v[i][0] = 0; ///fill the column w=0 with value 0
    }

    for(i = 1; i <= n; i++) { ///traversing through all elements;
        for(w = 1; w <= S; w++) {
            if(wt[i] <= w) { ///checking current weight is less than or equal to total weight
                v[i][w] = max(v[i - 1][w], val[i] + v[i - 1][w - wt[i]]);
            } else {
                v[i][w] = v[i - 1][w];
            }
        }
    }

    //max value that can be put inside the knapsack
    printf("Max Value: %d\n", v[n][S]);
    i = n;
    int k = S;
    printf("Taken Item: ");
    while(i > 0 && k > 0) {
        if(v[i][k] != v[i - 1][k]) {
            printf("%d ", wt[i]);
            i--;
            k -= val[i];
        } else
            i--;
    }
}
