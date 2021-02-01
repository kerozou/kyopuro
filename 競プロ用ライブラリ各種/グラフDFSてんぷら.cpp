// グラフDFSテンプレ
#include <iostream>
#include <vector>
using namespace std;


//  seen: その頂点を検知済みかどうかを表す配列
//  todo: 検知したがまだ訪問済みでない頂点の集合 (保留中の頂点の集合)

/* 
    1   seen 全体を false に初期化して、todo を空にする
    2   seen[s] = true として、todo に s を追加する
    3   todo が空になるまで以下を繰り返す:
　  4   todo から一つ頂点を取り出して v とする
　  5   T(v) の各要素 w に対して、
　  6   seen[w] = true であったならば、何もしない.
    7   そうでなかったら、seen[w] = true として、todo に w を追加する

*/

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        //  ここに処理を挟むと思われる

        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);  //有向グラフの際にはこの行を消せばおｋ
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}