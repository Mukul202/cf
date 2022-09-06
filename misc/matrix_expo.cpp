struct Matrix {
  int rows,cols;
	vector<vector<int>>a;
	Matrix(int rows=2,int cols=2) {
    this->rows=rows,this->cols=cols;
    a=(vector<vector<int>>(rows,vector<int>(cols)));
		fr(i, rows) {
			fr(j, cols) {
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix();
    int p=rows,q=cols,r=other.cols;
		fr(i, p) {
			fr(j, q) {
				fr(k, r) {
					product.a[i][k] += a[i][j] * other.a[j][k];
					product.a[i][k] %= mod;
				}
			}
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long n) {
	Matrix res = Matrix();
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


//own template
using ll=long long;
const ll mod=1e9+7;


vector<vector<ll>>mul(vector<vector<ll>>&a,vector<vector<ll>>&b){
  int p=(int)a.size();
  int q=(int)a[0].size();
  int r=(int)b[0].size();
  
  vector<vector<ll>>res(p,vector<ll>(r));
  
  for(int i=0;i<p;++i){
    for(int j=0;j<q;++j){
      for(int k=0;k<r;++k){
        res[i][k]+=(a[i][j]*b[j][k])%mod;
        res[i][k]%=mod;
      }
    }
  }
  
  return res;
}

vector<vector<ll>>power(vector<vector<ll>>&a,int p){
  if(p==1)return a;
  
  auto subans=power(a,p/2);
  subans=mul(subans,subans);
  if(p&1)subans=mul(subans,a);
  return subans;
}
