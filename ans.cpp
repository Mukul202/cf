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


//iterative
template<class T>
struct Seg {
	const T ID = 0;

	T comb(T a, T b) { return a+b; }

	int n;
	vector<T> seg;

	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

inline void solve()
{
  int n;
  in(n);
  vector<int>a(n);
  in(a);
  struct node[
    int val=0;
    vector<struct node*>next(2,nullptr);
    node(){}
  ];
  struct node* head;
  auto insert=[&](int mask){
    struct node* temp=head;
    for(int i=0;i<8;++i){
      int bit=(mask>>i&1);
      if(temp->next[bit]==nullptr)temp->next[bit]=new node();
      temp=temp->next[bit];
    }
    temp->val=mask;
  };
  auto search=[&](int mask){
    auto temp=head;
    for(int i=0;i<8;++i){
      int bit=(mask>>i&1);
      if(temp->next[bit^1])temp=temp->next[bit^1];
      else temp=temp->next[bit];
    }
    return temp->val^mask;
  };
  int ans=0;
  for(auto el:a){
    insert(el);
    ans=max(ans,search(el));
  }
  out(ans);
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
  cin >> t;
  fr(j, t)
  {
    // cout<<"Case #"<<j+1<<": ";
    solve();
  }

  printclock;
  return 0;
}
