#include <iostream>
#include <cstdlib>

using namespace std;

class Character{
    protected:
    int maxHealth = 0;
    int health = 0;
    int damage = 0;

    public:

    Character(int maxHealth, int damage) 
    : maxHealth(maxHealth), health(maxHealth),  damage(damage) {}

    void resetHealth() {
        health = maxHealth;
    }

    virtual void attack() {
        cout << "Нанесение урона";
    }

    void takeDamage(int damage) {
        health -= damage;
        
        if (health < 0) {
            health = 0;
        }
    }

    int getHealth() {
        return health;
    }

    int getDamage() {
        return damage;
    }

};

class Player : public Character {
    private:
    bool powerPotionUsed = false;
    public:

    Player() : Character (100, 10)
    {}

    void attack() override {
        cout << "Вы ударили мечом и нанёсли " << damage << " урона!\n";
    }

    void potionHeal() {
        cout << "Вы исцелились на 50 здоровья\n";
        health += 50;

        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    void potionPower() {
    if (powerPotionUsed) {
        cout << "Вы уже использовали зелье урона!\n";
        return;
    }

    cout << "Вы увеличили силу на 15\n";

    damage += 15;
    powerPotionUsed = true;
}
    

    void unpower() {
        damage -= 15;
        if (damage <= 10) {
            damage = 10;
        }
        powerPotionUsed = false;
    }
    
};

class Zombie : public Character {
    private:

    public:

    Zombie() : Character(100, 5) {
    }

    void attack() override {
        cout << "Вас укусили и нанёсли " << damage << " урона!\n";
    }

};

class Robot : public Character {
    private:
    
    public:

    Robot() : Character(120, 10)
    {}

    void attack() override {
        cout << "Вас поджарили и нанёсли " << damage << " урона!\n";
    }

};    

class Boss : public Character {
    private: 

    public: 

    Boss() : Character(200, 20) {
    }

    void attack() override {
        cout << "Вас ударили молотом и нанёсли " << damage << " урона!\n";
    }
};

bool bossFight(Player& player, Boss& boss) {
     cout << "Вы сражаетесь с боссом!\n";

    int number;

    while (boss.getHealth() > 0 && player.getHealth() > 0)
    {
        cout << "\nВаши действия:\n";
        cout << "1. Атаковать\n";
        cout << "2. Использовать зелье здоровья\n";
        cout << "3. Использовать зелье урона\n";
        cout << "Введите число: ";

        if (!(cin >> number))
        {
            cout << "Ошибка! Нужно ввести число!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        switch (number)
        {
        case 1:
            player.attack();
            boss.takeDamage(player.getDamage());
            break;

        case 2:
            player.potionHeal();
            break;

        case 3:
            player.potionPower();
            break;

        default:
            cout << "Неверное число!\n";
            continue;
        }

        cout << "У босса осталось: " << boss.getHealth() << " hp\n";

        if (boss.getHealth() > 0)
        {
            boss.attack();

            player.takeDamage(boss.getDamage());

            cout << "У вас осталось: " << player.getHealth() << " hp\n";
        }
    }   

    if (player.getHealth() <= 0)
    {
        player.resetHealth();
        boss.resetHealth();
        return false;
    }

    if (boss.getHealth() <= 0)
    {
        cout << "Вы победили босса!\n";
        return true;
    }

    return false;
}

bool secondEnemy(Player& player, Robot& robot) {
     cout << "Вы сражаетесь с роботом!\n";

    int number;

    while (robot.getHealth() > 0 && player.getHealth() > 0)
    {
        cout << "\nВаши действия:\n";
        cout << "1. Атаковать\n";
        cout << "2. Использовать зелье здоровья\n";
        cout << "3. Использовать зелье урона\n";
        cout << "Введите число: ";

        if (!(cin >> number))
        {
            cout << "Ошибка! Нужно ввести число!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        switch (number)
        {
        case 1:
            player.attack();
            robot.takeDamage(player.getDamage());
            break;

        case 2:
            player.potionHeal();
            break;

        case 3:
            player.potionPower();
            break;

        default:
            cout << "Неверное число!\n";
            continue;
        }

        cout << "У робота осталось: " << robot.getHealth() << " hp\n";

        if (robot.getHealth() > 0)
        {
            robot.attack();

            player.takeDamage(robot.getDamage());

            cout << "У вас осталось: " << player.getHealth() << " hp\n";
        }
    }   

    if (player.getHealth() <= 0)
    {
        player.resetHealth();
        robot.resetHealth();
        return false;
    }

    if (robot.getHealth() <= 0)
    {
        cout << "Вы победили второго противника!\n";
        player.unpower();
        robot.resetHealth();
        return true;
    }

    return false;
}

bool firstEnemy(Player& player, Zombie& zombie)
{
    cout << "Вы сражаетесь с зомби!\n";

    int number;

    while (zombie.getHealth() > 0 && player.getHealth() > 0)
    {
        cout << "\nВаши действия:\n";
        cout << "1. Атаковать\n";
        cout << "2. Использовать зелье здоровья\n";
        cout << "3. Использовать зелье урона\n";
        cout << "Введите число: ";

        if (!(cin >> number))
        {
            cout << "Ошибка! Нужно ввести число!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        switch (number)
        {
        case 1:
            player.attack();
            zombie.takeDamage(player.getDamage());
            break;

        case 2:
            player.potionHeal();
            break;

        case 3:
            player.potionPower();
            break;

        default:
            cout << "Неверное число!\n";
            continue;
        }

        cout << "У зомби осталось: " << zombie.getHealth() << " hp\n";

        if (zombie.getHealth() > 0)
        {
            zombie.attack();

            player.takeDamage(zombie.getDamage());

            cout << "У вас осталось: " << player.getHealth() << " hp\n";
        }
    }   

    if (player.getHealth() <= 0)
    {
        player.resetHealth();
        zombie.resetHealth();
        return false;
    }

    if (zombie.getHealth() <= 0)
    {
        cout << "Вы победили первого противника!\n";
        zombie.resetHealth();
        player.unpower();
        return true;
    }

    return false;
}

bool startGame(Player& player, Zombie& zombie, Robot& robot, Boss& boss)
{
    cout << "Предыстория:\n";
    cout << "Ваша цель победить 2 врагов, и в конце убить босса.\n";
    cout << "Первый противник — зомби.\n";

    if (!firstEnemy(player, zombie)) {
        return false;
    }

    cout << "Переходим к следующему врагу!\n";

    if (!secondEnemy(player, robot)) {
        return false;
    }

    cout << "Переходим к боссу!\n";

    if (!bossFight(player, boss)) {
        return false;
    }

    cout << "Вы победили всех врагов!\n";

    return true;
}

int main() {
    Player player;
    Zombie zombie;
    Robot robot;
    Boss boss;

    cout << "Вы попали в простую RPG!\n";
    int number;
    do{
        cout << "1. Посмотреть хар-ки героя\n";
        cout << "2. Начать игру\n";
        cout << "0. Выход\n";
        cout << "Введите число: ";

        if (!(cin >> number)) {
        cout << "Ошибка! Нужно ввести число.\n";

        cin.clear();
        cin.ignore(10000, '\n');
        number = -1;

        continue;
        }

        switch (number)
        {
        case 1:
        cout << "-------------------\n";
        cout << "Ваш герой:\n";
        cout << "Здоровье: " << player.getHealth() << endl;
        cout << "Урон: " << player.getDamage() << endl;
        cout << "-------------------\n";
            break;

        case 2:
        if (startGame(player, zombie, robot, boss)) {
        cout << "Поздравляем! Вы прошли игру!\n";
        return 0;
        }

        cout << "Вы проиграли. Возвращаемся в меню.\n";
            break;

        case 0:
        cout << "Удачи!";
            break;
            
        default:
        cout << "Неверный ввод!";
            break;
        }
    } while (number != 0);
}
