class TrieNode {
  public:
    TrieNode() : children_(26) {}
    ~TrieNode() {
        for (TrieNode* node : children_) {
            delete node; 
        } 
    }
    
    void SetWord(const string& word) {
        word_ = word;
    }
    
    string GetWord() {
        return word_; 
    }
    
    TrieNode* AddChild(char c) {
        char diff = c - 'a'; 
        if (diff < 0 || diff >= 26) {
            return nullptr;
        }
        if (children_[diff] == nullptr) {
            children_[diff] = new TrieNode();
        }
        return children_[diff];
    }
    
    TrieNode* GetChild(char c) {
        char diff = c - 'a';
        if (diff < 0 || diff >= 26) {
            return nullptr;
        }
        return children_[diff]; 
    }
    
  private: 
    std::vector<TrieNode*> children_;   // Owned    
    string word_;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Add `words` to trie.      
        TrieNode root;
        for (const string& word : words) {
            TrieNode* cur = &root;
            for (char c : word) {
                TrieNode* next = cur->AddChild(c);
                cur = next;
            }
            cur->SetWord(word);
        }
        
        std::vector<string> result;
        int row_size = board.size();
        int col_size = board[0].size();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                 findWordsSub(i, j, row_size, col_size, board, &root, result); 
            }
        }
        return result;
    }
    
    void findWordsSub(int row, int col, int row_size, int col_size, std::vector<std::vector<char>>& board, TrieNode* node, std::vector<string>& result) {
        TrieNode* next = node->GetChild(board[row][col]);
        if (next == nullptr) {
            return; 
        }
        string next_word = next->GetWord();
        if (!next_word.empty()) {
            result.push_back(next_word); 
            next->SetWord("");
        }
        
        char original_char = board[row][col];
        board[row][col] = '#';
        if (isValidPosition(row + 1, col, row_size, col_size, board)) {
            findWordsSub(row + 1, col, row_size, col_size, board, next, result);
        }
        if (isValidPosition(row - 1, col, row_size, col_size, board)) {
            findWordsSub(row - 1, col, row_size, col_size, board, next, result);
        }
        if (isValidPosition(row, col + 1, row_size, col_size, board)) {
            findWordsSub(row, col + 1, row_size, col_size, board, next, result);
        }
        if (isValidPosition(row, col - 1, row_size, col_size, board)) {
            findWordsSub(row, col - 1, row_size, col_size, board, next, result);
        }
        board[row][col] = original_char;
        return;
    } 
    
    bool isValidPosition(int row, int col, int row_size, int col_size, const std::vector<std::vector<char>>& board) {
        return row >= 0 && row < row_size && col >= 0 && col < col_size && board[row][col] != '#';
    }
};
