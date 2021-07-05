//Jan Skwarczek

using namespace std;

template<typename KEY_TYPE, typename DATA_TYPE>
class BST{

    struct Node{
        KEY_TYPE key;
        DATA_TYPE data;

        Node* left;
        Node* right;
    };

public:

    Node* root;

    BST(){
        root = NULL;
    }

    ~BST(){
        freeTree(root);
    }

    void freeTree(Node* node){
        if(node){
            freeTree(node->left);
            freeTree(node->right);

            delete node;
        }
    }

    bool Insert(KEY_TYPE inputKey, DATA_TYPE inputData){
        return Insert(root, inputKey, inputData);
    }
    bool Insert(Node*& node, KEY_TYPE inputKey, DATA_TYPE inputData){
        if(!node){

            Node* temp = new Node();

            temp->key = inputKey;
            temp->data = inputData;

            temp->left = NULL;
            temp->right = NULL;

            node = temp;

            return true;
        }
        else{
            if(node->key < inputKey) {
                return Insert(node->right, inputKey, inputData);
            }
            else if(inputKey < node->key) {
                return Insert(node->left, inputKey, inputData);
            }
        }
        return false;
    }

    void PreOrder(){
        PreOrder(root);
    }
    void PreOrder(Node *node){
        if(node){
            cout << node->key << node->data;
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }

    void InOrder(){
        InOrder(root);
    }
    void InOrder(Node *node){
        if(node){
            InOrder(node->left);
            cout << node->key << node->data;
            InOrder(node->right);
        }
    }

    void PostOrder(){
        PostOrder(root);
    }
    void PostOrder(Node *node){
        if(node){
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->key << node->data;
        }
    }
    void LevelOrder(){

        for (int i = 1; i <= Height()+1; i++) {
            LevelOrder(root, i);
        }
    }
    void LevelOrder(Node* node, int level){

        if(node){
            if (level == 1)
                cout << node->key << node->data;
            else if (1 < level)
            {
                LevelOrder(node->left, level-1);
                LevelOrder(node->right, level-1);
            }
        }
    }

    DATA_TYPE* Search(KEY_TYPE inputKey){
        return Search(root, inputKey);
    }
    DATA_TYPE* Search(Node* node, KEY_TYPE inputKey){
        if(node){
            if(!(node->key < inputKey) && !(inputKey < node->key)) //node->key == inputKey
                return &(node->data);
            else if(inputKey < node->key)
                return Search(node->left, inputKey);
            else if(node->key < inputKey)
                return Search(node->right, inputKey);
        }

        return NULL;
    }

    int Height(){
        return Height(root);
    }
    int Height(Node* node){

        if (!node)
            return -1;

        else{
            int left_height = Height(node->left);
            int right_height = Height(node->right);

            if (right_height < left_height)
                return(left_height + 1);

            else
                return(right_height + 1);
        }
    }

    bool Delete(KEY_TYPE inputKey){

        bool didDelete = false;

        root = Delete(root, inputKey, didDelete);

        return didDelete;
    }

    Node* Delete(Node* node, KEY_TYPE inputKey, bool& didDelete){

        if (!node)
            return node;

        if (inputKey < node->key) {
            node->left = Delete(node->left, inputKey, didDelete);
            return node;
        }
        else if (node->key < inputKey) {
            node->right = Delete(node->right, inputKey, didDelete);
            return node;
        }

        //node ma jedno dziecko
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            didDelete = true;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            didDelete = true;
            return temp;
        }

            //node ma dwojke dzieci
        else {
            Node* successorParent = node;

            //znajdowanie successora
            Node* successor = node->right;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            //usuwanie successora
            if (!(!(node < successorParent) && !(successorParent < node)))
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            //kopiowanie danych z successora do wezla
            node->key = successor->key;
            node->data = successor->data;

            //usuwanie successora
            didDelete = true;
            delete successor;
            return node;
        }
    }

};