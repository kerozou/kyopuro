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
    LL N;cin >> N;
    map<LL,int> memo;
    rep(i,N)memo[i+1] = 0;  // map初期化
    map<LL,int> tmp;
    rep(i,N){
        if(i == 0)continue;
        tmp = prime_factor(i+1);
        for(auto itr = tmp.begin();itr != tmp.end();itr++){
            LL a = itr->F;
            int b = itr->S;
            memo[a] += b;
        }
    }
    LL ans = 1;
    for(auto itr = memo.begin();itr != memo.end();itr++){
        int c = itr->S;
        ans *= (c+1);
        ans %= MOD;
    }
    cout << ans << endl;
}


// 素因数分解便利すぎる。やばい。

// やってることは、N!の各構成要素ごとに素因数分解して、現れた因数の個数を記録用のmapにカウントしていっている。
// なので、最後に記録した因数の個数を　i+1 としてansにかけ合わせていき、毎回％MODすれば答えになる。

// 素因数分解の処理がきちんとできてないと泥沼になりそう。