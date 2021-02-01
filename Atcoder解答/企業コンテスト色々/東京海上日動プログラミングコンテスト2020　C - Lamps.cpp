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

int N,K;
vector<int> A;


void imos(vector<int> &A){
    vector<int> tmp(N,0);
    rep(i,N){
        int left = max(0,i-A[i]);
        int right = min(N-1,i+A[i]);
        tmp[left]++;
        if(right+1<N)tmp[right+1]--;
    }
    rep(i,N-1)tmp[i+1] += tmp[i];
    A = tmp;
    return;
}

int main() {
    cin >> N >> K;
    A.resize(N);

    rep(i,N)cin >> A[i];
    
    K = min(K,50);
    rep(i,K)imos(A);

    rep(i,N)cout << A[i] << endl;

}

// 東京海上日動プログラミングコンテスト2020　C - Lamps

/*
    各電球 i が  left = i-A[i] から right = i + A[i] までを照らすという問題。
    このとき、[left,right] を電球の数だけ更新するので、imos法で一回分の操作をO(N)で行うことができる。
    
    ところで、imos法についてのメモ。
    imos法の考え方はBITに似ていて、imos研の説明の通り「1次元上に長方形を重ねていく」イメージである。
    上に書いてる void imos() を見てみれば何やってるかだいたい分かるはず。
    これが多次元でも応用できるらしい。
    今回は1次元のimosである。

    閑話休題。
    imos で1操作をO(N)でできるが、K <= 10^5 なので O(NK) は10^10になりそうな感じ。
    しかし、実際に操作してみると「一番溜まるのが遅いのが端っこ」であり、端っこもだいたい倍々で増えていく。
    0 * 40 個で試してみると

    1 : 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
    2 : 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 
    3 : 4 5 6 6 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 6 6 5 4 
    4 : 8 9 10 11 12 12 13 13 14 14 14 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 14 14 14 13 13 12 12 11 10 9 8 
    5 : 16 17 18 19 20 21 22 23 24 24 25 25 26 26 26 26 27 27 26 27 27 26 27 27 26 26 26 26 25 25 24 24 23 22 21 20 19 18 17 16 
    6 : 27 28 28 29 30 30 31 32 32 33 33 34 34 35 35 36 36 36 36 36 36 36 36 36 36 35 35 34 34 33 33 32 32 31 30 30 29 28 28 27 
    7 : 33 33 34 34 35 36 36 37 37 38 39 39 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 39 39 38 37 37 36 36 35 34 34 33 33 
    8 : 36 36 37 38 38 39 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 39 38 38 37 36 36 
    9 : 38 38 39 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 39 38 38 
    10 : 39 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 39 
    11 : 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 

    てな具合になり、倍々で増えていって、途中からゆるくなるのがわかる。
    これがO(logN)で収まる証明はちょっとできないけど、10^5 * 10^2 程度で収まるはずなので K = 100 くらいまでを操作すれば間に合う。
    実際、K=50 でクリアできた。

    https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
*/



