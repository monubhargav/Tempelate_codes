#include <iostream>
using namespace std;

// Trie implementation for small letters
struct Node
{
    Node *arr[26];
    bool flag = false;
    bool contains(char c)
    {
        return (arr[c - 'a'] != NULL);
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            // there might be previously word[i] may be present
            if (!temp->contains(word[i]))
            {
                Node *new_node = new Node();
                temp->arr[word[i] - 'a'] = new_node;
            }
            temp = temp->arr[word[i] - 'a'];
        }
        temp->flag = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!temp->contains(word[i]))
                return false;
            temp = temp->arr[word[i] - 'a'];
        }
        return temp->flag;
    }

    bool startsWith(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!temp->contains(word[i]))
                return false;
            temp = temp->arr[word[i] - 'a'];
        }
        return (temp != NULL);
    }
};

int main()
{
    Trie *t1 = new Trie();
    t1->insert("herbal");
    t1->insert("herbs");
    t1->insert("her");
    t1->insert("harsh");
    t1->insert("hero");
    cout << t1->search("her") << endl;    // True
    cout << t1->startsWith("he") << endl; // True
    cout << t1->startsWith("haro") << endl;  // False
    return 0;
}
