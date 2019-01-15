#include <iostream>
#include <algorithm>
#include<stdio.h>
#include<string.h>
#define int64 long long
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int64 n, k;
    cin >> n >> k;
    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int64 i = 0, j = n-1;
    int64 ans = 0;;
    while(i<j){
        if(a[i] + a[j] < k){
             ans += j-i;
             i++;
        }
        else{
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
