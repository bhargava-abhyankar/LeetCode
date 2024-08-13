class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool is_terminal;

        TrieNode(char c) 
        {
            data = c;
            is_terminal = false;

            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
};

class Trie {
    TrieNode* root;
public:

    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) 
    {
        TrieNode *traverse = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if(traverse->children[ch - 'a'] == NULL) {
                traverse->children[ch - 'a'] = new TrieNode(ch);
            }
            traverse =  traverse->children[ch - 'a'];
        }
        traverse->is_terminal = true;
    }
    
    bool search(string word) 
    {
        TrieNode *traverse = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if(traverse->children[ch - 'a'] == NULL) {
                return false;
            }
            traverse = traverse->children[ch - 'a'];
        }
        return traverse->is_terminal;        
    }
    
    bool startsWith(string prefix) {
        TrieNode *traverse = root;

        for(int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];

            if(traverse->children[ch - 'a'] == NULL) {
                return false;
            }
            traverse = traverse->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */