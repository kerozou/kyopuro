// ダイクストラ法の簡単なやつ




typedef struct edge{
    int v;              // エッジの　終点　
    LL w;               // エッジの　重み　
    edge() {}                                             
    edge(int v, LL w) : v(v), w(w) {};          
} Edge;

vector<LL> dijkstra(int n, vector<vector<Edge> >& G, int s) {   // N , G , start (ノードは0-index)
    vector<LL> d(n, LLONG_MAX/10); d[s] = 0;                    
    priority_queue<pair<LL, int> > que;                        
    que.push(make_pair(0LL, s));                                           
    while (!que.empty()) {                                  
        auto p = que.top(); que.pop();                      
        int u = p.second;                                      
        LL  dist = -p.first;                                 
        if (dist > d[u]) continue;                           
        for (Edge e : G[u]) {                                
            if (d[e.v] > d[u]+e.w) {                         
                d[e.v] = d[u] + e.w;                          
                que.push(make_pair(-d[e.v], e.v));           
            }                                                 
        }
    }
    return d;                                                
}





/////////////////////////////////////




// 主な使い方としては、
   vector<vector<Edge>> G(N);  //で有向グラフを定義して
// 
   rep(i,X){
      int from,to; LL cost; 
      cin >> from >> to >> cost;
      G[from].emplace_back(to,cost);
   }