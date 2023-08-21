vector<int>dp(n);
  vector<int>dp2(n),c(n);
  function<void(int,int)>f=[&](int node,int par){
    dp[node]=dp2[node]=0;
    for(auto child:graph[node]){
      if(child==par)continue;
      f(child,node);
      if(dp[child]+1>dp[node]){
        dp2[node]=dp[node];
        dp[node]=dp[child]+1;
        c[node]=child;
      }else if(dp[child]+1>dp2[node]){
        dp2[node]=dp[child]+1;
      }
    }
  };
  f(0,-1);
  vector<int>ans(n,0);
  function<void(int,int)>dfs=[&](int node,int par){
    for(auto child:graph[node]){
      if(child==par)continue;
      if(c[node]==child){
        if(dp2[node]+1>dp[child]){
          dp2[child]=dp[child];
          dp[child]=dp2[node]+1;
          c[child]=node;
        }else{
          dp2[child]=max(dp2[child],dp2[node]+1);
        }
      }else{
        dp2[child]=dp[child];
        dp[child]=dp[node]+1;
        c[child]=node;
      }
      dfs(child,node);
    }
  };
  dfs(0,-1);