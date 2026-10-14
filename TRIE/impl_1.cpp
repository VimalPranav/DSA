#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord = false;
    int cnt = 0;
    bool contains(char c){
        return children[c - 'a'] != nullptr;
    }
};

class Trie {
    TrieNode* root;
    int count = 0;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char c : word){
            if(!node->contains(c)){
                node->children[c - 'a'] = new TrieNode();
                count++;
            }
            node = node->children[c - 'a'];
            node->cnt++;
        }
        node->isEndOfWord = true;
    }

    bool search(string word){
        TrieNode* node = root;
        for(char c : word){
            if(!node->contains(c)) return false;
            node = node->children[c-'a'];
        }
        if(node->isEndOfWord) return true;
        return false;
    }

    bool startsWith(string word){
        TrieNode* node = root;
        for(char c : word){
            if(!node->contains(c)) return false;
            node = node->children[c-'a'];
        }
        return true;
    }

    int countWordsEqualTo(string word){
        int cnt = 0;
        TrieNode* node = root; 
        for(char c : word){
            if(!node->contains(c)) return 0;
            node = node->children[c-'a'];
        }
        if(node->isEndOfWord) return node->cnt;
        return 0;
    }

    int countWordsStartingWith(string word){
        int cnt = 0;
        TrieNode* node = root; 
        for(char c : word){
            if(!node->contains(c)) return 0;
            node = node->children[c-'a'];
        }
        return node->cnt;
    }

    void erase(string word){
        TrieNode* node = root;
        for(char c : word){
            if(!node->contains(c)) return;
            node->children[c-'a']->cnt--;
            node = node->children[c-'a'];
        }
    }

    int countDistinctSubstrings(string s) {
        return count+1;
    }
};

int main() {
    Trie* trie = new Trie();
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> arguments = { {}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"} };

    vector<string> output;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "Trie") {
            output.push_back("null");
        } else if (operations[i] == "insert") {
            trie->insert(arguments[i][0]);
            output.push_back("null");
        } else if (operations[i] == "search") {
            bool result = trie->search(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        } else if (operations[i] == "startsWith") {
            bool result = trie->startsWith(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        }
    }

    for (string res : output) {
        cout << res << endl;
    }

    delete trie;
    cout << "------------------------" << endl;

    Trie trie2;
    trie2.insert("apple");
    trie2.insert("apple");
    cout << "Inserting strings 'apple' twice into trie2" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie2.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie2.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie2" << endl;
    trie2.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie2.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie2.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie2" << endl;
    trie2.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie2.countWordsStartingWith("app") << endl;
    cout << "------------------------" << endl;

    Trie trie3;

    string s = "aba";  
    cout << "Current String: " << s << endl;
    for(int i=0; i<s.length(); i++){
        string suffix = s.substr(i);
        trie3.insert(suffix);
    }
    // Input string
    cout << "Number of distinct substrings: " << trie3.countDistinctSubstrings(s) << endl;  
    return 0;
}