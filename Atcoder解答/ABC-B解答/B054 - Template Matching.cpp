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

int N,M;
vector<string> A;
vector<string> B;

bool cal(int p,int q){
    bool ok = true;
    for(int i = 0;i < M;i++){
        for(int j = 0;j < M;j++){
            int a = p+i;
            int b = q+j;
            if(A[a][b] != B[i][j])ok = false;
        }
    }
    return ok;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    rep(i,N)cin >> A[i];
    rep(i,M)cin >> B[i];

    bool ans = false;
    for(int i = 0;i <= N - M;i++){
        for(int j = 0;j <= N - M;j++){
            if(cal(i,j))ans = true;
        }
    }

    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;
}


// ABC054 B054 - Template Matching

/*
    50*50*50*50 = 6.25 * 10^6   程度なので、全探索する。
    その際に、B行列がA行列の中にあるかどうかを与えられた始点から検索する関数を用意した。
    あとは、その関数を使って適切な始点の範囲を与えてあげればいい。
*/