#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

using namespace std;
int main()
{
    //プレイヤー
    int PlayerHP = 50;  //プレイヤーのHP
    int PlayerMAXHP = 50;//プレイヤーの最大値HP
    int PlayerMP = 30;//プレイヤーのMP
    //int PlayerMAXMP = 20;//プレイヤーの最大値MP
    int PlayerAttack = 5;//プレイヤーの"こうげき"コマンド
    int PlayerSkill = 15;//プレイヤーの"スキル"コマンド
    int PlayerHeal = 15;//プレイヤーの"かいふく"コマンド
    int PlayerRs = PlayerHP;//プレイヤーの"ふっかつのじゅもん"コマンド
    bool usedResurrection = false;//"ふっかつのじゅもん"を使ったか確認

    //敵
    int EnemyHP = 75;  //敵のHP
    int EnemyAttack = 7;//敵のこうげき
    int EnemySkill = 15;//敵のスキル

    //乱数の初期化
    srand(time(nullptr));

    while (PlayerHP > 0 && EnemyHP > 0)
    {
        //PlayerHP・MPとEnemyHPの表示
        cout << "======================" << endl;
        cout << "Player HP : " << PlayerHP << endl;
        cout << "Player MP : " << PlayerMP << endl;
        cout << "Enemy  HP : " << EnemyHP << endl;
        cout << "======================" << endl;

        //コマンド表示
        cout << "コマンドをえらべ！！" << endl;
        cout << "1:こうげき " << endl;
        cout << "2:スキル " << endl;
        cout << "3:かいふく " << endl;
        cout << "4:ふっかつのじゅもん" << endl;

        //キーボード入力を受け取る
        int Command;
        cin >> Command;

        //プレイヤーの行動
        switch (Command)
        {
        case 1:
            cout << "プレイヤーのこうげき！" << endl;
            EnemyHP -= PlayerAttack;
            break;

        case 2:
            if (PlayerMP >= 7){
            cout << "ソードアタック!!" << endl;
            EnemyHP -= PlayerSkill;
            PlayerMP -= 7;
                }
                else
                {
                    cout << "MP不足！" << endl;
                }
                break;

        case 3:
            if (PlayerMP >= 3)
            {
                cout << "プレイヤーは回復した！" << endl;
                PlayerHP += PlayerHeal;
                PlayerMP -= 3;
                if (PlayerHP > PlayerMAXHP) {
                    PlayerHP = PlayerMAXHP;
                }
            }
            else
            {
                cout << "MPが足りない！" << endl;
            }
            break;

        case 4:

            // 既に使っているか判定
            if (usedResurrection == true)
            {
                cout << "ふっかつのじゅもんはもう使えない！" << endl;
            }
            else
            {
                cout << "ふっかつのじゅもん！ HP全回復！" << endl;

                PlayerHP = PlayerRs;

                // 使用済みにする
                usedResurrection = true;
            }

            break;

        default:
            cout << "無効なコマンドです" << endl;
            break;
        }

        //敵が倒れたら終了
        if (EnemyHP <= 0) {
            cout << "敵を倒した！ 勝利！！" << endl;
            break;
        }

        // 敵の行動（ランダム）
        int enemyCommand = rand() % 2; // 0 or 1

        if (enemyCommand == 0)
        {
            cout << "敵のこうげき！" << endl;
            PlayerHP -= EnemyAttack;
        }
        else
        {
            cout << "敵のスキル！" << endl;
            PlayerHP -= EnemySkill;
        }
        //プレイヤーが倒れたか判定
        if (PlayerHP <= 0) {
            cout << "プレイヤーは倒れた..." << endl;
            break;
        }
    }

    cout << "ゲーム終了" << endl;

}
