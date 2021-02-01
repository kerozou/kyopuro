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
    string S;cin >> S;
    if(S[1] == 'W'){ // ミシ
        if(S[6] == 'B')cout << "Mi" << endl;
        else cout << "Si" << endl;
    }
    else if(S[3] == 'B'){ // ドファソ
        if(S[5] == 'B')cout << "Fa" << endl;
        else if(S[10] == 'B')cout << "Do" << endl;
        else cout << "So" << endl;
    }
    else{ // レラ
        if(S[8] == 'B')cout << "Re" << endl;
        else cout << "La" << endl;
    }
}

// 鍵盤の絵を20枚分くらいかいて、とりあえず左から12枚分くらいドレミファソラシドを描く。
// すると、（ミ、シ）（ド、ファ、ソ）（レ、ラ）の3組に分けられる。