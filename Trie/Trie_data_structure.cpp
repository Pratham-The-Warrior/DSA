/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Trie Data structure
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    { // constructor
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    /*
        current = root: We start at the top of the tree.
        ch - 'a': A clever ASCII trick. Subtracting the character 'a' from any lowercase letter gives you its alphabetical index (e.g., 'a' - 'a' = 0, 'b' - 'a' = 1, etc.).
        The if condition: If the pointer at that character's index is nullptr, the letter doesn't exist yet, so we dynamically allocate a new TrieNode().
        current = current->children[index]: We step down into that node.
        current->isEndOfWord = true: Once the loop finishes processing every letter, we plant a flag on the final node to mark that a full word ends here.
    */
    void insert(const string &word)
    {
        TrieNode *current = root;
        for (auto ch : word)
        {
            int idx = ch - 'a';
            if (current->children[idx] == nullptr)
            {
                // if nit found make bew branch
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->isEndOfWord = true;
    }

    /*


    */
    bool search(const string &word)
    {
        TrieNode *current = root;
        for (auto ch : word)
        {
            int idx = ch - 'a';
            if (current->children[idx] == nullptr)
            {
                return false;
            }
            current = current->children[idx];
        }

        return current->isEndOfWord;
    }

    bool startsWith(const string &prefix)
    {
        TrieNode *current = root;
        for (auto ch : prefix)
        {
            int idx = ch - 'a';
            if (current->children[idx] == nullptr)
            {
                return false;
            }
            current = current->children[idx];
        }

        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");

    trie.insert("app");

    cout << trie.search("appp");

    return 0;
}