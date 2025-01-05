#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->child[index] == NULL) {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->child[index] == NULL) {
                return false;
            }
            node = node->child[index];
        }
        return node->isEndOfWord;
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->child[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    bool Delete(TrieNode* node, string word, int depth) {
        if (depth == word.size()) {
            if (node->isEndOfWord == false) {
                return false;
            }
            node->isEndOfWord = false;
            return isEmpty(node);
        }

        int index = word[depth] - 'a';
        if (node->child[index] == NULL) {
            return false;
        }

        bool shouldDeleteChild = Delete(node->child[index], word, depth + 1);
        if (shouldDeleteChild) {
            delete node->child[index];
            node->child[index] = NULL;
            return !node->isEndOfWord && isEmpty(node);
        }
        return false;
    }

    void deleteWord(string word) {
        Delete(root, word, 0);
    }
};

int main() {
    Trie* tree = new Trie();
    tree->insert("apple");
    tree->insert("apex");
    tree->insert("almond");

    cout << "Does it exist? " << tree->search("apple") << endl;
    cout << "Does it exist? " << tree->search("app") << endl;

    tree->deleteWord("apple");
    cout << "After deletion, does it exist? " << tree->search("apple") << endl;

    return 0;
}
