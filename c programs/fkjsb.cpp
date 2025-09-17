#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Sound {
    int v, p, idx;
};

bool solve() {
    int n;
    cin >> n;
    vector<Sound> sounds(n);
    for (int i = 0; i < n; ++i) {
        cin >> sounds[i].v >> sounds[i].p;
        sounds[i].idx = i + 1;
    }

    if (n == 1) {
        cout << "YES\n1\n";
        return true;
    }

    bool all_same_v = true;
    int first_v = sounds[0].v;
    for (const auto& s : sounds) {
        if (s.v != first_v) {
            all_same_v = false;
            break;
        }
    }

    bool all_same_p = true;
    int first_p = sounds[0].p;
    for (const auto& s : sounds) {
        if (s.p != first_p) {
            all_same_p = false;
            break;
        }
    }

    if (all_same_v || all_same_p) {
        cout << "NO\n";
        return false;
    }

    sort(sounds.begin(), sounds.end(), [](const Sound& a, const Sound& b) {
        if (a.v != b.v) return a.v < b.v;
        return a.p < b.p;
    });

    vector<int> sequence;
    int left = 0, right = n - 1;
    bool toggle = true;
    while (left <= right) {
        if (toggle) {
            sequence.push_back(sounds[left].idx);
            left++;
        } else {
            sequence.push_back(sounds[right].idx);
            right--;
        }
        toggle = !toggle;
    }

    bool valid = true;
    for (int i = 0; i < n - 1; ++i) {
        int v1 = sounds[sequence[i] - 1].v;
        int p1 = sounds[sequence[i] - 1].p;
        int v2 = sounds[sequence[i + 1] - 1].v;
        int p2 = sounds[sequence[i + 1] - 1].p;
        if (v1 != v2 && p1 != p2) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        int half = n / 2;
        vector<Sound> part1(sounds.begin(), sounds.begin() + half);
        vector<Sound> part2(sounds.begin() + half, sounds.end());
        sequence.clear();
        int i = 0, j = 0;
        while (i < part1.size() && j < part2.size()) {
            sequence.push_back(part1[i].idx);
            sequence.push_back(part2[j].idx);
            i++;
            j++;
        }
        while (i < part1.size()) {
            sequence.push_back(part1[i].idx);
            i++;
        }
        while (j < part2.size()) {
            sequence.push_back(part2[j].idx);
            j++;
        }

        valid = true;
        for (int i = 0; i < n - 1; ++i) {
            int v1 = sounds[sequence[i] - 1].v;
            int p1 = sounds[sequence[i] - 1].p;
            int v2 = sounds[sequence[i + 1] - 1].v;
            int p2 = sounds[sequence[i + 1] - 1].p;
            if (v1 != v2 && p1 != p2) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        cout << "NO\n";
        return false;
    }

    bool non_boring = true;
    for (int i = 0; i < n - 2; ++i) {
        int v1 = sounds[sequence[i] - 1].v;
        int p1 = sounds[sequence[i] - 1].p;
        int v2 = sounds[sequence[i + 1] - 1].v;
        int p2 = sounds[sequence[i + 1] - 1].p;
        int v3 = sounds[sequence[i + 2] - 1].v;
        int p3 = sounds[sequence[i + 2] - 1].p;
        if ((v1 == v2 && v2 == v3) || (p1 == p2 && p2 == p3)) {
            non_boring = false;
            break;
        }
    }

    if (non_boring) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return true;
    } else {
        cout << "NO\n";
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}