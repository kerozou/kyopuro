#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)


map<LL,int> prime_factor(LL n){
  map<LL,int> ret;
  for(LL i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}


int main(){
    int N;cin >> N;

    // N!までに含まれている素因数の数をカウント
    map<LL,int> lis;
    for(LL i = 2;i <= N;++i){
        map<LL,int> tmp = prime_factor(i);
        for(auto a : tmp){
            if(lis[a.F] > 74)continue;
            lis[a.F] += a.S;
        }
    }

    // 指数が74以下の素因数の数をチェック
    vector<LL> pri(75,0);
    for(auto a : lis){
        int k = a.S;
        if(k >= 2)pri[2]++;
        if(k >= 4)pri[4]++;
        if(k >= 14)pri[14]++;
        if(k >= 24)pri[24]++;
        if(k >= 74)pri[74]++;
    }

    // 75 は 3*5*5 3*25 75 15*5 の4通りで表せる
    LL ans = 0;
    if(pri[2] > 2 && pri[4] > 1)ans += (pri[2] -2) * pri[4] * (pri[4] -1) / 2;
    if(pri[2] > 1 && pri[24] > 0)ans += (pri[2] -1) * pri[24];
    if(pri[74] > 0)ans += pri[74];
    if(pri[4] > 1 && pri[14] > 0)ans += (pri[4] -1) * pri[14];

    cout << ans << endl;
}

// ABC114 D - 756

// 最後の場合の数を求めるときに、素因数の指数が大きいものから順に、使ったものを1個引くという非復元抽出をきちんとやる。