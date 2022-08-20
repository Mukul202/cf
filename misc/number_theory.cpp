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