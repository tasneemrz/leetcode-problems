class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> mainFolders;
        mainFolders.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string mainFolder = mainFolders.back();
            // subfolders will have a slash after main folder
            mainFolder += '/'; 

            // find if main folder is a substring of the current folder[i]
            size_t index = folder[i].find(mainFolder);

            // if not found or not found at the beginning of folder[i]
            // then folder[i] is a new main folder
            if (index == string::npos || index != 0) {
                mainFolders.push_back(folder[i]);
            }
        }
    
        return mainFolders;
    }
};