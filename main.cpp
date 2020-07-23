class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> tempSet;
        
        for (int i = 0; i < emails.size(); ++i) {
            const string &str = emails[i];
            string tempStr = "";
            bool plusFound = false;
            
            for (int j = 0; j < str.size(); ++j) {
                if (str[j] != '.') {
                    if (str[j] == '+') {
                        plusFound = true;    
                    }
                    else if (str[j] == '@') {
                        tempStr += str.substr(j, str.size() - j);
                        break;
                    }
                    else {
                        if (!plusFound) {
                            tempStr += str[j];
                        }
                    }
                }
            }
            
            tempSet.insert(tempStr);
        }
        return tempSet.size();
    }
};
