#include <bits/stdc++.h>
using namespace std;

bool isFeasible(vector<long long>& arr, long long n, long long k, long long maxSum) {
    long long currentSum = 0, groups = 1;
    for (long long i = 0; i < n; i++) {
        if (arr[i] > maxSum) return false; // Single element exceeds maxSum
        if (currentSum + arr[i] > maxSum) {
            groups++;
            currentSum = arr[i];
            if (groups > k) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

long long minimizeMaxGroupSum(vector<long long>& arr, long long n, long long k) {
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isFeasible(arr, n, k, mid)) {
            result = mid; // Update result and try for a smaller maxSum
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    long long k, n;
    cin >> k >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minimizeMaxGroupSum(arr, n, k) << endl;
    return 0;
}
