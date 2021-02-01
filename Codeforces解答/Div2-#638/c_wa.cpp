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
    int t;cin >> t;
    rep(l,t){
        int n,k;cin >> n >> k;
        string s;cin >> s;
        sort(all(s));
        map<char,int> m;
        int lim = s.size();
        rep(i,lim)m[s[i]]++;
        vector<int> num(lim);
        num[0] = 1;
        rep(i,lim-1){
            if(s[i] != s[i+1]){
                num[i+1] = num[i] + 1;
            }
            else{
                num[i+1] = num[i];
            }
        }
   

        if(k == 1)cout << s << endl;
        else{
            if(s[k-2] == s[k-1]){
                if(m.size() == 1){
                    rep(i,(n+k-1)/k)cout << s[0];
                    cout << endl;
                }
                else if(m.size() == 2){
                    char c = m.begin() -> F;
                    char e = m.end() -> F;
                    for(auto i = m.begin();i != m.end();i++){
                        if(i == m.begin())continue;
                        e = i -> F;
                    }

                    if(m[c] > k){
                        rep(j,m[c]-k+1)cout << c;
                        rep(j,m[e])cout << e ;
                        cout << endl;
                    }
                    else{
                        cout << c;
                        rep(j,(m[e]+k-1)/k)cout << e;
                        cout << endl;
                    }
                }
                else{
                    if(num[k-1] >= 2)cout << s[k-1] << endl;
                    else{
                        for(int j = k-1;j < lim;j++){
                            cout << s[j];
                        }
                        cout << endl;
                    }
                }
            }
            else{
                cout << s[k-1] << endl;
            }
        }
    }
}