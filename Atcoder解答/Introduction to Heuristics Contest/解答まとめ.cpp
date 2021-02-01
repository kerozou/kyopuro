#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

LL D;
vector<vector<LL>> last;
vector<LL> c(27);
vector<vector<LL>> s;
vector<LL> t;

vector<LL> ()

LL calcLast(int d){
    LL tmp = 0;
    for(int i = 1;i <= 26;i++){
        tmp += (c[i]*(d - last[d][i]));
    }
    return tmp;
}

void reloadLast(int d,int i){
    for(int j = d;j <= D;j++){
        last[j][i] = d;
    }
}

int main() {

    // D : 何日目かは 1-index で処理する
    // c : コンテストの番号も 1-index で処理する
    // s : 満足度の上昇具合も　1-index で処理する


    cin >> D;
    for(int i = 1;i <= 26;i++)cin >> c[i];
    s.resize(D+1,vector<LL>(27,0));
    for(int i = 1;i <= D;i++)for(int j = 1;j <= 26;j++)cin >> s[i][j];
    t.resize(D+1);

    // last[d][i] : d 日目以前(d含む)にタイプ i のコンテストを開催した最後の日
    last.resize(D+1,vector<LL>(27,0));
    


    /*
    // B 問題用　入力
    for(int i = 1;i <= D;i++)cin >> t[i];
    */

    /*
    // B問題　の　計算機
    LL v = 0;
    for(int i = 1;i <= D;i++){
        // 満足度を加算
        v += s[i][t[i]];

        // last 更新
        reloadLast(i,t[i]);

        // 下がる満足度
        v -= calcLast(i);

        // v の出力
        cout << v << endl;
    }
    */


    // 初期値生成
    
   

   
}