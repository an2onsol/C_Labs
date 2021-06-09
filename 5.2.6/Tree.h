struct Node {
    Node& operator=(const Node node) {
      data = node.data;
      left = node.left;
      right = node.right;
    }
    short int count = 1;
    char data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(const char &x, Node* l, Node* r): data(x), left(l), right(r) {}
};

class Tree {
private:
    Node* root;

    void insert(Node* &rt, const char ch) {
      if (rt == nullptr)
        rt = new Node(ch, nullptr, nullptr);
      else if (ch < rt->data)
        insert(rt->left, ch);
      else
        insert(rt->right, ch);
    }


    Node* find(char ch, Node* &rt) {
      if (rt == nullptr) {
        return nullptr;
      }
      else {
        if (ch > rt->data) {
          return find(ch, rt->right);
        } 
        else if (ch < rt->data) {
          return find(ch, rt->left);
        }
        else {
          return rt;
        }
      }
    }
    int count(char ch, Node* rt) {
      return rt == nullptr ? 0 : 1 + count(ch, rt->left) + count(ch, rt->right);
    }

public:
    Tree() {
      root = nullptr;
    }
    int count(char ch) {
      Node* rt = find(ch, root);
      return count(ch, rt) - 1;
    }
    void insert(const char& ch) {
      Node* rt = find(ch, root);
      if (rt != nullptr) {
        rt->count++;
        return;
      }
      insert(root, ch);
    }
};

