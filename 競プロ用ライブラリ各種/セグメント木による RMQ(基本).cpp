// セグメント木による RMQ : Renge Minimam Query

// RMQ とは配列のある区間内の最小値を求める問題のこと。


// セグ木RMQ で できること
/*
    ・segch()  : 区間上の値を更新 O(logN)
    ・getq() : 任意の区間上の最小値を取得する O(logN)
*/

// 下記ライブラリの  [  //**  ] 部分の min を max に帰れば最大を取れる。
// 他にも、この部分をいじれば色々作れそう。


// ※注意
// 求める範囲は [a,b) と半開区間になっているので、queryは[a,b+1) とすること

// getq_sub()　の区間推移は実際に数直線を書いてみて区間をスライドさせてみると分かりやすい。
// クエリに与える区間[a,b)は元の配列のindex (0-index)
// 「配列」と「セグ木」の表現を間違えないように



int n;              // 配列サイズ
vector<LL> seg;     // セグ木

void segch(int i,int x){    // 配列i番目要素をxに変更
    i += (n-1);
    seg[i] = x;
    while(i > 0){
        i = (i-1)/2;
        seg[i] = min(seg[2*i+1],seg[2*i+2]);    //**
    }
}

LL getq_sub(int a,int b,int k,int l,int r){ 
    // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
    if(r <= a || b <= l)return INF;             //**
    else if(a <= l && r <= b)return seg[k];     
    else{                                       
        int ind = (l+r)/2;
        int vl = getq_sub(a,b,2*k+1,l,ind);
        int vr = getq_sub(a,b,2*k+2,ind,r);
        return min(vl,vr);                      //**
    }
}


LL getq(int a,int b){     // [a,b) の区間でminを返す
    return getq_sub(a,b,0,0,n);
}








int main() {

    // 入力　__ 配列サイズn と 配列A
    cin >> n;
    vector<LL> A(n);rep(i,n)cin >> A[i];

    // 配列の要素数を 2^x 個にするためにINFで埋める  
    rep(i,32){
        if(n <= pow(2,i)){
            n = pow(2,i);
            break;
        }
    }
    int st = A.size();
    for(int i = st;i < n;i++)A.push_back(INF);

    // seg木の配列初期化
    seg.resize(2*n-1);rep(i,2*n-1)seg[i] = INF; //**
    rep(i,n)segch(i,A[i]);

    // query 入手
    int i,x;cin >> i >> x;      // i は操作を加えるAのindex     x は代入する値

    // 実行
    segch(i,x);

    // 区間最小を求める exp..min[a,b) = [2,5)の最小
    int a = 2;
    int b = 5;
    LL ans = getq(a,b);



    cout << ans << endl;

}