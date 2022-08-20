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

inline void solve()
{
  int n;
  in(n);
  struct edge{
    int to,a,b;
    edge(int to,int a,int b){
      this->to=to;
      this->a=a;
      this->b=b;
    }
  };
  vector<vector<edge>>graph(n+1);
  map<pii,pii>m;
  for(int j=2;j<=n;++j){
    int p,a,b;
    in(p,a,b);
    // --p;
    graph[p].pb(edge(j,a,b));
    m[{p,j}]={a,b};
  }
  vector<pii>ans(n+1);
  deque<int>v;
  function<void(int,int)>f=[&](int node,int par){
    //1 means par was included
    //ans[par].ff stores the diff Ea-Eb

    auto [a,b]=m[{par,node}];

    v.pb((v.empty()?b:v.back()+b));

    // deb(par,a,b,node,v[node]);

    //find the required len 
    int req=ans[par].first+a;

    auto it=upper_bound(all(v),req);

    if(it==v.begin()){
      ans[node]=pair{req,0LL};
    }else{
      ans[node]=pair{req,it-v.begin()};
    }

    for(auto [child,a,b]:graph[node]){
      f(child,node);
    }
    v.pop_back();
  };
  ans[0]=pair{0,0};
  // v[1]=vector<int>();
  for(auto [child,a,b]:graph[1]){
    // deb(child,a,b);
    f(child,1);
  }
  for(int i=2;i<=n;++i){
    cout<<ans[i].second<<" ";
  }
  out("");
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
#ifndef ONLINE_JUDGE
  FILE;
#endif


  int t = 1;
  cin >> t;
  fr(j, t)
  {
    // cout<<"Case #"<<j+1<<":  ";
    solve();
  }

  printclock;
  return 0;
}
