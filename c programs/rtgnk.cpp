#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll,ll>
#define ll long long 
#define ld long double
#define mp map<ll,ll>
#define pu push_back
#define vdll vector<vec>
#define vecp vector<pair<ll,ll> >
#define vect vector<tuple<ll,ll,ll> >
#define vec vector<ll>
#define vs vector<string>
#define gridinp(g,n,m) for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>g[i][j];
#define loop(i,n) for(ll i=0;i<n;i++)
#define all(it) it.begin(),it.end()
#define eb emplace_back
#define vinp(v11,n) vec v11(n,0);for(auto &it : v11) cin >> it;
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define po priority_queue<ll>
#define pq_ priority_queue<ll,vec,greater<ll> >
#define msll multiset<ll>
#define setr set<ll, greater<ll> >
#define qll queue<ll>
#define lo(v11,t) lower_bound(all(v11),t)-v11.begin()
#define hi(v11,t) upper_bound(all(v11),t)-v11.begin()
#define findit(t,v11) find(all(v11),t)==v11.end()
#define findmp(t,mp) mp.find(t)==mp.end()
#define pvec(v11) for(auto &it : v11){ cout<<it<<" ";} cout<<endl;
#define one(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define ff f1
#define takein(x,a) for(ll i=0;i<a;i++) cin>>x[i];
#define ss s
#define i(n) ll n;cin >> n;
#define rall(v11) v11.rbegin(), v11.rend()
#define sumv(v11) accumulate(all(v11),0LL)
#define pqp2 priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compPair)> 
const ll MOD2=1000000007;
const ll MOD1=998244353;
const ll MAX=1000005;
// ll fact[MAX];
// ll invfact[MAX];
ll binexp(ll a, ll b, ll m) {
    ll res=1;
    while(b >0) {
        if(b & 1)
            res=(res * a)%m;
        a=(a * a)%m;
        b >>= 1;
    }
    return res;
}
// ll binexp_no_mod(ll a, ll b) {
//     ll res=1;
//     while(b >0) {
//         if(b & 1)
//             res=res * a;
//         a=a * a;
//         b >>= 1;
//     }
//     return res;
// }
ll invmod(ll a, ll m) {
    return binexp(a, m-2, m);
}
// void pcmp() {
//     fact[0]=1;
//     for(ll i= 1;i<MAX;i++)
//         fact[i]=(fact[i-1] * i)%MOD1;
//     invfact[MAX-1]=invmod(fact[MAX-1], MOD1);
//     for(ll i= MAX-1;i >0;i--)
//         invfact[i-1]=(invfact[i] * i)%MOD1;
// }
// ll ncr(ll n, ll r) {
//     if(r<0 || r > n) return 0;
//     ll num=fact[n];
//     ll den=(fact[r] * fact[n-r])%MOD1;
//     return (num * invmod(den, MOD1))%MOD1;
// }
// // ll fastncr(ll n, ll r, ll m=MOD1) {
// //     if(r<0 || r > n) return 0;
// //     ll res=1;
// //     for(ll i= 1;i <= r;i++) {
// //         res=res * (n-r+i)%MOD1;
// //         res=res * invmod(i, MOD1)%MOD1;
// //     }
// //     return res;
// // }
// ll gcd(ll a, ll b) {
//     while(b) {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
// // ll lcm(ll a, ll b) {
// //     return a / tmp(a, b) * b;
// // }
// // ll gcdm(ll a, ll b, ll &it, ll &i) {
// //     if(b ==0) {
// //         it=1;
// //         i=0;
// //         return a;
// //     }
// //     ll d=gcdm(b, a%b, i, it);
// //     i -= (a / b) * it;
// //     return d;
// // }
// // vec spf(MAX);
// // void spf_sieve() {
// //     for(ll i= 1;i<MAX;i++) spf[i]=i;
// //     for(ll i= 2;i * i<MAX;i++) {
// //         if(spf[i] == i) {
// //             for(ll j=i * i;j<MAX;j += i) {
// //                 if(spf[j] == j)
//                     spf[j]=i;
//             }
//         }
//     }
// }
// vec facprime(ll it) {
//     vec factors;
//     while(it != 1) {
//         factors.push_back(spf[it]);
//         it /= spf[it];
//     }
//     return factors;
// }
// ll phi(ll n) {
//     ll result=n;
//     while(n > 1) {
//         ll p=spf[n];
//         while(n%p ==0)
//             n /= p;
//         result -= result / p;
//     }
//     return result;
// }
// vec divisors(ll it) {
//     vec divs;
//     for(ll i= 1;i*i <= it;i++) {
//         if(it%i ==0) {
//             divs.push_back(i);
//             if(i != it/i)
//                 divs.push_back(it/i);
//         }
//     }
//     sort(all(divs));
//     return divs;
// }
// vector<bool> sieve(ll n) {
//     vector<bool> isp(n+1, true);
//     if(n >=0) isp[0]=false;
//     if(n >= 1) isp[1]=false;
//     for(ll i= 2;i*i <= n;i++) {
//         if(isp[i]) {
//             for(ll j=i*i;j <= n;j += i)
//                 isp[j]=false;
//         }
//     }
//     return isp;
// }
 
// for bfs the code is 
// qll q1;
// bool visited[n];
// ll distance[n];
// ll node;
// visited[node]=true;
// distnace[node]=0;
// q1.push(node);
// while(!q1.empty()){
//     ll m=q1.top();
//     q1.pop();
//     for(auto it:adj[m]){
//         if(visited[it]) continue;
//         visited[it]=true;
//         distance[it]=distance[m]+1;
//         q1.push(it);
//     }
// }
// ll calc(ll d,ll n,ll b){
//     if((d-b)>0){
//         return d-b;
//     }
//     else {
//         return d-b+n;
//     }
// }
// ll gibqry(ll l,ll r,ll n,ll m){
//     if(m){
//         ll w=n-l;
//         l=n-r;
//         r=w;
//     }
//     ll g;
//     cout<< "? "<<l+1<<" "<<r<<flush<<endl;
//     cin>>g;
//     return g;
// }
// vec ans(2e5+10,0),ans1(2e5+10,0);
// vector<vector<pair<ll,ll> > > v1(2e5+10,vector<pair<ll,ll> >);
// void dfs(ll u,ll d,vector<vector<ll> >&v2,vector<ll>&max_i,vector<ll>&min_i,vector<ll>&v1){
//     for(auto it:v2[u]){
//         if(it==d){
//             continue;
//         }
//         else {
//             max_i[it]=max(v1[it],v1[it]-min_i[u]);
//             min_i[it]=min(v1[it],v1[it]-max_i[u]);
//             dfs(it,u,v2,max_i,min_i,v1);
//         }
//     }
// }
// struct edge{
//     ll dist;
//     ll node;
//     ll depot;
//     bool operator>(const edge& other) const {
//         return dist>other.dist;
//     }
// };
// struct tmp{
//     vec p;
//     tmp(ll n) : p(n) {
//         iota(all(p), 0);
//     }
//     ll find(ll it){
//         if(p[it]!=it){
//             p[it]=find(p[it]);
//         }
//         return p[it];
//     }
//     void merge(ll it,ll i){
//         ll m =find(it);
//         ll k =find(i);
//         if(m!=k){
//             p[m]=k;
//         }
//     }
// };
// ll gibans(ll n){
//     ll ans=0;
//     for(ll i = 2;i*i <= n; i++){
//         ll c=0;
//         while(n%i ==0){
//             n/=i;
//             c++;
//         }
//         ans^=c;
//     }
//     if(n>1) {
//         ans^=1;
//     }
//     return ans;
// }
// pair<ll,ll> gibfib(ll n){
//     if(n==0 ){
//         return {0,1};
//     }
//     pair<ll,ll> p;
//     p=gibfib( n >> 1);
//     ll it=(p.f1*(((2*p.s )%MOD2-p.f1+MOD2 )%MOD2))%MOD2;
//     ll i=(p.f1*p.f1%MOD2+p.s*p.s%MOD2)%MOD2;
//     if(n&1){
//         return {i,(it+i)%MOD2};
//     }
//     else {
//         return {it,i};
//     }
// }
void dfs(ll u,ll m,vector<vector<ll>> &adj,ll chck,vec &vis,ll hck2){
    vis[u]=1;
    for(auto it:adj[u]){
        if(vis[it]==0){
            if(it==chck){
                cout<<u<<" "<<it<<endl;
                dfs(it,1,adj,chck,vis,hck2);
                continue;
            }
            if(it==hck2){
                cout<<it<<" "<<u<<endl;
                dfs(it,0,adj,chck,vis,hck2);
                continue;
            }
            if(m==0){
                cout<<u<<" "<<it<<endl;
                dfs(it,1-m,adj,chck,vis,hck2);
            }
            else {
                cout<<it<<" "<<u<<endl;
                dfs(it,1-m,adj,chck,vis,hck2);
            }
        }
    }
}
void solve(){ 
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    vec deg(n+1,0);
    ll root,chck;
    vec a1(n),b1(n);
    for(ll y=0;y<n-1;y++){
        cin>>a1[y]>>b1[y];
        adj[a1[y]].pu(b1[y]);
        adj[b1[y]].pu(a1[y]);
        deg[a1[y]]++;
        deg[b1[y]]++;
    }
    ll c=0;
    for(ll y=1;y<=n;y++){
        if(deg[y]==1){
            c++;
        }
    }
    if(n==3){
        cout<<"YES"<<endl;
        if(deg[1]==2){
            cout<<2<<" "<<1<<endl;
            cout<<1<<" "<<3<<endl;
        }
        else if(deg[2]==2){
            cout<<2<<" "<<1<<endl;
            cout<<3<<" "<<2<<endl;
        }
        else {
            cout<<1<<" "<<3<<endl;
            cout<<3<<" "<<2<<endl;
        }
        return ;
    }
    if(n==1 || n==2){
        cout<<"NO"<<endl;
        return ;
    }
    if(c>=n-1){
        cout<<"NO"<<endl;
    }
    else {
        ll root=0;
        for(ll y=1;y<=n;y++){
            if(deg[y]==2){
                root = y;
            }
        }
        if(root==0){
            cout<<"NO"<<endl;
            return ;
        }
        ll chck=adj[root][0];
        ll chck2=adj[root][1];
        cout<<"YES"<<endl;
        vec vis(n+1,0);
        dfs(root,0,adj,chck,vis,chck2);
    }


}
signed main(){
    FAST;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}