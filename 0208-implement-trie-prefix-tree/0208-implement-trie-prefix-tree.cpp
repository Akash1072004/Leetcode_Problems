class Node {
    public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;

    Node(char data){
        this->data = data;
        this->terminal = false;
    }
    void makeTerminal(){
        this->terminal = true;
    }
    bool isTerminal(){
        return this->terminal == true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else {
                // char not present 
                Node* newNode = new Node(ch);
                cur->children[ch] = newNode;
                cur = newNode;
            }
        }
        cur->makeTerminal();
    }
    
    bool search(string word) {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else {
                // char not present 
                return false;
            }
        }
        return cur->isTerminal();
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            if(cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else {
                // char not present 
                return false;
            }
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