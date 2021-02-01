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
    LL K;cin >> K;
    LL ct = 1;
    LL ans = 0;
    LL lim = S.size();

if(S[0] == S[lim - 1]){
    LL tcl = 1;
        rep(i,lim){
            if(S[0] == S[tcl]){
                tcl++;
            }
            else break;
        }
      //  cout << tcl << endl;
    LL tcr = 1;
        rep(i,lim){
            if(S[lim-1] == S[lim-1-tcr]){
                tcr++;
            }
            else break;
        }
    if(lim == 1){
        LL an = K/2;
        cout << an  << endl;
    }
    else if(tcl == 1 && tcr == 1){
        ans += K-1;
        char tmp = S[0];
        LL ctem = 0;
    rep(i,lim){
        if(i == 0)continue;
        if(S[i] == S[i-1]){
            ct++;
            if(i == lim){
                ctem += ct/2;
            }
        }
        else{
            ctem += ct/2;
            ct = 1;
        }
    }
    ctem *= K;
    ans += ctem;

   cout << ans << endl;
    }
    else if(tcl == lim){
        cout << (lim*K)/2 << endl;
    }
    else{
        ans += tcl/2 + tcr/2 + (K-1)*((tcl+tcr)/2);
  //    cout << ans << endl;
        char tmp = S[tcl];
        LL ctem = 0;
    for(int i = tcl;i<lim-tcr;i++){
        if(i == 0)continue;
        if(S[i] == S[i-1]){
            ct++;
            if(i == lim-tcr-1){
                ctem += ct/2;
            }
        }
        else{
            ctem += ct/2;
            ct = 1;
        }
    }
    ctem *= K;
    ans += ctem;

    cout << ans << endl;
    }

//cout << tcl << " " << tcr << endl;
}
else{

    char tmp = S[0];
    LL ctem = 0;
    rep(i,lim){
        if(i == 0)continue;
        if(S[i] == S[i-1]){
            ct++;
            if(i == lim-1){
                ctem += ct/2;
            }
        }
        else{
            ctem += ct/2;
            ct = 1;
        }
    }
    ctem *= K;
    ans += ctem;
    cout << ans << endl;
}

}

