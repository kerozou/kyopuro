// 二分探索の知識と使い方

// 二分探索とは解の存在範囲を狭めていくことで最適解を求める手法である。

// 1.lower_boundとupper_bound
//    lower_boundとupper_boundはC++のSTLライブラリの関数なのじゃ…
//    俗に言う二分探索に似たやつなのじゃ…
//    違いとしては

        lower_boundは、探索したいkey以上のイテレータを返す
        upper_boundは、探索したいkeyより大きいイテレータを返す
//    という点なのじゃ…

// 2. binary_search
// 　   binary_searchは一番シンプルな二分探索じゃの…
//　    ソートされた配列やvectorの中に、keyがあるかどうかを探索するのじゃ…
//　    関数の返り値はbool値であり
        ・keyがあるかどうかは分かる
      　・しかし、どこにkeyがあるのか分からない
      　・さらに、同じ値のkeyが複数あったとき、どのkeyを指しているのか分からない
//    　という特徴があるのじゃ…
　
//  　  lower_boundとupper_boundは、この欠点を補った二分探索というわけじゃな…
//　    ただ、keyがあるかどうかだけを調べたいんじゃったら、binary_searchだけでいいのじゃ…


//　lower_bound の使用例

#define ALL(a)  (a).begin(),(a).end()

int main() {

    //ソートする必要があるのじゃ…
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto Iter1 = lower_bound(ALL(a), 4);
    auto Iter2 = lower_bound(ALL(a), 6);
    auto Iter3 = lower_bound(ALL(a), 7);
    auto Iter4 = lower_bound(ALL(a), 19);
    auto Iter5 = lower_bound(ALL(a), 20);

    //値の表示
    cout << "----------value----------" << endl;
    cout << "Iter1 = " << *Iter1 << endl; //Iter1 = 4
    cout << "Iter2 = " << *Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << *Iter3 << endl; //Iter3 = 7
    cout << "Iter4 = " << *Iter4 << endl; //Iter4 = 19
    cout << "Iter5 = " << *Iter5 << endl; //Iter5 = 1326115891

    //先頭からの距離
    cout << "----------from----------" << endl;
    cout << "Iter1 = " << Iter1 - a.begin() << endl; //Iter1 = 1
    cout << "Iter2 = " << Iter2 - a.begin() << endl; //Iter2 = 3
    cout << "Iter3 = " << Iter3 - a.begin() << endl; //Iter3 = 3
    cout << "Iter4 = " << Iter4 - a.begin() << endl; //Iter4 = 9
    cout << "Iter5 = " << Iter5 - a.begin() << endl; //Iter5 = 10

    //末尾までの距離
    cout << "----------to----------" << endl;
    cout << "Iter1 = " << a.end() - Iter1 << endl; //Iter1 = 9 
    cout << "Iter2 = " << a.end() - Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << a.end() - Iter3 << endl; //Iter3 = 7
    cout << "Iter4 = " << a.end() - Iter4 << endl; //Iter4 = 1
    cout << "Iter5 = " << a.end() - Iter5 << endl; //Iter5 = 0

    return 0;
}


////////

// lower_bound の性質

    lower_boundのイテレータから先頭のイテレータを引くと、あるkeyより小さい要素の個数を求めることができる。
    末尾のイテレータからlower_boundのイテレータを引くと、あるkey以上の要素の個数を求めることができる。

//////

// 二分探索実装例

//入力
int n,k;
int a[MAX_N];

int main(){
    //解の存在範囲を初期化
    int lb = -1,ub =n;

    //解の存在範囲が1より大きい間、繰り返す
    while (ub-lb > 1){
        int mid = (lb + ub)/2;
        if(a[mid] >= k){
                //midが条件を満たせば、解の存在範囲は(lb,mid]
            ub = mid;
        }
        else{
            //midが条件を満たさなければ、解の存在範囲は(mid,ub]
        }
    }

    cout << ub << endl;
}

/////
// このような手法を二分探索と呼び、STLにはlower_boundという関数として含まれている。
// この手法は今回のようなソート列からの値の検索以外にも、最適解を求める問題において非常に有用。

// ある条件C(x)を満たすような最小のxを求めよという問題を考える。
// あるxがC(X)を満たすとき、
　　すべての　x">=x　がC(x")を満たす
// ならば同じく二分探索を用いて最小のｘを求めることが可能。
// この場合、区間の下端 lb を条件C(x)を満たさない値に、上端 ub を条件C(x)を満たす値にそれぞれ初期化し、
// 解の存在範囲　(lb,ub]　が十分に小さくなるまで、中央の値 mid=(lb+ub)/2 が　条件C(mid)　を満たすかどうか判定して存在範囲を狭めていく。

// 最終的に、ubが求めたい最小の値となる。最大化問題でも同様に行うことができる。

つまり、二分探索で条件関数をクリアする問題では、
1. クリアするべき条件をC(x)としてxを含む形にする。
2. C(x)を数式もしくはスクリプトで表す。
3. C(x)をbool関数として、実装しておいて、if(C(mid))として判定していく。
4. 実際には
        if(C(mid))lb=mid;
        else ub = mid;
   とすればよい。（細かい設定は変わるが）

以下に蟻本にのってる問題Cable Masterを解く。

問題
　長さがそれぞれ　Li　であるような　N　本のひもがあり、これらのひもを切って同じ長さのひもをK本作るときの最長の長さを求めなさい。答えは小数点以下2桁まで切り捨てる。

//C(x):= 長さｘの紐をK本切り出せる。　→　(floor(Li/x)の総和がK以上）
//C(x)を満たすxの最大値を求める問題に帰結する。

//入力
int N,K;
double L[Max];

//条件判定関数
bool C(double x){               //      C(x)関数
        int num = 0;
        rep(i,N)num += floor(L[i]/x);
        return num >= x;
}

int main(){
        //解の存在範囲の初期化
        double lb = 0,ub = INF;         //      -1,INFとかでもいいし、-1,1000000とかでもいい

        //解の存在範囲が十分に狭くなるまで繰り返す
        rep(i,100){
                double mid = (lb + ub)/2;       // 1LL << 60 が10^18とかなので、2^100回はとんでもなくデカく、100回も繰り返しとけば十分.なんなら1000回くらいやってもいいぞ
                if(C(mid))lb = mid;             // mid がtrueだったら、midよりも大きいxが存在するかもしれないので、midをlbに設定するということ。
                else ub = mid;                  // 逆にmidが通らなかったら、それ以上のxはすべて通らないことになるので、ubにセットするということ。
        }
        cout << ub << endl;
}

// 結局、二分探索が可能になるためには、境界条件配列内に一つしか存在しないことが必要。
// なので、単調性が担保されないとならないので、配列はソート済みでなければならない。

・二分探索の収束判定

・STD　binary_search
// first, last はソートした配列のイテレータ
// key は検索したい数値
std::binary_search(first, last, key)

std::lower_bound　と std::upper_bound をもっと使おう