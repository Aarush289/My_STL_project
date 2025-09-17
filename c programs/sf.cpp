#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

// Utility function (assuming it's defined elsewhere in original code)
ll s3(ll n) {
    // Placeholder: original code likely computes something specific
    return n; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    if (!(cin >> testCases)) return 0;

    // Precompute powers of 3
    vec<unsigned long long> pow3(40, 1);
    for (int i = 1; i < 40; i++) {
        pow3[i] = pow3[i - 1] * 3ULL;
    }

    while (testCases--) {
        ll n, k;
        cin >> n >> k;

        ll sum = s3(n);
        ll d0 = min(k, n);
        ll d = (d0 % 2 == n % 2) ? d0 : d0 - 1;

        // If condition fails, output -1
        if (d <= 0) {
            cout << -1 << "\n";
            continue;
        }

        ll m = (n - d) / 2;

        vec<unsigned long long> counts(n + 1, 0ULL);
        ll add = 0;
        int idx = 0;

        while (m > 0) {
            if (idx >= (int)counts.size()) counts.push_back(0);

            unsigned long long available = counts[idx] / 3ULL;
            if (available == 0 && idx > 0) {
                idx++;
                continue;
            }

            unsigned long long take = min((unsigned long long)m, available);
            add += take * pow3[idx];
            counts[idx] -= take * 3ULL;

            if (idx + 1 >= (int)counts.size()) counts.push_back(0);
            counts[idx + 1] += take;

            m -= (ll)take;
        }

        cout << (3ULL * (unsigned long long)n + add) << "\n";
    }

    return 0;
}
