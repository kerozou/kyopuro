#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    LL X,Y;cin >> X >> Y;
    int ans;
    while(X <= Y){
        ans++;
        X *= 2;
    }
    cout << ans << endl;
}

/*
    double X,Y;cin >> X >> Y;
        X = log(X)/log(2);
        Y = log(Y)/log(2);
        X = Y - X ;

        int ans = floor(X) + 1;
        cout << ans << endl;
*/

// 上の計算では一個だけ通らなかった。おそらく、小数点以下で誤差が生じて通らないものがあるっぽい。
// doubleの割り算とか繰り返すやつは危険なので、なるべく避けるほうがいい。

// O(log2(N)) で通るので、10^18でも60程度