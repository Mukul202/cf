#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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

template <typename T>
using min_pq = priority_queue<T, std::vector<T>, greater<T>>;
#define pii pair<int, int>

template <class T, class F>
istream &operator>>(istream &is, pair<T, F> &p)
{
  is >> p.ff >> p.ss;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
  for (auto &it : v)
    is >> it;
  return is;
}
template <typename... Args>
void in(Args &...args)
{
  ((cin >> args), ...);
}

template <class T, class U>
ostream &operator<<(ostream &os, pair<T, U> &p)
{
  os << p.ff << " " << p.ss;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &x)
{
  for (auto &el : x)
    os << el << " ";
  return os;
}
template <typename... Args>
void out(Args... args)
{
  ((cout << args << " "), ...);
  cout << "\n";
}
// template<typename T>void out(T& x){for(auto&el :x)cout<<el<<" ";cout<<"\n";}
template <typename T, typename... Args>
std::string debug_detail(const char *names, T &&var, Args &&...args)
{
  std::stringstream builder;
  const char *end = names;
  while (*end != ',' && *end != '\0')
    ++end;
  (builder).write(names, end - names) << '=' << var;
  if constexpr (sizeof...(Args) > 0)
  {
    (builder << ", ") << debug_detail(end + 1, std::forward<Args>(args)...);
  }
  return builder.str();
}
template <typename... Args>
void debug_entry(const char *names, Args &&...args)
{
  std::stringstream retval;
  retval << "[" << debug_detail(names, std::forward<Args>(args)...) << "]\n";
  std::cout << retval.str();
}
#define deb(...) debug_entry(#__VA_ARGS__, __VA_ARGS__)

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

inline void solve()
{
  int n;
  string s;
  in(n,s);
  vector<int>p=prefix_function(s);
  vector<int>dp(n+1);
  dp[0]=0,dp[1]=p[1];
  for(int i=2;i<n;++i){
    if(!p[i] || p[i]==1){
      dp[i]=p[i];
      continue;
    }
    dp[i]=(!dp[p[i]-1]?p[i]:dp[p[i]-1]);
  }
  int ans=0;
  for(int i=1;i<n;++i){
    if(!dp[i])continue;
    ans+=(i+1LL-dp[i]);
  }
  out(ans);
}

inline void solve2()
{
  string s,t;
  in(s,t);
  int n=(int)s.length();
  int m=(int)t.length();
  vector<int>p=prefix_function(t+'#'+s);
  int cnt=0;
  for(int i=m;i<=n+m;++i)if(p[i]==m)cnt++;
  out(cnt);
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
    solve2();
  }

  printclock;
  return 0;
}
