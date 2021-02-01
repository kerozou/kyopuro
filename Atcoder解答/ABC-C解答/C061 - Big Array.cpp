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

int main(){
   LL N,K;cin >> N >> K;
   vector<pair<LL,LL>> L(N);
   rep(i,N){
       LL a,b;cin >> a >> b;
       L[i].F = a;
       L[i].S = b;
   }
   sort(all(L));
   LL tmp = 0;
   LL ans = 0;
   rep(i,N){
       tmp += L[i].S;
       if(tmp >= K){
           ans = L[i].F;
           break;
       }
   }
   cout << ans << endl;
}

// int でやったら死亡した（1敗）