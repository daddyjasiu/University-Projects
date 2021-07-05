//Jan Skwarczek

#include <iostream>
#include <string>

using namespace std;

class PLAYER_CLASS {

protected:
    PLAYER_CLASS *next;

    unsigned int maxHP;
    unsigned int currHP;
    unsigned int attack;
    unsigned int agility;

    virtual void die() {
        currHP = 0;
    }

public:

    PLAYER_CLASS() {
        next = 0;
    }

    virtual unsigned int getDamage() = 0;

    virtual void takeDamage(unsigned int dmg) = 0;

    virtual void printParams() = 0;

    virtual string getID() {
        return "";
    }

    virtual unsigned int getDefense() {
        return 0;
    }

    virtual unsigned int getAgility() {
        return agility;
    }

    virtual void applyWinnerReward() {
        attack += 2;
        agility += 2;
    }

    virtual unsigned int getRemainingHealth() {
        return (currHP * 100 / maxHP);
    }

    virtual void cure() {
        currHP = maxHP;
    }

    friend class CAESAR_CLASS;

    friend class ARENA_CLASS;

    friend class SQUAD_CLASS;

};

class CAESAR_CLASS {

public:
    int judgeCounter;

    void judgeDeathOfLife(PLAYER_CLASS *player) {

        judgeCounter++;

        if (judgeCounter % 3 == 0 && judgeCounter != 0) {
            judgeCounter = 0;
            player->die();
        }
    }

};

class ARENA_CLASS {

private:
    CAESAR_CLASS cesar;

public:
    ARENA_CLASS(CAESAR_CLASS *cesarValue) {
        cesar = *cesarValue;
        cesar.judgeCounter = 0;
    }

    void fight(PLAYER_CLASS *player1, PLAYER_CLASS *player2) {

        int attackCounter = 0;

        PLAYER_CLASS *firstPlayer;
        PLAYER_CLASS *secondPlayer;

        if (player1->getRemainingHealth() != 0 && player2->getRemainingHealth() != 0) {
            if (player1->getAgility() < player2->getAgility()) {
                firstPlayer = player2;
                secondPlayer = player1;
            } else {
                firstPlayer = player1;
                secondPlayer = player2;
            }

            firstPlayer->printParams();
            secondPlayer->printParams();

            while (firstPlayer->getRemainingHealth() >= 10 && secondPlayer->getRemainingHealth() >= 10 &&
                   attackCounter < 40) {

                secondPlayer->takeDamage(firstPlayer->getDamage());
                secondPlayer->printParams();
                attackCounter++;

                if (secondPlayer->getRemainingHealth() >= 10) {
                    firstPlayer->takeDamage(secondPlayer->getDamage());
                    firstPlayer->printParams();
                    attackCounter++;
                }
            }

            if (firstPlayer->getRemainingHealth() == 0) {
                firstPlayer->die();
            }
            if (secondPlayer->getRemainingHealth() == 0) {
                secondPlayer->die();
            }

            if (attackCounter % 2 == 0) {
                if (firstPlayer->getRemainingHealth() != 0) {
                    cesar.judgeDeathOfLife(firstPlayer);
                    firstPlayer->printParams();
                }
                if (secondPlayer->getRemainingHealth() != 0) {
                    cesar.judgeDeathOfLife(secondPlayer);
                    secondPlayer->printParams();
                }
            } else {
                if (firstPlayer->getRemainingHealth() != 0) {
                    cesar.judgeCounter++;
                    firstPlayer->printParams();
                }
                if (secondPlayer->getRemainingHealth() != 0) {
                    cesar.judgeCounter++;
                    secondPlayer->printParams();
                }
            }

            if (firstPlayer->getRemainingHealth() != 0) {
                firstPlayer->applyWinnerReward();
                firstPlayer->cure();
            }
            if (secondPlayer->getRemainingHealth() != 0) {
                secondPlayer->applyWinnerReward();
                secondPlayer->cure();
            }

            firstPlayer->printParams();
            secondPlayer->printParams();

        }
    }

};

class HUMAN_CLASS : virtual public PLAYER_CLASS {

protected:
    string id;
    unsigned int defense;

public:
    HUMAN_CLASS(string idValue) {
        id = idValue;
        maxHP = 200;
        currHP = 200;
        attack = 30;
        agility = 10;
        defense = 10;
    }

    string getID() {
        return id;
    }

    unsigned int getDefense() {
        return defense;
    }

    unsigned int getAgility() {
        return agility;
    }

    unsigned int getDamage() {
        return attack;
    }

    void takeDamage(unsigned int dmg) {
        if (dmg > defense + agility) {
            if ((int) (currHP - (dmg - (defense + agility))) <= 0)
                this->die();
            else
                currHP -= (dmg - (defense + agility));
        }
    }

    unsigned int getRemainingHealth() {
        return (currHP * 100 / maxHP);
    }

    void printParams() {
        if (currHP != 0) {
            cout << id << ":" << maxHP << ":" << currHP << ":" << this->getRemainingHealth() << "%:"
                 << this->getDamage() << ":"
                 << this->getAgility() << ":" << defense << endl;
        } else {
            cout << id << ":" << "R.I.P." << endl;
        }
    };

};

class BEAST_CLASS : virtual public PLAYER_CLASS {

protected:
    string id;

public:
    BEAST_CLASS(string idValue) {
        id = idValue;
        maxHP = 150;
        currHP = 150;
        attack = 40;
        agility = 20;
    }

    string getID() {
        return id;
    }

    unsigned int getDefense() {
        return 0;
    }

    unsigned int getAgility() {
        return agility;
    }

    unsigned int getDamage() {

        if ((currHP * 100 / maxHP) < 25)
            return attack * 2;

        return attack;
    }

    void takeDamage(unsigned int dmg) {
        if (dmg > 0.5 * agility) {
            if ((int) (currHP - (dmg - (0.5 * agility))) <= 0)
                this->die();
            else
                currHP -= (dmg - (0.5 * agility));
        }
    }

    unsigned int getRemainingHealth() {
        return (currHP * 100 / maxHP);
    }

    void printParams() {

        if (currHP != 0) {
            cout << id << ":" << maxHP << ":" << currHP << ":" << this->getRemainingHealth() << "%:"
                 << this->getDamage() << ":"
                 << this->getAgility() << endl;
        } else {
            cout << id << ":" << "R.I.P." << endl;
        }
    };

};

class BERSERKER_CLASS : virtual public HUMAN_CLASS, virtual public BEAST_CLASS {

public:
    BERSERKER_CLASS(string idValueHuman, string idValueBeast) : HUMAN_CLASS(idValueHuman),
                                                                BEAST_CLASS(idValueBeast) {
        maxHP = 200;
        currHP = 200;
        attack = 35;
        agility = 5;
        defense = 15;
    }

    string getID() {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::id;
        else
            return BEAST_CLASS::id;
    }

    unsigned int getDefense() {
        return defense;
    }

    unsigned int getAgility() {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::getAgility();
        else
            return BEAST_CLASS::getAgility();
    }

    unsigned int getDamage() {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            return HUMAN_CLASS::getDamage();
        else
            return BEAST_CLASS::getDamage();
    }

    void takeDamage(unsigned int dmg) {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            HUMAN_CLASS::takeDamage(dmg);
        else
            BEAST_CLASS::takeDamage(dmg);
    }

    unsigned int getRemainingHealth() {
        return (currHP * 100 / maxHP);
    }

    void printParams() {
        if (this->getRemainingHealth() >= 25 || this->getRemainingHealth() == 0)
            HUMAN_CLASS::printParams();
        else
            BEAST_CLASS::printParams();

    }
};

class SQUAD_CLASS : public PLAYER_CLASS {

protected:
    string id;
    PLAYER_CLASS *first;

public:

    SQUAD_CLASS(string idValue) {
        id = idValue;
        maxHP = 1;
        currHP = 0;
        first = 0;
    }

    void addPlayer(PLAYER_CLASS *playerToAdd) {

        if (playerToAdd->getRemainingHealth() != 0) {
            if (first == NULL) {
                first = playerToAdd;
            } else {
                PLAYER_CLASS *itr = first;

                while (itr->next != NULL) {
                    if (itr == playerToAdd)
                        return;
                    itr = itr->next;
                }

                itr->next = playerToAdd;
                itr->next->next = NULL;

            }

            PLAYER_CLASS *itr = first;
            currHP = 0;

            while (itr != NULL) {

                if (itr->getRemainingHealth() > getRemainingHealth()) {
                    currHP = itr->currHP;
                    maxHP = itr->maxHP;
                }
                itr = itr->next;
            }

            paramsSort();
        }

    }

    string getID() {
        return id;
    }

    unsigned int getRemainingHealth() {

        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            unsigned int remainingHealthCounter = 0;

            while (itr != NULL) {

                if (itr->getRemainingHealth() > remainingHealthCounter)
                    remainingHealthCounter = itr->getRemainingHealth();

                itr = itr->next;
            }
            return remainingHealthCounter;
        }

        return 0;
    }

    unsigned int getDefense() {

        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            int defenseCounter = 0;

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0)
                    defenseCounter += itr->getDefense();

                itr = itr->next;
            }

            return defenseCounter;
        }

        return 0;
    }

    unsigned int getAgility() {

        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            int agilityCounter = -1;

            if (itr->getRemainingHealth() != 0)
                agilityCounter = itr->getAgility();

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0) {
                    if (agilityCounter > itr->getAgility())
                        agilityCounter = itr->getAgility();
                }

                itr = itr->next;
            }

            return agilityCounter;
        }
        return 0;
    }

    void applyWinnerReward() {
        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0)
                    itr->applyWinnerReward();

                itr = itr->next;
            }
        }
    }

    unsigned int getDamage() {

        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            int damageCounter = 0;

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0)
                    damageCounter += itr->getDamage();

                itr = itr->next;
            }

            return damageCounter;
        }

        return 0;
    }

    void takeDamage(unsigned int dmg) {

        PLAYER_CLASS *itr = first;
        PLAYER_CLASS *itrePrev = NULL;

        int playerCount = this->countPlayers();

        if (countPlayers() != 0) {

            while (itr != NULL) {

                itr->takeDamage((dmg / playerCount));

                if (itr->getRemainingHealth() == 0) {
                    if (itrePrev != NULL) {
                        itrePrev->next = itr->next;
                    } else {
                        first = first->next;
                    }
                }
                else{
                    itrePrev = itr;
                }

                itr = itr->next;
            }

        }
    }

    int countPlayers() {
        PLAYER_CLASS *itr = first;
        int playerCounter = 0;

        while (itr != NULL) {

            playerCounter++;

            itr = itr->next;
        }

        return playerCounter;
    }

    bool isGreater(PLAYER_CLASS *player1, PLAYER_CLASS *player2) {

        if (player1->getID() > player2->getID()) {
            return true;
        } else if (player1->getID() == player2->getID()) {
            if (player1->maxHP > player2->maxHP) {
                return true;
            } else if (player1->maxHP == player2->maxHP) {
                if (player1->currHP > player2->currHP) {
                    return true;
                } else if (player1->currHP == player2->currHP) {
                    if (player1->getRemainingHealth() > player2->getRemainingHealth()) {
                        return true;
                    } else if (player1->getRemainingHealth() == player2->getRemainingHealth()) {
                        if (player1->getDamage() > player2->getDamage()) {
                            return true;
                        } else if (player1->getDamage() == player2->getDamage()) {
                            if (player1->getAgility() > player2->getAgility()) {
                                return true;
                            } else if (player1->getAgility() == player2->getAgility()) {
                                if (player1->getDefense() > player2->getDefense()) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }

    void paramsSort(){

        int count = countPlayers();

        for(int i = count; i > 1; i--){

            PLAYER_CLASS *temp, *player1;
            player1 = first;

            for(int j = 0; j < count-1; j++){

                if(isGreater(player1, player1->next)){

                    PLAYER_CLASS *player2 = player1->next;
                    player1->next = player2->next;
                    player2->next = player1;

                    if(player1 == first){
                        first = player2;
                        player1 = player2;
                    }
                    else{
                        player1 = player2;
                        temp->next = player2;
                    }
                }
                temp = player1;
                player1 = player1->next;
            }
        }
    }

    void printParams() {

        if (countPlayers() != 0) {

            cout << id << ":" << countPlayers() << ":" << getRemainingHealth() << "%" << ":" <<
                 getDamage() << ":" << getAgility() << endl;

            paramsSort();

            PLAYER_CLASS *itr = first;

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0)
                    itr->printParams();

                itr = itr->next;
            }
        } else {
            cout << id << ":" << "nemo" << endl;
        }
    }

    void die() {
        PLAYER_CLASS *itr = first;

        if (itr != NULL) {

            while (itr != NULL) {

                itr->currHP = 0;

                itr = itr->next;
            }

            currHP = 0;
        }
    }

    void cure() {
        PLAYER_CLASS *itr = first;

        if (countPlayers() != 0) {

            while (itr != NULL) {

                if (itr->getRemainingHealth() != 0)
                    itr->currHP = itr->maxHP;

                if (itr->getRemainingHealth() > getRemainingHealth()) {
                    currHP = itr->currHP;
                    maxHP = itr->maxHP;
                }

                itr = itr->next;
            }
        }
    }
};
