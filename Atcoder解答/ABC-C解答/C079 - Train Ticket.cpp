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
    string S;cin >> S;
    int A,B,C,D;
    A = S[0] - '0';
    B = S[1] - '0';
    C = S[2] - '0';
    D = S[3] - '0';
    int op1,op2,op3;
    char o1,o2,o3;
    string ans = "asd";
    int tmp;
    rep(i,2) rep(j,2) rep(k,2){
        if(i)op1 = 1,o1 = '+';
        else op1 = -1,o1 = '-';
        if(j)op2 = 1,o2 = '+';
        else op2 = -1,o2 = '-';
        if(k)op3 = 1,o3 = '+';
        else op3 = -1,o3 = '-';
        tmp = A+(op1*B)+(op2*C)+(op3*D);
        if(tmp == 7){
            ans[0] = o1;
            ans[1] = o2;
            ans[2] = o3;
        }
    }
    cout << S[0] <<ans[0] << S[1] << ans[1] << S[2] << ans[2] << S[3] << "=7" << endl;
}   

// 解説することはないです