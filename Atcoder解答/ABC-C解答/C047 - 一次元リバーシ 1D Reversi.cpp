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
    char tmp = S[0];
    int ct = 0;
    rep(i,S.size()){
        if(i == 0)continue;
        if(tmp == S[i])continue;
        else {
            ct++;
            tmp = S[i];
        }
    }
    cout << ct << endl;
}

// 左右どちらかからの２通りでひっくり返していくと思われるが、両サイドを同時に使う時があるかもしれないので要検証。
// 異なる文字の隙間の数が最小回数に等しいことがわかるので、左右の検証もいらない。
// なので、左から愚直に行く。
// i=0 で現在の石をtmpに取得。あとは毎文字探索して、tmpに一致すれば飛ばして、一致しなかったらct++して、
// tmpの文字を変えて次へ。終わり。
