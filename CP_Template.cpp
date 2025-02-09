#include <bits/stdc++.h>

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 

//Aliases to op

using ll = long long;
using ull = unsigned long long;
using dl =  double;

//Constants
const ll MOD = 1e9 + 7; //Used for CP
const ll INF = 4e18;
const ld EPS = 1e-9; //(10^(-9))

//Macros
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define rall(x) begin(x), end(x)

typedef vector<int> vi;
typedef pair<int,int> pi;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define endl "\n"
#define rep(i,a,b) for(int i=a ; i<b ; i++)

const ll mod = 998244353; //Used for FFT , NTT

ll inv(ll i){if(i==1)return 1; return (mod - ((mod/i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
  
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 

ll perr(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD; 
        a = a * a % MOD;
        b >>= 1; 
    }
    return res;
}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

template <typename T> // cin >> vector<T>

istream &operator>>(istream &istream , vector<T> &v)
{
    for(auto &it : v)
        cin >> it;
    return istream;
}

template <Typename T> // cout << vector<T>

ostram &operator<<(ostream &ostream, const vector,T> &c)
{
    for(auto &it : c)
        cout << it << " ";
    return ostream;
}

// Mathematical functions
int GCD(int a , int b)
{
    while(b)
    {
        a = a % b;
        swap(a,b);
    }
    return a;
}

int GCD_extended(int a , int b , int &x , int &y)
{
    x = 1 , y = 0;
    int x1 = 0 , y1 = 1 , a1 = a , b1 = b;
    while(b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int LCM(int a , int b)
{
    return ((ll)a*b / GCD(a, b));
}

ll modpow(ll x , ll n , int n = MOD)
{
    if(x == 0 && n == 0)
        return 0;
    ll res = 1;
    while(n > 0)
    {
        if(n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modiv(int x , int m = MOD)
{
    return modpow(x , m - 2 , m);
}



ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }

ll factorial(ll n){
    if (n==0){
        return 1;
    }
    ll ans=1;
    for (ll i=1;i<=n;i++){
         ans=mod_mul(ans,i);
    }
    return ans;
}

ll lcm(ll a,ll b){
    ll g=__gcd(a,b);
    return (a*b/g);
}

long long int power(int base, int exp)
{
    if (exp == 0)
       return 1;
    else if (exp == 1)
       return base;
    else
    {
       long long int calc;
       if (exp % 2 == 0)
       {
         calc = power(base, exp/2);
         calc *= calc;
       }
       else
       {
         calc = base*power(base, exp-1);
       }
       return calc;
    }
}

class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        int diff=a.second-a.first;
        int diff2=b.second-b.first;
 
        if (diff == diff2) {
            return a.first>b.first;
        }
        
        
 
        return diff<diff2;
        }
};

bool get(ll a,ll b, ll x){
    if (a<b){
        swap(a,b);
    }
    if (x==a || x==b){
        return true;
    }
    if (a==0 || b==0){
        return false;
    }
    return get(a%b,b,x);
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r,vector<ll>&f) {
    if (n<r){
        return 0;
    }
    ll ans=f[n];
    // ans=mod_mul(ans,inv(f[r]));
    ans=mod_mul(ans,inv(f[n-r]));
    return ans;
}


ll mysqrt(ll n){
    ll ans=0;
    ll low=1;
    ll high=1e9;
    while(low<=high){
        ll md=(low+high)/2;
        if (md*md<=n){
            ans=md;
            low=md+1;
        }
        else{
            high=md-1;
        }
    }
    return ans;
}

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b)
{
    return a.second < b.second;
} 

bool check(ll i,ll n,ll k){
   ll x=i;
   ll par=x/2+1;
   ll st=1+(par-1)*(n/i);
   ll en=st+n/i-1;
   if (((en+st)/2)==k){
        return true;
    }
   return false;
}


void solve(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}