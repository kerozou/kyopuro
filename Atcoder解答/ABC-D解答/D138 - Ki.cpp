#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[200005];
ll val[200005];

//入力段階では、単に頂点に値を足していって、最後にDFSで根からスタートして回答を一気につくる。

void dfs(int p, int c, ll sum){
  val[c] += sum;
  for(auto v : g[c]){
    if(v!=p){                   // 親と同じものを選択することはできない。
      dfs(c, v, val[c]);        // 0から始まってたので、初めは0を親に設定。真ん中は次に進むノードを決めてそこでDFSする。
    }
  }
}

int main(int argc, char *argv[]) {
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=0;i<q;i++){
    int p,x;cin>>p>>x;
    p--;
    val[p] += x;
  }
  dfs(-1, 0, 0);

  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    cout<<val[i];
  }
  cout<<endl;

  return 0;
}