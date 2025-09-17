#include <iostream>
#include <vector>
using namespace std;

void execute_strategy(int t, vector<vector<long long>>& test_cases) {
    while (t--) {
        vector<long long>& a = test_cases.back(); test_cases.pop_back();
        int n = a.size();
        vector<vector<long long>> operations;

        for (int step = 0; step < 17; ++step) {
            long long total = 0;
            for (auto x : a) total += x;
            if (total == 0) break;

            long long left = 0, right = 0;
            for (int i = 0; i < n; ++i) right += a[i];

            bool changed = false;

            for (int i = 0; i < n - 1; ++i) {
                left += a[i];
                right -= a[i];

                if (left == right) {
                    operations.push_back(a);
                    for (int j = 0; j < n; ++j) a[j] = 0;
                    changed = true;
                    break;
                }

                if (left < right && (right - left) <= (n / 2 - 1)) {
                    vector<long long> b(n, 0);
                    b[i] = a[i];
                    long long deficit = right - left;

                    for (int j = 0; j < i && deficit > 0; ++j) {
                        b[j] = min(1LL, a[j]);
                        deficit -= b[j];
                    }

                    for (int j = i + 1; j < n; ++j)
                        b[j] = a[j];

                    if (deficit == 0) {
                        operations.push_back(b);
                        for (int j = 0; j < n; ++j) a[j] -= b[j];
                        changed = true;
                        break;
                    }
                }

                if (right < left && (left - right) <= (n / 2 - 1)) {
                    vector<long long> b(n, 0);
                    b[i + 1] = a[i + 1];
                    long long deficit = left - right;

                    for (int j = i + 2; j < n && deficit > 0; ++j) {
                        b[j] = min(1LL, a[j]);
                        deficit -= b[j];
                    }

                    for (int j = 0; j <= i; ++j)
                        b[j] = a[j];

                    if (deficit == 0) {
                        operations.push_back(b);
                        for (int j = 0; j < n; ++j) a[j] -= b[j];
                        changed = true;
                        break;
                    }
                }
            }

            if (!changed) {
                cout << -1 << "\n";
                goto next_case;
            }
        }

        cout << operations.size() << "\n";
        for (auto& op : operations) {
            for (auto x : op) cout << x << " ";
            cout << "\n";
        }

    next_case:;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<vector<long long>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        test_cases[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> test_cases[i][j];
        }
    }

    execute_strategy(t, test_cases);

    return 0;
}
