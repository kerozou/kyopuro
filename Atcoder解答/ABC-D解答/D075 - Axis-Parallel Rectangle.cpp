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
    int N,K;cin >> N >> K;
    vector<pll> xy(N);
    rep(i,N)cin >> xy[i].F >> xy[i].S;
    sort(all(xy));
    LL ans = 1LL << 62;
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            for(int k = 0;k < N;++k){
                for(int l = 0;l < N;++l){
                    LL ct = 0;
                    LL L,R,U,D;
                    if(xy[i].F <= xy[j].F){
                        L = xy[i].F;
                        R = xy[j].F;
                    }
                    else{
                        L = xy[j].F;
                        R = xy[i].F;                            
                    }
                    if(xy[k].S <= xy[l].S){
                        D = xy[k].S;
                        U = xy[l].S;
                    }
                    else{
                        D = xy[l].S;
                        U = xy[k].S;
                    }
                    for(int m = 0;m < N;++m){
                        pll tmp = xy[m];
                        if(tmp.F >= L && tmp.F <= R && tmp.S <= U && tmp.S >= D)ct++;
                    }
                    if(ct >= K)ans = min(ans,1LL*(R - L)*(U - D));
                }
            }
        }
    }
    cout << ans << endl;
}

// ABC075 D - Axis-Parallel Rectangle

// 解説放送神
// それ以外の方針は解説pdfが神

// http://tatanaideyo.hatenablog.com/entry/2017/10/16/125741
// k-enclosing problem っていう問題群の一つらしい。

// 基本は5重ループ回せばおk。
// 10^9のマス目をN=50までに落とし込めるところがポイント。