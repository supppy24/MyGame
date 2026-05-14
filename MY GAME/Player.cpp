#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
    : hp(50), maxHp(50), mp(30), attackPower(5), skillPower(15), healPower(15), usedResurrection(false) {
}

void Player::showStatus() const {
    cout << "Player HP : " << hp << endl;
    cout << "Player MP : " << mp << endl;
}
//通常攻撃
void Player::attack(int& enemyHp) {
    cout << "プレイヤーのこうげき！" << endl;
    enemyHp -= attackPower;// 引数で渡された敵のHPを直接減らす
}
//スキルの攻撃
void Player::skill(int& enemyHp) {
    if (mp >= 7) {
        cout << "ソードアタック!!" << endl;
        enemyHp -= skillPower;
        mp -= 7;
    }
    else {
        cout << "MP不足！" << endl;
    }
}
//かいふく
void Player::heal() {
    if (mp >= 3) {
        cout << "プレイヤーは回復した！" << endl;
        hp += healPower;
        mp -= 3;
        if (hp > maxHp) hp = maxHp;
    }
    else {
        cout << "MPが足りない！" << endl;
    }
}
//ふっかつのじゅもん
void Player::resurrect() {
    if (usedResurrection) {
        cout << "ふっかつのじゅもんはもう使えない！" << endl;
    }
    else {
        cout << "ふっかつのじゅもん！ HP全回復！" << endl;
        hp = maxHp;
        usedResurrection = true;
    }
}
// ダメージを受ける処理
void Player::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}