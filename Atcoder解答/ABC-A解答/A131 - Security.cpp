#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;

int main(){
    string S; cin >> S;
    string OK = "Good";
    rep(i,S.size()){
        if(i == 0)continue;
        if(S[i] == S[i-1])OK = "Bad";
    }
    cout << OK << endl;
}