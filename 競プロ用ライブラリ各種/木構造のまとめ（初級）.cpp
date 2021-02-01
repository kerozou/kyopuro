// 木構造　根付き木の表現

// 細かい定義
// 同じ親を持つ子同士を 兄弟 と呼び、節点の 深さ とは親を0としたときの世代番号のこと。木の 高さ とは、深さの最大値の事。子の数を次数という。

     u の節点番号
     u の節点の種類（根、内部ノードまたは葉）
     u の親の節点番号
     u の子のリスト
     u の深さ

// 以上を調べることができるテンプレをつくる。

// まずは入力されたデータを、各節点が以下のような情報を持つように整理する。

    ・節点 u の親ノード
    ・節点 u の最も左の子(left)
    ・節点 u のすぐ右の兄弟(right)

// これらは構造体を使うことで表せる

struct Node {
    int parent;     //・節点 u の親ノード
    int left;       //・節点 u の最も左の子(left)
    int right;      //・節点 u のすぐ右の兄弟(right)
    int end;        //・節点 u 子の一番右の兄弟
}node;    //node と書けば、struct Node　を省略できる。

// parent とか　left とか　面倒になってきたら p,l,r　でよい。

// 各節点の親は u.parent を参照することで知ることができる。
// 親が存在しないとき、uは　根　になる。
// また、 u.left が存在しないと節点が　葉　となり、u.right が存在しない節点が最も右の子になる。

// 親、左の子、右の兄弟が存在しないことを示すために、設定する節点番号として、NILを使用する。
// NILは、節点として選ばれることのない数字を与えておく。例えば-1など。

// 各節点の深さを求めるアルゴリズム

int NIL = -1;                   // NILはグローバルでセットしとく。
vector<node> T(節点数);         // T は　構造体Node　を型にもつ配列。　つまり、木のこと。   注意として、u　自体はintで、T[u]のuがNodeとしてカウントされることに注意。
void GetDepth(int u,int &d){    // u は節点番号、d は深さ
    d = 0;
    while(T[u].parent != NIL){  // T[u]には　節点番号u　が持つ親、左の子、右の兄弟の情報が入っているので、
        u = T[u].parent;        // 親を参照し続けて自らを親に更新して木を上り続ける。
        d++;                    // d は参照渡ししているので、呼び出し元のdにそのまま更新される。
    }
    return;
}

//

// また、あらかじめ深さリスト　D　を用意しておいて、いっぺんに全部のNodeの深さを取得する再帰関数も作れる。
// こちらのほうが作業的にも高速らしい。

int NIL = -1;  
vector<node> T(節点数); 
void SetDepth(int u,int p,vector<int> &D){     // u は節点番号、pは更新する値、Dは深さの配列
    D[u] = p;
    if(T[u].right != NIL)SetDepth(T[u].right,p,D);  // T[u]は配列の要素で、Nodeになっているが、T[u].rightはメンバなのでint。
    if(T[u].left != NIL)SetDepth(T[u].left,p+1,D);
}

// 上の再帰の場合、SetDepth(u = 0,0,D) として、使うといい。

// 子のリスト取得などは

void GetChildren(int u,vector<vector<int>> &CL){    // CLが子のリスト
    int c;
    if(T[u].left != NIL)c = T[u].left;
    else return;
    while(c != NIL){
        CL[u].push_back(c); 
        c = T[c].right;
    }
    return;
}

// で行えばよい。


// 入力に関して
// 木構造の入力に関しては
    N
    i k c1 c2 c3 .....      //i は番号、k は次数、cは子の番号
// と与えられるらしい
    int N;cin >> N; //Nはノードの数？
    vector<node> T(N);
    rep(i,N)T[i].parent = T[i].left = T[i].right = NIL;
// これで初期化。
// この後に、T[i]にc1～ckまでpush_backする。
// c1 だけT[i].left を更新して、各cごとにT[c].parent = i で更新して、T[i].left.right = c2 して、以降T[c]....とすればよさそうだけどわかりづらいからコードで

rep(i,N){   //入力
    cin << v << k;      // vは入力のiで、kはそのままk
    rep(j,k){
        cin << c;
        if(j == 0)T[v].left = c;
        else T[L].right = c;
        L = c;
        T[c].parent = v;
    }
}
int root;  // 根の番号
rep(i,N) if(T[i].parent == NIL)root = i;

// 上記のようにして木構造の入力ができるはず。

// ここまでで、螺旋本8章P,185~192　までをまとめてる。


// 20190818 ABC138-D をうけて
// 入力形式が（ai bi) のように二つのノードを与えられる形の時の入力をメモしておく

int main(){
    int N,Q;cin >> N >> Q;
    vector<struct Node> T;  // ノード入れ
    T.resize(N+1);

    rep(i,N+1)T[i].parent = T[i].left = T[i].right = NIL; // 初期化

    int tmp1,tmp2; // tmp1 は親、tmp2　は追加される子

    rep(i,N-1){     //  ノードの入力
        cin >> tmp1 >> tmp2;
        if(T[tmp1].left == NIL)T[tmp1].left = T[tmp1].end = tmp2;
        else{
            int c = T[tmp1].end;
            T[c].right = tmp2;
            T[tmp1].end = tmp2;
        }
        T[tmp2].parent = tmp1;  //　親登録
    }
}


// GetChildren について
// CL をリサイズして1次元まで作っておかないと死亡。
    vector<vector<int>> CL; //子リスト
    CL.resize(N+1); //これ大事
    for(int i = 1;i < N+1;i++)GetChildren(i,CL);  //子リスト取得
//


/////////////


////////////


////////////


木については、あまりこのへんを使わないほうがよさそう。
バグが出まくったり、実行が遅すぎたり、条件が多すぎる。

なので、基本はvectorで二次元配列を作って、無向グラフを作るために
    g[a].push_back(b);
    g[b].push_back(a);
を繰り返す。

そんで、木という特徴上、全域木中に登場するノードは必ず一意にきまるので、

//一例
void dfs(int p, int c, ll sum){
  val[c] += sum;
  for(auto v : g[c]){
    if(v!=p){                   // 親と同じものを選択することはできない。
      dfs(c, v, val[c]);        // 0から始まってたので、初めは0を親に設定。真ん中は次に進むノードを決めてそこでDFSする。
    }
  }
}

のように、for(auto v : g[c])　で上から順にループして、if(v!=p)　でたどってきた親と異なるかどうかをチェックするだけで、木の場合取りつくすことができてしまう。

なので、以降はこれを使うように。これの方が最速だし、バグもないはず。