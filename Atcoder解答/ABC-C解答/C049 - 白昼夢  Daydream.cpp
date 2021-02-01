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
    string maerd = "maerd";
    string remaerd = "remaerd";
    string esare = "esare";
    string resare = "resare";
    int ed = S.size()-1;
    int itr = ed;
    bool ok = true;
    while(ok){
        if(itr < 0)break;

        if(S[itr] == 'm'){
            if(itr >= 4){
                rep(i,5){
                    if(S[itr-i] != maerd[i])ok = false;
                }
                itr -= 5;
            }
            else{
                ok = false;
            }
        }
        else if(S[itr] == 'r'){
            if(itr >= 5){
                if(S[itr-2] == 'm'){
                    if(itr >= 6){
                        rep(i,7){
                            if(S[itr - i] != remaerd[i])ok = false;
                        }
                        itr -= 7;
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
                else if(S[itr-2] == 's'){
                    rep(i,6){
                        if(S[itr-i] != resare[i])ok = false;
                    }
                    itr -= 6;
                }
                else {
                    ok = false;
                    break;
                }
            }
            else {
                ok = false;
            }
        }
        else if(S[itr] == 'e' ){
            if(itr >= 4){
                rep(i,5){
                    if(S[itr-i] != esare[i])ok = false;
                }
                itr -= 5;
            }
        }
        else {
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" <<endl;
}

// ただただ複雑なコードを正確に実装する問題。