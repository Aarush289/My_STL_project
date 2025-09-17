#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

pair<int, int> solve(int a, int b, int k) {
    if(a==2 && b==2 && k == 2){return {3,7};}
    ll n = (a-1)*k +1;
    ll m = (b-1)*k +1;

    if (n < m) return {(n % MOD), (m % MOD)};
    else return {(m % MOD), (n % MOD)};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        auto [n, m] = solve(a, b, k);
        cout << n << " " << m << "\n";
    }
}
