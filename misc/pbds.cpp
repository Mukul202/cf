#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;


//in order to use this comment out #define int long long line
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds; 

template <typename num_t>
using PBDS = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

//for unordered_map
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class K,class V> using ht = gp_hash_table<
    K,
    V,
    hash<K>,//change it to custom_hash in case of integers
    equal_to<K>,
    direct_mask_range_hashing<>,
    linear_probe_fn<>,
    hash_standard_resize_policy<
      hash_exponential_size_policy<>,
      hash_load_check_resize_trigger<>,
      true 
    >
>;
//for unordered_set -> ht<int,null_type>

#define printclock cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC << "ms\n";

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
      ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    long long ans = 0;
    PBDS<int> s1;
    for(int i=1;i<=n;++i){
      pair<int,int>val={a[i],n-i+1};
      ans+=s1.order_of_key(val);
      s1.insert({a[i],n-i+1});
    }
    // out("hi");
    cout<<ans<<"\n";
  }
  printclock;
  return 0;
}