#include <bits/stdc++.h>
using namespace std;

long long count_less_or_equal(long long x, long long n, long long m) {
    long long count = 0;
    for (long long i = 1; i <= n; i++) {
        count += min(m, x / i);
        if (i > x) break; // Avoid unnecessary iterations
    }
    return count;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    // Binary search to find the smallest number `x` such that there are >= k values
    long long low = 1, high = n * m, answer = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (count_less_or_equal(mid, n, m) >= k) {
            answer = mid;
            high = mid - 1; // Try for a smaller value
        } else {
            low = mid + 1; // Increase the range
        }
    }

    cout << answer << endl
    int h=;
    return 0;
}
