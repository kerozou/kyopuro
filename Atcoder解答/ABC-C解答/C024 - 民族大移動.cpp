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
    int N,D,K;cin >> N >> D >> K;
    vector<int> L(D);
    vector<int> R(D);
    rep(i,D)cin >> L[i] >> R[i];
    vector<int> S(K);
    vector<int> T(K);
    rep(i,K)cin >> S[i] >> T[i];

    vector<int> ans(K);

    rep(i,K){
        rep(j,D){
            if(L[j] <= S[i] && S[i] <= R[j]){
                if(S[i] < T[i]){    // 左から右
                    if(T[i] <= R[j]){
                        ans[i] = j+1;
                        break;
                    }
                    else{
                        S[i] = R[j];
                        continue;
                    }
                }
                else{   //　右から左
                    if(T[i] >= L[j]){
                        ans[i] = j+1;
                        break;
                    }
                    else{
                        S[i] = L[j];
                        continue;
                    }
                }
            }
        }
    }

    rep(i,K)cout << ans[i] << endl;
}


// ABC024 C - 民族大移動

/*
    L→R　と　R→L　は基本的に同じ考え方でクリアできる。
    まず、スタートがLRの区間に入っているか見て、入っていたら動く。
    S<T　なら　右に動き、　S>T　なら　左に動く。
    動いたときにまだ目的地に達していなかったら　S　を　右ならRに　左ならLに　更新して回し続ける。
*/