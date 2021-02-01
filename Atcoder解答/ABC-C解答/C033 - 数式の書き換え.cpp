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
    string S;cin >> S;
    vector<int> num(S.size());
    vector<char> ope(S.size());
    rep(i,S.size()){
        if(i % 2 == 0)num[i/2] = S[i] - '0';
        else ope[(i-1)/2] = S[i];
    }
    ope[(S.size() - 1)/2] = 'e';
    int ct = 0;
    bool zero = false;
    rep(i,S.size()){
        if(ope[i] == '*'){
            if(num[i] == 0)zero = true;
        }
        else if(ope[i] == '+'){
            if(num[i] == 0)zero = true;
            if(!zero)ct++;
            zero = false;
        }
        else if(ope[i] == 'e'){
            if(num[i] == 0)zero = true;
            if(!zero)ct++;
            break;
        }
    }
    cout << ct << endl;
}

// 1+3*4*0 は　01234556 と index して
// vec num 0123
// vec ope 0123
// として格納。
// そんで、□　＋　□　＋　□　の各□内は＊しか存在せず（もしくは単一）、□の中に0がすでに含まれているかをチェックしていけばよいことがわかる。
// 流れは

// 1.□の検出
// 2.□内の0の検出　有→ctそのまま　無→ct++;
// 3.□の個数分ct++したらctを出力

// となる。
// あとは、opeが　*　+　e　の各時でifしてzeroフラグをその都度リセットしてあげればいい。
