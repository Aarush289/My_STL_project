#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

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

void take(long long int arr[], int n)
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
    return result % (1000000007);
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
        std::swap(arr[n - i], arr[j]);
        if (n - i != j && abs(n - i - j) + arr[n - i] > arr[j])
        {
            arr2[j] = 1e15;
        }
        else
        {
            arr2[j] = abs(n - i - j) + arr[n - i] + mincost(arr, i - 1, n);
        }
        //  if(debug){cout << arr2[j] << " " << i << endl;}
        std::swap(arr[n - i], arr[j]);
    }
    ll min = arr2[0];
    for (int k = 0; k < n; k++)
    {
        if (min > arr2[k])
        {
            min = arr2[k];
        }
    }

    return min;
}

const int MOD = 998244353;
const int MAX = 1e6;
long long fact[MAX], invFact[MAX];

// Fast exponentiation for modular inverse
long long power(long long a, long long b, int mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2, MOD); // Fermat's little theorem
    for (int i = MAX - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

long long nCr(ll n, ll r)
{
    if (r == 0)
    {
        return 1;
    }
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

ll calculate(ll index, ll res)
{
    ll sum = 0;
    for (int i = 0; i <= (res / 2); i++)
    {
        sum += (nCr(index + i - 1, i) % MOD) * (nCr(1 + res - 2 * i, res - 2 * i) % MOD);
        sum %= MOD;
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

vector<vector<int>> findCycles(const vector<int> &arr)
{
    int n = arr.size();
    vector<bool> visited(n, false);
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
            continue;

        unordered_set<int> currentSet;
        vector<int> path;
        int current = i;

        // Follow the chain until we revisit a node
        while (!visited[current] && currentSet.find(current) == currentSet.end())
        {
            currentSet.insert(current);
            path.push_back(current);
            current = arr[current];
        }

        // If we detect a cycle in the current path
        if (currentSet.find(current) != currentSet.end())
        {
            vector<int> cycle;
            bool inCycle = false;
            for (int idx : path)
            {
                if (idx == current)
                    inCycle = true;
                if (inCycle)
                    cycle.push_back(idx);
                visited[idx] = true;
            }
            result.push_back(cycle);
        }
        else
        {
            // Mark all visited even if no cycle was found
            for (int idx : path)
            {
                visited[idx] = true;
            }
        }
    }

    return result;
}

template <typename T>
vector<T> prime_factors(T n)
{
    vector<T> factors;
    for (T i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

long long mod_inverse(long long a, long long m)
{
    return power(a, m - 2, m);
}

int LIS(const vector<int> &a)
{
    vector<int> dp;
    for (int x : a)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }
    return dp.size();
}

int juo(int x, int y)
{
    return (x % y + y % x);
}

int min_steps_to_g(vector<int> &a, int g)
{
    const int MAX = 5000;
    vector<bool> visited(MAX + 1, false);
    vector<int> dist(MAX + 1, INT_MAX);
    queue<int> q;

    for (int x : a)
    {
        if (!visited[x])
        {
            visited[x] = true;
            dist[x] = 0;
            q.push(x);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : a)
        {
            int z = __gcd(x, y);
            if (!visited[z])
            {
                visited[z] = true;
                dist[z] = dist[x] + 1;
                q.push(z);
            }
        }
    }

    return dist[g] == INT_MAX ? -1 : dist[g];
}

const ll MOD1 = 1e9 + 7; // remove MOD if you want full result

struct Matrix
{
    ll a, b, c, d; // [a b]
                   // [c d]

    Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}

    Matrix operator*(const Matrix &other) const
    {
        return Matrix(
            (a * other.a + b * other.c) % MOD1,
            (a * other.b + b * other.d) % MOD1,
            (c * other.a + d * other.c) % MOD1,
            (c * other.b + d * other.d) % MOD1);
    }
};

Matrix power(Matrix base, ll n)
{
    Matrix result(1, 0, 0, 1); // identity matrix
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = result * base;
        }
        result = result;
        base = base * base;
        n /= 2;
    }
    return result;
}

ll fibonacci(ll n)
{
    if (n == 0)
        return 0;
    Matrix F(1, 1, 1, 0);
    Matrix res = power(F, n - 1);
    return res.a;
}

ll sumcal(ll n)
{
    ll fn2 = fibonacci(n + 2) % MOD1;
    ll fn3 = fibonacci(n + 3) % MOD1;
    ll term1 = ((n % MOD1) * fn2) % MOD1;
    ll ans = (term1 - fn3 + 2 + MOD1) % MOD1;
    return ans;
}

vector<pair<long long, int>> prime_factors(long long n)
{
    vector<pair<long long, int>> factors;

    // Handle 2 separately
    int count = 0;
    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }
    if (count > 0)
        factors.push_back({2, count});

    // Handle odd numbers
    for (long long i = 3; i * i <= n; i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count > 0)
            factors.push_back({i, count});
    }

    // If n is still greater than 1, it's a prime number
    if (n > 1)
    {
        factors.push_back({n, 1});
    }

    return factors;
}

#define debug 0
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, int>> v1;
        vector<pair<ll, int>> v2;
        vector<pair<ll, int>> v3;
        map<ll, int> mp1;
        map<ll, int> mp2;
        v1 = prime_factors(n);
        v2 = prime_factors(m);
        for (int i = 0; i < v1.size(); i++)
        {
            mp1[v1[i].first] = v1[i].second;
        }
        for (int i = 0; i < v2.size(); i++)
        {
            mp2[v2[i].first] = v2[i].second;
        }

        for (int i = 0; i < v2.size(); i++)
        {
            v3.push_back({v2[i].first, (v2[i].second - mp1[v2[i].first])});
        }
        map<ll, int> mp3;
        for (int i = 0; i < v3.size(); i++)
        {

            mp3[v3[i].first] = v3[i].second;
        }
        int flag = 0;
        int count = 0;
        ll factor1 = 1;
        ll factor2 = 1;
        // ll factor3=1;
        //cout << mp1.count(3) <<endl;
        for (auto it : mp1)
        {
            if (it.second == mp2[it.first])
            {
                continue;
            }
            if (mp3[it.first] == 0)
            {
                if (k < it.first)
                {
                    flag = 1;
                    break;
                }
                ll m = factor1;
                int flag2 = 0;
                if (factor1 != 1)
                {
                    while (m <= k && it.second > 0)
                    {
                        m *= it.first;
                        it.second--;
                    }
                    if (m > k)
                    {
                        m /= it.first;
                        it.second++;
                    }
                    if (it.second == 0)
                    {
                        factor1 = m;
                        continue;
                    }
                }
                m = it.first;
                ll temp = it.second;
                ll power1 = 1;
                while (it.second > 0 && m <= k)
                {
                    m *= it.first;
                    power1++;
                    it.second--;
                }
                if (m > k)
                {
                    m /= it.first;
                    power1--;
                }
                if (temp % power1 == 0)
                {
                    factor1 = m;
                }
                else
                {
                    factor1 = power(it.first, temp % power1, MOD);
                }
                count += (temp / power1) + (temp % power1 > 0 ? 1 : 0);
                cout << count << "c" << factor1 << "f1 ";
            }
            else
            {
                if (mp3[it.first] > 0)
                {   
                    
                    if (k < it.first)
                    {
                        flag = 1;
                        break;
                    }
                   
                    ll m = factor2;
                    int flag2 = 0;
                    if (factor2 != 1)
                    {
                        while (m <= k && mp3[it.first] > 0)
                        {
                            m *= it.first;
                            mp3[it.first]--;
                        }
                        if (m > k)
                        {
                            m /= it.first;
                            mp3[it.first]++;
                        }
                        if (mp3[it.first] == 0)
                        {
                            factor2 = m;
                            continue;
                        }
                    }
                    m = it.first;
                    ll temp = mp3[it.first];
                    ll power1 = 1;
                    while ( mp3[it.first] > 0 && m <= k)
                    {
                        m *= it.first;
                        power1++;
                        mp3[it.first]--;
                    }
                    if (m > k)
                    {
                        m /= it.first;
                        power1--;
                    }
                    if (temp % power1 == 0)
                    {
                        factor2 = m;
                    }
                    else
                    {
                        factor2 = power(it.first, temp % power1, MOD);
                    }
                    count += (temp / power1) + (temp % power1 > 0 ? 1 : 0);
                    cout << count << "c" << factor2 << "f2 ";
                }
                else
                {
                    if (mp3[it.first] < 0)
                    {
                        if (k < it.first)
                        {
                            flag = 1;
                            break;
                        }

                        ll m = factor1;
                        int flag2 = 0;
                        if (factor1 != 1)
                        {
                            while (m <= k && mp3[it.first] < 0)
                            {
                                m *= it.first;
                                mp3[it.first]++;
                            }
                            if (m > k)
                            {
                                m /= it.first;
                                mp3[it.first]--;
                            }
                            if (mp3[it.first] == 0)
                            {
                                factor1 = m;
                                continue;
                            }
                        }
                        m = it.first;
                        ll temp = -mp3[it.first];
                        ll power1 = 1;
                        while (temp > 0 && m <= k)
                        {
                            m *= it.first;
                            power1++;
                            temp--;
                        }
                        temp = -mp3[it.first];
                        if (m > k)
                        {
                            m /= it.first;
                            power1--;
                        }
                        if (temp % power1 == 0)
                        {
                            factor1 = m;
                        }
                        else
                        {
                            factor1 = power(it.first, temp % power1, MOD);
                        }
                        count += (temp / power1) + (temp % power1 > 0 ? 1 : 0);
                        cout << count << "c" << factor1 << "f1 ";
                    }
                }
            }

            // cout << count << endl;
        }
        // for(auto it: mp3){
        //     if(!mp1.count(it.first)){
        //         if(k < it.first){
        //             flag=1;
        //             break;
        //         }
        //         ll m=it.first;
        //         ll temp = it.second;
        //         while(it.second >0 && m <= k){
        //             m *= it.first;
        //             it.second--;
        //         }
        //         if( m> k){m/= it.first;}
        //         count +=  (temp/m) + (temp%m > 0 ? 1 : 0);
        //     }
        // }

        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << count << endl;
        }
    }
}