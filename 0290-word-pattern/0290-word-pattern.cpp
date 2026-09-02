
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        // Split string into words
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        // Number of characters and words must be equal
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];

            // Character already mapped to a different word
            if (charToWord.count(ch) && charToWord[ch] != w) {
                return false;
            }

            // Word already mapped to a different character
            if (wordToChar.count(w) && wordToChar[w] != ch) {
                return false;
            }

            // Create the mappings
            charToWord[ch] = w;
            wordToChar[w] = ch;
        }

        return true;
    }
};

