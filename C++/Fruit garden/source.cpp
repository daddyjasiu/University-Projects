//Jan Skwarczek

#include <iostream>

class GARDEN_CLASS;
class BRANCH_CLASS;
class WOOD_CLASS;
class FRUIT_CLASS {

private:
    unsigned int weight;
    BRANCH_CLASS *branch;
    FRUIT_CLASS *next;
    FRUIT_CLASS *prev;
    unsigned int pos;

public:

    FRUIT_CLASS(BRANCH_CLASS *pointer = NULL, int position = 0, FRUIT_CLASS *previous = NULL, unsigned int w = 0, FRUIT_CLASS *nxt = NULL) {
        branch = pointer;
        pos = position;
        weight = w;
        next = nxt;
        prev = previous;
    }

    FRUIT_CLASS(const FRUIT_CLASS &currElem, BRANCH_CLASS *pointer = NULL) {
        branch = pointer;
        pos = currElem.pos;
        weight = currElem.weight;
        next = NULL;
        prev = NULL;
    }

    unsigned int getLength() {
        return pos;
    }

    unsigned int getWeight() {
        return weight;
    }

    void growthFruit() {
        weight++;
    }

    void fadeFruit() {
        if (weight > 0) weight--;
    }

    void pluckFruit() {
        weight = 0;
    }

    BRANCH_CLASS *getBranchPointer() {
        return branch;
    }

    FRUIT_CLASS *getNext() {
        return next;
    }

    void setNext(FRUIT_CLASS *nxt) {
        next = nxt;
    }

    FRUIT_CLASS *getPrev() {
        return prev;
    }

    void setPrev(FRUIT_CLASS *nxt) {
        prev = nxt;
    }

    ~FRUIT_CLASS() {
        weight = 0;
        pos = 0;
        branch = NULL;
        next = NULL;
        prev = NULL;
    }
};

class BRANCH_CLASS {

private:
    FRUIT_CLASS *head;
    FRUIT_CLASS *tail;
    BRANCH_CLASS *next;
    BRANCH_CLASS *prev;
    WOOD_CLASS *tree;
    unsigned int length;
    unsigned int height;

public:

    WOOD_CLASS *getWoodPointer() {
        return tree;
    }

    BRANCH_CLASS *getNext() {
        return next;
    }

    void setNext(BRANCH_CLASS *pointer) {
        next = pointer;
    }

    void setHeight(unsigned int h) {
        height = h;
    }

    BRANCH_CLASS *getPrev() {
        return prev;
    }

    BRANCH_CLASS *setPrev(BRANCH_CLASS *pointer) {
        prev = pointer;
    }


    BRANCH_CLASS(WOOD_CLASS *pointer = NULL, unsigned int h = 0, unsigned int l = 0, BRANCH_CLASS *previous = NULL, BRANCH_CLASS *nxt = NULL) {

        tree = pointer;
        prev = previous;
        next = nxt;
        length = l;
        height = h;
        head = NULL;
        tail = NULL;
    }

    BRANCH_CLASS(const BRANCH_CLASS &currElem, WOOD_CLASS *pointer = NULL, unsigned int h = 0, BRANCH_CLASS *previous = NULL, BRANCH_CLASS *nxt = NULL) {

        length = currElem.length;
        height = h;
        tree = pointer;
        prev = previous;
        next = nxt;
        head = NULL;
        tail = NULL;

        FRUIT_CLASS *temp = currElem.head;

        while (temp != NULL) {

            FRUIT_CLASS *newFruit = new FRUIT_CLASS(*temp, this);

            if (temp == currElem.head) {
                head = newFruit;
                tail = newFruit;
            } else {
                tail->setNext(newFruit);
                newFruit->setPrev(tail);
                newFruit->setNext(NULL);
                tail = newFruit;
            }
            temp = temp->getNext();
        }
    }

    unsigned int getFruitsTotal() {

        unsigned int counter = 0;
        FRUIT_CLASS *temp = head;

        while (temp != NULL) {
            temp = temp->getNext();
            counter++;
        }

        return counter;
    }

    unsigned int getWeightsTotal() {

        unsigned int weight = 0;
        FRUIT_CLASS *temp = head;

        while (temp != NULL) {
            weight += temp->getWeight();
            temp = temp->getNext();
        }

        return weight;
    }

    unsigned int getHeight() {
        return height;
    }

    unsigned int getLength() {
        return length;
    }

    void growthBranch() {
        FRUIT_CLASS *temp = head;

        while (temp != NULL) {
            temp->growthFruit();
            temp = temp->getNext();
        }

        length++;

        if (length % 2 == 0) {

            FRUIT_CLASS *temp = new FRUIT_CLASS(this, length, tail);

            if (length == 2) {
                head = temp;
                tail = temp;
                head->setPrev(NULL);
                tail->setNext(NULL);
            } else {
                tail->setNext(temp);
                temp->setPrev(tail);
                temp->setNext(NULL);
                tail = temp;
            }
        }
    }

    void fadeBranch() {

        if (length == 0)
            return;

        if (length % 2 != 0) {

            length--;
            FRUIT_CLASS *temp = head;

            while (temp != NULL) {
                temp->fadeFruit();
                temp = temp->getNext();
            }
        } else {

            FRUIT_CLASS *temp = tail;

            if (tail == head) {
                head = NULL;
                delete tail;
                tail = NULL;
            } else {

                if (tail->getPrev() != NULL) {
                    tail->getPrev()->setNext(NULL);
                    tail = tail->getPrev();
                }

                delete temp;
                temp = tail;

                while (temp != NULL) {
                    temp->fadeFruit();
                    temp = temp->getPrev();
                }
            }
            length--;
        }
    }

    void harvestBranch(unsigned int w) {

        FRUIT_CLASS *temp = head;

        while (temp != NULL) {
            if (temp->getWeight() >= w) {
                temp->pluckFruit();
            }
            temp = temp->getNext();
        }
    }

    void cutBranch(unsigned int len) {

        if (len < 0) len = 0;
        FRUIT_CLASS *temp = tail;
        FRUIT_CLASS *curr;

        while (temp != NULL && temp->getLength() > len) {
            curr = temp;
            temp = temp->getPrev();
            delete curr;
        }

        if (len == 2) {
            tail = head;
            tail->setNext(NULL);
        }
        else if (len <= 1) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = temp;
            temp->setNext(NULL);
        }
        length = len;
    }

    FRUIT_CLASS *getFruitPointer(unsigned int l) {

        if (l > length || l % 2 != 0) {
            return NULL;
        } else {

            if (l > length / 2) {
                FRUIT_CLASS *temp = tail;

                while (temp != NULL && temp->getLength() > l) {
                    temp = temp->getPrev();
                }

                if (temp != NULL && temp->getLength() == l) {
                    return temp;
                }
                else {
                    return NULL;
                }
            }
            else {
                FRUIT_CLASS *temp = head;

                while (temp != NULL && temp->getLength() < l) {
                    temp = temp->getNext();
                }

                if (temp != NULL && temp->getLength() == l) {
                    return temp;
                }
                else {
                    return NULL;
                }
            }
        }
    }

    ~BRANCH_CLASS() {

        FRUIT_CLASS *temp = head;
        FRUIT_CLASS *prev;

        while (temp != NULL) {
            prev = temp;
            temp = temp->getNext();
            delete prev;
        }

        head = NULL;
        tail = NULL;
        next = NULL;
        prev = NULL;
        tree = NULL;
        length = 0;
        height = 0;
    }
};

class WOOD_CLASS {

private:
    BRANCH_CLASS *head;
    BRANCH_CLASS *tail;
    GARDEN_CLASS *garden;
    unsigned int id;
    unsigned int height;
    WOOD_CLASS *next;
    WOOD_CLASS *prev;

public:

    unsigned int getHeight() {
        return height;
    }

    GARDEN_CLASS *getGardenPointer() {
        return garden;
    }

    unsigned int getNumber() {
        return id;
    }

    WOOD_CLASS *getNext() {
        return next;
    }

    WOOD_CLASS *getPrev() {
        return prev;
    }

    void setNumber(unsigned int num) {
        id = num;
    }

    void setPrev(WOOD_CLASS *pointer) {
        prev = pointer;
    }

    void setNext(WOOD_CLASS *pointer) {
        next = pointer;
    }

    void setLast(BRANCH_CLASS *pointer) {
        tail = pointer;
    }

    WOOD_CLASS(const WOOD_CLASS &currElem, GARDEN_CLASS *pointer = NULL) {

        height = currElem.height;
        prev = NULL;
        next = NULL;
        garden = pointer;
        id = 0;
        head = NULL;
        tail = NULL;

        BRANCH_CLASS *temp = currElem.head;

        while (temp != NULL) {
            BRANCH_CLASS *newBranch = new BRANCH_CLASS(*temp, this, temp->getHeight());

            if (temp == currElem.head) {
                head = newBranch;
                setLast(newBranch);
            } else {
                tail->setNext(newBranch);
                newBranch->setPrev(tail);
                newBranch->setNext(NULL);
                tail = newBranch;
            }
            temp = temp->getNext();
        }
    }

    WOOD_CLASS(GARDEN_CLASS *g = NULL, unsigned int i = 0) {
        head = NULL;
        next = NULL;
        prev = NULL;
        garden = g;
        id = i;
        height = 0;
    }

    unsigned int getBranchesTotal() {

        BRANCH_CLASS *temp = head;
        unsigned int counter = 0;

        while (temp != NULL) {
            counter++;
            temp = temp->getNext();
        }
        return counter;
    }

    unsigned int getFruitsTotal() {

        BRANCH_CLASS *temp = head;
        unsigned int counter = 0;

        while (temp != NULL) {
            counter += temp->getFruitsTotal();
            temp = temp->getNext();
        }
        return counter;
    }

    unsigned int getWeightsTotal() {

        BRANCH_CLASS *temp = head;
        unsigned int weight = 0;

        while (temp != NULL) {
            weight += temp->getWeightsTotal();
            temp = temp->getNext();
        }
        return weight;
    }

    void growthWood() {

        if (height <= 1) {
            height++;
            return;
        }
        height++;

        if (height % 3 != 0) {
            BRANCH_CLASS *temp = head;

            while (temp != NULL) {
                temp->growthBranch();
                temp = temp->getNext();
            }
        }
        else {

            if (head == NULL) {
                head = new BRANCH_CLASS(this, height);
                tail = head;
                head->setPrev(NULL);
                head->setNext(NULL);
            }
            else {
                BRANCH_CLASS *temp = head;

                while (temp != NULL) {
                    temp->growthBranch();
                    temp = temp->getNext();
                }
                temp = new BRANCH_CLASS(this, height);
                tail->setNext(temp);
                temp->setPrev(tail);
                temp->setNext(NULL);
                tail = temp;
            }
        }
    }

    void fadeWood() {

        if (height == 0) return;

        if (height % 3 != 0) {
            height--;
            BRANCH_CLASS *temp = head;
            while (temp != NULL) {
                temp->fadeBranch();
                temp = temp->getNext();
            }
        }
        else {
            height--;
            BRANCH_CLASS *temp = head;

            while (temp != NULL) {
                temp->fadeBranch();
                temp = temp->getNext();
            }

            if (tail != NULL) {
                temp = tail;
                tail = tail->getPrev();

                if (tail != NULL) {
                    tail->setNext(NULL);
                }
                else {
                    head = NULL;
                }
                delete temp;
            }
        }
    }

    void harvestWood(unsigned int w) {

        BRANCH_CLASS *temp = head;

        while (temp != NULL) {
            temp->harvestBranch(w);
            temp = temp->getNext();
        }
    }

    void cutWood(unsigned int h) {

        if (h < 0) h = 0;
        height = h;
        BRANCH_CLASS *temp = tail;
        BRANCH_CLASS *prev = NULL;
        while (temp != NULL && temp->getHeight() > height) {
            prev = temp;
            temp = temp->getPrev();
            delete prev;
        }

        if (height == 3) {
            tail = head;
            tail->setNext(NULL);
        }
        else if (height <= 2) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = temp;
            temp->setNext(NULL);
        }
    }

    BRANCH_CLASS *getBranchPointer(unsigned int h) {

        if (h > height || h == 0 || h % 3 != 0) return NULL;

        if (h > height / 2) {

            BRANCH_CLASS *temp = tail;

            while (temp != NULL && temp->getHeight() > h) {
                temp = temp->getPrev();
            }
            return temp;
        }
        else {
            BRANCH_CLASS *temp = head;

            while (temp != NULL && temp->getHeight() < h) {
                temp = temp->getNext();
            }
            return temp;
        }
    }

    void cloneBranch(BRANCH_CLASS *currElem) {

        if (currElem == NULL)
            return;

        BRANCH_CLASS *temp = head;

        while (temp != NULL && temp->getLength() > 0) {
            temp = temp->getNext();
        }
        if (temp == NULL)
            return;

        BRANCH_CLASS *newBranch = new BRANCH_CLASS(*currElem, this);
        newBranch->setHeight(temp->getHeight());
        
        if (temp == head && temp == tail) {
            head = newBranch;
            tail = newBranch;
        }
        else if (temp == head) {
            temp->getNext()->setPrev(newBranch);
            newBranch->setNext(temp->getNext());
            head = newBranch;
        }
        else if (temp == tail) {
            temp->getPrev()->setNext(newBranch);
            newBranch->setPrev(temp->getPrev());
            tail = newBranch;
        }

        else {
            temp->getPrev()->setNext(newBranch);
            temp->getNext()->setPrev(newBranch);
            newBranch->setPrev(temp->getPrev());
            newBranch->setNext(temp->getNext());
        }
    }

    ~WOOD_CLASS() {
        BRANCH_CLASS *temp = head;
        BRANCH_CLASS *prev;

        while (temp != NULL) {
            prev = temp;
            temp = temp->getNext();
            delete prev;
        }
        head = NULL;
        tail = NULL;
        garden = NULL;
        id = 0;
        height = 0;
        next = NULL;
        prev = NULL;
    }
};

class GARDEN_CLASS {

private:
    WOOD_CLASS *head;
    WOOD_CLASS *tail;
    int emptyPlace;

public:
    GARDEN_CLASS() {
        head = NULL;
        tail = NULL;
        emptyPlace = 0;
    }

    unsigned int getWoodsTotal() {

        WOOD_CLASS *temp = head;
        unsigned int counter = 0;

        while (temp != NULL) {
            counter++;
            temp = temp->getNext();
        }
        return counter;
    }

    unsigned int getBranchesTotal() {

        WOOD_CLASS *temp = head;
        unsigned int counter = 0;
        while (temp != NULL) {
            counter += temp->getBranchesTotal();
            temp = temp->getNext();
        }
        return counter;
    }

    unsigned int getFruitsTotal() {

        WOOD_CLASS *temp = head;
        unsigned int counter = 0;
        while (temp != NULL) {
            counter += temp->getFruitsTotal();
            temp = temp->getNext();
        }
        return counter;
    }

    unsigned int getWeightsTotal() {

        WOOD_CLASS *temp = head;
        unsigned int weight = 0;
        while (temp != NULL) {
            weight += temp->getWeightsTotal();
            temp = temp->getNext();
        }
        return weight;
    }

    void plantWood() {

        if (emptyPlace == 0) {
            if (head == NULL) {
                head = new WOOD_CLASS(this, 0);
                tail = head;
                head->setNext(NULL);
                tail->setPrev(NULL);
            } else {
                WOOD_CLASS *newTree = new WOOD_CLASS(this, tail->getNumber() + 1);
                tail->setNext(newTree);
                newTree->setPrev(tail);
                newTree->setNext(NULL);
                tail = newTree;
            }
        } else if (emptyPlace > 0) {
            WOOD_CLASS *temp = head;
            unsigned int counter = 0;
            while (temp != NULL && temp->getNumber() == counter) {
                temp = temp->getNext();
                counter++;
            }
            WOOD_CLASS *newTree;
            if (temp == head) {
                newTree = new WOOD_CLASS(this, 0);
                newTree->setNext(head);
                head->setPrev(newTree);
                newTree->setPrev(NULL);
                head = newTree;
            } else {
                newTree = new WOOD_CLASS(this, temp->getNumber() - 1);
                newTree->setNext(temp);
                temp->getPrev()->setNext(newTree);
                newTree->setPrev(temp->getPrev());
                temp->setPrev(newTree);
            }
            if (emptyPlace > 0)
                emptyPlace--;
        }
    }

    void extractWood(unsigned int i) {

        WOOD_CLASS *temp;
        if (tail == NULL) return;

        if (i < tail->getNumber()) {

            if (i == head->getNumber()) {
                temp = head;
                head = head->getNext();
                head->setPrev(NULL);
                delete temp;
                emptyPlace++;
            }

            else {
                temp = head;
                while (temp != NULL && temp->getNumber() < i) {
                    temp = temp->getNext();
                }
                if (temp != NULL && temp->getNumber() == i) {
                    temp->getNext()->setPrev(temp->getPrev());
                    temp->getPrev()->setNext(temp->getNext());
                    delete temp;
                    emptyPlace++;
                }
            }
        }

        else if (i == tail->getNumber()) {

            temp = tail;

            if (head == tail) {
                delete temp;
                head = NULL;
                tail = NULL;
            }

            else {
                tail = tail->getPrev();
                tail->setNext(NULL);
                delete temp;
            }
        }
    }

    void growthGarden() {
        WOOD_CLASS *temp = head;
        while (temp != NULL) {
            temp->growthWood();
            temp = temp->getNext();
        }
    }

    void fadeGarden() {

        WOOD_CLASS *temp = head;
        while (temp != NULL) {
            temp->fadeWood();
            temp = temp->getNext();
        }
    }

    void harvestGarden(unsigned int w) {
        WOOD_CLASS *temp = head;
        while (temp != NULL) {
            temp->harvestWood(w);
            temp = temp->getNext();
        }
    }

    void cloneWood(unsigned int i) {

        WOOD_CLASS *currElem = head;

        while (currElem != NULL && currElem->getNumber() < i) {
            currElem = currElem->getNext();
        }

        if (currElem == NULL || currElem->getNumber() != i) return;
        WOOD_CLASS *newTree;
        if (emptyPlace == 0) {
            if (head == NULL) {
                newTree = new WOOD_CLASS(*currElem, this);
                newTree->setNumber(0);
                head = newTree;
                tail = head;
            } else {
                newTree = new WOOD_CLASS(*currElem, this);
                newTree->setNumber(tail->getNumber() + 1);
                tail->setNext(newTree);
                newTree->setPrev(tail);
                tail = newTree;
            }
        } else if (emptyPlace > 0) {
            WOOD_CLASS *temp = head;
            unsigned int counter = 0;
            while (temp != NULL && temp->getNumber() == counter) {
                temp = temp->getNext();
                counter++;
            }
            if (temp == head) {
                newTree = new WOOD_CLASS(*currElem, this);
                newTree->setNumber(0);
                newTree->setNext(head);
                head->setPrev(newTree);
                head = newTree;
            } else if (temp == tail) {
                newTree = new WOOD_CLASS(*currElem, this);
                newTree->setNumber(tail->getNumber() + 1);
                newTree->setPrev(tail);
                tail->setNext(newTree);
                tail = newTree;
            } else {
                newTree = new WOOD_CLASS(*currElem, this);
                newTree->setNumber(temp->getNumber() - 1);
                newTree->setNext(temp);
                newTree->setPrev(temp->getPrev());
                temp->getPrev()->setNext(newTree);
                temp->setPrev(newTree);
            }
            emptyPlace--;
        }
    }

    WOOD_CLASS *getWoodPointer(unsigned int i) {
        WOOD_CLASS *temp = head;
        while (temp != NULL && temp->getNumber() != i) {
            temp = temp->getNext();
        }
        return temp;
    }

    ~GARDEN_CLASS() {
        WOOD_CLASS *temp = head;
        WOOD_CLASS *prev = NULL;
        while (temp != NULL) {
            prev = temp;
            temp = temp->getNext();
            delete prev;
        }
        head = NULL;
        tail = NULL;
        emptyPlace = 0;
    }
};
