vector<int>graph[N];
int a[N];
int sub[N],p[N],dep[N];
int tp[N],tin[N],st[4*N];
int cur=0;
int n;

void update(int pos,int val){
  st[pos+=n]=val;
  for(pos/=2;pos;pos/=2)st[pos]=max(st[pos<<1],st[pos<<1|1]);
}
int query(int lo,int hi){
  int ra=0,rb=0;
  for(lo+=n,hi+=n+1;lo<hi;lo/=2,hi/=2){
    if(lo&1)ra=max(ra,st[lo++]);
    if(hi&1)rb=max(rb,st[--hi]);
  }
  return max(ra,rb);
}
void dfs_sz(int node,int par,int depth){
  sub[node]=1;
  dep[node]=depth;
  for(auto child:graph[node]){
    if(child==par)continue;
    dfs_sz(child,node,depth+1);
    sub[node]+=sub[child];
    p[child]=node;
  }
}

void dfs_hld(int node,int par,int top){
  pii best={-1,-1};
  tin[node]=cur++;
  tp[node]=top;
  update(tin[node],a[node]);
  for(auto child:graph[node]){
    if(child!=par){
      best=max(best,{sub[child],child});
    }
  }
  if(best.second==-1)return ;
  dfs_hld(best.second, node,top);
  for(auto child:graph[node]){
    if(child!=par && child!=best.second){
      dfs_hld(child,node,child);
    }
  }
}

int path(int x,int y){
  int ret=0;
  while(tp[x]!=tp[y]){
    if(dep[tp[x]]<dep[tp[y]])swap(x,y);
    ret=max(ret,query(tin[tp[x]],tin[x]));
    x=p[tp[x]];
  }
  if(dep[x]>dep[y])swap(x,y);
  ret=max(ret,query(tin[x],tin[y]));
  return ret;
}


template <class T, int V>
class HeavyLight {
  int parent[V], heavy[V], depth[V];
  int root[V], treePos[V];
  SegmentTree<T> tree;

  template <class G>
  int dfs(const G& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      depth[u] = depth[v] + 1;
      int subtree = dfs(graph, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }

  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(treePos[u], treePos[v] + 1);
  }

public:
  template <class G>
  void init(const G& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    parent[0] = -1;
    depth[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
    tree.init(n);
  }

  void set(int v, const T& value) {
    tree.set(treePos[v], value);
  }

  void modifyPath(int u, int v, const T& value) {
    processPath(u, v, [this, &value](int l, int r) { tree.modify(l, r, value); });
  }

  T queryPath(int u, int v) {
    T res = T();
    processPath(u, v, [this, &res](int l, int r) { res.add(tree.query(l, r)); });
    return res;
  }
};