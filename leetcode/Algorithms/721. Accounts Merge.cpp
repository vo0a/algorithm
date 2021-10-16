class Solution {
public:   
    
    vector<bool> chk;
    vector<vector<int>> adj;
    vector<vector<string>> acc;
    set<string> s;
    void dfs(int x, int flg) {
        if (flg) {
            for (int i = 1; i < acc[x].size(); i++) {
                s.insert(acc[x][i]);
            }
        }

        for (auto next : adj[x]) {
            if (!chk[next]) {
                chk[next] = true;
                dfs(next, flg);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        acc = accounts;
        int size = accounts.size();
        adj.resize(size + 1);
        chk.resize(size);
        map<string, int> m;
        
        for (int i = 0; i < size; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!m.count(accounts[i][j])) {
                    m[accounts[i][j]] = i;
                }
                else {
                    if (m[accounts[i][j]] == i) continue;
                    adj[m[accounts[i][j]]].push_back(i);
                    adj[i].push_back(m[accounts[i][j]]);
                }
            }
        }
        

        int idx = 0;
        for (int i = 0; i < size; i++) {
            if (!chk[i]) {
                chk[i] = true;
                idx++;
                dfs(i, 0);
            }
        }
        fill(chk.begin(), chk.begin() + size, false);
        vector<vector<string>> ret(idx);
        idx = 0;
        for (int i = 0; i < size; i++) {
            if (!chk[i]) {
                s.clear();
                chk[i] = true;
                ret[idx].push_back(accounts[i][0]);
                dfs(i, 1);
                for (auto e : s) {
                    ret[idx].push_back(e);
                }			
                idx++;
            }
        }
        return ret;
    }
    
};