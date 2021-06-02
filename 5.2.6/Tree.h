#pragma once

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

    void insert_helper(Node* &rt, const char ch) {
      if (rt == nullptr)
        rt = new Node(ch, nullptr, nullptr);
      else if (ch < rt->data)
        insert_helper(rt->left, ch);
      else
        insert_helper(rt->right, ch);
    }


    Node* find_helper(char ch, Node* &rt) {
      if (rt == nullptr) {
        return nullptr;
      } else {
        if (ch > rt->data) {
          return find_helper(ch, rt->right);
        } else if (ch < rt->data) {
          return find_helper(ch, rt->left);
        } else {
          return rt;
        }
      }
    }
    int count_helper(char ch, Node* rt) {
      return rt == nullptr ? 0 : 1 + count_helper(ch, rt->left) + count_helper(ch, rt->right);
    }

public:
    Tree() {
      root = nullptr;
    }
    int count(char ch) {
      Node* rt = find_helper(ch, root);
      return count_helper(ch, rt) - 1;
    }
    void insert(const char& ch) {
      Node* rt = find_helper(ch, root);
      if (rt != nullptr) {
        rt->count++;
        return;
      }
      insert_helper(root, ch);
    }
};

