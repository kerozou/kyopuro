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

// 1.index
// 2.未満
// 3.1が既出か
//

//桁DPではあるが、1が複数個でる場合を分けなくてはならない。
//だけど、それを複数DPとかにしたり、細かく場合分けすると泥沼化するので、うまいこと遷移DPでやりたい。
//結局、一つ前の桁までに k 個の 1 を含んでいるとしてDPに保存し、i＋１ 桁目に1が来るか来ないかで、分岐させれば全部の場合を掃けるはず。

int main(){
    string N;cin >> N;
    LL dp[10][2][10] = {0};
    vector<int> a;
    int asize = N.size();
    for(auto b : N){
        a.push_back(b-'0');
    }
    dp[0][0][0] = 1;
    rep(i,asize) rep(j,2) rep(k,10) {
        int lim = j ? 9 : a[i];
        rep(d,lim + 1){
            if(d == 1){
                dp[i+1][j || d < a[i]][k+1] += dp[i][j][k];         //i+1桁目が1の時は上位桁までの数＋１という判断
            }
            else{
                dp[i+1][j || d < a[i]][k] += dp[i][j][k];           //i+1桁目が1以外の時は1の個数は上位桁から変化しないという判断
            }
        }
    }
    LL ans;
    rep(i,asize){
        ans += (i+1)*dp[asize][0][i+1] + (i+1)*dp[asize][1][i+1];
    }
    cout << ans << endl;
}