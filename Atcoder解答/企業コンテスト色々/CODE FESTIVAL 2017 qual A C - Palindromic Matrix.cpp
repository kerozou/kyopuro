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


bool Hch(int w){

}
int main() {
    int H,W;cin >> H >> W;
    vector<int> mo(4);
    map<char,int> m;
    rep(i,H*W){
        char c;cin >> c;
        m[c]++;
    }
    for(auto t : m){
        int tmp = t.S % 4;
        mo[tmp]++;
    }

    bool ok = true;
    if(H % 2 == 0 && W % 2 == 0){
        if(mo[1] > 0 || mo[2] > 0 || mo[3] > 0)ok = false;
    }
    else if(H % 2 == 1 && W % 2 == 1){
        if(mo[2] > ((H-1)/2 + (W-1)/2))ok = false;
        if(mo[1]+mo[3] != 1)ok = false;
    }
    else{
        if(H % 2 == 0 && mo[2] > H/2)ok = false;
        if(W % 2 == 0 && mo[2] > W/2)ok = false;
        if(mo[1]+mo[3] > 0)ok = false;
    }

    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

// 	CODE FESTIVAL 2017 qual A C - Palindromic Matrix

/*
    MODで分けるのが本質。
    構築と考察はただただ注意力が問われる。
*/