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
    string s;cin >> s;
    int a,b;
    a = -1;
    b = -1;
    if(s.size() == 2){
        if(s[0] == s[1]){
            a=1;b=2;
        }
    }
    rep(i,s.size()-2){
        if(s[i] == s[i+1]){
            a = i+1;
            b = i+3;
            break;
        }
        else if(s[i] == s[i+2]){
            a = i+1;
            b = i+3;
            break;
        }
    }
    cout << a << " " << b << endl;
}

// ABC043 D - アンバランス / Unbalanced

// XXY か　YXX　か　XYX　を検出すればおｋなので、頭からしらべるだけ。
// 注意点としては、2文字の時だけループが回らないので別分岐が必要。

