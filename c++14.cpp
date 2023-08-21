 
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
#define FILE                        \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout)
#define pb emplace_back // push_back
#define fio                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define ps(x, y) fixed << setprecision(y) << x
const int mod = 1000000007;
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int inf=1e9;

const int N = 1e5 + 5;
#define mod2 998244353

using namespace std;

const int MOD=mod;
struct mint {
  int value;
  static const int MOD_value = MOD;
 
  mint(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  mint(long long a, long long b) : value(0){ *this += a; *this /= b;}
 
  mint& operator+=(mint const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  mint& operator-=(mint const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  mint& operator*=(mint const& b) {value = (long long)value * b.value % MOD;return *this;}
 
  friend mint power(mint a, long long e) {
    mint res = 1; while (e) { if (e&1LL) res *= a; a *= a; e >>= 1LL; }
    return res;
  }
  friend mint inverse(mint a) { return power(a, MOD - 2); }
 
  mint& operator/=(mint const& b) { return *this *= inverse(b); }
  friend mint operator+(mint a, mint const b) { return a += b; }
  friend mint operator-(mint a, mint const b) { return a -= b; }
  friend mint operator-(mint const a) { return 0 - a; }
  friend mint operator*(mint a, mint const b) { return a *= b; }
  friend mint operator/(mint a, mint const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.value;}
  friend std::istream& operator>>(std::istream& is,mint& a){is>>a.value;a.value%=MOD;if(a.value<0)a.value+=MOD;return is;}
  friend bool operator==(mint const& a, mint const& b) {return a.value == b.value;}
  friend bool operator!=(mint const& a, mint const& b) {return a.value != b.value;}
  friend bool operator<(mint const&a,mint const&b){return a.value<b.value;}
  friend bool operator>(mint const& a,mint const& b){return a.value>b.value;}
  friend mint max(mint const& a,mint const& b){return a>b?a:b;}
  friend mint min(mint const& a,mint const& b){return a<b?a:b;}
};

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};


//for unordered_map
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class K,class V> using ht = gp_hash_table<
    K,
    V,
    custom_hash,//change it to custom_hash in case of integers
    equal_to<K>,
    direct_mask_range_hashing<>,
    linear_probe_fn<>,
    hash_standard_resize_policy<
      hash_exponential_size_policy<>,
      hash_load_check_resize_trigger<>,
      true 
    >
>;


int get(const string&s){
  int ans=0;
  int n=(int)s.length();
  vector<vector<pii>>dp(n,vector<pii>(2,make_pair(-1LL,-1LL)));
  
  function<pii(int,int)>f=[&](int i,int bound){
    if(i>=n)return make_pair(0LL,1LL);
    if(dp[i][bound].first!=-1LL)return dp[i][bound];
    int ans=0;
    int max_digit=(bound?s[i]-'0':9);
    int times=0;
    for(int j=0;j<=max_digit;++j){
      pair<int,int> p=f(i+1,(bound&&j==max_digit));
      times+=p.second;
      ans+=p.first;
      ans+=p.second*j;
    }
    return dp[i][bound]={ans,times};
  };
  
  return f(0,1).first;
}
  
inline void solve()
{
  int n,x;
  cin>>n>>x;
  vector<int>a(n);
  for(auto &it:a)cin>>it; 
  vector<mint>dp(x+1,0);
  dp[0]=1;
  for(int i=0;i<n;++i){
    for(int j=a[i];j<=x;++j)dp[j]+=dp[j-a[i]];
  }
  out(dp[x]);
}

inline void solve2()
{
  
}

inline void solve3()
{
  
}

int32_t main()
{
  fio;
// #ifndef ONLINE_JUDGE
//   FILE;
// #endif


  int t = 1;
  // cin >> t;
  fr(j, t)
  {
    // cout<<"Case #"<<j+1<<":  ";
    solve();
  }

  printclock;
  return 0;
}
