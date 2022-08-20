const int MAXN=1e5;
int cnt[MAXN];
bool big[MAXN];

void add(int node,int par,int val){
  cnt[col[node]]+=x;
  for(auto child:graph[node]){
    if(child!=par && !big[child])
      add(child,node,val);
  }
}

void dfs(int node,int par,bool keep){
  int mx=-1,bigChild=-1;
  
  for(auto child:graph[node]){
    if()
  }
}
