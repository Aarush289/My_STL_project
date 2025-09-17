#include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    // #include <ext/pb_ds/assoc_container.hpp> 
    // #include <ext/pb_ds/tree_policy.hpp> 
    // using namespace __gnu_pbds; 
    // #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
    #define MOD 1000000007 
    #define pu push_back
    #define fi find_by_order
    typedef map<ll,ll> mp;
    typedef vector<ll> vec;
    typedef vector<pair<ll,ll> > vecp;
    typedef map<ll ,pair<ll,ll> >mpp;
    typedef map<ll , vector<ll > > mpv;
    #define all(v) v.begin(),v.end()
 
        unsigned long long power(unsigned long long x, unsigned long long int y, unsigned long long int p)
    {
        unsigned long long res = 1; // Initialize result
    
        x = x % p; // Update x if it is more than or
        // equal to p
    
        while (y > 0) {
    
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res * x) % p;
    
            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }
    
    // Returns n^(-1) mod p
    unsigned long long modInverse(unsigned long long n, unsigned long long  p)
    {
        return power(n, p - 2, p);
    }
    unsigned long long mul(unsigned long long x,
                        unsigned long long y, unsigned long long p)
    {
        return x * 1ull * y % p;
    }
    unsigned long long divide(unsigned long long x,
                            unsigned long long y, unsigned long long  p)
    {
        return mul(x, modInverse(y, p), p);
    }
    // Returns nCr % p using Fermat's little
    // theorem.
    unsigned long long nCrModPFermat(unsigned long long n,
                                    unsigned long long int r, unsigned long long p)
    {
        // If n<r, then nCr should return 0
        if (n < r)
            return 0;
        // Base case
        if (r == 0)
            return 1;
        // if n-r is less calculate nCn-r
        if (n - r < r)
            return nCrModPFermat(n, n - r, p);
    
        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r
        unsigned long long res = 1;
        // keep multiplying numerator terms and dividing denominator terms in res
        for (long  int i = r; i >= 1; i--)
            res = divide(mul(res, n - i + 1, p), i, p);
        return res;
    }
    // ll ans(string s,ll n){
    //     vec v1(26,0),v2(26,0);
    //     ll min1=0,min2=0;
    //     for(ll y=0;y<n;y++){
    //         if(y%2){    
    //             v1[s[y]-'a']++;
    //             min1=max(min1,v1[s[y]-'a']);
    //         }
    //         else {
    //             v2[s[y]-'a']++;
    //             min2=max(min2,v2[s[y]-'a']);
    //         }
    //     }
    //     return n-min1-min2;
    // }
    string decToBinary(ll n) {
        string bin = "";
        
        while (n > 0) {
            ll bit = n%2;
              bin.push_back('0' + bit);
            n /= 2;
        }
      
        // reverse(bin.begin(), bin.end());
        return bin;
    }
    ll binexp(ll a,ll b){
        ll ans=1;
        while(b){
            if(b%2){
                ans*=a;
            }
            a*=a;
            b/=2;
        }
        return ans;
    }
    void solve (){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        reverse(all(s));
        ll a=power(2,n-1,MOD);
        ll b=(a*(n-2))%MOD;
        ll sum=0;
        for(ll y=0;y<n;y++){
            if(s[y]=='1'){
                sum+=power(2,y,MOD);
                sum%=MOD;
            }
        }
        sum+=b;
        ll j=modInverse(a,MOD);
        sum=((sum*j))%MOD;
        cout<<sum<<endl;
    }
    
        int main (){
        
        ll t;
        cin>>t;
        while(t--){
            solve();
        }
    }
