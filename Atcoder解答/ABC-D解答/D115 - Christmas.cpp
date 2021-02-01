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

LL rec(LL n,LL x){
    if(n == 0)return 1;
    LL len = (1LL << n+1) - 3;      // n-1 のバーガーの長さ
    LL num = (1LL << n) -  1;        // n-1 のバーガーのパティの枚数
    if(x == 1)return 0;
    if(x == len + 2)return num + 1; // ちょうど半分
    if(x < len + 2)return rec(n-1,x-1);
    if(x > len + 2)return num + 1 + rec(n-1,x-(len+2));
}

int main(){
    LL N;cin >> N;
    LL X;cin >> X;
    cout << rec(N,X) << endl;
}

// ABC115 	D - Christmas

// 再帰関数を実装するだけ。
// 漸化式をたてて、きちんと例外処理を作る練習。