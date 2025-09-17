#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // ---- Step 0: compute mex and frequency of the original array ----
        vector<int> freq(n + 2, 0);
        for (int x : a) ++freq[x];
        int M = 0;
        while (M <= n && freq[M] > 0) ++M;   // mex of original

        // ---- Step 1 (simultaneous): build arr2 from a ----
        // Rule: for each i,
        //   if a[i] < M and freq[a[i]] == 1 -> arr2[i] = a[i]
        //   else                            -> arr2[i] = M
        vector<int> arr2(n);
        long long sum2 = 0;
        bool arr2_has_zero = false;
        for (int i = 0; i < n; ++i) {
            int v;
            if (a[i] < M && freq[a[i]] == 1) v = a[i];
            else v = M;
            arr2[i] = v;
            sum2 += v;
            if (v == 0) arr2_has_zero = true;
        }

        if (k == 1) {
            cout << sum2 << '\n';
            continue;
        }

        // ---- Step 2 (simultaneous): build arr3 from arr2 ----
        // Need mex of arr2 and freq of arr2.
        vector<int> freq2(n + 3, 0);
        for (int v : arr2) ++freq2[v];
        int M2 = 0;
        while (M2 <= n + 1 && freq2[M2] > 0) ++M2;   // mex of arr2

        long long sum3 = 0;
        for (int i = 0; i < n; ++i) {
            int v3;
            if (arr2[i] < M2 && freq2[arr2[i]] == 1) v3 = arr2[i];
            else v3 = M2;
            sum3 += v3;
        }

        // ---- Decide for general k >= 2 using the 2-cycle parity ----
        if (arr2_has_zero) {
            // The sequence alternates: arr2 <-> arr3 <-> arr2 ...
            // For k even:  sum(arr3)
            // For k odd (>=3): sum(arr2)
            if (k % 2 == 0) cout << sum3 << '\n';
            else            cout << sum2 << '\n';
        } else {
            // arr2 has no zero -> arr3 becomes all zeros,
            // then it alternates between all-ones and all-zeros.
            // For k even: sum(arr3) == 0
            // For k odd (>=3): sum == n (all ones)
            if (k % 2 == 0) cout << 0 << '\n';
            else            cout << (long long)n << '\n';
        }
    }
    return 0;
}
