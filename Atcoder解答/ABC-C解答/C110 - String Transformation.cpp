#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;

int main(){
    string S,T; cin >> S >> T ;
    map<char,char> mp,imp;
    bool ok = true;
    
    rep(i,S.size()){
        char s = S[i] , t = T[i];
        if(mp.count(s)) if(mp[s] != t) ok = false;
        if(imp.count(t)) if(imp[t] != s) ok = false;
        mp[s] = t;
        imp[t] = s;             
    }
    if(ok){
         cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}