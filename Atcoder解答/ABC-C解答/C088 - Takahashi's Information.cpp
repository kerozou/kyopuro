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
    //入力と準備
    int c[3][3];
    rep(i,3) rep(j,3) cin >> c[i][j];
    int a[3],b[3];
    int x2[3],x3[3];

    int tmp = min(c[0][0],c[1][0]); //c[0][~]の最小値をb1とおく。
    b[0] = min(tmp,c[2][0]);        //b1 を固定

    rep(i,3) a[i] = c[i][0] - b[0]; //b1 を頼りに a1,a2,a3 を固定

    rep(i,3) x2[i] = c[i][1] - a[i]; //b2 候補を選出
    rep(i,3) x3[i] = c[i][2] - a[i]; //b3 候補を選出
    if(x2[0] != x2[1] || x2[1] != x2[2] || x2[0] != x2[2]) cout << "No" << endl;    //b2 が決まらないとき
    else{
        if(x3[0] != x3[1] || x3[1] != x3[2] || x3[2] != x3[0]) cout << "No" << endl;    //b3 が決まらないとき
        else cout << "Yes" << endl; //b1,b2,b3 が決まるとき
    }
}

// ABC088 C - Takahashi's Information
// ・結局、問題の制約が甘いので、a,bが対称性をもつということを利用する。

// つまり、a1,a2,a3,b1,b2,b3　はどこかを固定して考えても構わないということ。
// 図に表すと以下のようになる。

/*          \  b1  b2  b3
            a1 c11 c12 c13
            a2 c21 c22 c23
            a3 c31 c32 c33
*/

// 上図を見ながら考える。
// a+b=c　が成立する以上、c-b=a　ももちろん成り立つ。
// これより、min(c)=b1　と決め打ちして、a1,a2,a3を固定する。
// すると、b2 も　c-a　より候補をあげることができる。
// このとき、3つ現れるb2候補はすべて等しくないとならない。（b2は一つしか存在しないため）
// 同様にb3についても調べてあげて、b2,b3ともに一意に決まるとき”Yes"、そうでないとき”No"である。