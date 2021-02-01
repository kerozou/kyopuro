#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//  結局、123 | 345 | 567 | 789 | 9 10 |
//  のような両端が被ってるエリア分けを作って、1の入っているエリアから両サイドに広がっていくしかない。
//  なので、あらかじめ、このエリア分けがどのように行われるかをチェック。
//  エリア分けのエリア数がそのまま答えになる。
//  というか、Aの入力はでたらめでもN,Kの数で答えが決まる。

int main(){
    int N,K; cin >> N >> K;
    int ans;
    int tmp;
    while(true){
        if(tmp == 0){
            ans++;
            tmp += K;
        }
        else{
            ans++;
            tmp += K-1;
        }
        if(tmp >= N)break;
    }
    cout << ans << endl;
}