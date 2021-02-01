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

int main() {
    int N;cin >> N;
    vector<string> w(N);rep(i,N)cin >> w[i];

    map<char,int> m;
    m['z'] = 1;m['Z'] = 1;m['r'] = 1;m['R'] = 1;
    m['b'] = 2;m['B'] = 2;m['c'] = 2;m['C'] = 2;
    m['d'] = 3;m['D'] = 3;m['w'] = 3;m['W'] = 3;
    m['t'] = 4;m['T'] = 4;m['j'] = 4;m['J'] = 4;
    m['f'] = 5;m['F'] = 5;m['q'] = 5;m['Q'] = 5;
    m['l'] = 6;m['L'] = 6;m['v'] = 6;m['V'] = 6;
    m['s'] = 7;m['S'] = 7;m['x'] = 7;m['X'] = 7;
    m['p'] = 8;m['P'] = 8;m['m'] = 8;m['M'] = 8;
    m['h'] = 9;m['H'] = 9;m['k'] = 9;m['K'] = 9;
    m['n'] = 10;m['N'] = 10;m['g'] = 10;m['G'] = 10;

    string ans = "";
    vector<string> st(N);

    rep(i,N){
        bool ok = false;
        for(auto t : w[i]){
            if(m[t] > 0){
                ok = true;
                int tmp = m[t]-1;
                char c = '0' + tmp;
                st[i] += c;
            }
        }
    }

    rep(i,N){
        if(st[i].size() == 0)continue;
        else{
            ans += st[i];
            ans += " ";
        }
    }
    if(ans.size() != 0)ans.pop_back();
    cout << ans << endl;
}

// ARC011 B - ルイス・キャロルの記憶術

/*
    文字列と空白の扱いに注意するだけ。
*/