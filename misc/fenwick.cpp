struct FenwickTreeOneBasedIndexing
{
  vector<int> bit; // binary indexed tree
  int n;

  FenwickTreeOneBasedIndexing(int n)
  {
    this->n = n + 1;
    bit.assign(n + 1, 0);
  }

  FenwickTreeOneBasedIndexing(vector<int> a)
      : FenwickTreeOneBasedIndexing(a.size())
  {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }

  int sum(int idx)
  {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      ret += bit[idx];
    return ret;
  }

  int sum(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta)
  {
    for (++idx; idx < n; idx += idx & -idx)
      bit[idx] += delta;
  }
};

struct FenwickTreeMin
{
  vector<int> bit;
  int n;
  const int INF = (int)1e9;

  FenwickTreeMin(int n)
  {
    this->n = n;
    bit.assign(n, INF);
  }

  FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size())
  {
    for (size_t i = 0; i < a.size(); i++)
      update(i, a[i]);
  }

  int getmin(int r)
  {
    int ret = INF;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret = min(ret, bit[r]);
    return ret;
  }

  void update(int idx, int val)
  {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] = min(bit[idx], val);
  }
};
