#include<bits/stdc++.h>
using namespace std;
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

int N;
string s;

int cal(char a,char b,char c,char d){
    string L;
    L += a;
    L += b;
    string R;
    R += c;
    R += d;

    int ct = 0;
    rep(i,N){
        ct++;
        if(i == N-1)break;
        if(s.substr(i,2) == L || s.substr(i,2) == R)i++;
    }

    return ct;
}


int main() {
    cin >> N;
    cin >> s;

    string lis = "ABXY";

    int ans = 1e9;
    for(auto a : lis){
        for(auto b : lis){
            for(auto c : lis){
                for(auto d : lis){
                    ans = min(ans,cal(a,b,c,d));
                }
            }
        }
    }   

    cout << ans << endl;
}

// ARC002 C - コマンド入力

/*
    substr　の使いどころさん

    基本的に毎ターンなんらかのボタンを押さなければならないので、とりあえずct++する。
    そんで、2連結文字でいけるならそっちを採用してindexを一つ飛ばすという感じ。
    結局貪欲。
*/