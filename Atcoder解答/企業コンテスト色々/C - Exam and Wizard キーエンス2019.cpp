#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N;cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    vector<int> dif(N);
    LL minsum = 0;
    int ct = 0;
    LL ctsum = 0;
    bool ok = true;
    rep(i,N){
        ctsum += (A[i] - B[i]);
        dif[i] = A[i] - B[i];
        if(dif[i] < 0){
            ok = false;
            minsum += dif[i];
            ct++;
        }
    }

    sort(rall(dif));


    if(ctsum < 0){
        cout << -1 << endl;
    }
    else if(ok){
        cout << 0 << endl;
    }
    else{
        rep(i,N){
            if(abs(minsum) >= dif[i])ct++;
            minsum += dif[i];
            if(minsum >= 0){
                ct++;
                break;
            }
        }
        cout << ct << endl;
    }
}

// C - Exam and Wizard	キーエンス２０１９