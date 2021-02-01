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

int main(){
    map<LL,LL> L;
    LL tmp;
    int N;cin >> N;
    rep(i,N){
        cin >> tmp;
        L[tmp]++;
    }  
    LL ans = 0;
    for(auto itr = L.begin();itr != L.end();itr++){ 
        LL key = itr -> first;
        LL value = itr -> second;
        if(key > value)ans += value;
        else ans += value - key;
    }
    cout << ans << endl;
}

// ABC082 C - Good Sequence
//　・ある数 ｘ の個数が x 未満の時は全部排除。 個数が ｘ 以上の時は その個数 - x で取り除く数が決まる。

// これを実装するときに、vectorに格納したいところだが、vector だと、存在しない数字の配列とかを考えるのが面倒くさそうなので、mapで実装するとよい。
// vector で実装すると、L[i] = empty　の時の分岐とかでメモリぶっ壊れそう。