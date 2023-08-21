vector<bool>p(N+1,false);
vector<int>primes;
void sieve(){
  p[0]=p[1]=false;
  for(int i=2;i<=N;++i){
    if(!p[i])
      continue;
    primes.emplace_back(i);
    for(int j=i*i;j<=N;j+=i){
      p[j]=false;
    }
  }
}

vector<vector<int>>divisors(N+1,vector<int>(1,1));
void sieve(){
  for(int i=2;i<=N;++i){
    for(int j=i;j<=N;j+=i){
      divisors[j].emplace_back(i);
    }
  }
}

vector<int>max_div;
const int MAX_N=1e5;
void prime_factorization(){
  max_div.resize(MAX_N,0);
  for (int i = 2; i <= MAX_N; i++) {
		if (max_div[i] == 0) {
			for (int j = i; j <= MAX_N; j += i) {
				max_div[j] = i;
			}
		}
	}
}

array<int,3> extendEuclid(int a, int b) {
	array<int,3> x = {1,0,a}, y = {0,1,b};
	// we know that 1*a+0*b=a and 0*a+1*b=b
	for (;y[2];swap(x,y)) { // run extended Euclidean algo
		int k = x[2]/y[2];
		fr(i,3) x[i] -= k*y[i];
		// keep subtracting multiple of one equation from the other
	}
	return x; // x[0]*a+x[1]*b=x[2], x[2]=gcd(a,b)
}