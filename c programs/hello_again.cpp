#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define debug 1
#define ll long long

const int N = 2 * (1e7) + 1;
vector<bool> isPrime(N, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p < N; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i < N; i += p)
            {
                isPrime[i] = false; // Mark multiples of p as not prime
            }
        }
    }
}

void take(long long int arr[], ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void take(int arr[], int n)
{
    for (int i = 0; i < n; i++)
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
    int flag = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return (flag == 0);
}

long long int power2(long long int m)
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

int first_of(const set<int> &s)
{
    return s.empty() ? INT_MAX : *s.begin(); // INT_MAX if empty
}

std ::pair<ll, ll> sq(ll n)
{
    int factor;
    int count = 0;
    for (int i = 2; i <= (sqrt(n)); i++)
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

int findKthLargest(vector<int> &nums, int k)
{
    map<int, int> mp;
    for (int i = (1e-4); i <= (1e4); i++)
    {
        mp[i] = 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int sum = 0;
    int ans;
    for (int i = (1e4); i >= (1e-4); i--)
    {
        sum += mp[i];
        if (sum >= k)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

bool check(char str[], int mid, int index, int len)
{
    map<char, int> mp1;
    map<char, int> mp2;
    for (int i = index; i < index + mid; i++)
    {
        mp1[str[i]]++;
    }
    for (int i = len - index - 1; i > (len - index - 1 - mid); i--)
    {
        if (i < index + mid)
        {
            break;
        }
        mp2[str[i]]++;
    }
    int flag = 0;
    for (const auto &pair : mp2)
    {
        if (pair.second > mp1[pair.first])
        {
            flag = 1;
            break;
        }
    }
    map<char, int> mp3;
    map<char, int> mp4;
    for (int i = index; i < index + mid; i++)
    {
        if (i > len - index - 1 - mid)
        {
            break;
        }
        mp3[str[i]]++;
    }
    for (int i = len - index - 1; i > (len - index - 1 - mid); i--)
    {
        mp4[str[i]]++;
    }
    int flag1 = 0;
    for (const auto &pair : mp3)
    {
        if (pair.second > mp4[pair.first])
        {
            flag1 = 1;
            break;
        }
    }

    if (flag && flag1)
    {
        return false;
    }

    int flag3 = 0;

    for (int i = index + mid; i <= (len - index - 1 - mid); i++)
    {
        if (str[i] != str[len - i - 1])
        {
            flag3 = 1;
        }
    }
    if (flag3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

class RotRevArr
{
    vector<int> arr;
    int offset;
    bool reversed;

public:
    RotRevArr(const vector<int> &input) : arr(input), offset(0), reversed(false) {}

    void rightRotateBy1()
    {
        offset = (offset - 1 + arr.size()) % arr.size();
    }

    void reverse()
    {
        reversed = !reversed;
        offset = (offset + 1) % arr.size();
    }

    int get(int i)
    {
        int idx;
        if (!reversed)
            idx = (offset + i) % arr.size();
        else
            idx = (offset - i + arr.size()) % arr.size();
        return arr[idx];
    }

    void printArray()
    {
        for (int i = 0; i < arr.size(); ++i)
            cout << get(i) << " ";
        cout << endl;
    }
};

class SmartDeque
{
    deque<int> dq;
    bool reversed;

public:
    SmartDeque(initializer_list<int> input) : dq(input), reversed(false) {}

    void rightRotateBy1()
    {
        if (!reversed)
        {
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
        }
        else
        {
            int first = dq.front();
            dq.pop_front();
            dq.push_back(first);
        }
    }

    void reverse()
    {
        reversed = !reversed;
    }

    void push_back(int val)
    {
        if (!reversed)
            dq.push_back(val); // logical end is physical back
        else
            dq.push_front(val); // logical end is physical front
    }

    int operator[](int i) const
    {
        if (i < 0 || i >= dq.size())
        {
            throw out_of_range("Index out of range");
        }

        if (!reversed)
            return dq[i];
        else
            return dq[dq.size() - 1 - i];
    }
    int size() const
    {
        return dq.size();
    }

    void printArray()
    {
        if (!reversed)
        {
            for (int x : dq)
                cout << x << " ";
        }
        else
        {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                cout << *it << " ";
        }
        cout << endl;
    }
};

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
bool solve(int mid, int arr[], int arr2[], int n, int m)
{
    int po1 = 0;
    int count = 0;
    int po2 = 0;
    int flag1 = 0;
    for (int i = 0; i < m; i++)
    {
        if (!flag1 && arr2[i] == mid)
        {
            flag1 = 1;
            continue;
        }
        int flag = 0;
        for (int j = po1; j < n - (m - 1 - i); j++)
        {
            if (arr[j] >= arr2[i])
            {
                po2 = j;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            count++;
        }
        else
        {
            po1 = po2 + 1;
        }
    }
    if (count > 1)
    {
        return false;
    }
    return true;
}

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

ll mincost(int arr[], int i, int n)
{
    if (i == 0)
    {
        return 0;
    }
    ll arr2[n];
    for (int j = 0; j < n; j++)
    {
        std:: swap(arr[n - i],arr[j]);
        if( n-i !=j && abs(n-i-j) + arr[n-i] > arr[j]){arr2[j] = 1e15;}
        else{arr2[j] = abs(n - i - j) + arr[n-i] + mincost(arr, i-1 , n);}
      //  if(debug){cout << arr2[j] << " " << i << endl;}
        std:: swap(arr[n - i],arr[j]);
    }
    ll min=arr2[0];
    for(int k=0;k<n;k++){
        if(min > arr2[k]){
            min=arr2[k];
        }
    }

    return min;
} 




const int MOD =  1000000007;
const int MAX = 1e6 ;
long long fact[MAX], invFact[MAX];

// Fast exponentiation for modular inverse
long long power(long long a, long long b, int mod) {
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
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2, MOD); // Fermat's little theorem
    for (int i = MAX - 2; i >= 0; i--)
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


ll calculate(ll index, ll res){
    ll sum=0;
    for(int i=0;i<=(res/2);i++){
        sum+=(nCr(index+i-1,i)%MOD)*(nCr(1+res-2*i,res-2*i)%MOD);
        sum%=MOD;
    }
    return (sum);
}

// int pre[n+1];
//         pre[0]=0;
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(arr[i]<=k){count++;}
//             pre[i+1]=count;
//         }

vector<vector<int>> findCycles(const vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        unordered_set<int> currentSet;
        vector<int> path;
        int current = i;

        // Follow the chain until we revisit a node
        while (!visited[current] && currentSet.find(current) == currentSet.end()) {
            currentSet.insert(current);
            path.push_back(current);
            current = arr[current];
        }

        // If we detect a cycle in the current path
        if (currentSet.find(current) != currentSet.end()) {
            vector<int> cycle;
            bool inCycle = false;
            for (int idx : path) {
                if (idx == current) inCycle = true;
                if (inCycle) cycle.push_back(idx);
                visited[idx] = true;
            }
            result.push_back(cycle);
        } else {
            // Mark all visited even if no cycle was found
            for (int idx : path) {
                visited[idx] = true;
            }
        }
    }

    return result;
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


ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

long long mod_inverse(long long a, long long m) {
    return power(a, m - 2, m);
}

int LIS(const vector<int>& a) {
    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

int juo(int x,int y){
    return (x%y + y%x);
}

int min_steps_to_g(vector<int>& a, int g) {
    const int MAX = 5000;
    vector<bool> visited(MAX + 1, false);
    vector<int> dist(MAX + 1, INT_MAX);
    queue<int> q;

    for (int x : a) {
        if (!visited[x]) {
            visited[x] = true;
            dist[x] = 0;
            q.push(x);
        }
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : a) {
            int z = __gcd(x, y);
            if (!visited[z]) {
                visited[z] = true;
                dist[z] = dist[x] + 1;
                q.push(z);
            }
        }
    }

    return dist[g] == INT_MAX ? -1 : dist[g];
}



bool dfs(int u, vector<vector<int>> &sets, unordered_map<int, int> &match, unordered_set<int> &visited) {
    for (int val : sets[u]) {
        if (visited.count(val)) continue;
        visited.insert(val);
        if (!match.count(val) || dfs(match[val], sets, match, visited)) {
            match[val] = u;
            return true;
        }
    }
    return false;
}

bool can_match(int k, const vector<vector<int>> &sets) {
    unordered_map<int, int> match; // number -> set index
    for (int i = 0; i < k; ++i) {
        unordered_set<int> visited;
        if (!dfs(i, const_cast<vector<vector<int>>&>(sets), match, visited)) {
            return false;
        }
    }
    return true;
}

int max_sets(vector<vector<int>> &sets) {
    int left = 0, right = sets.size(), ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
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
    for(int i=0;i<n-1;i++){
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

bool bfs_forcycle(int i , vector<int>& vis , vector<vector<int>>& v , vector<int>& par){
    vis[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int j=0;j<v[x].size();j++){
            if(!vis[v[x][j]]){vis[v[x][j]]=1;q.push(v[x][j]);par[v[x][j]]=x;}
            else{
                if(par[x]!=v[x][j]){return true;}
            }
        }
        
    }
    return false;
}
bool isCyclebfs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
        vector<int>vis(n,0);
        vector<int> par(n,-1);
        for(int i=0;i<n;i++){
        if(!vis[i]){ if(bfs_forcycle(i, vis , v , par)){return true;}}
    }
    return false;
    
}

bool dfs_forcycle(int i , vector<int>& vis , vector<vector<int>>& v , int par){
    vis[i]=1;
    for(int j=0;j<v[i].size();j++){

        if(!vis[v[i][j]]){  if(dfs_forcycle(v[i][j], vis , v , i)){return true;}}
    else{
        if(par!= v[i][j] ){return true;}
    }
    }
    return false;
}
bool isCycledfs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
        vector<int>vis(n,0);
    
        for(int i=0;i<n;i++){
        if(!vis[i]){ if(dfs_forcycle(i, vis , v , -1)){return true;}}
    }
    return false;
}

bool condition(ll a, ll b) {
    return a < b; // Change this to your desired condition
}
// Sieve of Eratosthenes to generate primes up to n
vector<int> get_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;

    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            primes.push_back(i);

    return primes;
}

void generate_good_permutation(int n) {
    vector<int> p(n + 1, 0);          // Result permutation (1-based)
    vector<bool> used(n + 1, false);  // To track which positions are filled
    vector<int> primes = get_primes(n);
    reverse(primes.begin(), primes.end()); // Start from largest prime

    for (int prime : primes) {
        vector<int> group;
        for (int i = prime; i <= n; i += prime) {
            if (!used[i])
                group.push_back(i);
        }

        if (group.size() > 1) {
            for (int i = 0; i < group.size(); ++i) {
                int from = group[i];
                int to = group[(i + 1) % group.size()];
                p[from] = to;
                used[from] = true;
            }
        }
    }

    // Fill any remaining positions (typically just 1)
    set<int> unused;
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            unused.insert(i);

    for (int i = 1; i <= n; ++i)
        if (p[i] == 0) {
            p[i] = *unused.begin();
            unused.erase(unused.begin());
        }

    // Output the permutation
    for (int i = 1; i <= n; ++i)
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
    for (int i = 0; i < 64; ++i) {
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

void bfs_for(int node ,vector<vector<ll>>& adj , map<ll,ll>& m , ll mino,ll maxo , vector<int>& vis , ll arr[]){
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
    for(int i=0;i<n-1;i++){
        cin >> p;
        adj[i+1].push_back(p-1);
        adj[p-1].push_back(i+1);
    }
    return adj;
}

vector<vector<ll>> levels(vector<vector<ll>>& adj){
   // int level=0;
    queue<ll> q;
    vector<vector<ll>> ans;
    q.push(0);
    vector<ll> vis(adj.size(),0);
    
    vector<ll> v;
    vis[0]=1;
    while(!q.empty()){
        int siz = q.size();
        v.clear();
        for(int i=0;i<siz;i++){
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

int editDistance(const string &A, const string &B) {
    int n = A.size();
    int m = B.size();

    // Only two rows needed for space optimization
    vector<int> prev(m+1, 0), curr(m+1, 0);

    // Base case: converting empty string to B[0..j]
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        curr[0] = i; // converting A[0..i] to empty string

        for(int j = 1; j <= m; j++){
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
int longestCommonSubsequence(const vector<T>& A, const vector<T>& B) {
    int n = A.size();
    int m = B.size();
    
    // DP table: only 2 rows needed for space optimization
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int i = 1; i <= n; i++) {
        curr[0] = 0; // LCS with empty array is 0
        for(int j = 1; j <= m; j++) {
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
int knapsack01(const vector<int> &weight, const vector<int> &value, int W) {
    int n = weight.size();
    vector<int> dp(W+1, 0); // space optimized

    for(int i = 0; i < n; i++) {
        // iterate from W to weight[i] to avoid reusing the same item
        for(int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

int unboundedKnapsack(const vector<int> &weight, const vector<int> &value, int W) {
    int n = weight.size();
    vector<int> dp(W+1, 0);

    for(int w = 0; w <= W; w++) {
        for(int i = 0; i < n; i++) {
            if(weight[i] <= w)
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

// Function to find LCS of 3 arrays
template <typename T>
int lcs3(const vector<T> &A, const vector<T> &B, const vector<T> &C) {
    int n = A.size();
    int m = B.size();
    int o = C.size();

    // 3D DP table
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(o+1, 0)));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= o; k++) {
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

