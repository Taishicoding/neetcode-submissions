class Solution {
public:

    string encode(vector<string>& strs) {
        string longString;
        for(const auto& s : strs){
            longString += to_string(s.size()) + "#" + s; // Add String , ignore char and string
        }
        return longString;
    }

    vector<string> decode(string s) {
        vector<string> strings;
            int i = 0;
            string number;
            int value;
            while(s[i] != '\0'){
                if(s[i] == '#'){
                    value = stoi(number); // Change the stored string number to actual integer
                    number = "";
                    string temp;
                    ++i; // Move position out of the hash
                    while(value > 0){
                        temp += s[i];
                        ++i;
                        --value;
                    }
                    strings.push_back(temp); // Push the completed string
                }
                if(isdigit(s[i])){
                    number += s[i]; // Adding the number values
                    ++i;
                }else{
                    return strings;
                }

            }
            return strings;
    }
};
