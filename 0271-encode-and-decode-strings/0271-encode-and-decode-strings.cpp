#include <string>
class Codec {
public:
    vector<int> idxs; 
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        idxs.clear();
        std::string str;
        for (int i = 0; i < strs.size(); i++){
            str.append(strs[i]);
            idxs.push_back(strs[i].size());
        }
        cout << "encoded string: " << str << "\n";
        cout << "mapped array: ";
        for (int i = 0; i < idxs.size(); i++){
            cout << idxs[i] << ",";
        }
        cout << "\n";
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> answer;
        int pos = 0; // index into s

        for (int k = 0; k < idxs.size(); k++) {
            answer.push_back(s.substr(pos, idxs[k]));
            pos += idxs[k];
        }

        cout << "answer: ";
        for (int i = 0; i < (int)answer.size(); i++) {
            cout << answer[i] << ",";
        }
        cout << "\n";

        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));