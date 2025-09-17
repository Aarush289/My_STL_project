#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#define ll long long

bool find_balanced_b(const vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    ll total = accumulate(a.begin(), a.end(), 0LL);

    for (int split = 1; split < n; ++split) {
        // Try to make sum of first "split" equal to sum of remaining
        ll prefix = 0, suffix = total;
        for (int i = 0; i < split; ++i)
            prefix += a[i];
        suffix -= prefix;

        if (prefix != suffix) continue;

        // If possible, use full a[i] as b[i]
        b.assign(n, 0);
        for (int i = 0; i < split; ++i)
            b[i] = a[i];
        for (int i = split; i < n; ++i)
            b[i] = a[i];

        // Scale b[i] down to make sums equal
        ll sum1 = accumulate(b.begin(), b.begin() + split, 0LL);
        ll sum2 = accumulate(b.begin() + split, b.end(), 0LL);
        ll to_reduce = sum1 - sum2;
        if (to_reduce > 0) {
            for (int i = 0; i < split && to_reduce > 0; ++i) {
                ll delta = min(to_reduce, b[i]);
                b[i] -= delta;
                to_reduce -= delta;
            }
        } else if (to_reduce < 0) {
            to_reduce = -to_reduce;
            for (int i = split; i < n && to_reduce > 0; ++i) {
                ll delta = min(to_reduce, b[i]);
                b[i] -= delta;
                to_reduce -= delta;
            }
        }

        // Double check it's now balanced
        ll l = accumulate(b.begin(), b.begin() + split, 0LL);
        ll r = accumulate(b.begin() + split, b.end(), 0LL);
        return l == r;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<vector<ll>> ops;

        for (int it = 0; it < 17 && accumulate(a.begin(), a.end(), 0LL) > 0; ++it) {
            vector<ll> b(n);
            if (!find_balanced_b(a, b)) break;
            ops.push_back(b);
            for (int i = 0; i < n; ++i)
                a[i] -= b[i];
        }

        if (accumulate(a.begin(), a.end(), 0LL) != 0) {
            cout << -1 << "\n";
        } else {
            cout << ops.size() << "\n";
            for (auto &op : ops) {
                for (auto x : op) cout << x << " ";
                cout << "\n";
            }
        }
    }
}
