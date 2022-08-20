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