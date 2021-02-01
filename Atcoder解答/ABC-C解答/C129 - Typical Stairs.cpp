#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const auto MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//壊れた階段を０と設定し、n-1 n-2 段目までの到達数を足し合わせる。

//1000000007MODをとるときは、途中計算の時にMODを取っておいていい時とそうでないときがあることに注意。
//今回は加法なので、MODを加算することはおｋ。
//逆に、途中でとっておかないと、値がおかしなことになる。


vector<LL> L;

int DFS(int i){
    if(i == 0)return L[i] = 1;
    if(i == 1 && L[1] != 0)return L[1] = 1;

    if(L[i] != -1)return L[i]; //メモ化再帰

    return L[i] = (DFS(i-1) + DFS(i-2)) % MOD;
}


int main(){
    int N,M;
    cin >> N >> M;
    L.assign(N+1,-1);   //assign は　コンテナの再代入メンバ関数
    int a;
    rep(i,M){
        cin >> a;L[a] = 0;
    }
    cout << DFS(N) << endl;

}