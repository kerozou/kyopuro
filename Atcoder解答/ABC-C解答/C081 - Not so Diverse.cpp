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
    //入力
    int N,K;cin >> N >> K;
    map<int,int> L;         // <index、個数>
    rep(i,N){
        int c;cin >> c;
        L[c]++;
    }


    int ans = 0;
    vector<int> tmp;
    int mapsize = L.size();
    if(mapsize > K){        //  K種類より多い時
        int lim = mapsize - K;
        for(auto itr = L.begin();itr != L.end();itr++){ // map内にある数字の個数をとりあえず配列に入れてる。
            int value = (itr -> second);
            if(value)tmp.push_back(value);  //  個数が0の事はないので、これは省略してよい。
        }
        sort(all(tmp));     // 昇順に並べる
        rep(i,lim){
            ans += tmp[i];  // 小さい順に取り除いてけばおｋ
        }
        cout << ans << endl;
    }
    else {                  //  K種類より少ない時
        cout << 0 << endl;
    }

}

// ABC081 C - Not so Diverse
// ・K種類以下であれば0回の操作、K種類以上あれば個数の少ないものから順に書き換えていく。

// 0個の要素をカウントする必要がない時は、やはりmapやsetを扱うのが強い。
// 今回はある数xが現れる回数をカウントしておく必要があるので、mapを使う。