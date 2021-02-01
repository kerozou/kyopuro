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
    rep(k,t){
        string s;cin >> s;
        map<int,int> m;
        rep(i,s.size()){
            int c = s[i] - '0';
            m[c]++;
        }

        if(m.size() == 1){
            cout << s << endl;
        }
        else{
            vector<int> ans;
            int st = s[0] - '0';

            rep(i,s.size()){
                int y = s[i] - '0';

                if(i == s.size()-1){
                    
                    ans.push_back(y);
                    if(s[i] != s[i-1])break;
                    ans.push_back((2-y)/2);

                }
                
                ans.push_back(y);
                if(s[i] == s[i+1]){
                    ans.push_back((2-y)/2);
                }

            }
            for(auto p : ans)cout << p;
            cout << endl;
        }
    }
}