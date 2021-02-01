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


// C - 755 を桁DPで解く。
// DPは
//  i 1.現在地の桁
//  j 2.未満フラグ      0で桁一致、1で未満
//  k 3.3が既出か       0で出てない、1で既出
//  l 4.5が既出か       0で出てない、1で既出
//  m 5.7が既出か       0で出てない、1で既出
//  n 6.357以外が既出か       0で出てない、1で既出  (以外というところに注意)
//  o 7.0より大きいか     （Leading zeroを被753とカウントしないかどうか）（つまり、0000753とかの0000)

int main(){
    string N;cin >> N;      //めっちゃデカい桁にも対応できるように文字列で入力　→　桁DPの優れている点
    int K = N.size();  //nの長さ
    int dp[K+1][2][2][2][2][2][2] = {0};      //桁DP配列
    vector<int> X;      //int配列X

    for(auto a : N){        //文字列Nをint配列nに作り替える
        X.push_back(a-'0');
    }

    dp[0][0][0][0][0][0][0] = 1;    //桁DP配列の-1桁目ともいえる部分を設定。初期化。
    
    rep(i,K) rep(j,2) rep(k,2) rep(l,2) rep(m,2) rep(n,2) rep(o,2){     //メインループ
        int lim = (j ? 9 : X.at(i));  //条件演算子で未満フラグがONの時は自由選択、OFFの時は上限が各桁の数字に設定される。
        rep(d,lim + 1){             //調べている現在の桁を数え上げてる
            bool non357 = n ? (d != 0 && d != 3 && d != 5 && d != 7)          //d = 0,3,5,7 のとき　0
                            : (d != 3 && d != 5 && d != 7);   //d = 3,5,7の時 0 
                            //上の操作は、結局nが1の時は上位の桁に3,5,7以外が含まれてるので、口述するLeading zeroを考慮するためだけのbool値を作る。
                            //n=0の時は、上位の桁に3,5,7しか存在しないので、3,5,7かどうかを判定するbool値となる。
            dp[i+1][j || d < lim][k || d == 3][l || d == 5][m || d == 7][n || non357][o || non357]  //n と oはそれぞれnon357と合わせて0になる時を考えるとよい
                += dp[i][j][k][l][m][n][o];
        }
    }

    int ans = 0;
    rep(i,K) rep(j,2) rep(k,2) rep(l,2) rep(m,2) rep(n,2) rep(o,2){
        if(k == 1 && l == 1 && m == 1 && o == 0) ans += dp[i][j][k][l][m][n][o];
    }
    cout << ans << endl;
}