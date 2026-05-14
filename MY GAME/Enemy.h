#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int hp;
    int attackPower;
    int skillPower;

public:
    Enemy();
    void showStatus() const;
    int getHp() const { return hp; }
    void takeDamage(int damage);

    // 敵の行動（ダメージ値を返す）
    int act();// 敵が行動を選び、与えるダメージを返す
    bool isDead() const { return hp <= 0; }
};

#endif