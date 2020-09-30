#include<iostream>
using namespace std;
int main() {
    int a[] = {12, 23, 45, 56, 78, 83, 91, 95};
    int n = sizeof(a) / sizeof(int);
    // cout<<n<<endl;
    int low = 0, high = n - 1, mid, found = 45;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == found) {
            cout << "found" << endl;
            return 0;
        }
        /*if(a[mid]>=found) To find the upper bound of the elements;
        {
        if we remove the equal sign then we ca find the lower bound of this element;
            you should declare flag above of while loop;int flag=-1;
            cout<<found at<<flag<<endl;
            low=mid+1;
        }*/
        else if(a[mid] < found)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Not found" << endl;


    return 0;
}
