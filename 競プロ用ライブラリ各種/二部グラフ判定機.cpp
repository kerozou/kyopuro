int BipartiteGraph(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> color(n, -1);
        int white_cnt = 0;
        function<bool (int, int, int)> dfs = [&](int u, int prev, int c) {
                color[u] = c;
                if (c == 1) white_cnt ++;
                for (auto v : g[u]) if (v != prev) {
                        if (color[v] == -1) {
                                if (!dfs(v, u, 1 - c)) return false;
                        } else if (color[v] != 1 - c) {
                                return false;
                        }
                }
                return true;
        };
        if (!dfs(0, -1, 0)) return -1;
        return white_cnt;
}

// 計算量O(|V|+|E|)
// 無向グラフの隣接リストgを投げて使う。
// 二部グラフでないときは、-1が帰ってくる。
// 二部グラフの時は、色を塗った時の片方の色の数が返ってくる。（全体から引けばもう一方になる？）

//https://www.learning-algorithms.com/entry/2018/01/28/152346
//より