#include <stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;

int arr[] = {5, 15, 12, 4, 10, 2};
int n = 6;
int heap[10];

void buildHeap(int i) {
    cout<<"Building heap"<<endl;
    if(i == 0) return;
    int par = (i-1)/2;
    int chi = i;
    printf("Parent = %d && Child = %d\n",par,chi);
    if(heap[par] >= heap[chi]) {
        swap(heap[par], heap[chi]);
        buildHeap(par);
    }
}

void deleteHeap(int i, int sz) {
    int par = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int mn = par;

    if(leftChild <= sz && heap[par] > heap[leftChild]) {
        mn = leftChild;
    }
    if(rightChild <= sz && heap[mn] > heap[rightChild]) {
        mn = rightChild;
    }

    if(mn != par) {
        swap(heap[mn], heap[par]);
        deleteHeap(mn, sz);
    }
}

int main() {

    for(int i=0; i<n; i++) {
        heap[i] = arr[i];
        buildHeap(i);
    }

    for(int i=0; i<n; i++) {
        arr[i] = heap[0];
        swap(heap[0], heap[n-i-1]);
        deleteHeap(0, n-i-2);
    }
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
