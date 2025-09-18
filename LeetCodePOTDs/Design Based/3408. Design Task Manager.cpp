#include<bits/stdc++.h>
using namespace std;

// T.C :- Constructor: O(m log m)

// add/edit/rmv/execTop: O(log n) per operation

// Space Complexity: O(n)

class TaskManager {
public:

    set<pair<int,pair<int,int> > > st;
    unordered_map<int,pair<int,int>> mp;

    TaskManager(vector<vector<int>>& tasks) {
        
        for(int i=0;i<tasks.size();i++){

            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];

           mp.insert({taskId,{userId,priority}});
           st.insert({-priority,{-taskId,userId}});
        }

    }
    
    void add(int userId, int taskId, int priority) {
        mp.insert({taskId,{userId,priority}});
        st.insert({-priority,{-taskId,userId}});
    }
    
    void edit(int taskId, int newPriority) {
        int oldUserId = mp[taskId].first;
        int oldPriority = mp[taskId].second;
        st.erase({-oldPriority,{-taskId,oldUserId}});
        st.insert({-newPriority,{-taskId,oldUserId}});
        mp.erase(taskId);
        mp.insert({taskId,{oldUserId,newPriority}});
    }
    
    void rmv(int taskId) {

        int priority = mp[taskId].second;
        int userId = mp[taskId].first;
        st.erase({-priority,{-taskId,userId}});
        mp.erase(taskId);
    }
    
    int execTop() {
        
        int result = abs(st.begin()->second.second);
        int taskId = abs(st.begin()->second.first);
        int priority = mp[taskId].second;
        int userId = mp[taskId].first;
        st.erase({-priority,{-taskId,userId}});
        mp.erase(taskId);
        if(result != userId){
            return -1;
        }
        return result;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */