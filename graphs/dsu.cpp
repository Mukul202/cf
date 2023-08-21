vector<int>parent,components_size;
void make_set(int n) {
    parent.resize(n+1);
    component_size.resize(n+1);
    for(int i=0;i<=n;++i){
        parent[i]=i;
        components_size[i]=1;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (components_size[a] < components_size[b])
            swap(a, b);
        parent[b] = a;
        components_size[a] += components_size[b];
    }
}

struct DSU{
  vector<int>p,component_size;
  int n;
  DSU(int _n):n(_n){
    p.resize(n);
    iota(all(p),0);
    component_size.assign(n,1);
  }
  int find(int u){if(p[u]==u)return u;return p[u]=find(p[u]);}
  void merge(int u,int v){
    int p1=find(u);
    int p2=find(v);
    if(p1!=p2){
      if(component_size[p1]<component_size[p2])swap(p1,p2);
      p[p2]=p1;
      component_size[p1]+=component_size[p2];      
    }
  }
  bool same_set(int u,int v){return find(u)==find(v);}
};
