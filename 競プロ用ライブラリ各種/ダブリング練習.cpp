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


int N;
vector<vector<int>> nex;
string S;
int LOG_MAX = floor(log(100000)/log(2));

// 前処理 O(NlogN)
void before(){
    
    // 1回操作した時の座標を取得
    rep(i,N){
        if(S[i] == 'R')nex[0][i] = i+1;
        else nex[0][i] = i-1;
    }

    // ダブリングの前処理
    rep(k,LOG_MAX) rep(i,N){    
        if(nex[k][i] == -1)nex[k+1][i] = -1;  // 今回はいらなかったこれ
        else nex[k+1][i] = nex[k][nex[k][i]];
    }

    return;
}

// p番目の子どもの「Q回移動後の地点」を求める O(logN)
int move(int p,int q){
    for(int k = LOG_MAX -1;k >= 0;--k){
        if(p == -1)break;
        if(q >> k & 1)p = nex[k][p];
    }
    return p;
}


int main(){
    cin >> S;
    N = S.size();
    nex.resize(LOG_MAX + 1,vector<int>(N));

    // 前処理
    before();

    // 移動
    vector<int> ans(N);
    rep(i,N){
        int tmp = move(i,100000);
        ans[tmp]++;
    }

    // 出力
    rep(i,N)cout << ans[i] << " ";

}


// abc-136 D - Gathering Children
// を使ってダブリングの練習。


// ダブリングの練習がてらダブリングで問題を解いてみた。
// ダブリングの説明はsatanicさんのサイトがいい。
// http://satanic0258.hatenablog.com/entry/2017/02/23/222647

// この問題では、前処理の時点で10^5までリストを作ってる。
// 結局、想定できる最大のケースを作っておく必要があるので、10^5にしておくと、どんな場合でもいける。