/*
*The Trie (Prefix Tree)
A Trie (typically pronounced "try" to distinguish it from a tree, deriving from the word retrieval)
is a specialized tree-based data structure used for storing a collection of strings. Unlike a
binary search tree, nodes in a Trie do not store the key associated with that node.
Instead, the node's position in the tree defines the key with which it is associated.

All descendants of a particular node share a common string prefix associated with that node,
and the root is associated with the empty string.

*Key Characteristics
Fast Lookups: Tries offer incredibly fast word retrieval.
The time complexity for searching, inserting, or deleting a word is $O(L)$,
where $L$ is the length of the word. This is often faster than hash tables
because there are no hash collisions.

Prefix Matching: Because strings are stored character-by-character along paths,
Tries are exceptionally good at finding all words that share a specific prefix.

Memory Intensive: The main drawback is space complexity.
Every node can contain multiple pointers

*Common Use Cases
Autocomplete/Typeahead: Predicting the rest of a word as a user types.

Spell Checkers: Storing dictionaries and quickly validating if a word exists.

IP Routing: Looking up longest prefix matches for routing tables.

Word Games: Efficiently solving games like Boggle or Scrabble.






*/