const int MAXN = N;
const int k=25;
int st[MAXN][K + 1];
void build(vector<int>&array){
  int n=(int)array.size();
  for (int i = 0; i < n; i++)
    st[i][0] = array[i];

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1]; 
}
int get(int l,int r){
  long long sum = 0;
  for (int j = K; j >= 0; j--) {
      if ((1 << j) <= R - L + 1) {
          sum += st[L][j];
          L += 1 << j;
      }
  }
  return sum;
}

//DST
const int K=25;
int log[MAXN+1];
const int MAXN = N;
int st[MAXN][K + 1];

void build(vector<int>&a){
  int log[MAXN+1];
  log[1] = 0;
  for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;
  for (int i = 0; i < N; i++)
    st[i][0] = a[i];

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

//get min,max,gcd,and,or
int get_min(int l,int r){
  int j = log[R - L + 1];
  int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
  return minimum;
}