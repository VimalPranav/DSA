#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(ll i = 0; i < n; i++)

class Solution {
public:
    Solution() {}

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<string> q;
        q.push(startWord);
        int ladderLength = 0;
        vector<string> visited(wordList.size());
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(startWord);

        while(!q.empty()){
            ladderLength++;
            int size = q.size();
            f(i, size){
                string word = q.front();
                q.pop();
                
                if(word == targetWord) return ladderLength;

                f(i, word.size()){
                    char originalChar = word[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[i] = c;
                        if(wordSet.find(word) != wordSet.end()){
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = originalChar;
                }
            }
        }
            
        return 0;
    }
};

int main() {
    vector<string> wordList = {"geek", "gefk"};
    string startWord = "geek", targetWord = "gefk";

    Solution obj;
    cout << obj.wordLadderLength(startWord, targetWord, wordList) << endl;
    return 0;
}