// 木構造のDFS

// 基本はしたみたいに進めてく。
// こいつに足していく。

// ABC-D126 D - Even Relation
// ABC-D146 D - Coloring Edges on Tree
// あたりを参照するといい。



// v は現在見ている頂点, p は v の親
vector<vector<int>> G;

void dfs(int v, int p ) {
    for (auto nv : G[v]) {
      if (nv == p) continue;  // これがツリー探索で一般的な書き方
      dfs(nv, v);
    }
}

int main() {
  int root = 0;
  dfs(root, -1); // root の親はいないので -1
}


// Euler Tour
// v は現在見ている頂点, p は v の親
vector<vector<int>> G;

int MAX_N = 100000;
vector<int> g[MAX_N];
vector<int> euler;
int beg[2*MAX_N];
int en[2*MAX_N];
int ct_e = 0;

void dfs_Euler(int v, int p ) {
    beg[v] = ct_e;
    euler.push_back(v);
    ct_e++;
    for (auto nv : G[v]) {
      if (nv == p) continue;  // これがツリー探索で一般的な書き方
      dfs_Euler(nv, v);
      euler.push_back(v);
      ct_e++;
    }
    en[v] = ct_e;
}













// ABC-D 126 EvenRelation より DFSの描き方例

using Graph = vector<vector<pair<int,LL>> >;
Graph G;
vector<LL> dis;

// v は現在見ている頂点, p は v の親
void dfs(int v, int p ,LL sum) {
    dis[v] = sum;
    if(G[v].size() == 1 && v != 0)return;   // v != 0 を忘れると、スタート時点で一本しか道が無い時に積む
    for (auto nv : G[v]) {
        if (nv.F == p) continue;  // これがツリー探索で一般的な書き方
        dfs(nv.F, v, sum + nv.S);
    }
}