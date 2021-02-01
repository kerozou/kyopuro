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
    string S;cin >> S;

    stack<int> st;
    int ct = 0;
    rep(i,S.size()){
        if(S[i] == '('){
            st.push(0);
        }
        else{
            if(st.empty()){
                ct++;
            }
            else{
                st.pop();
            }
        }
    }
    rep(i,ct){
        cout << '('; 
    }
    rep(i,S.size()){
        cout << S[i];
    }
    rep(i,st.size()){
        cout << ')';
    }
}

// ABC064 	D - Insertion

// stack で（）を管理すればできる。
// http://drken1215.hatenablog.com/entry/2018/06/27/130200
// ここを見れば何言ってるかわかる