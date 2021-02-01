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
    // 入力
    int N;cin >> N;
    vector<string> S(N);
    rep(i,N)cin >> S[i];

    // 頭文字の人数カウント
    vector<LL> ct(5);
    rep(i,N){string X = S[i];if(X[0] == 'M')ct[0]++;}
    rep(i,N){string X = S[i];if(X[0] == 'A')ct[1]++;}
    rep(i,N){string X = S[i];if(X[0] == 'R')ct[2]++;}
    rep(i,N){string X = S[i];if(X[0] == 'C')ct[3]++;}
    rep(i,N){string X = S[i];if(X[0] == 'H')ct[4]++;}

    // 答えの取得
    LL ans;
    rep(i,3) for(LL j = i+1;j < 4;j++) for(LL k = j+1;k < 5;k++) ans+= ct[i]*ct[j]*ct[k];

    // 出力
    cout << ans << endl;
}

// ABC089 C - March 
// ・MARCHを頭文字に持つ人を3人選ぶ。つまり、5C3通りそれぞれの頭文字を持つ人の数の積を和にとる。

// 1. Sの配列をつくる。
// 2. それぞれの頭文字を持つ人数を取得。
// 3. 頭文字が重複しないようにループをとって、それぞれのカウント数の積を算入する。

// 注意として、int*int*int = int として計算されてしまうので、明らかにintの域を出ない人数カウント配列もLLで定義する必要がある。（1敗）