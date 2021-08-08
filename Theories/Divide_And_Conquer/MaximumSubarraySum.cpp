#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

#define INF -1e9
int maxMidSum(vector<int> a, int left, int mid, int right) {
    int sum = 0;
    int left_part_sum = INF;
    for (int i = mid; i >= left; i--) {
        sum = sum + a[i];
        if (sum > left_part_sum) {
            left_part_sum = sum;
        }
    }
    sum = 0;
    int right_part_sum = INF;
    for (int i = mid + 1; i <= right; i++) {
        sum = sum + a[i];
        if (sum > right_part_sum) {
            right_part_sum = sum;
        }
    }
    return left_part_sum + right_part_sum;
}

int maxSubArraySum(vector<int> a, int left, int right) {
    if (left == right) {
        return a[left];
    }
    int mid = (left + right) / 2;
    int max_sum_left = maxSubArraySum(a, left, mid);
    int max_sum_right = maxSubArraySum(a, mid + 1, right);
    int max_sum_mid = maxMidSum(a, left, mid, right);
    return max(max_sum_left, max(max_sum_right, max_sum_mid));
}

void solve() {
    int n, value;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> value;
        a.push_back(value);
    }
    cout << "Maximum subarray sum is: " << maxSubArraySum(a, 0, n - 1);
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}