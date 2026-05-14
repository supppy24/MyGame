#include <iostream>
#include <ctime>
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main() {
    // 乱数の種をセット
    srand(static_cast<unsigned int>(time(nullptr)));

    Player player;
    Enemy enemy;

    // 敵のHPを管理する変数
    int enemyHp = enemy.getHp(); // Enemyクラス側のHPを管理用変数に同期

    // どちらかが倒れるまでループ
    while (!player.isDead() && enemyHp > 0) {
        cout << "======================" << endl;
        player.showStatus();
        cout << "Enemy  HP : " << enemyHp << endl;
        cout << "======================" << endl;

        cout << "コマンドをえらべ！！" << endl;
        cout << "1:こうげき\n2:スキル\n3:かいふく\n4:ふっかつのじゅもん" << endl;

        int command;
        cin >> command;

        // プレイヤーのターン
        switch (command) {
        case 1: player.attack(enemyHp); break;
        case 2: player.skill(enemyHp); break;
        case 3: player.heal(); break;
        case 4: player.resurrect(); break;
        default: cout << "無効なコマンドです" << endl; continue;
        }

        if (enemyHp <= 0) {
            cout << "敵を倒した！ 勝利！！" << endl;
            break;
        }

        // 敵のターン
        int damage = enemy.act();// 敵が行動し、ダメージ値を計算
        player.takeDamage(damage);// プレイヤーにダメージを適用

        if (player.isDead()) {
            cout << "プレイヤーは倒れた..." << endl;
            break;
        }
    }

    cout << "ゲーム終了" << endl;
    return 0;
}