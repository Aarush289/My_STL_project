#include <bits/stdc++.h>
using namespace std;

int N, Q;
string s1, s2;

int process_query(int l, int r) {
    int len = r - l + 1;
    string a = s1.substr(l, len);  // local s1
    string b = s2.substr(l, len);  // local s2

    bool changed = true;
    for (int iter = 0; iter < 5 && changed; iter++) {
        changed = false;

        // Rule 1: if a[i] == a[i+2] == 'D' => b[i+1] = 'N'
        for (int i = 0; i + 2 < len; i++) {
            if (a[i] == 'D' && a[i + 2] == 'D' && b[i + 1] == 'D') {
                b[i + 1] = 'N';
                changed = true;
            }
        }

        // Rule 2: if b[i] == b[i+2] == 'N' => a[i+1] = 'N'
        for (int i = 0; i + 2 < len; i++) {
            if (b[i] == 'N' && b[i + 2] == 'N' && a[i + 1] == 'D') {
                a[i + 1] = 'N';
                changed = true;
            }
        }
    }

    // Count 'N' in final version of a (local s1)
    return count(a.begin(), a.end(), 'N');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N ;
    cin >> s1 >> s2;
    cin >> Q;

    while (Q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << process_query(l, r) << '\n';
    }

    return 0;
}
