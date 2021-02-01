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
    int N;cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    pair<int,int> ans[N][N];
    rep(i,N)rep(j,N)ans[i][j] = make_pair(-1000000,-1000000);
    rep(i,N)rep(j,N){
        if(i == j)continue;
        int start = min(i,j);
        int end = max(i,j) - min(i,j);
        int ct = 0;
        pair<int,int> tmp = make_pair(0,0);
        for(int k = 0;k <= end;k++){
            if(k % 2 == 0)tmp.F += a[start+k];       //奇数番目（0indexなら偶数番目）
            else tmp.S += a[start+k];
        }
        ans[i][j] = tmp;
    }

    /*
    rep(i,N){
        rep(j,N)cout << ans[i][j].F << "  ";
        cout << endl;
    }
    //
    cout << "//////////" << endl;
    //
    rep(i,N){
        rep(j,N)cout << ans[i][j].S << "  ";
        cout << endl;
    }   
    */

   // 上は確認用のコード
   
    vector<int> taka(N);
    int aoki = -1000000;
    int tms;
    int tmi = 0;
    rep(i,N){
        tms = -1000000;         // 取得値リセット　←　これいらんくない？
        aoki = -1000000;        // 青木の最高得点リセット
        rep(j,N){
            if(i == j)continue;
            tms = ans[i][j].S;
            if(aoki < tms){             //  ここで青木君の最高得点が左端になるようにしている
                aoki = tms;
                tmi = j;                //  jが何の時ans[i][~]が最大になるかを記録してる
            }
        }
        taka[i] = ans[i][tmi].F;
    }
    sort(rall(taka));
    cout << taka[0] << endl;
}

// ABC-031C
// 高橋君が大きい数字を選んだ時に、青木君は小さい数字を選びうることを忘れてはいけない（一敗）