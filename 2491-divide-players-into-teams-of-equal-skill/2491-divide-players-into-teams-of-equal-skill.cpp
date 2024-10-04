class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());

        long long target_team_sum = skill[0] + skill[n-1]; 
        int i = 0, j = skill.size()-1;
        long long chemistry = 0;

        while(i < j) {
            if((skill[i] + skill[j]) != target_team_sum) 
                return -1;
            chemistry += (skill[i] * skill[j]);
            i++;
            j--;
        }

        return chemistry;
    }
};