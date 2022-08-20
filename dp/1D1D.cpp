void f(vector<int>&a){
  dp[0] = 0;
  vector<pair<int, int> > v; // (start pos, best k)
  v.push_back(make_pair(0, 0));
  for (int x = 1; x <= n; x++) {
    int k = (--lower_bound(v.begin(), v.end(), make_pair(x + 1, 0)))->second;
    dp[x] = dp[k] + w(k, x);
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      int y = v[i].first, oldk = v[i].second;
      if (y > x && dp[x] + w(x, y) < dp[oldk] + w(oldk, y)) v.pop_back();
      else {
        int l = y + 1, r = n + 1;
        while (l < r) {
          int mid = (l + r) / 2;
          if (dp[x] + w(x, mid) < dp[oldk] + w(oldk, mid)) r = mid;
          else l = mid + 1;
        }
        if (r != n + 1) v.push_back(make_pair(r, x));
        break;
      }
    }
    if (v.size() == 0) v.push_back(make_pair(0, x));
  }
  cout << dp[n] << '\n';
}