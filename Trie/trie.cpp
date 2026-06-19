#include <iostream>
#include <string>
#include <vector>

/**
 * ============================================================================
 * THEORY: WHAT IS A TRIE NODE?
 * ============================================================================
 * Instead of storing strings as a whole, a Trie breaks them into characters.
 * Each Node represents a single character in a path, but it does not explicitly
 * store its own character. Instead, its position in the parent's `children`
 * array implicitly determines which character it represents (index 0='a', 1='b', etc.).
 * * Space Complexity Optimization Note:
 * Using a fixed array of size 26 is highly efficient for time ($O(1)$ random access),
 * but can be memory-heavy if the tree has many sparse branches. For universal
 * character sets, a std::unordered_map<char, TrieNode*> can be used instead.
 * ============================================================================
 */
struct TrieNode
{
    // Array of 26 pointers to represent lowercase English alphabets ('a' through 'z')
    TrieNode *children[26];

    // Flag to mark if a complete word ends at this specific node
    bool isEndOfWord;

    // Constructor to initialize a clean node
    TrieNode()
    {
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

    // Helper function for memory cleanup (Post-order traversal)
    void clear(TrieNode *node)
    {
        if (!node)
            return;
        for (int i = 0; i < 26; i++)
        {
            clear(node->children[i]);
        }
        delete node;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Destructor ensures no memory leaks occur
    ~Trie()
    {
        clear(root);
    }

    /**
     * ============================================================================
     * OPERATION 1: INSERTION
     * ============================================================================
     * Time Complexity: $O(L)$ where L is the length of the word.
     * Space Complexity: $O(L)$ worst-case (if no prefix is shared, L new nodes created).
     * * How it works:
     * 1. Start at the root.
     * 2. For each character, calculate its index (0 to 25).
     * 3. If the pointer at that index is null, instantiate a new TrieNode.
     * 4. Move the current pointer to that child node.
     * 5. Once the loop finishes, mark `isEndOfWord = true` on the final node.
     * ============================================================================
     */
    void insert(const std::string &word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            int index = ch - 'a'; // Map 'a'-'z' to 0-25

            // If the path doesn't exist, create a new branch
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            // Move down to the next node
            current = current->children[index];
        }

        // Mark the last node as the end of a valid word
        current->isEndOfWord = true;
    }

    /**
     * ============================================================================
     * OPERATION 2: EXACT SEARCH
     * ============================================================================
     * Time Complexity: $O(L)$ where L is the length of the word.
     * Space Complexity: $O(1)$ auxiliary space.
     * * How it works:
     * 1. Traverse character by character from the root.
     * 2. If at any step `children[index]` is null, the word does not exist ($O(1)$ early exit).
     * 3. If you reach the end of the word successfully, return `current->isEndOfWord`.
     * (This distinguishes between a full word and just a prefix).
     * ============================================================================
     */
    bool search(const std::string &word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            int index = ch - 'a';
            if (current->children[index] == nullptr)
            {
                return false; // Character missing -> word doesn't exist
            }
            current = current->children[index];
        }

        // Return true only if it is explicitly marked as a complete word
        return current->isEndOfWord;
    }

    /**
     * ============================================================================
     * OPERATION 3: PREFIX SEARCH (startsWith)
     * ============================================================================
     * Time Complexity: $O(L)$ where L is the length of the prefix.
     * Space Complexity: $O(1)$ auxiliary space.
     * * How it works:
     * Identical to the search operation, except we do not care if `isEndOfWord`
     * is true or false at the end. If we successfully navigated the entire path of
     * the prefix without hitting a null pointer, some word starting with this
     * prefix must exist in the Trie.
     * ============================================================================
     */
    bool startsWith(const std::string &prefix)
    {
        TrieNode *current = root;

        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (current->children[index] == nullptr)
            {
                return false; // Prefix path broken
            }
            current = current->children[index];
        }

        return true; // Whole prefix path found successfully
    }
};

// ============================================================================
// DEMONSTRATION & VERIFICATION
// ============================================================================
int main()
{
    Trie myTrie;

    std::cout << std::boolalpha; // Forces terminal to print true/false instead of 1/0
    std::cout << "--- Trie Data Structure Verification ---\n\n";

    // Inserting strings
    std::cout << "Inserting: 'apple', 'app', 'bats', 'bat'\n";
    myTrie.insert("apple");
    myTrie.insert("app");
    myTrie.insert("bats");
    myTrie.insert("bat");
    std::cout << "Insertion complete.\n\n";

    // Exact Match Search Tests
    std::cout << "1. Search exact word 'apple': " << myTrie.search("apple") << " (Expected: true)\n";
    std::cout << "2. Search exact word 'app': " << myTrie.search("app") << " (Expected: true)\n";
    std::cout << "3. Search exact word 'appl': " << myTrie.search("appl") << " (Expected: false)\n";
    std::cout << "4. Search exact word 'batman': " << myTrie.search("batman") << " (Expected: false)\n\n";

    // Prefix Search Tests
    std::cout << "5. Prefix startsWith 'appl': " << myTrie.startsWith("appl") << " (Expected: true)\n";
    std::cout << "6. Prefix startsWith 'ba': " << myTrie.startsWith("ba") << " (Expected: true)\n";
    std::cout << "7. Prefix startsWith 'xyz': " << myTrie.startsWith("xyz") << " (Expected: false)\n";

    return 0;
}