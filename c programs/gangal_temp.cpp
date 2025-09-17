//B87678
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdint>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

// ready for the action
#define debug 1
#define ll long long
#define ld long double
typedef pair<ll, ll> pii;
typedef map<ll, ll> mp;
typedef vector<ll> vec;
typedef vector<ld> vecd;
typedef vector<vec> vv1;
typedef vector<vecd> vvd;

#define mkp make_pair
#define all(a) a.begin(), a.end()
#define fsort(a) sort(a.begin(), a.end())
#define ssort(a) sort(all(a), sortbysec)
#define ub(a,b) upper_bound(all(a), b)
#define lb(a,b) lower_bound(all(a), b)
#define bs(a,b) binary_search(all(a), b)
#define pb(a) push_back(a)
#define sz(a) a.size()

#define inf 1000000000;
const int INF = 1e9 + 11;
const ll N = 2 * (1e7) + 1;
const ll MOD = 1000000007;    
const ll MAX = 1e6 + 5;         
ll fact[MAX], invFact[MAX];
vector<bool> isPrime(N, true);

ll min(ll a,ll b) {
    if(a<b) {
        return a;
    }
    else {
        return b;
    }
}
ll max(ll a,ll b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}
ll pow(ll a) {
    ll ans=1;
    while(a--) {
        ans*=2;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a,ll b) {
    ll x = (a*b);
    ll y = gcd(a,b);
    ll z = x/y;
    return z;
}

void sieve()
{
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (ll p = 2; p * p < N; p++)
    {
        if (isPrime[p])
        {
            for (ll i = p * p; i < N; i += p)
            {
                isPrime[i] = false; // Mark multiples of p as not prime
            }
        }
    }
}

bool prime_or_not(ll n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    ll flag = 0;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return (flag == 0);
}

// ----------------- Fast Modular Exponentiation -----------------
ll mod_pow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// ----------------- Modular Inverse using Fermat's Theorem -----------------
ll mod_inverse(ll a, ll mod = MOD) {
    return mod_pow(a, mod - 2, mod);
}

// ----------------- Precompute Factorials and Inverses -----------------
void init_factorials() {
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = mod_inverse(fact[MAX - 1]);
    for (ll i = MAX - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll nPr_mod(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[n-r] % MOD;
}

long double nCr_real(long long n, long long k) {
    if (k < 0 || k > n) return 0.0L;
    k = min(k, n - k);
    long double r = 1.0L;
    for (long long i = 1; i <= k; ++i) {
        r *= (long double)(n - k + i);
        r /= (long double)i;
    }
    return r;
}

// ----------------- nCr % MOD -----------------
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// ----------------- Exact Ratio C(A,k)/C(B,k) (long double) -----------------
ld comb_ratio(ll A, ll B, ll k) {
    if (k < 0 || A < k || B < k) return 0.0L;
    ld r = 1.0L;
    for (ll i = 0; i < k; ++i)
        r *= (ld)(A - i) / (ld)(B - i);
    return r;
}

ll nCr_small(ll n, ll r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r; // because C(n, r) = C(n, n-r)
    ll result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

ll nCr_large(ll n, ll r, ll MOD) {
    if(r==0) return 1;
    return nCr_large(n/MOD, r/MOD, MOD) * nCr_small(n%MOD, r%MOD) % MOD;
}

template <typename T > vector<T> prime_factors(T n) {
    vector<T> factors;
    for (T i = 2; i*i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

vector<ll> get_primes(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;

    for (ll i = 2; i <= n; ++i)
        if (is_prime[i])
            primes.push_back(i);

    return primes;
}

ll merge(vector<ll> &arr, ll low, ll mid, ll high) {
    vector<ll> temp; // temporary array
    ll left = low;      // starting index of left half of arr
    ll right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    ll cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

ll mergeSort(vec &arr, ll low, ll high) {
    ll cnt = 0;
    if (low >= high) return cnt;
    ll mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

ll numberOfInversions(vec &a, ll n) {
    return mergeSort(a, 0, n - 1);
}

long double cac(ll n){
    
}
void solve() {
    // double p = 5, q = 7;
    // double prob = p / q;
    // cout << fixed << setprecision(6) << prob << endl;
    // ll ans = (p * modinv(q)) % MOD;
    ll n;
    cin >>n;
    ll ans = cac(ll n);
    cout << ans << endl;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}