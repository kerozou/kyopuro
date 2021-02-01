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

    ///// グローバル

    int dp[4] = {0,-1,0,1};
    int dq[4] = {-1,0,1,0};

    int ep[8] = {-1,-1,-1,0,1,1,1,0};
    int eq[8] = {-1,0,1,1,1,0,-1,-1};

    int width; // size of the grid
    int height; // top left corner is (x=0, y=0)
    int mypaclim;   // ローカルのlim を保存
    int now_time;   // 現在の経過ターン数
    

    vector<string> fie; // マップ情報
    vector<pair<int,int>> mp;   // 歩行可能マス
    vector<bool> p_received(10,false);  // パックマンが指示を貰っているか true で貰ってる
    vector<pair<int,int>> p_destination(10,{-1,-1});    // パックマンの目的地
    vector<vector<bool>> peret_my_checked(100,vector<bool>(100,true));  // 見たペレットの情報
    pair<int,int> nex;  //  dfsで見つけた座標を返すときの変数
    vector<queue<pair<int,int>>> dfs_queue(10);


    // 前回のパックマン達
    vector<int> b_y(10,0);
    vector<int> b_x(10,0);
    vector<string> b_type(10,"");
    vector<int> b_speedTurn(10,0);
    vector<int> b_abicool(10,0);
    vector<int> b_dir(10,-1);
    vector<bool> b_collision(10,false);
    ///////




    /////


int make_direction(int id,vector<int> &p_y,vector<int> &p_x){
    // パックマンの現在向いている方向を返す     方角はdp,dqと同じ
    int t_p = p_y[id] - b_y[id];
    int t_q = p_x[id] - b_x[id];
    int dir = b_dir[id];
    rep(j,4)if(t_p == dp[j] && t_q == dq[j])dir = j;
    return dir;
}
    
bool check_collision(int id,vector<int> &p_y,vector<int> &p_x){
    // パックマンが現在衝突中かどうかを判定 true で衝突中
    if(b_y[id] == p_y[id] && b_x[id] == p_x[id])return true;
    else return false;
}

pair<int,int> get_rn_pos(){
    // 歩行可能マスの座標を一つランダムで返す
    int sz = mp.size();
    int rn = rand() % sz;
    return {mp[rn]};
}


////// cout コマンド
void move(int id, pair<int,int> pos){
    // MOVEコマンド　pos にはget_rn_pos() 辺りをいれとくと便利
    cout << "MOVE " << id << " " << pos.S << " " << pos.F << "|";
    p_received[id] = true;
    p_destination[id] = pos;
}

void speed(int id){
    // SPEEDコマンド
    cout << "SPEED " << id << "|";
    p_received[id] = false;
}

void hand_change(int id, string hand){
    // SWITCHコマンド
    cout << "SWITCH " << id << " " << hand << "|";
}

///////


bool check_received(int id,vector<int> &p_y,vector<int> &p_x){
    // 指示が終わっているかどうかを返す
    if(p_destination[id].F == p_y[id] && p_destination[id].S == p_x[id])return true;
    else return false;
}


pair<int,int> search_peret(int id,vector<int> &p_y,vector<int> &p_x,vector<vector<bool>> &peret){
    // パックマンの前方・左右のペレットをサーチする なかった場合 {0,0}を返す
    int ny = p_y[id];
    int nx = p_x[id];

    pair<int,int> ans = {ny,nx};

    rep(i,4){
        if(0 <= ny+dp[i] && ny+dp[i] < height && 0 <= nx+dq[i] && nx+dq[i] < width){
            if(peret[ny+dp[i]][nx+dq[i]])return {ny+dp[i],nx+dq[i]};
        }
        else if(nx+dq[i] == -1){
            if(peret[ny+dp[i]][width-1])return {ny+dp[i],width-1};
        }
        else if(nx+dq[i] == width){
            if(peret[ny+dp[i]][0])return {ny+dp[i],0};
        }
    }

    return ans;
}



void dfs(int p,int q,int prp,int prq,int n,int ct,int &ma,const vector<vector<bool>> &pnow,vector<vector<bool>> &pb,map<pair<int,int>,bool> &pac_exist,int dir,queue<pair<int,int>> que,int id){
    // <y座標,x座標,一個前のy,一個前のx,何回目か,得点,現在の最高得点,ペレットのマップ,デカペレットのマップ,パックマンの存在マップ,最初に向いてる方向,dfs_queue,id>
    // dfsで一番ポイントが溜まる順路を選ぶ.
    // 途中でパックマンがいたらそのルートは使わない。
    // デカ玉を優先する。
    if(n == 5){     
        if(ma < ct){
            ma = ct;
            dfs_queue[id] = que;
            nex = {p,q};
        }
        return;
    }

    queue<pair<int,int>> nque = que;

    rep(i,4){
        int np = p+dp[i];
        int nq = q+dq[i];
        int dirp = dp[(dir+2)%4];
        int dirq = dq[(dir+2)%4];
        if(n == 0)if(p + dirp == np && q + dirq == nq)continue;
        if(np == prp && nq == prq)continue;
        if(n >= 2)if(pac_exist[{np,nq}])continue;
        if(fie[np][nq] == '#')continue;
        if(0 <= np+dp[i] && np+dp[i]  < height && 0 <= nq+dq[i] && nq+dq[i]  < width){
            int point = ct;
            if(pnow[np][nq]){
                point++;
                if(pb[np][nq])point += 20;
            }
            if(ma < point){
                ma = point;
                nex = {p,q};
            }
            nque.push({np,nq});
            dfs(np,nq,p,q,n+1,point,ma,pnow,pb,pac_exist,dir,nque,id);
        }
    }

}

void dfs_bigperet(int p,int q,int prp,int prq,int n,int ct,int &ma,const vector<vector<bool>> &pnow,vector<vector<bool>> &pb,map<pair<int,int>,bool> &pac_exist,int dir,queue<pair<int,int>> que,int id){
    // <y座標,x座標,一個前のy,一個前のx,何回目か,得点,現在の最高得点,ペレットのマップ,デカペレットのマップ,パックマンの存在マップ,最初に向いてる方向,dfs_queue,id>
    // デカ玉を優先する。
    if(n == 10){     
        if(ma < ct){
            ma = ct;
            nex = {p,q};
        }
        return;
    }

    if(ct >= 20){
        if(ma < ct){
            ma = ct;
            nex = {p,q};
        }
        return;        
    }
    queue<pair<int,int>> nque = que;

    rep(i,4){
        int np = p+dp[i];
        int nq = q+dq[i];
        int dirp = dp[(dir+2)%4];
        int dirq = dq[(dir+2)%4];
        if(n != 0)if(p + dirp == np && q + dirq == nq)continue;
        if(np == prp && nq == prq)continue;
        if(fie[np][nq] == '#')continue;
        if(0 <= np+dp[i] && np+dp[i]  < height && 0 <= nq+dq[i] && nq+dq[i]  < width){
            int point = ct;
            if(pb[np][nq])point += 20;
            dfs_bigperet(np,nq,p,q,n+1,point,ma,pnow,pb,pac_exist,dir,nque,id);
        }
    }

}

int get_distance(int id1,int id2,vector<int> &p_y,vector<int> &p_x){
    // 2者の距離を測る
    int p1 = p_y[id1];
    int p2 = p_y[id2];
    int q1 = p_x[id1];
    int q2 = p_x[id2];
    int tmp = abs(p1-p2) + abs(q1-q2);
    return tmp;
}


string check_enemy(int id,vector<int> &p_y,vector<int> &p_x,vector<string> &p_type,vector<int> &ene_pac_id){
    // 3マス圏内に敵がいたら敵のhandを返す
    int sz = ene_pac_id.size();
    rep(i,sz){
        int tmp = get_distance(id,ene_pac_id[i],p_y,p_x);
        if(tmp <= 3){
            nex = {p_y[ene_pac_id[i]],p_x[ene_pac_id[i]]};
            return p_type[ene_pac_id[i]];
        }
    }
    return "NONE";
}


int main()
{

    cin >> width >> height; cin.ignore();

    
    fie.resize(height);         // マップ情報


    // マップの入力
    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        fie[i] = row;
        rep(j,row.size()){
            if(row[j] == ' ')mp.push_back({i,j});
        }
    }


    // 全パックマンの情報達
    vector<int> p_y(10,0);
    vector<int> p_x(10,0);
    vector<string> p_type(10,"");
    vector<int> p_speedTurn(10,0);
    vector<int> p_abicool(10,0);
    vector<int> p_dir(10,-1);
    vector<bool> p_collision(10,false);
    

    ////// 初期化処理

    rep(i,10)p_destination[i] = get_rn_pos();

    

    // game loop
    while (1) {

        ////// while内ローカル変数宣言
        vector<int> my_pac_id;      //  自機パックマンのid
        vector<int> ene_pac_id;     //  敵パックマンのid
        vector<vector<bool>> peret(height,vector<bool>(width,false));   // peretの位置
        vector<pair<int,int>> big_peret;    // superperet の位置
        vector<vector<bool>> big_peret_bool(height,vector<bool>(width,false));  // superperet の位置のbool表
        int lim = 0;    // 自機の数
        map<pair<int,int>,bool> pac_exist;


        ////// グローバル初期化
        mypaclim = 0;
        


        //////  スタンバイフェイズ
        now_time++;
        


        //////  スコア等入力

        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();


        ///////  パックマン情報入力

        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();

            p_y[pacId] = y;
            p_x[pacId] = x;
            p_type[pacId] = typeId;
            p_speedTurn[pacId] = speedTurnsLeft;
            p_abicool[pacId] = abilityCooldown;

            peret_my_checked[y][x] = false;
            pac_exist[{y,x}] = true;
            
            if(mine){
                lim++;      //  自機カウント
                my_pac_id.push_back(pacId);
            }
            else{
                ene_pac_id.push_back(pacId);
            }
            
        }


        //////   ペレット情報入力


        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
            peret[y][x] = true;
            if(value == 10){
                big_peret.push_back({y,x});
                big_peret_bool[y][x] = true;
            }
        }


        ///// メインフェイズ
        rep(i,lim){
            p_dir[my_pac_id[i]] = make_direction(my_pac_id[i],p_y,p_x);
            p_collision[my_pac_id[i]] = check_collision(my_pac_id[i],p_y,p_x);
            if(check_received(my_pac_id[i],p_y,p_x))p_received[my_pac_id[i]] = false;

            // if 周囲にペレットが落ちてたらそっちに向かう 
            pair<int,int> pp = search_peret(my_pac_id[i],p_y,p_x,peret);
            if(pp.F != p_y[my_pac_id[i]] || pp.S != p_x[my_pac_id[i]]){
                p_destination[my_pac_id[i]] = pp;
                p_received[my_pac_id[i]] = true;
            }

            // もろもろの情報
            int ma = 0;
            int dir = p_dir[my_pac_id[i]];
            int ny = p_y[my_pac_id[i]];
            int nx = p_x[my_pac_id[i]];
            queue<pair<int,int>> tmp_q;

            // 現在地からdfsして最もポイントが高くなる場所へ向かう
            if(dfs_queue[my_pac_id[i]].size() < 2){          
                dfs(ny,nx,ny,nx,0,0,ma,peret_my_checked,big_peret_bool,pac_exist,dir,tmp_q,my_pac_id[i]);
                if(dfs_queue[my_pac_id[i]].empty() > 2){
                    p_destination[my_pac_id[i]] = dfs_queue[my_pac_id[i]].front();
                    dfs_queue[my_pac_id[i]].pop();
                    p_received[my_pac_id[i]] = true; 
                }
            }
            else{
                p_destination[my_pac_id[i]] = dfs_queue[my_pac_id[i]].front();
                dfs_queue[my_pac_id[i]].pop();
                p_received[my_pac_id[i]] = true;                 
            }

            // bigperetが落ちてたら最優先で向かう
            dfs_bigperet(ny,nx,ny,nx,0,0,ma,peret_my_checked,big_peret_bool,pac_exist,dir,tmp_q,my_pac_id[i]);
            if(ma != 0){
                p_destination[my_pac_id[i]] = nex;
                p_received[my_pac_id[i]] = true;  
                while(!dfs_queue[my_pac_id[i]].empty())dfs_queue[my_pac_id[i]].pop();
            }

            // 衝突していたら命令キャンセル
            if(p_collision[my_pac_id[i]])p_received[my_pac_id[i]] = false;

            
        }



        /////  現在のパックマン情報 を 過去のパックマン情報 に渡して更新
        rep(i,1){
            b_y = p_y;
            b_x = p_x;
            b_type = p_type;
            b_speedTurn = p_speedTurn;
            b_abicool = p_abicool;
            b_dir = p_dir;
            b_collision = p_collision;
        }


        ///////   エンドフェイズ
        if(now_time % 300 == 0){
            // 100回に一回SPEED
            rep(i,lim){
                if(p_abicool[my_pac_id[i]] == 0)speed(my_pac_id[i]);
                else{
                    if(p_speedTurn[my_pac_id[i]] == 5){
                        move(my_pac_id[i],p_destination[my_pac_id[i]]);
                    }
                    else{
                        if(!p_received[my_pac_id[i]]){
                            pair<int,int> dispos = get_rn_pos();
                            rep(j,3){
                                if(peret_my_checked[dispos.F][dispos.S])break;
                                dispos = get_rn_pos();
                            }
                            move(my_pac_id[i],dispos);
                        }
                        else move(my_pac_id[i],p_destination[my_pac_id[i]]);
                    }
                }
            }
        }
        else{
            // 敵が周囲にいたらSWITCHして、いなかったら目標へ向かう。目標がなかったらランダムで目標をセット。
            rep(i,lim){
                string tmp = check_enemy(my_pac_id[i],p_y,p_x,p_type,ene_pac_id);
                if(tmp != "NONE" && p_abicool[my_pac_id[i]] == 0){
                    p_destination[my_pac_id[i]] = nex;
                    p_received[my_pac_id[i]] = true; 
                    if(tmp == "ROCK")hand_change(my_pac_id[i],"PAPER");
                    if(tmp == "PAPER")hand_change(my_pac_id[i],"SCISSORS");
                    if(tmp == "SCISSORS")hand_change(my_pac_id[i],"ROCK");
                }
                else if(p_speedTurn[my_pac_id[i]] == 5){
                    move(my_pac_id[i],p_destination[my_pac_id[i]]);
                }
                else{
                    if(!p_received[my_pac_id[i]]){
                        pair<int,int> dispos = get_rn_pos();
                        rep(j,3){
                            if(peret_my_checked[dispos.F][dispos.S])break;
                            dispos = get_rn_pos();
                        }
                        move(my_pac_id[i],dispos);
                    }
                    else move(my_pac_id[i],p_destination[my_pac_id[i]]);
                }
            }
        } 

        cout << endl;

    }
}


// 変更点
/*
    ・パックマンは基本的にDFSで動く。
    ・デカいペレットをみつけると問答無用で拾いに行く。
    ・後方にはdfsしない。
    ・他のパックマンがdfs進路上にいたら行かない。
    ・DFS先までの経路をqueueに入れておいて、最短で行くべきでないところを最短で行かないように制御する。
*/