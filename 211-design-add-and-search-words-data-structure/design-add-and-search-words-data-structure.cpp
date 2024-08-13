class TrieNode {
    public:
        char data;
        bool is_terminal;
        TrieNode* children[26];

        TrieNode(char ch)
        {
            data = ch;
            is_terminal = false;

            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() 
    {
        root = new TrieNode('\0');
    }
    
    void addWord(string word) 
    {
        TrieNode *traverse = root;

        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if(traverse->children[ch - 'a'] == NULL) {
                traverse->children[ch - 'a'] = new TrieNode(ch);
            }

            traverse = traverse->children[ch - 'a']; 
        }

        traverse->is_terminal = true;
    }

    bool search_a_node(string word, TrieNode *cur, int index)
    {
        if(index == word.length()) {
            return cur->is_terminal;
        }

        char ch = word[index];

        if(ch == '.') {

            for(int i = 0; i < 26; i++) {
                if(cur->children[i] && search_a_node(word, cur->children[i], index + 1))
                    return true;
            }
            return false;

        } else {

            if ((cur->children[ch - 'a']) == NULL) {
                return false;
            }

            return search_a_node(word, cur->children[ch - 'a'], index + 1);
        }
    }

    bool search(string word) 
    {
        return search_a_node(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */