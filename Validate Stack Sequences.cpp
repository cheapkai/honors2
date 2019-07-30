class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> s1;
        for(int y=(popped.size()-1);y>=0;y--)
        {
            s1.push(popped[y]);
        }
    stack<int> s2;
        for(int j=0;j<pushed.size();j++)
        {
            s2.push(pushed[j]);
        if(!s2.empty())
        {
            if(s1.top()==s2.top()){
                cout << s2.top() << endl;s1.pop();s2.pop();
            }
        }
        }
        
        if(s1.empty() && s2.empty()){return true;}
        
            
            while(!s1.empty() && !s2.empty() && (s1.top() == s2.top()))
            {s1.pop();s2.pop();}
        
        if(s1.empty() && s2.empty())return true;
        }
        return false;
    }
};