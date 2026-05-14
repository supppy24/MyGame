#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int hp; //現在のHP
    int maxHp;  //最大のHP
    int mp;     //現在のMP
    int attackPower; //通常攻撃の攻撃力
    int skillPower; //スキルの攻撃力
    int healPower;  //かいふくの量
    bool usedResurrection;  //"ふっかつのじゅもん"を使ったか

public:
    Player();
    void showStatus() const;// ステータス表示
    int getHp() const { return hp; }
    int getMp() const { return mp; }

    // アクション
    void attack(int& enemyHp);// 敵のHPを書き換えるので「参照 &」で受け取る
    void skill(int& enemyHp);
    void heal();
    void resurrect();
    void takeDamage(int damage);// ダメージを受ける処理

    bool isDead() const { return hp <= 0; }// HPが0以下ならtrueを返す
    bool hasUsedResurrection() const { return usedResurrection; }
};

#endif