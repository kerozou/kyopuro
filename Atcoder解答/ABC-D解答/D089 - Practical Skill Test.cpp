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
    int H,W,D;cin >> H >> W >> D;
    vector<vector<int>> A(H+1,vector<int>(W+1,0));
    vector<pair<int,pair<int,int>>> B(H*W+1);
    rep(i,H)rep(j,W){
        cin >> A[i+1][j+1];
        B[A[i+1][j+1]] = {A[i+1][j+1],{i+1,j+1}};
    }
    sort(all(B));   // index順に並べる
    int Q;cin >> Q;
    vector<pair<int,int>> lr(Q);
    rep(i,Q)cin >> lr[i].F >> lr[i].S;

    vector<LL> rui(H*W+1,0);    // i番目がRとなるときの絶対値の累積和
    for(int i = 1;i <= H*W;++i){
        if(i + D <= H*W){
            rui[i + D] = rui[i] + abs(B[i+D].S.F - B[i].S.F) + abs(B[i+D].S.S - B[i].S.S);
        }
    }

    vector<int> ans(Q);
    rep(i,Q){
        ans[i] = rui[lr[i].S] - rui[lr[i].F];
    }
    rep(i,Q)cout << ans[i] << endl;
}

// 	ABC089 D - Practical Skill Test

// 自力AC

// 絶対値の和がそれぞれ独立して成立することに注目すれば、O(N)で通すためにはDPや累積和な方法が必要なことが分かる。
// あらかじめ、indexと座標を所持した配列を用意しておき、これを昇順にソートしてあげると頭から順に累積和を作っていける。

