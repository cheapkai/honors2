class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int dr[6][6][6][6][6][6];
        
        for(int a=0;a<6;a++)
            for(int b=0;b<6;b++)
                for(int c=0;c<6;c++)
                    for(int d=0;d<6;d++)
                        for(int e=0;e<6;e++)
                            for(int f=0;f<6;f++)
                            {
                                dr[a][b][c][d][e][f]=-1;
                                
                            }
        
        vector<int> va;
        va.push_back(1);va.push_back(2);va.push_back(3);va.push_back(4);va.push_back(5);va.push_back(0);
        vector<int> st;
        for(int y=0;y<board.size();y++)
            for(int j=0;j<board[y].size();j++)
            {
                st.push_back(board[y][j]);
                
            }
        
        
    }
};