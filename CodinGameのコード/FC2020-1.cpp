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

struct dt{
    int id;
    string type;
    int d[4];
    int pri;
    int tome;
    int tax;
    bool cast;
    bool repeat;
};

struct inv{
    int in[4];
    int sc;
};

int main()
{

    int turnCount = 0;

    // game loop
    while (1) {
        int actionCount; // the number of spells and recipes in play

        cin >> actionCount; cin.ignore();
        vector<dt> actionList(actionCount);
        vector<inv> list(2);
        bool limitbreak = false;    // 呪文使わないと身動き取れなくなったときの保険
        
        turnCount++;

        for (int i = 0; i < actionCount; i++) {
            int actionId; // the unique ID of this spell or recipe
            string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
            int delta0; // tier-0 ingredient change
            int delta1; // tier-1 ingredient change
            int delta2; // tier-2 ingredient change
            int delta3; // tier-3 ingredient change
            int price; // the price in rupees if this is a potion
            int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax
            int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >> actionId >> actionType >> delta0 >> delta1 >> delta2 >> delta3 >> price >> tomeIndex >> taxCount >> castable >> repeatable; cin.ignore();

            actionList[i].id = actionId;
            actionList[i].type = actionType;
            actionList[i].d[0] = delta0;
            actionList[i].d[1] = delta1;
            actionList[i].d[2] = delta2;
            actionList[i].d[3] = delta3;
            actionList[i].pri = price;
            actionList[i].tome = tomeIndex;
            actionList[i].tax = taxCount;
            actionList[i].cast = castable;
            actionList[i].repeat = repeatable;

        }
        
        for (int i = 0; i < 2; i++) {
            int inv0; // tier-0 ingredients in inventory
            int inv1;
            int inv2;
            int inv3;
            int score; // amount of rupees
            cin >> inv0 >> inv1 >> inv2 >> inv3 >> score; cin.ignore();

            list[i].in[0] = inv0;
            list[i].in[1] = inv1;
            list[i].in[2] = inv2;
            list[i].in[3] = inv3;
            list[i].sc = score;

        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // ここから処理

        int actId = -1; // 醸造先のid
        int eva = 0;    // 評価値
        bool castAct = false;
        stack<int> spell;

        for(int i = 0;i < actionCount;i++){
            if(actionList[i].type == "CAST"){
                if(actionList[i].cast == 1)spell.push(i);
            }
        }

        while(!spell.empty()){
            int t = spell.top();
            spell.pop();
            if(actionList[t].d[0] > 0 && list[0].in[0] > 2)continue;
            if(actionList[t].d[1] > 0 && list[0].in[1] > 2)continue;
            if(actionList[t].d[2] > 0 && list[0].in[2] > 1)continue;
            if(actionList[t].d[3] > 0 && list[0].in[3] > 0)continue;
            int a[4];
            rep(i,4){
                a[i] = actionList[t].d[i];
            }
            bool ch = true;
            rep(i,4){
                if(list[0].in[i] + a[i] < 0)ch = false;
            }
            if(!ch)continue;
            actId = actionList[t].id;
            castAct = true;
            break;
        }


        if(castAct){
            int ans = actId;
            actId = -1;
            cout << "CAST " << ans << endl; 
            
        }
        else{
            for(int i = 0;i < actionCount;i++){
                int tmp = 0;
                bool ok = true;
                if(actionList[i].type == "BREW"){
                    rep(j,4){
                        if(abs(actionList[i].d[j]) > list[0].in[j])ok = false;
                    }
                    if(ok)tmp = actionList[i].pri;
                }
                if(eva < tmp){
                    eva = tmp;
                    actId = actionList[i].id;
                }
            }

            int ans = actId;
            eva = 0;
            actId = -1;

            // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
            if(ans != -1){
                cout << "BREW " << ans << endl;
            }
            else{
                cout << "REST" << endl; 
            }
            
        }


    }
}