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
    int N,K;cin >> N >> K;
    int R,S,P;cin >> R >> S >> P;
    string T;cin >> T;

    // R 0 S 1 P 2
    LL point[3] = {P,R,S};
    vector<vector<LL>> win(K);
    rep(i,N){
        int num = i % K;
        int tmp;
        if(T[i] == 'r')tmp = 0;
        if(T[i] == 's')tmp = 1;
        if(T[i] == 'p')tmp = 2;
        win[num].push_back(tmp);
    }

/*    rep(i,K){
        rep(j,win[i].size()){
            cout << win[i][j] << " ";
        }
        cout << endl;
    }
*/

    LL ans = 0;

    rep(i,K){
        bool ok = false;
        rep(j,win[i].size()){
            if(j == 0){
                ans += point[win[i][j]];
            }
            else if(win[i][j] != win[i][j-1]){
                ans += point[win[i][j]];
                ok = false;
            }
            else{
                if(ok){
                    ans += point[win[i][j]];
                    ok = false;
                }
                else{
                    ok = true;
                }
            }
        }
    }
    cout << ans << endl;
}

// ABC149 D - Prediction and Restriction

// Kの剰余類で分類して、各剰余類ごとに連続して同じ手が出るかをチェックしながら計算すればおｋ。

// else if の時にfalseに戻すのを忘れてて1WA