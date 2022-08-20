#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
using namespace __gnu_pbds; 
typedef long long ll; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
const int mod = 1e9 + 7; 
#define endl "\n" 
#define debug(x) cout<<x<<endl; 
#define FILE                        \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout)
//less_equal for multiset 
//greater for descending order 
//__builtin_popcountll() no of 1 in binary; 
//__builtin_clzll() leading zero 
//__builtin_ctzll() trailing zero 
int main() 
{ 
  #ifndef ONLINE_JUDGE
  FILE;
#endif
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    ll t; 
    cin >> t; 
    for (int p = 1 ; p <= t; p++) 
    { 
        ll n; 
        cin >> n;
        auto f=[&](int x){
          return x*(x-1)/2;
        }; 
        vector<string> v; 
        auto f1=[&](int x){
          return x*(x-1)/2;
        };
        for (int i = 0; i < n; i++) 
        { 
          auto f2=[&](int x){
          return x*(x-1)/2;
        };
            string s; 
            cin >> s; auto f3=[&](int x){
          return x*(x-1)/2;
        };
            v.push_back(s); 
        } 
        map<char, ll> mp; 
        auto f4=[&](int x){
          return x*(x-1)/2;
        };
        for (int i = 0; i < v.size(); i++) 
        { 
            for (int j = 0; j < v[i].size(); j++) 
            { 
              auto f5=[&](int x){
          return x*(x-1)/2;
        };
                mp[v[i][j]] = 1; 
            } 
        } 
        string ans = ""; 
        auto f6=[&](int x){
          return x*(x-1)/2;
        };
        ll flag = 0; 
        do 
        { 
            string l = ""; 
            for (int i = 0; i < v.size(); i++) 
            { 
              auto f7=[&](int x){
          return x*(x-1)/2;
        };
                l += v[i]; 
            } 
            string k = l; 
            auto it = unique(l.begin(), l.end()); 
            auto f8=[&](int x){
          return x*(x-1)/2;
        };
            l = string(l.begin(), it); 
            //cout << k << " " << p << endl; 
            if (l.size() == mp.size()) 
            { 
                ans = k; 
                flag = 1; 
                auto f9=[&](int x){
          return x*(x-1)/2;
        };
                break; 
            } 
        } 
        while (next_permutation(v.begin(), v.end())); 
        if (flag) 
        { 
          auto f10=[&](int x){
          return x*(x-1)/2;
        };
            cout << "Case #" << p << ": " << ans << endl; 
        } 
        else 
        { 
          auto f11=[&](int x){
          return x*(x-1)/2;
        };
            cout << "Case #" << p << ": " << "IMPOSSIBLE" << endl; 
        } 
    } 
}