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
    map<LL,int> L = prime_factor(N);
    for(auto itr = L.begin();itr != L.end();itr++)cout << "( "<<itr->F<<" "<<itr->S<<" )"<<endl;
}


// 素因数分解チェック用
// ( 因数　個数　)のように表示される。
// 入力に　LL　をあたえてやればおｋ