#include "Enemy.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Enemy::Enemy() : hp(75), attackPower(7), skillPower(15) {}

void Enemy::showStatus() const {
    cout << "Enemy  HP : " << hp << endl;
}
// 敵の行動ロジック
int Enemy::act() {
    int enemyCommand = rand() % 2;
    if (enemyCommand == 0) {
        cout << "敵のこうげき！" << endl;
        return attackPower;
    }
    else {
        cout << "敵のスキル！" << endl;
        return skillPower;
    }
}

void Enemy::takeDamage(int damage) {
    // 今回、敵へのダメージ処理はPlayerクラス側で直接EnemyHPを操作していますが、
    // 本来はこの関数で hp -= damage; とするのがより安全です。
}