//Jan Skwarczek

#include <iostream>

using namespace std;

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

    FRUIT_CLASS* getNext();
    void setNext(FRUIT_CLASS *nxt);
    FRUIT_CLASS* getPrev();
    void setPrev(FRUIT_CLASS *nxt);
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();

    FRUIT_CLASS(BRANCH_CLASS *pointer = NULL, int position = 0, FRUIT_CLASS *previous = NULL, unsigned int w = 0,
                FRUIT_CLASS *nxt = NULL) {
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
    unsigned int totalWeight;
    unsigned int totalFruits;
    unsigned int length;
    unsigned int height;

public:

    void displayAll();

    WOOD_CLASS *getWoodPointer();
    BRANCH_CLASS *getNext();
    void setNext(BRANCH_CLASS *pointer);
    void setHeight(unsigned int h);
    BRANCH_CLASS *getPrev();
    void setPrev(BRANCH_CLASS *pointer);
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void increaseFruitsTotal(unsigned int fruitAmount);
    void increaseWeightsTotal(unsigned int weightAmount);
    void decreaseFruitsTotal(unsigned int fruitAmount);
    void decreaseWeightsTotal(unsigned int weightAmount);
    unsigned int getHeight();
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int w);
    void cutBranch(unsigned int len);
    FRUIT_CLASS *getFruitPointer(unsigned int l);


    BRANCH_CLASS(WOOD_CLASS *pointer = NULL, unsigned int h = 0, unsigned int l = 0, BRANCH_CLASS *previous = NULL,
                 BRANCH_CLASS *nxt = NULL) {

        tree = pointer;
        prev = previous;
        next = nxt;
        totalWeight = 0;
        totalFruits = 0;
        height = h;
        length = l;
        head = NULL;
        tail = NULL;
    }

    BRANCH_CLASS(const BRANCH_CLASS &currElem, WOOD_CLASS *pointer = NULL, unsigned int h = 0,
                 BRANCH_CLASS *previous = NULL, BRANCH_CLASS *nxt = NULL) {

        totalWeight = currElem.totalWeight;
        totalFruits = currElem.totalFruits;
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
        totalWeight = 0;
        totalFruits = 0;
        length = 0;
        height = 0;
    }
};

class WOOD_CLASS {

private:
    BRANCH_CLASS *head;
    BRANCH_CLASS *tail;
    GARDEN_CLASS *garden;
    unsigned int totalWeight;
    unsigned int totalFruits;
    unsigned int totalBranches;
    unsigned int id;
    unsigned int height;
    WOOD_CLASS *next;
    WOOD_CLASS *prev;

public:

    void displayAll();

    unsigned int getHeight();
    GARDEN_CLASS *getGardenPointer();
    unsigned int getNumber();
    WOOD_CLASS *getNext();
    WOOD_CLASS *getPrev();
    void setNumber(unsigned int num);
    void setPrev(WOOD_CLASS *pointer);
    void setNext(WOOD_CLASS *pointer);
    void setLast(BRANCH_CLASS *pointer);
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void increaseBranchesTotal(unsigned int branchAmount);
    void increaseFruitsTotal(unsigned int fruitAmount);
    void increaseWeightsTotal(unsigned int weightAmount);
    void decreaseBranchesTotal(unsigned int branchAmount);
    void decreaseFruitsTotal(unsigned int fruitAmount);
    void decreaseWeightsTotal(unsigned int weightAmount);
    void growthWood();
    void fadeWood();
    void harvestWood(unsigned int w);
    void cutWood(unsigned int h);
    BRANCH_CLASS *getBranchPointer(unsigned int h);
    void cloneBranch(BRANCH_CLASS *currElem);

    WOOD_CLASS(const WOOD_CLASS &currElem, GARDEN_CLASS *pointer = NULL) {

        totalWeight = currElem.totalWeight;
        totalFruits = currElem.totalFruits;
        totalBranches = currElem.totalBranches;
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
        totalWeight = 0;
        totalFruits = 0;
        totalBranches = 0;
        height = 0;
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
        totalWeight = 0;
        totalFruits = 0;
        totalBranches = 0;
        next = NULL;
        prev = NULL;
    }
};

class GARDEN_CLASS {

private:
    WOOD_CLASS *head;
    WOOD_CLASS *tail;
    int emptyPlace;
    unsigned int totalWoods;
    unsigned int totalBranches;
    unsigned int totalFruits;
    unsigned int totalWeights;

public:

    void displayAll();

    unsigned int getWoodsTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void increaseWoodsTotal(unsigned int woodAmount);
    void increaseBranchesTotal(unsigned int branchAmount);
    void increaseFruitsTotal(unsigned int fruitAmount);
    void increaseWeightsTotal(unsigned int weightAmount);
    void decreaseWoodsTotal(unsigned int woodAmount);
    void decreaseBranchesTotal(unsigned int branchAmount);
    void decreaseFruitsTotal(unsigned int fruitAmount);
    void decreaseWeightsTotal(unsigned int weightAmount);
    void plantWood();
    void extractWood(unsigned int i);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int w);
    void cloneWood(unsigned int i);
    WOOD_CLASS *getWoodPointer(unsigned int i);

    GARDEN_CLASS() {
        head = NULL;
        tail = NULL;
        emptyPlace = 0;
        totalWoods = 0;
        totalWeights = 0;
        totalFruits = 0;
        totalBranches = 0;
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
        totalWoods = 0;
        totalBranches = 0;
        totalFruits = 0;
        totalWeights = 0;
        emptyPlace = 0;
    }
};

unsigned int FRUIT_CLASS::getLength() {
    return pos;
}

unsigned int FRUIT_CLASS::getWeight() {
    return weight;
}

void FRUIT_CLASS::growthFruit() {
    weight++;

    if(branch != NULL){
        branch->increaseWeightsTotal(1);
        if(branch->getWoodPointer() != NULL){
            branch->getWoodPointer()->increaseWeightsTotal(1);
            if(branch->getWoodPointer()->getGardenPointer() != NULL){
                branch->getWoodPointer()->getGardenPointer()->increaseWeightsTotal(1);
            }
        }
    }
}

void FRUIT_CLASS::fadeFruit() {
    if (weight > 0){
        weight--;
        if(branch != NULL){
            branch->decreaseWeightsTotal(1);
            if(branch->getWoodPointer() != NULL){
                branch->getWoodPointer()->decreaseWeightsTotal(1);
                if(branch->getWoodPointer()->getGardenPointer() != NULL){
                    branch->getWoodPointer()->getGardenPointer()->decreaseWeightsTotal(1);
                }
            }
        }
    }

}

void FRUIT_CLASS::pluckFruit() {

    if(branch != NULL){
        branch->decreaseWeightsTotal(weight);
        if(branch->getWoodPointer() != NULL){
            branch->getWoodPointer()->decreaseWeightsTotal(weight);
            if(branch->getWoodPointer()->getGardenPointer() != NULL){
                branch->getWoodPointer()->getGardenPointer()->decreaseWeightsTotal(weight);
            }
        }
    }

    weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer() {
    return branch;
}

FRUIT_CLASS* FRUIT_CLASS::getNext() {
    return next;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS *nxt) {
    next = nxt;
}

FRUIT_CLASS* FRUIT_CLASS::getPrev() {
    return prev;
}

void FRUIT_CLASS::setPrev(FRUIT_CLASS *nxt) {
    prev = nxt;
}

/////////////////////////////////////////////////////////////////////////////

WOOD_CLASS* BRANCH_CLASS::getWoodPointer() {
    return tree;
}

BRANCH_CLASS* BRANCH_CLASS::getNext() {
    return next;
}

void BRANCH_CLASS::setNext(BRANCH_CLASS *pointer) {
    next = pointer;
}

void BRANCH_CLASS::setHeight(unsigned int h) {
    height = h;
}

BRANCH_CLASS* BRANCH_CLASS::getPrev() {
    return prev;
}

void BRANCH_CLASS::setPrev(BRANCH_CLASS *pointer) {
    prev = pointer;
}

unsigned int BRANCH_CLASS::getFruitsTotal() {

    return totalFruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {

    return totalWeight;
}

void BRANCH_CLASS::increaseFruitsTotal(unsigned int fruitAmount){
    totalFruits += fruitAmount;
}

void BRANCH_CLASS::increaseWeightsTotal(unsigned int weightAmount){
    totalWeight += weightAmount;
}

void BRANCH_CLASS::decreaseFruitsTotal(unsigned int fruitAmount){
    totalFruits -= fruitAmount;
}

void BRANCH_CLASS::decreaseWeightsTotal(unsigned int weightAmount){
    totalWeight -= weightAmount;
}

unsigned int BRANCH_CLASS::getHeight() {
    return height;
}

unsigned int BRANCH_CLASS::getLength() {
    return length;
}

void BRANCH_CLASS::growthBranch() {
    FRUIT_CLASS *temp = head;

    while (temp != NULL) {
        temp->growthFruit();
        temp = temp->getNext();
    }

    length++;

    if (length % 2 == 0) {

        FRUIT_CLASS *temp = new FRUIT_CLASS(this, length, tail);

        totalFruits++;

        if(tree != NULL) {
            tree->increaseFruitsTotal(1);
            if(tree->getGardenPointer() != NULL)
                tree->getGardenPointer()->increaseFruitsTotal(1);
        }

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

void BRANCH_CLASS::fadeBranch() {

    if (length != 0) {

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

                totalFruits--;
                if(tree != NULL) {
                    tree->decreaseFruitsTotal(1);
                    if(tree->getGardenPointer() != NULL)
                        tree->getGardenPointer()->decreaseFruitsTotal(1);
                }

            } else {

                if (tail->getPrev() != NULL) {
                    tail->getPrev()->setNext(NULL);
                    tail = tail->getPrev();
                }

                delete temp;
                temp = tail;

                totalFruits--;
                if(tree != NULL) {
                    tree->decreaseFruitsTotal(1);
                    if(tree->getGardenPointer() != NULL)
                        tree->getGardenPointer()->decreaseFruitsTotal(1);
                }

                while (temp != NULL) {
                    temp->fadeFruit();
                    temp = temp->getPrev();
                }
            }
            length--;
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int w) {

    FRUIT_CLASS *temp = head;

    while (temp != NULL) {
        if (temp->getWeight() >= w) {
            temp->pluckFruit();
        }
        temp = temp->getNext();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int len) {

    if (len < 0)
        len = 0;

    FRUIT_CLASS *temp = tail;
    FRUIT_CLASS *curr;

    if(tree != NULL){
        tree->decreaseWeightsTotal(totalWeight);
        if(tree->getGardenPointer() != NULL)
            tree->getGardenPointer()->decreaseWeightsTotal(totalWeight);
    }


    while (temp != NULL && temp->getLength() > len) {
        curr = temp;
        totalWeight -= curr->getWeight();
        temp = temp->getPrev();
        delete curr;
        totalFruits--;

        if(tree != NULL) {
            tree->decreaseFruitsTotal(1);
            if(tree->getGardenPointer() != NULL)
                tree->getGardenPointer()->decreaseFruitsTotal(1);
        }

    }

    if(tree != NULL) {
        tree->increaseWeightsTotal(totalWeight);
        if(tree->getGardenPointer() != NULL)
            tree->getGardenPointer()->increaseWeightsTotal(totalWeight);
    }

    if (len <= 1) {
        head = NULL;
        tail = NULL;
    }
    else if (len == 2) {
        tail = head;
        tail->setNext(NULL);
    }
    else {
        tail = temp;
        temp->setNext(NULL);
    }
    length = len;
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int l) {

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
            } else {
                return NULL;
            }
        } else {
            FRUIT_CLASS *temp = head;

            while (temp != NULL && temp->getLength() < l) {
                temp = temp->getNext();
            }

            if (temp != NULL && temp->getLength() == l) {
                return temp;
            } else {
                return NULL;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////

unsigned int WOOD_CLASS::getHeight() {
    return height;
}

GARDEN_CLASS *WOOD_CLASS::getGardenPointer() {
    return garden;
}

unsigned int WOOD_CLASS::getNumber() {
    return id;
}

WOOD_CLASS *WOOD_CLASS::getNext() {
    return next;
}

WOOD_CLASS *WOOD_CLASS::getPrev() {
    return prev;
}

void WOOD_CLASS::setNumber(unsigned int num) {
    id = num;
}

void WOOD_CLASS::setPrev(WOOD_CLASS *pointer) {
    prev = pointer;
}

void WOOD_CLASS::setNext(WOOD_CLASS *pointer) {
    next = pointer;
}

void WOOD_CLASS::setLast(BRANCH_CLASS *pointer) {
    tail = pointer;
}

unsigned int WOOD_CLASS::getBranchesTotal() {

    return totalBranches;
}

unsigned int WOOD_CLASS::getFruitsTotal() {

    return totalFruits;
}

unsigned int WOOD_CLASS::getWeightsTotal() {

    return totalWeight;
}

void WOOD_CLASS::increaseBranchesTotal(unsigned int branchAmount) {
    totalBranches += branchAmount;
}

void WOOD_CLASS::increaseFruitsTotal(unsigned int fruitAmount){
    totalFruits += fruitAmount;
}

void WOOD_CLASS::increaseWeightsTotal(unsigned int weightAmount){
    totalWeight += weightAmount;
}

void WOOD_CLASS::decreaseBranchesTotal(unsigned int branchAmount) {
    totalBranches -= branchAmount;
}

void WOOD_CLASS::decreaseFruitsTotal(unsigned int fruitAmount){
    totalFruits -= fruitAmount;
}

void WOOD_CLASS::decreaseWeightsTotal(unsigned int weightAmount){
    totalWeight -= weightAmount;
}

void WOOD_CLASS::growthWood() {

    if(height >= 2){

        height++;

        if (height % 3 != 0) {
            BRANCH_CLASS *temp = head;

            while (temp != NULL) {
                temp->growthBranch();
                temp = temp->getNext();
            }

        } else {

            if (head == NULL) {
                head = new BRANCH_CLASS(this, height);

                totalBranches++;

                if(garden != NULL) {
                    garden->increaseBranchesTotal(1);
                }

                tail = head;
                head->setPrev(NULL);
                head->setNext(NULL);
            } else {
                BRANCH_CLASS *temp = head;

                while (temp != NULL) {
                    temp->growthBranch();
                    temp = temp->getNext();
                }

                temp = new BRANCH_CLASS(this, height);

                totalBranches++;

                if(garden != NULL) {
                    garden->increaseBranchesTotal(1);
                }

                tail->setNext(temp);
                temp->setPrev(tail);
                temp->setNext(NULL);
                tail = temp;
            }
        }

    }
    else{
        height++;
    }

}

void WOOD_CLASS::fadeWood() {

    if(height != 0){

        if (height % 3 != 0) {
            height--;
            BRANCH_CLASS *temp = head;
            while (temp != NULL) {
                temp->fadeBranch();
                temp = temp->getNext();
            }

        } else {
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
                } else {
                    head = NULL;
                }
                delete temp;

                totalBranches--;
                if(garden != NULL) {
                    garden->decreaseBranchesTotal(1);
                }
            }
        }
    }
}

void WOOD_CLASS::harvestWood(unsigned int w) {

    BRANCH_CLASS *temp = head;

    while (temp != NULL) {

        temp->harvestBranch(w);
        temp = temp->getNext();
    }
}

void WOOD_CLASS::cutWood(unsigned int h) {

    if (h < 0) h = 0;
    height = h;
    BRANCH_CLASS *temp = tail;
    BRANCH_CLASS *prev = NULL;

    if(garden != NULL) {
        garden->decreaseWeightsTotal(totalWeight);
        garden->decreaseFruitsTotal(totalFruits);
    }

    while (temp != NULL && temp->getHeight() > height) {
        prev = temp;

        totalWeight -= temp->getWeightsTotal();
        totalFruits -= temp->getFruitsTotal();

        temp = temp->getPrev();
        delete prev;

        totalBranches--;
        if(garden != NULL) {
            garden->decreaseBranchesTotal(1);
        }
    }

    if(garden != NULL) {
        garden->increaseWeightsTotal(totalWeight);
        garden->increaseFruitsTotal(totalFruits);
    }

    if (height == 3) {
        tail = head;
        tail->setNext(NULL);
    } else if (height <= 2) {
        head = NULL;
        tail = NULL;
    } else {
        tail = temp;
        temp->setNext(NULL);
    }
}

BRANCH_CLASS *WOOD_CLASS::getBranchPointer(unsigned int h) {

    if (h > height || h == 0 || h % 3 != 0) return NULL;

    if (h > height / 2) {

        BRANCH_CLASS *temp = tail;

        while (temp != NULL && temp->getHeight() > h) {
            temp = temp->getPrev();
        }
        return temp;
    } else {
        BRANCH_CLASS *temp = head;

        while (temp != NULL && temp->getHeight() < h) {
            temp = temp->getNext();
        }
        return temp;
    }
}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS *currElem) {

    if(currElem != NULL){
        BRANCH_CLASS *temp = head;

        while (temp != NULL && temp->getLength() > 0) {
            temp = temp->getNext();
        }

        if(temp != NULL){
            BRANCH_CLASS *newBranch = new BRANCH_CLASS(*currElem, this, temp->getHeight());

            totalFruits += newBranch->getFruitsTotal();
            totalWeight += newBranch->getWeightsTotal();

            if(garden != NULL) {
                garden->increaseFruitsTotal(newBranch->getFruitsTotal());
                garden->increaseWeightsTotal(newBranch->getWeightsTotal());
            }

            newBranch->setHeight(temp->getHeight());

            if (temp == head && temp == tail) {
                head = newBranch;
                tail = newBranch;
                delete temp;
            } else if (temp == head) {
                temp->getNext()->setPrev(newBranch);
                newBranch->setNext(temp->getNext());
                head = newBranch;
                delete temp;
            } else if (temp == tail) {
                temp->getPrev()->setNext(newBranch);
                newBranch->setPrev(temp->getPrev());
                tail = newBranch;
                delete temp;
            } else {
                temp->getPrev()->setNext(newBranch);
                temp->getNext()->setPrev(newBranch);
                newBranch->setPrev(temp->getPrev());
                newBranch->setNext(temp->getNext());
                delete temp;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////

unsigned int GARDEN_CLASS::getWoodsTotal() {

    return totalWoods;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {

    return totalBranches;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {

    return totalFruits;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {

    return totalWeights;
}

void GARDEN_CLASS::increaseWoodsTotal(unsigned int woodAmount){
    totalWoods += woodAmount;
}

void GARDEN_CLASS::increaseBranchesTotal(unsigned int branchAmount) {
    totalBranches += branchAmount;
}

void GARDEN_CLASS::increaseFruitsTotal(unsigned int fruitAmount){
    totalFruits += fruitAmount;
}

void GARDEN_CLASS::increaseWeightsTotal(unsigned int weightAmount){
    totalWeights += weightAmount;
}

void GARDEN_CLASS::decreaseWoodsTotal(unsigned int woodAmount){
    totalWoods -= woodAmount;
}

void GARDEN_CLASS::decreaseBranchesTotal(unsigned int branchAmount) {
    totalBranches -= branchAmount;
}

void GARDEN_CLASS::decreaseFruitsTotal(unsigned int fruitAmount){
    totalFruits -= fruitAmount;
}

void GARDEN_CLASS::decreaseWeightsTotal(unsigned int weightAmount){
    totalWeights -= weightAmount;
}

void GARDEN_CLASS::plantWood() {

    if (emptyPlace == 0) {
        if (head == NULL) {
            head = new WOOD_CLASS(this, 0);

            totalWoods++;

            tail = head;
            head->setNext(NULL);
            tail->setPrev(NULL);
        } else {
            WOOD_CLASS *newTree = new WOOD_CLASS(this, tail->getNumber() + 1);

            totalWoods++;

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

            totalWoods++;

            newTree->setNext(head);
            head->setPrev(newTree);
            newTree->setPrev(NULL);
            head = newTree;
        } else {
            newTree = new WOOD_CLASS(this, temp->getNumber() - 1);

            totalWoods++;

            newTree->setNext(temp);
            temp->getPrev()->setNext(newTree);
            newTree->setPrev(temp->getPrev());
            temp->setPrev(newTree);
        }
        if (emptyPlace > 0)
            emptyPlace--;
    }
}

void GARDEN_CLASS::extractWood(unsigned int i) {

    WOOD_CLASS *temp;

    if(tail != NULL){
        if (i < tail->getNumber()) {

            if (i == head->getNumber()) {
                temp = head;
                head = head->getNext();
                head->setPrev(NULL);

                totalWoods--;

                totalFruits -= temp->getFruitsTotal();
                totalBranches -= temp->getBranchesTotal();
                totalWeights -= temp->getWeightsTotal();

                delete temp;

                emptyPlace++;
            } else {
                temp = head;
                while (temp != NULL && temp->getNumber() < i) {
                    temp = temp->getNext();
                }
                if (temp != NULL && temp->getNumber() == i) {
                    temp->getNext()->setPrev(temp->getPrev());
                    temp->getPrev()->setNext(temp->getNext());

                    totalWoods--;

                    totalFruits -= temp->getFruitsTotal();
                    totalBranches -= temp->getBranchesTotal();
                    totalWeights -= temp->getWeightsTotal();

                    delete temp;

                    emptyPlace++;
                }
            }
        } else if (i == tail->getNumber()) {

            temp = tail;

            if (head == tail) {

                head = NULL;
                tail = NULL;

                totalWoods--;

                totalFruits -= temp->getFruitsTotal();
                totalBranches -= temp->getBranchesTotal();
                totalWeights -= temp->getWeightsTotal();

                delete temp;
            } else {
                tail = tail->getPrev();
                tail->setNext(NULL);

                totalWoods--;

                totalFruits -= temp->getFruitsTotal();
                totalBranches -= temp->getBranchesTotal();
                totalWeights -= temp->getWeightsTotal();

                delete temp;
            }
        }
    }

}

void GARDEN_CLASS::growthGarden() {
    WOOD_CLASS *temp = head;

    while (temp != NULL) {
        temp->growthWood();
        temp = temp->getNext();
    }
}

void GARDEN_CLASS::fadeGarden() {
    WOOD_CLASS *temp = head;

    while (temp != NULL) {
        temp->fadeWood();
        temp = temp->getNext();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int w) {
    WOOD_CLASS *temp = head;

    while (temp != NULL) {
        temp->harvestWood(w);
        temp = temp->getNext();
    }
}

void GARDEN_CLASS::cloneWood(unsigned int i) {

    WOOD_CLASS *currElem = head;

    while (currElem != NULL && currElem->getNumber() < i) {
        currElem = currElem->getNext();
    }

    if(currElem != NULL && currElem->getNumber() == i){
        WOOD_CLASS *newTree;
        if (emptyPlace == 0) {
            if (head == NULL) {

                newTree = new WOOD_CLASS(*currElem, this);
                totalWoods++;
                totalBranches += newTree->getBranchesTotal();
                totalFruits += newTree->getFruitsTotal();
                totalWeights += newTree->getWeightsTotal();

                newTree->setNumber(0);
                head = newTree;
                tail = head;
            } else {

                newTree = new WOOD_CLASS(*currElem, this);
                totalWoods++;
                totalBranches += newTree->getBranchesTotal();
                totalFruits += newTree->getFruitsTotal();
                totalWeights += newTree->getWeightsTotal();

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

                totalWoods++;
                totalBranches += newTree->getBranchesTotal();
                totalFruits += newTree->getFruitsTotal();
                totalWeights += newTree->getWeightsTotal();

                newTree->setNumber(0);
                newTree->setNext(head);
                head->setPrev(newTree);
                head = newTree;
            } else if (temp == tail) {
                newTree = new WOOD_CLASS(*currElem, this);

                totalWoods++;
                totalBranches += newTree->getBranchesTotal();
                totalFruits += newTree->getFruitsTotal();
                totalWeights += newTree->getWeightsTotal();

                newTree->setNumber(tail->getNumber() + 1);
                newTree->setPrev(tail);
                tail->setNext(newTree);
                tail = newTree;
            } else {
                newTree = new WOOD_CLASS(*currElem, this);

                totalWoods++;
                totalBranches += newTree->getBranchesTotal();
                totalFruits += newTree->getFruitsTotal();
                totalWeights += newTree->getWeightsTotal();

                newTree->setNumber(temp->getPrev()->getNumber() + 1);
                newTree->setNext(temp);
                newTree->setPrev(temp->getPrev());
                temp->getPrev()->setNext(newTree);
                temp->setPrev(newTree);
            }
            emptyPlace--;
        }
    }

}

WOOD_CLASS *GARDEN_CLASS::getWoodPointer(unsigned int i) {
    WOOD_CLASS *temp = head;
    while (temp != NULL && temp->getNumber() != i) {
        temp = temp->getNext();
    }
    return temp;
}

/////////////////////////////////////////////////////////////////////////////
