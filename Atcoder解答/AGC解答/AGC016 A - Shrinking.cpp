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



bool same(string t){
    bool ok = true;
    char l = t[0];
    for(auto r : t){
        if(r != l)ok = false;
    }
    return ok;
}

void cal(int i,string s,int& ct){
    if(same(s))return;

    char c = 'a' + i;
    string t;
    rep(r,s.size()-1){
        if(s[r] == c || s[r+1] == c)t.push_back(c);
        else t.push_back(s[r]);
    }
    ct++;
    cal(i,t,ct);
}

int main() {
    string s;cin >> s;
    int ans = 1e9;

    rep(i,26){
        int ct = 0;
        cal(i,s,ct);
        ans = min(ans,ct);
    }

    cout << ans << endl;

}

// AGC016 A - Shrinking

/*
    解説AC。
    変えるアルファベットを選んで26通り全探索する。

    制約が小さい時は全探索を疑おう。
*/