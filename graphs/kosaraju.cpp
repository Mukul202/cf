vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... processing next component ...

            component.clear();
        }
}

//struct form

struct scc {
  vector<vector<int> > edges, redges;
  vector<bool> used;
  vector<int> order, component;
  int n;

  void init(int _n) {
    n = _n;
    edges = vector<vector<int> >(n);
    redges = vector<vector<int> >(n);
    order.clear();
    component.clear();
  }

  void edge(int u, int v) {
    edges[u].push_back(v);
    redges[v].push_back(u);
  }

  void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
      if (!used[edges[v][i]]) {
        dfs1(edges[v][i]);
      }
    }
    order.push_back(v);
  }

  void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < redges[v].size(); i++) {
      if (!used[redges[v][i]]) {
        dfs2(redges[v][i]);
      }
    }
  }

  vector<vector<int> > run() {
    vector<vector<int> > components;
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs1(i);
      }
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      int v = order[n - 1 - i];
      if (!used[v]) {
        dfs2(v);
        components.push_back(component);
        component.clear();
      }
    }

    return components;
  }
};