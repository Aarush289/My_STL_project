//B87678
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define debug 1
#define ll long long

const ll N = 2 * (1e7) + 1;
vector<bool> isPrime(N, true);

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
    }//B87678
}

void take(long long arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void take(int arr[], int n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void take(char str[])
{
    scanf("%s", str);
}
bool prie(ll n)
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

ll power2(long long m)
{
    long long result = 1;
    ll base = 2;
    while (m > 0)
    {
        if (m % 2 == 1) // If exp is odd, multiply result with base
            result *= base;
        result %= (1000000007);
        base *= base;
        base %= (1000000007); // Square the base
        m /= 2;               // Reduce exponent by half
    }
    return result ;
}

ll first_of(const set<int> &s)
{
    return s.empty() ? INT_MAX : *s.begin(); // INT_MAX if empty
}

std ::pair<ll, ll> sq(ll n)
{
    ll factor;
    ll count = 0;
    for (ll i = 2; i <= (sqrt(n)); i++)
    {
        if (n % i == 0)
        {
            if (count == 0)
            {
                factor = i;
            }
            count++;
        }
    }
    if (count == 1 && ((n / factor) % factor != 0 || factor * factor == n))
    {
        return make_pair(1, factor);
    }
    else
    {
        return make_pair(0, 0);
    }
}

// class RotRevArr
// {
//     vector<int> arr;
//     ll offset;
//     bool reversed;

// public:
//     RotRevArr(const vector<int> &input) : arr(input), offset(0), reversed(false) {}

//     void rightRotateBy1()
//     {
//         offset = (offset - 1 + arr.size()) % arr.size();
//     }

//     void reverse()
//     {
//         reversed = !reversed;
//         offset = (offset + 1) % arr.size();
//     }

//     ll get(ll i)
//     {
//         ll idx;
//         if (!reversed)
//             idx = (offset + i) % arr.size();
//         else
//             idx = (offset - i + arr.size()) % arr.size();
//         return arr[idx];
//     }

//     void printArray()
//     {
//         for (ll i = 0; i < arr.size(); ++i)
//             cout << get(i) << " ";
//         cout << endl;
//     }
// };

// class SmartDeque
// {
//     deque<int> dq;
//     bool reversed;

// public:
//     SmartDeque(initializer_list<int> input) : dq(input), reversed(false) {}

//     void rightRotateBy1()
//     {
//         if (!reversed)
//         {
//             ll last = dq.back();
//             dq.pop_back();
//             dq.push_front(last);
//         }
//         else
//         {
//             ll first = dq.front();
//             dq.pop_front();
//             dq.push_back(first);
//         }
//     }

//     void reverse()
//     {
//         reversed = !reversed;
//     }

//     void push_back(ll val)
//     {
//         if (!reversed)
//             dq.push_back(val); // logical end is physical back
//         else
//             dq.push_front(val); // logical end is physical front
//     }

//     ll operator[](ll i) const
//     {
//         if (i < 0 || i >= dq.size())
//         {
//             throw out_of_range("Index out of range");
//         }

//         if (!reversed)
//             return dq[i];
//         else
//             return dq[dq.size() - 1 - i];
//     }
//     ll size() const
//     {
//         return dq.size();
//     }

//     void printArray()
//     {
//         if (!reversed)
//         {
//             for (ll x : dq)
//                 cout << x << " ";
//         }
//         else
//         {
//             for (auto it = dq.rbegin(); it != dq.rend(); ++it)
//                 cout << *it << " ";
//         }
//         cout << endl;
//     }
// };

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

// void reverseArray(ll arr[], ll size)
// {
//     ll start = 0;
//     ll end = size - 1;

//     while (start < end)
//     {
//         // Swap elements
//         ll temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;

//         start++;
//         end--;
//     }
// }



const ll MOD =  1000000007;
const ll MAX = 1e6 ;
long long fact[MAX], invFact[MAX];

// Fast exponentiation for modular inverse
long long power(long long a, long long b, ll mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// Fast exponentiation for modular inverse
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2, MOD); // Fermat's little theorem
    for (ll i = MAX - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

long long nCr(ll n, ll r) {
    if(r==0){return 1;}
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

long double comb_ratio(long long A, long long B, long long k) {
    if (k < 0) return 0.0L;
    if (A < k) return 0.0L;      // numerator C(A,k) = 0
    if (B < k) return 0.0L;      // guard; for your case ensure sum >= n before calling
    long double r = 1.0L;
    for (long long i = 0; i < k; ++i) {
        r *= (long double)(A - i) / (long double)(B - i);
    }
    return r;
}

// ll pre[n+1];
//         pre[0]=0;
//         ll count=0;
//         for(ll i=0;i<n;i++){
//             if(arr[i]<=k){count++;}
//             pre[i+1]=count;
//         }

// vector<vector<int>> findCycles(const vector<int>& arr) {
//     ll n = arr.size();
//     vector<bool> visited(n, false);
//     vector<vector<int>> result;

//     for (ll i = 0; i < n; ++i) {
//         if (visited[i]) continue;

//         unordered_set<int> currentSet;
//         vector<int> path;
//         ll current = i;

//         // Follow the chain until we revisit a node
//         while (!visited[current] && currentSet.find(current) == currentSet.end()) {
//             currentSet.insert(current);
//             path.push_back(current);
//             current = arr[current];
//         }

//         // If we detect a cycle in the current path
//         if (currentSet.find(current) != currentSet.end()) {
//             vector<int> cycle;
//             bool inCycle = false;
//             for (ll idx : path) {
//                 if (idx == current) inCycle = true;
//                 if (inCycle) cycle.push_back(idx);
//                 visited[idx] = true;
//             }
//             result.push_back(cycle);
//         } else {
//             // Mark all visited even if no cycle was found
//             for (ll idx : path) {
//                 visited[idx] = true;
//             }
//         }
//     }

//     return result;
// }


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


ll gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

long long mod_inverse(long long a, long long m) {
    return power(a, m - 2, m);
}

ll LIS(const vector<int>& a) {
    vector<int> dp;
    for (ll x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

ll juo(ll x,ll y){
    return (x%y + y%x);
}

ll min_steps_to_g(vector<int>& a, ll g) {
    const ll MAX = 5000;
    vector<bool> visited(MAX + 1, false);
    vector<int> dist(MAX + 1, INT_MAX);
    queue<int> q;

    for (ll x : a) {
        if (!visited[x]) {
            visited[x] = true;
            dist[x] = 0;
            q.push(x);
        }
    }

    while (!q.empty()) {
        ll x = q.front(); q.pop();
        for (ll y : a) {
            ll z = __gcd(x, y);
            if (!visited[z]) {
                visited[z] = true;
                dist[z] = dist[x] + 1;
                q.push(z);
            }
        }
    }

    return dist[g] == INT_MAX ? -1 : dist[g];
}



bool dfs(ll u, vector<vector<int>> &sets, unordered_map<int, int> &match, unordered_set<int> &visited) {
    for (ll val : sets[u]) {
        if (visited.count(val)) continue;
        visited.insert(val);
        if (!match.count(val) || dfs(match[val], sets, match, visited)) {
            match[val] = u;
            return true;
        }
    }
    return false;
}

bool can_match(ll k, const vector<vector<int>> &sets) {
    unordered_map<int, int> match; // number -> set index
    for (ll i = 0; i < k; ++i) {
        unordered_set<int> visited;
        if (!dfs(i, const_cast<vector<vector<int>>&>(sets), match, visited)) {
            return false;
        }
    }
    return true;
}

ll max_sets(vector<vector<int>> &sets) {
    ll left = 0, right = sets.size(), ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (can_match(mid, sets)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}



vector<vector<ll>> connect(ll n){
    vector<vector<ll>> v(n);
    for(ll i=0;i<n-1;i++){
        ll a ,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    return v;
}
void addnode(ll a, ll b , vector<vector<ll>>& v){
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
}
vector<ll> bfs(const vector<vector<ll>>& v , ll n , ll start){
    queue<ll> q;
    vector<bool> vis(n, false);
    vector<ll> ans;
    vis[start]=1;
    q.push(start);
    while(!q.empty()){
        ll num = q.front();
        q.pop();
        ans.push_back(num);
        for(auto it : v[num]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}


vector<ll> full_bfs(const vector<vector<ll>>& graph, ll n) {
    vector<bool> vis(n, false);
    vector<ll> total;

    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<ll> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                ll u = q.front(); q.pop();
                total.push_back(u);

                for (ll v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return total;
}

void gotoDepth(ll start ,const vector<vector<ll>>& v , vector<ll>& vis , vector<ll>& ans){
    vis[start]=1;
    ans.push_back(start);
    for(auto it: v[start]){
        if(!vis[it]){
            gotoDepth(it , v , vis , ans);
        }
    }

}
vector <ll> dfs(const vector<vector<ll>>& v , ll n , ll start){
    vector<ll> vis(n,0);
    vector<ll> ans;
    gotoDepth(start , v , vis , ans);
    return ans;
}

vector<ll> dfs_iterative(const vector<vector<ll>>& v, ll n, ll start) {
    vector<ll> vis(n, 0);
    vector<ll> ans;
    stack<ll> s;
    s.push(start);

    while (!s.empty()) {
        ll node = s.top();
        s.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        ans.push_back(node);

        // Push neighbors in reverse to maintain order similar to recursive
        for (auto it = v[node].rbegin(); it != v[node].rend(); ++it) {
            if (!vis[*it]) {
                s.push(*it);
            }
        }
    }

    return ans;
}

void dfs_util(ll node, const vector<vector<ll>>& adj, vector<ll>& vis, vector<ll>& component) {
    vis[node] = 1;
    component.push_back(node);
    for (ll neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs_util(neighbor, adj, vis, component);
        }
    }
}

vector<vector<ll>> full_dfs(const vector<vector<ll>>& adj, ll n) {
    vector<ll> vis(n, 0);
    vector<vector<ll>> all_components;

    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            vector<ll> component;
            dfs_util(i, adj, vis, component);
            all_components.push_back(component);
        }
    }

    return all_components;
}

bool bfs_forcycle(ll i , vector<int>& vis , vector<vector<int>>& v , vector<int>& par){
    vis[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        for(ll j=0;j<v[x].size();j++){
            if(!vis[v[x][j]]){vis[v[x][j]]=1;q.push(v[x][j]);par[v[x][j]]=x;}
            else{
                if(par[x]!=v[x][j]){return true;}
            }
        }
        
    }
    return false;
}
bool isCyclebfs(ll n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
    for(ll i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
        vector<int>vis(n,0);
        vector<int> par(n,-1);
        for(ll i=0;i<n;i++){
        if(!vis[i]){ if(bfs_forcycle(i, vis , v , par)){return true;}}
    }
    return false;
    
}

bool dfs_forcycle(ll i , vector<int>& vis , vector<vector<int>>& v , ll par){
    vis[i]=1;
    for(ll j=0;j<v[i].size();j++){

        if(!vis[v[i][j]]){  if(dfs_forcycle(v[i][j], vis , v , i)){return true;}}
    else{
        if(par!= v[i][j] ){return true;}
    }
    }
    return false;
}
bool isCycledfs(ll n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
    for(ll i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
        vector<int>vis(n,0);
    
        for(ll i=0;i<n;i++){
        if(!vis[i]){ if(dfs_forcycle(i, vis , v , -1)){return true;}}
    }
    return false;
}

bool condition(ll a, ll b) {
    return a < b; // Change this to your desired condition
}
// Sieve of Eratosthenes to generate primes up to n
vector<int> get_primes(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
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

void generate_good_permutation(ll n) {
    vector<int> p(n + 1, 0);          // Result permutation (1-based)
    vector<bool> used(n + 1, false);  // To track which positions are filled
    vector<int> primes = get_primes(n);
    reverse(primes.begin(), primes.end()); // Start from largest prime

    for (ll prime : primes) {
        vector<int> group;
        for (ll i = prime; i <= n; i += prime) {
            if (!used[i])
                group.push_back(i);
        }

        if (group.size() > 1) {
            for (ll i = 0; i < group.size(); ++i) {
                ll from = group[i];
                ll to = group[(i + 1) % group.size()];
                p[from] = to;
                used[from] = true;
            }
        }
    }

    // Fill any remaining positions (typically just 1)
    set<int> unused;
    for (ll i = 1; i <= n; ++i)
        if (!used[i])
            unused.insert(i);

    for (ll i = 1; i <= n; ++i)
        if (p[i] == 0) {
            p[i] = *unused.begin();
            unused.erase(unused.begin());
        }

    // Output the permutation
    for (ll i = 1; i <= n; ++i)
        cout << p[i] << " ";
    cout << "\n";
}
#include <cmath>

bool isPerfectSquare(long long n) {
    if (n < 0) return false;
    long long root = (long long)(sqrtl(n));
    return root * root == n;
}

ll min_penalty_x(ll y, ll b, ll c) {
    ll mask = b | c;
    ll x = y;

    // If x already satisfies the mask condition, done
    if ((x & mask) == mask) return x;

    // Now we want to flip the lowest possible bits to satisfy the condition
    for (ll i = 0; i < 64; ++i) {
        if ((mask >> i) & 1) {
            // Bit i must be set in x
            if (!((x >> i) & 1)) {
                // Bit is not set in x, try setting it and zeroing all lower bits
                ll candidate = (x | (1LL << i));
                candidate &= ~((1LL << i) - 1); // clear lower bits
                candidate |= (mask & ((1LL << i) - 1)); // force lower mask bits
                if ((candidate & mask) == mask && candidate >= y) {
                    x = candidate;
                    break;
                }
            }
        }
    }
     if ((x & mask) != mask || x < y) {
        x = (y | mask);
        if ((x & mask) != mask) return -1; // Just in case (safety)
    }

    return x;
}

void bfs_for(ll node ,vector<vector<ll>>& adj , map<ll,ll>& m , ll mino,ll maxo , vector<int>& vis , ll arr[]){
    vis[node]=1;
    m[node] = max(arr[node]-mino , arr[node]);
    ll min1 = min(arr[node]-maxo , arr[node]);
    ll max1 = max(arr[node] - mino , arr[node]);
    for(auto it: adj[node]){
        if(!vis[it]){ bfs_for(it , adj , m , min1 , max1 , vis , arr);}
    }
    return;
}

vector<vector<ll>> connect_par(ll n){
    ll p;
    vector<vector<ll>> adj(n) ;
    for(ll i=0;i<n-1;i++){
        cin >> p;
        adj[i+1].push_back(p-1);
        adj[p-1].push_back(i+1);
    }
    return adj;
}

vector<vector<ll>> levels(vector<vector<ll>>& adj){
   // ll level=0;
    queue<ll> q;
    vector<vector<ll>> ans;
    q.push(0);
    vector<ll> vis(adj.size(),0);
    
    vector<ll> v;
    vis[0]=1;
    while(!q.empty()){
        ll siz = q.size();
        v.clear();
        for(ll i=0;i<siz;i++){
            ll j= q.front();
            q.pop();
            v.push_back(j);
            for(auto it:adj[j]){
                if(!vis[it]) {q.push(it);vis[it]=1;}
            }
        }
        ans.push_back(v);
    }
    return ans;
}

ll editDistance(const string &A, const string &B) {
    ll n = A.size();
    ll m = B.size();

    // Only two rows needed for space optimization
    vector<int> prev(m+1, 0), curr(m+1, 0);

    // Base case: converting empty string to B[0..j]
    for(ll j = 0; j <= m; j++) prev[j] = j;

    for(ll i = 1; i <= n; i++){
        curr[0] = i; // converting A[0..i] to empty string

        for(ll j = 1; j <= m; j++){
            if(A[i-1] == B[j-1])
                curr[j] = prev[j-1]; // no operation needed
            else
                curr[j] = 1 + min({ prev[j-1], // replace
                                    prev[j],   // delete
                                    curr[j-1]  // insert
                                  });
        }

        swap(prev, curr); // move current row to previous
    }

    return prev[m]; // minimum edit distance
}

template <typename T>
ll longestCommonSubsequence(const vector<T>& A, const vector<T>& B) {
    ll n = A.size();
    ll m = B.size();
    
    // DP table: only 2 rows needed for space optimization
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(ll i = 1; i <= n; i++) {
        curr[0] = 0; // LCS with empty array is 0
        for(ll j = 1; j <= m; j++) {
            if(A[i-1] == B[j-1])
                curr[j] = prev[j-1] + 1; // match found
            else
                curr[j] = max(prev[j], curr[j-1]); // take max from left or top
        }
        swap(prev, curr);
    }
    
    return prev[m]; // length of LCS
}

// Returns max value we can get for 0/1 Knapsack
ll knapsack01(const vector<int> &weight, const vector<int> &value, ll W) {
    ll n = weight.size();
    vector<int> dp(W+1, 0); // space optimized

    for(ll i = 0; i < n; i++) {
        // iterate from W to weight[i] to avoid reusing the same item
        for(ll w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

ll unboundedKnapsack(const vector<ll> &weight, const vector<ll> &value, ll W) {
    ll n = weight.size();
    vector<ll> dp(W+1, 0);

    for(ll w = 0; w <= W; w++) {
        for(ll i = 0; i < n; i++) {
            if(weight[i] <= w)
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

// Function to find LCS of 3 arrays
template <typename T>
ll lcs3(const vector<T> &A, const vector<T> &B, const vector<T> &C) {
    ll n = A.size();
    ll m = B.size();
    ll o = C.size();

    // 3D DP table
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(o+1, 0)));

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            for(ll k = 1; k <= o; k++) {
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[n][m][o];
}

long long maxFirstPlayerScore(const vector<long long> &a) {
    ll n = a.size();

    // prefix sum to compute subarray sums efficiently
    vector<long long> prefix(n+1, 0);
    for(ll i=0; i<n; i++) prefix[i+1] = prefix[i] + a[i];

    auto sum = [&](ll l, ll r) -> long long {
        return prefix[r+1] - prefix[l];
    };

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for(ll len=1; len<=n; len++) {
        for(ll i=0; i+len-1<n; i++) {
            ll j = i+len-1;
            if(i==j) dp[i][j] = a[i];
            else dp[i][j] = max(a[i] + (sum(i+1,j) - dp[i+1][j]),
                                a[j] + (sum(i,j-1) - dp[i][j-1]));
        }
    }

    return dp[0][n-1];
}

// Function to count subsets that sum up to target
long long countSubsets(vector<int> &arr, ll target) {
    ll n = arr.size();
    vector<long long> dp(target + 1, 0);

    // Base case: sum 0 can always be achieved with empty subset
    dp[0] = 1;

    // Iterate over each number in the array
    for (ll i = 0; i < n; i++) {
        // Go backwards to avoid using the same element multiple times
        for (ll j = target; j >= arr[i]; j--) {
            dp[j] += dp[j - arr[i]];
        }
    }

    return dp[target];
}


// Function to find minimum difference between two subsets
long long minSubsetSumDifference(vector<long long> &arr) {
    ll n = arr.size();
    long long totalSum = 0;
    for (auto x : arr) totalSum += x;

    // dp[s] = true if subset with sum s is possible
    vector<bool> dp(totalSum / 2 + 1, false);
    dp[0] = true;

    for (auto num : arr) {
        for (long long s = totalSum / 2; s >= num; s--) {
            dp[s] = dp[s] || dp[s - num];
        }
    }

    // Find the largest possible sum s1 <= totalSum/2
    long long s1 = 0;
    for (long long s = totalSum / 2; s >= 0; s--) {
        if (dp[s]) {
            s1 = s;
            break;
        }
    }

    long long s2 = totalSum - s1;
    return abs(s2 - s1);
}


// Longest Increasing Subsequence (non-strict)
long long LIS(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> dp(n, 1); // dp[i] = length of LIS ending at i

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] >= arr[j]) // >= for non-strict
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Longest Decreasing Subsequence (non-strict)
long long LDS(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> dp(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] <= arr[j]) // <= for non-strict decreasing
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Longest Strictly Increasing Subsequence
long long LIS_strict(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> dp(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]) // strictly greater
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Longest Strictly Decreasing Subsequence
long long LDS_strict(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> dp(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] < arr[j]) // strictly smaller
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

struct Project {
    long long start, end, reward;
};

// Binary search helper to find the last project ending before current start
int findLastNonOverlap(vector<Project> &projects, int idx) {
    int l = 0, r = idx - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(projects[mid].end < projects[idx].start) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

long long maxReward(vector<Project> &projects) {
    int n = projects.size();
    // Sort by end time
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });

    vector<long long> dp(n, 0);
    dp[0] = projects[0].reward;

    for(int i = 1; i < n; i++) {
        long long include = projects[i].reward;
        int last = findLastNonOverlap(projects, i);
        if(last != -1) include += dp[last];
        dp[i] = max(dp[i-1], include);
    }

    return dp[n-1];
}


struct State {
    int rides;      // number of rides
    long long last; // weight of the last ride
};

// Function to calculate minimum elevator rides
int minElevatorRides(const vector<long long>& weights, long long maxWeight) {
    int n = weights.size();
    int maskSize = 1 << n;
    vector<State> dp(maskSize, {n+1, 0}); // initialize with max rides
    dp[0] = {1, 0}; // no people taken yet -> 1 ride with 0 weight

    for(int mask = 0; mask < maskSize; mask++) {
        for(int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) { // if person i not included yet
                int nextMask = mask | (1 << i);
                long long newWeight = dp[mask].last + weights[i];
                State newState;
                if (newWeight <= maxWeight) {
                    // add person i to current ride
                    newState = {dp[mask].rides, newWeight};
                } else {
                    // start new ride for person i
                    newState = {dp[mask].rides + 1, weights[i]};
                }
                // update dp[nextMask] if better
                if (newState.rides < dp[nextMask].rides ||
                    (newState.rides == dp[nextMask].rides && newState.last < dp[nextMask].last)) {
                    dp[nextMask] = newState;
                }
            }
        }
    }

    return dp[maskSize - 1].rides; // answer for all people
}


ll MOD5 = 1e9 + 7;

// Function to count ways to fill n x m grid with 1x2 and 2x1 tiles
long long countDominoTilings(int n, int m) {
    // If n < m, swap to reduce mask size (mask size = 2^min(n,m))
    if (n < m) swap(n, m);

    int maxMask = 1 << m;
    vector<long long> dp(maxMask, 0);
    dp[0] = 1; // empty row

    // Iterate over each row
    for (int row = 0; row < n; row++) {
        vector<long long> ndp(maxMask, 0);

        // Function to fill row recursively
        function<void(int,int,int)> dfs = [&](int mask, int pos, long long val) {
            if (pos == m) {
                ndp[mask] = (ndp[mask] + val) % MOD5;
                return;
            }
            if (mask & (1 << pos)) {
                // Cell already filled by vertical tile
                dfs(mask ^ (1 << pos), pos + 1, val);
            } else {
                // Place horizontal tile (if possible)
                if (pos + 1 < m && !(mask & (1 << (pos + 1)))) {
                    dfs(mask, pos + 2, val);
                }
                // Place vertical tile
                dfs(mask | (1 << pos), pos + 1, val);
            }
        };

        for (int mask = 0; mask < maxMask; mask++) {
            if (dp[mask] > 0) dfs(mask, 0, dp[mask]);
        }

        dp = ndp; // update dp for next row
    }

    return dp[0]; // fully filled mask
}


const int MAX_DIGITS = 20;

// Digit DP function to count numbers <= num where no two adjacent digits are the same
long long countNonAdjacentSame(const string &num) {
    int n = num.size();
    // dp[pos][tight][prev_digit] = number of ways
    long long dp[MAX_DIGITS][2][11];
    memset(dp, -1, sizeof(dp));

    // Recursive lambda function
    function<long long(int, int, int)> dfs = [&](int pos, int tight, int prev) -> long long {
        if (pos == n) return 1; // reached end, valid number
        if (dp[pos][tight][prev + 1] != -1) return dp[pos][tight][prev + 1];

        int limit = tight ? (num[pos] - '0') : 9;
        long long res = 0;
        for (int d = 0; d <= limit; d++) {
            if (d == prev) continue; // skip same as previous digit
            res += dfs(pos + 1, tight && (d == limit), d);
        }
        return dp[pos][tight][prev + 1] = res;
    };

    return dfs(0, 1, -1); // start at pos 0, tight bound, prev=-1
}

// Function to count numbers in [a, b]
long long countInRange(long long a, long long b) {
    auto toStr = [](long long x) { return to_string(x); };
    long long resB = countNonAdjacentSame(toStr(b));
    long long resA = countNonAdjacentSame(toStr(a - 1));
    return resB - resA;
}

struct Fenwick {
    vector<long long> bit;
    int n;
    Fenwick(int size) : n(size) { bit.assign(n + 2, 0); }

    void update(int idx, long long val) {
        while(idx <= n) {
            bit[idx] = (bit[idx] + val) % MOD;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long res = 0;
        while(idx > 0) {
            res = (res + bit[idx]) % MOD;
            idx -= idx & -idx;
        }
        return res;
    }
};

// Function to count increasing subsequences
long long countIncreasingSubsequences(vector<long long> &arr) {
    int n = arr.size();
    // Coordinate compression
    vector<long long> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
    
    auto getIndex = [&](long long val) {
        return lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin() + 1;
    };

    Fenwick ft(sortedArr.size());
    long long total = 0;

    for(auto x : arr) {
        int idx = getIndex(x);
        long long cnt = (ft.query(idx - 1) + 1) % MOD; // subsequences ending with x
        ft.update(idx, cnt);
        total = (total + cnt) % MOD;
    }

    return total;
}


vector<int> luckyNumbers;
vector<int> countUpTo; 
const int MAXK = 1e9;

void generateLucky(long long num = 0) {
    if (num > MAXK) return;
    if (num > 0) luckyNumbers.push_back(num);
    generateLucky(num * 10 + 4);
    generateLucky(num * 10 + 7);
}

void initLucky() {
    luckyNumbers.clear();
    generateLucky();
    sort(luckyNumbers.begin(), luckyNumbers.end());

    countUpTo.resize(luckyNumbers.size());
    for (int i = 0; i < (int)luckyNumbers.size(); i++) {
        countUpTo[i] = i + 1; // number of lucky numbers <= luckyNumbers[i]
    }
}

// O(1) query using precomputed vector
int countLuckyUpTo(int x) {
    auto it = upper_bound(luckyNumbers.begin(), luckyNumbers.end(), x);
    if (it == luckyNumbers.begin()) return 0;
    return countUpTo[it - luckyNumbers.begin() - 1];
}
 
long double cac(ll n , vector<long double>& dp){
    if(dp[n]!=-1){return dp[n];}
    if(n==0){return dp[n]=0;}
    long double sum=0.0;
    sum = cac(n-1 ,dp);
    sum+= double(1/n);
    return dp[n]= 1+sum;


}

ll cal(ll n){
    ll sum=0;
    for(int i=0;i<=(n/2);i++){
        sum+= nCr(n-i,i) ;
    }
    return sum;
}

void solve() {
   ll n,k;
   cin >>n >> k;
   ll arr[n];
   take(arr,n);
   sort(arr,arr+n);
   if(arr[n-1]==0){
        if(k%2==0){
            cout << "0" << endl;
        }
        else{
            cout << n << endl;
        }
        return;
   }
   if(arr[0]==arr[n-1]){
         if(k%2==0){
            cout << n << endl;
        }
        else{
            cout << "0"<< endl;
        }
        return;
   }
   map<ll,ll> m;
   for(int i=0;i<n;i++){m[arr[i]]++;}
   int count=0;
   ll sum=0;
   int index=0;
   for(int i=0;i<n;i++){
    if(arr[i]==i){count++;}
    else{index=i;}
    sum+=arr[i];
   }
   if(index>0 && arr[index]==arr[index-1]){count--;}

   ll arr2[n],arr3[n];
   ll mex=0;
   for(auto it:m){
    if(it.first==mex){mex++;}
    else{break;}
   }
   sum=0;
   map<ll,ll>m2;
   for(int i=0;i<n;i++){
    if(arr[i]>=mex){arr2[i]=mex;}
    else{
        if(m[arr[i]]==1){arr2[i]=arr[i];}
        else{
            arr2[i]=mex;
        }
    }
    sum+=arr2[i];
    m2[arr2[i]]++;
   }
   if(k==1){cout << sum << endl;return;}
   sort(arr2,arr2+n);
   if(arr2[0]!=0){
          if(k%2==1){
            cout << n << endl;
        }
        else{
            cout << "0"<< endl;
        }
        return;
   }

   ll sum2=0;
   mex=0;
   for(auto it:m2){
    if(it.first==mex){mex++;}
    else{break;}
   }
   for(int i=0;i<n;i++){
        if(arr2[i]>=mex){arr3[i]=mex;}
        else{
            arr3[i]=arr2[i];
        }
        sum2+=arr3[i];
   }
   sort(arr3,arr3+n);
   if(arr3[0]==0 && arr3[1]==arr3[n-1]){
        if(k%2==0){cout << n-1 << endl;}
        else{
            cout << 2*(n-1) << endl;
        }
        return;
   }
   cout << sum << endl;


}


int main() {
  string s;

  cin >> s;
  int n= s.size();
  s= ' '+ s;
  long double ans =0;
  long double w_count =0;
  long double sum_w=0;
  long double sum_till =0;
  for(int i=n;i>=1;i--){
    long double m = n-i+1;
    if(s[i]=='W'){w_count+=(m);}
    long double sum = (double)(m)*(double)(m+1)/(double)(2);
    long double val = (s[i]=='C') ? w_count : (sum - w_count) ;
    ans = (double)(val + sum_till)/(double)(m);
    sum_till+= ans;
  }
  cout << fixed << setprecision(12) << ans << endl;
}