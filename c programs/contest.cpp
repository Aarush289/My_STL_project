#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <initializer_list>
#include <climits>
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

map<int,int>mp;


int main()
{
    int cases;
    cin >> cases;
    while(case--){

    }
}
