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


vector< LL > divisor(LL n) {
  vector< LL > ret;
  for(LL i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


int main(){
    LL N,M;cin >> N >> M;
    vector<LL> div = divisor(M);
    int ans = 1;
    for(auto i : div)if(M % i == 0 && (M / i) >= N)ans = i;
    cout << ans << endl;
}

// ABC112 	D - Partition

// for(auto)を i <=1e7 とかにしてた時はできなかった。
// Mの最大約数がNの値によっては1e9とかになるため
// なので、ループ回数を減らすために、どうせiがMの約数になるとき（M%i==0)を仮定するなら、最初にMの約数を列挙しておけばいい。O(rootM)