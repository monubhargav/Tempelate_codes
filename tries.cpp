#include <iostream>
using namespace std;

// Trie implementation for small_case letters
struct Node
{
    int count_words = 0;
    int count_prefix = 0; // it will count number of words ends with the given prefix
    Node *arr[26];
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
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            // there might be previously word[i] may be present
            if (!temp->contains(word[i])) // if  node letter is not present at that position
            {
                Node *new_node = new Node();
                temp->arr[word[i] - 'a'] = new_node;
            }
            temp = temp->arr[word[i] - 'a'];
            temp->count_prefix++;
        }
        temp->count_words++;
    }

    int search(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!temp->contains(word[i]))
                return 0;
            temp = temp->arr[word[i] - 'a'];
        }
        return temp->count_words;
    }

    int startsWith(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!temp->contains(word[i]))
                return false;
            temp = temp->arr[word[i] - 'a'];
        }
        return temp->count_prefix;
    }
    void erase(string word)
    {
        Node *temp = root;
        if (search(word) == 0)
            return;
        // deletion only if word already exists in trie
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            temp = temp->arr[word[i] - 'a'];
            temp->count_prefix--;
        }
        temp->count_words--;
    }
};

int main()
{
    Trie *t1 = new Trie();
    t1->insert("herbal");
    t1->insert("herbs");
    t1->insert("her");
    t1->insert("her");
    t1->insert("harsh");
    t1->insert("hero");
    // cout << t1->search("her") << endl;
    // cout << t1->startsWith("he") << endl;
    // cout << t1->startsWith("haro") << endl;
    // cout << t1->startsWith("herbs") << endl;
    // cout << t1->startsWith("h") << endl;
    // cout<<endl;

    // cout << t1->search("herbs") << endl;
    // cout << t1->startsWith("her") << endl;
    t1->erase("herbs");
    // cout << t1->search("herbs") << endl;
    // cout << t1->startsWith("her") << endl;
    return 0;
}
