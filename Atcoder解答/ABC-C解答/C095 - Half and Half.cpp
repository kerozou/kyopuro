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
    int A,B,C;cin >> A >> B >> C;
    int X,Y;cin >> X >> Y;
    if(A+B < 2*C)cout << A*X + B*Y << endl; // 1 root
    else{                                   // 2 root
        int yen = (max(X,Y) == X ? A : B);              //　多い枚数はAピザかBピザか
        int ans = (yen < 2*C ? yen : 2*C);              //  (1)か(2)か
        cout << min(X,Y)*2*C + abs(X-Y)*ans << endl;    //  いずれも結局 abs(X-Y) * k　枚買うので　ans で一本にまとめた。
    }
}


// ABC095 C-Half and Half
// ・ABピザ二枚の値段　VS　A,B一枚ずつの値段

// 1.AB二枚の方が高い時は全部A,Bを単体で用意。
//
// 2.AB2枚の方が安い時は min(X,Y)*2 枚のABを購入
//  そののち、max(X,Y)の方のピザの値段　VS　AB二枚の値段
//     (1)max(X,Y)の方が安い時
//          abs(X-Y)枚　max(X,Y)ピザを買う。
//     (2)AB二枚の方が安い時
//          abs(X-Y)*2枚の　AB　を買う。
