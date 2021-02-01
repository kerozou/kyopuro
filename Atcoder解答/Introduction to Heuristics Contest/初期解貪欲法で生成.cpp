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


LL getScore(int D,vector<LL> &c,vector<vector<LL>> &s, vector<LL> &con){
    LL score = 0;
    vector<LL> pre(D+1,0);
    for(int i = 1;i <= D;i++){
        score += s[i][con[i]];
        pre[con[i]] = i;
        for(int j = 1; j <= 26;j++)score -= (c[j] * (i - pre[j]));
    }
    return score;
}

void First(int D,vector<LL> &c,vector<vector<LL>> &s ,vector<LL> &con){
    // greedy
    vector<LL> pre(27,0);
    for(int i = 1;i <= D;i++){
        LL score = -9999999999;
        int num = 1;
        for(int j = 1;j <= 26;j++){
            LL tmp = s[i][j];
            for(int k = 1;k <= 26;k++){
                if(k == j)continue;
                else{
                    tmp -= (c[k]*(i-pre[k]));
                }
            }
            if(score < tmp){
                score = tmp;
                num = j;
            }
        }
        pre[num] = i;
        con[i] = num;
    }
}

int main() {
    int D;cin >> D;
    vector<vector<LL>> s(D+1,vector<LL>(27,0));
    vector<LL> c(27);
    vector<LL> con(D+1,0);

    for(int i = 1;i <= 26;i++)cin >> c[i];
    for(int i = 1;i <= D;i++)for(int j = 1;j <= 26;j++)cin >> s[i][j];
    

    First(D,c,s,con);
    for(int i = 1;i <= D;i++)cout << con[i] << endl;

    // for(int i = 1;i <= D;i++)cout << con[i] << endl;

}