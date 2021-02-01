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
    int T;cin >> T;
    int N;cin >> N;
    vector<int> A(N);rep(i,N)cin >> A[i];
    int M;cin >> M;
    vector<int> B(M);rep(i,M)cin >> B[i];
    sort(all(A));
    sort(all(B));

    int num = 0;
    vector<bool> ok(N,false);

    vector<pair<int,int>> pA(N);
    rep(i,N){
        pA[i] = {A[i],A[i] + T};
    }

    bool ans = true;

    rep(i,M){
        bool um = true;
        rep(j,N){
            if(ok[j])continue;
            int tmp = B[i];
            if(pA[j].F <= tmp && tmp <= pA[j].S){
                ok[j] = true;
                um = false;
                break;
            }
        }
        if(um)ans = false;
    }

    if(ans)cout << "yes" << endl;
    else cout << "no" << endl;


}


// ABC005 C - おいしいたこ焼きの売り方

/*
    たこ焼きを売るだけ
*/