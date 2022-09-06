//in order to update pass the diff not the new_val
template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void build(vector<int>&arr) {
    n = (int)arr.size();
    tree = vector<num_t>(4 * n, 0);
    lazy = vector<num_t>(4 * n, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vector<int>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
  if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
  
  if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
  if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
};


struct min_t {
  long long val;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(long long v): val(v) {}

  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t& v, int size) {
    return min_t(val + v.val);
  }
};

struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;

  max_t(): val(0) {}
  max_t(long long v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }
  
  max_t lazy_op(max_t& v, int size) {
    return max_t(val + v.val);
  }
};

struct sum_t {
  long long val;
  static const long long null_v = 0;

  sum_t(): val(0) {}
  sum_t(long long v): val(v) {}

  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    return sum_t(val + v.val * size);
  }
};

//simple point update
struct Segtree
{
  using ll=long long;
    vector<int> t;

    Segtree(ll n){
        t.assign(4*n+20,0);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll nw){
        if(tl==tr){
            t[v]=max(t[v],nw);
        } else {
            ll tm=(tl+tr)/2;
            if(pos<=tm){
                update(2*v,tl,tm,pos,nw);
            } else {
                update(2*v+1,tm+1,tr,pos,nw);
            }
            t[v]=max(t[2*v],t[2*v+1]);
        }
    }
    
    ll query(ll v, ll tl, ll tr, ll l, ll r){
        if(l>tr || r<tl){
            return INT_MIN;
        }
        if(l<=tl && tr<=r){
            return t[v];
        }
        ll tm=(tl+tr)/2;
        return max(query(2*v,tl,tm,l,r),query(2*v+1,tm+1,tr,l,r));
    }
};


//finding the first greatest or equal element
struct segtree{
  vector<int>st;
  vector<int>a;
  int n;
  
  segtree(vector<int>&_a):a(_a),n(_a.size()){
   st.resize(4*_a.size()+20,0LL); 
   build(1,0,n-1);
  }
  
  void build(int v,int s,int e){
    if(s==e){
      st[v]=a[s];
    }else{
      int mid=s+((e-s)>>1LL);
      build(2*v,s,mid);
      build(2*v+1,mid+1,e);
      st[v]=max(st[v<<1],st[v<<1|1]);
    }
  }
  
  int query(int v,int s,int e,int l,int r,int x){
    if(s>r || e<l)return -1;
    if(s>=l && e<=r){
      if(st[v]<x)return -1;
      while(s!=e){
        int mid=s+((e-s)>>1LL);
        if(st[2*v]>=x){
          e=mid;
          v=2*v;
        }else{
          s=mid+1;
          v=2*v+1;
        }
      }
      return s;
    }
    int mid=s+((e-s)>>1LL);
    int ls=query(2*v,s,mid,l,r,x);
    if(ls!=-1)return ls;
    return query(2*v+1,mid+1,e,l,r,x);
  }
  
  void update(int v,int s,int e,int pos,int val){
    if(s==e){
      st[v]=val;
    }else{
      int mid=s+((e-s)>>1LL);
      if(pos<=mid){
        update(2*v,s,mid,pos,val);
      }else{
        update(2*v+1,mid+1,e,pos,val);
      }
      st[v]=max(st[v<<1],st[v<<1|1]);
    }
  }
  
};