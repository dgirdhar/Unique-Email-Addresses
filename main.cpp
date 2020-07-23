class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> tempMap;
        
        for (int i = 0; i < emails.size(); ++i) {
            const string &str = emails[i];
            char tempStr[100] = {0};
            int index = 0;
            bool plusFound = false;
            
            for (int j = 0; j < str.size(); ++j) {
                if (str[j] != '.') {
                    if (str[j] == '+') {
                        for (; str[j] != '@'; ++j) {
                        }
                        j--;
                    }
                    else if (str[j] == '@') {
                        for (; j < str.size(); ++j) {
                            tempStr[index++] = str[j];
                        }
                        break;
                    }
                    else {
                        tempStr[index++] = str[j];
                    }
                }
            }
            
            tempMap.insert(pair<string, int>(tempStr, 0));
        }
                           
        return tempMap.size();
    }
};
