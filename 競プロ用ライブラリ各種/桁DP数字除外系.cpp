#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//ABC-D 007 禁止された数字

// 1.index
// 2.未満フラグ
// 3.4.9既出か

// 桁DPで解こう！
// ちなみに longlong で19桁くらいだから、intだと死亡する。
// なので、DPはLLで作ろう。

// 全体の方針としては、
// Bの数　－　Aの数　＋　Aそのものに含むかどうか　＝　総数
// として調べるために、二回ほどDPループする。

int main(){
    string A,B;cin >> A >> B;   //文字列で取得
    LL dp[22][2][2] = {0};      //ここをLLで作り、なおかつ静的配列は{0}で初期化しないと、NULLっててバグる（1敗）
    LL dp2[22][2][2] = {0};
    int asize = A.size();
    int bsize = B.size();
    vector<int> a;
    vector<int> b;

    for(auto z : A){            //文字列からintへ桁を移す
        a.push_back(z-'0');
    }
    for(auto y : B){
        b.push_back(y-'0');     //文字列からintへ桁を移す(2)
    }

    dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
    dp2[0][0][0] = 1;
    rep(i,bsize) rep(j,2) rep(k,2){ //b root
        int lim = j ? 9 : b[i];     //各桁を何回調べるか決める
        rep(d,lim + 1){
            dp[i+1][j || d < b[i]][k || d == 4 || d == 9] += dp[i][j][k];       //DP遷移式
        }
    }
    rep(l,asize) rep(m,2) rep(n,2){ //a root
        int lim2 = m ? 9 : a[l];
        rep(x,lim2 + 1){
            dp2[l+1][m || x < a[l]][n || x == 4 || x == 9] += dp2[l][m][n];       //DP遷移式
        }
    }

    int tmp = 0;
    rep(i,asize){       //Aの被り部分を計算しておく
        if(a[i] == 4 || a[i] == 9)tmp = 1;
    }

    cout << (dp[bsize][0][1] + dp[bsize][1][1]) - (dp2[asize][0][1] + dp2[asize][1][1]) + tmp << endl;          //[0][1]と[1][1]を足し合わせると、全体になる。
}

//20190810 AC