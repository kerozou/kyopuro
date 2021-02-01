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

unsigned GetDigit(unsigned num){
    if(num == 0)return 1;
    return log10(num)+1;
}

int main(){
    LL n;cin >> n;
    double N = sqrt(n);
    LL lim = N;
    LL A=0,B=0;
    LL ans = INF;

    for(int i = 1;i <= lim;i++){
        if(i == 0)continue;
        if(n % i == 0){
            A = GetDigit(i);
            LL big = n/i;
            B = GetDigit(big);
            ans = min(ans,max(A,B));
        }
    }
    cout << ans << endl;
}

// 0除算と区間推定が危険
