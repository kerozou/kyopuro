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
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    int SW = 0;
    int S = 0;
    double Srate = 0;
    rep(i,F/100/A + A) rep(j,F/100/B + B){
        double water = A*i + B*j;
        int sugarlim = water*E;
        if(water*100 + sugarlim > F)sugarlim = F - water*100;
        rep(k,sugarlim/C + C) rep(l,sugarlim/D + D){
            double sugar = C*k + D*l;

            double tmp2 = (water*100+sugar != 0 ? sugar*100/(water*100+sugar) : 0 );
            if(water*100 + sugar <= F && sugarlim >= sugar) if(tmp2 > Srate){
                SW = water*100 + sugar;
                S = sugar;
                Srate = sugar*100/(water*100+sugar);
            }
        }
    }
    if(S == 0)SW = min(A,B)*100;
    cout << SW << " " << S << endl;
}

// いろいろしんどかった。テストケースを見ることができるようになって救われた。