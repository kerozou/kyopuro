#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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
    int N,M;cin >> N >> M;
    vector<LL> w(N);
    rep(i,N)cin >> w[i];
    vector<LL> l(M);
    vector<LL> v(M);
    rep(i,M)cin >> l[i] >> v[i];

    LL maxW = 0;
    rep(i,N)chmax(maxW,w[i]);

    bool ok = true;
    rep(i,M)if(maxW > v[i])ok = false;

    if(ok){
        map<LL,LL> cam_W;
        for(int bit = 0;bit < (1 << N);bit++){
            LL tmp = 0;
            rep(i,N){
                if(bit & (1 << i))tmp += w[i];
            }
            cam_W[bit] = tmp;
        }

        map<LL,LL> dist;
        for(int bit = 0;bit < (1 << N);bit++){
            LL tmp = 0;
            rep(i,M){
                if(cam_W[bit] > v[i]){
                    chmax(dist[bit],l[i]);
                }
            }
        }

        LL ans = INF;

        vector<int> per(N);
        rep(i,N)per[i] = i;
        do{
            vector<LL> dp(N+1,0);
            for(int i = 1;i <= N;i++){
                int bit = (1 << per[i]);
                for(int j = i-1;j >= 0;j--){
                bit |= (1 << per[j]);
                chmax(dp[i],dp[j] + dist[bit]);
                }
                
            }
            chmin(ans,dp[N-1]);
        }while(next_permutation(all(per)));

        cout << ans << endl;
    }
    else cout << -1 << endl;
    
}

// ARC105 C - Camels and Bridge

/*
    bit でラクダの団体を管理　→　順列でラクダ番号をピン立て　O(2^N)
    これを重さの和として、map等に入れて前処理　→　W(bit)　となる。

    重さの耐荷重が W(bit) 未満の橋の中で、長さが最大の者を dist(bit) として長さの和をmap化　O(2＾N　*　M)

    ここまで前処理

    この時、選んだラクダの集団の先頭と最後尾の距離 x[j] - x[i] は上記の条件より、ラクダが合体可能なことを考えると
    耐荷重を超える状態を作らないために x[j] - x[i] >= dist(bit) が常に満たされることになる。

    ここからdpに入る。
    dpを

        dp[i] := 先頭からi頭目のラクダの両短距離のmin　

    とするとdp[N]は

        ・dp[N-1] + dist[(N-1,N)]
        ・dp[N-2] + dist[(N-2,N-1,N)]
        ・dp[N-3] + dist[(N-3,N-2,N-1,N)]
        …
        ・dp[1] + dist[(1,2,3,....,N)]

    の最大値としてとれる。
    というのも、next_permutation で並べたラクダたちを見た時に
    i 頭目までの最適解は以下の各(i,j) の組の場合すべてが候補になるためである。

        j:[1~i] 頭目までの最適解　+ j 頭目から i 頭目までの dist(bit) 

    これをnext_permutation の各ループでdpで最適解を保存しつつ総当たりで調べることで、全体の最適解が分かるというわけである。

    dpは各next_permutationループ内で順に加算されるbitを用いて、
        
        dp[i] := chmax(dp[i],dp[j] + dist(bit))

    として求められる。

    全体の手順としては

        前処理　→　dp : next_permutation ループ　→　ラクダの頭数 i ループ　→　どのラクダからループするかの j ループ

    ででき、全体の計算量は O(2^N*M + N!*N^2) となり、256*10^5　~=　2.5*10^7 で間に合う。

        *補足
        i,jのループは、jの設定が上手い。
        i番目までのラクダを昇順に選びながらも、それ以降のj全てをbit立てしてdistを加算しているところが上手い。
        dpとperのindex が 1 と 0 でズレているから直感的になじまないが、きちんと辿るとよくわかる。

*/