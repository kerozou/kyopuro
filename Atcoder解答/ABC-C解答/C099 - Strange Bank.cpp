#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)


//  DPを使って解く。今回は複数の選択肢があるので、配るDPでいったほうがいい。
//  6,9のべき乗を使うわけだけど、6のべき乗が9よりも多くはいるので、　
//      j_roop_lim  =  log6(N)　/　10 
//  とおいて、lim==0（Nが6未満）を場合分けする。
//  その際、DPは9の方で拡張しておくと漏れない。

int main(){
    int N;cin >> N;

    int lim = log(N) / log(6);
    lim /= 1;

    vector<LL> DP(N+pow(9,lim)+1,INF);
    DP[0] = 0;


    rep(i,N){
        if(lim == 0){
            chmin(DP[i+1],DP[i] + 1);   // 1 select
        }
        else{
            for(int j = 1;j <= lim;j++){
                chmin(DP[i+1],DP[i] + 1);   // 1 select
                chmin(DP[i+pow(6,j)],DP[i] + 1); // 6^j select
                chmin(DP[i+pow(9,j)],DP[i] + 1); // 9^j select
            }
        }
    }

    cout << DP[N] << endl;
}