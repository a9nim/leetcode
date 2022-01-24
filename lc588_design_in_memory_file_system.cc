class FileSystem {
  public:
    FileSystem() : root_(true, "") {
    }
    
    vector<string> ls(string path) {
        std::vector<string> result;
        std::vector<string> split_paths = splitPath(path);
        if (split_paths.empty()) {
            for (const auto& filename_node_pair : root_.filename_to_node) {
                result.push_back(filename_node_pair.first); 
            }
        } else {
            FileNode* cur_node = &root_;
            for (const string& split_path : split_paths) {
                if (cur_node->filename_to_node.count(split_path) == 0) {
                    return result;
                } 
                cur_node = cur_node->filename_to_node[split_path].get();
            }
            
            // Check if the last node is directory or not.
            if (cur_node->is_dir) {
                for (const auto& filename_node_pair : cur_node->filename_to_node) {
                    result.push_back(filename_node_pair.first); 
                }
            } else {
                result.push_back(split_paths.back()); 
            }
        }
        std::sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        FileNode* cur_node = &root_;
        std::vector<string> split_paths = splitPath(path);
        for (const string& split_path : split_paths) {
            if (cur_node->filename_to_node.count(split_path) == 0) {
                (cur_node->filename_to_node)[split_path] = std::move(std::make_unique<FileNode>(true, ""));
            } 
            cur_node = cur_node->filename_to_node[split_path].get();
        }
        return;
    }
    
    void addContentToFile(string filePath, string content) {
        FileNode* cur_node = &root_;
        std::vector<string> split_paths = splitPath(filePath);
        for (int i = 0; i < split_paths.size(); ++i) {
            const string& filename = split_paths[i];
            if (i == split_paths.size() - 1) {
                if (cur_node->filename_to_node.count(filename) == 0) {
                    (cur_node->filename_to_node)[filename] = std::move(std::make_unique<FileNode>(false, content));
                } else {
                    FileNode* existing_node = (cur_node->filename_to_node)[filename].get();
                    existing_node->content = existing_node->content + content;
                }
            } else {
                cur_node = cur_node->filename_to_node[filename].get();
            }
        }
        return;
    }
    
    string readContentFromFile(string filePath) {
        FileNode* cur_node = &root_;
        std::vector<string> split_paths = splitPath(filePath);
        for (int i = 0; i < split_paths.size(); ++i) {
            const string& filename = split_paths[i];
            if (i == split_paths.size() - 1) {
                FileNode* existing_node = (cur_node->filename_to_node)[filename].get();
                return existing_node->content;
            } else {
                cur_node = cur_node->filename_to_node[filename].get();
            }
        }
        return "";
    }
    
    std::vector<string> splitPath(const string& filepath) {
        std::vector<string> result;
        if (filepath == "/") {
            return result; 
        } 
        int slash_index = filepath.find("/", 1);
        int prev_slash_index = 0;
        while (slash_index != string::npos) {
            string dirname = filepath.substr(prev_slash_index + 1, slash_index - prev_slash_index - 1); 
            result.push_back(dirname);
            prev_slash_index = slash_index;
            slash_index = filepath.find("/", slash_index + 1);
        }
        string last_name = filepath.substr(prev_slash_index + 1);
        result.push_back(last_name);
        return result;
    }
    
  private:
    struct FileNode {
        FileNode(bool input_is_dir, const string& input_content) : is_dir(input_is_dir), content(input_content) {}
        bool is_dir;
        std::unordered_map<string, std::unique_ptr<FileNode>> filename_to_node;
        string content;
    };
    
    FileNode root_;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
