vector<int>top_sort(int n){
  min_pq<int>q;
  vector<int>indeg(n,0LL);
  for(int i=1;i<=n;++i){
    for(auto nbr:graph[i]){
      ++indeg[nbr];
    }
  }
  for(int i=1;i<=n;++i){
    if(indeg[i]==0){
      q.push(i);
    }
  }
  vector<int>ans;
  while(!q.empty()){
    auto node=q.top();
    q.pop();
    ans.emplace_back(node);
    for(auto nbr:graph[node]){
      --indeg[nbr];
      if(!indeg[nbr]){
        q.push(nbr);
      }
    }
  }
  if(ans.size()!=n){
    //no topsort
    return {};
  }
  return ans;
}