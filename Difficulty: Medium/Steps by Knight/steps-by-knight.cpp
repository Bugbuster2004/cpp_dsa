//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




int dx[8]={-2,2,-1,-1,-2,2,1,1};
int dy[8]={1,1,-2,2,-1,-1,-2,2};
 
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
bool isValid(int i,int j,int &N,vector<vector<bool>> &visited){
    if(i<0 || j<0 || i>=N || j>=N || visited[i][j])
        return false;
    return true;
}
 
 
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    // Code here
    queue<pair<int,pair<int,int>>> q;//cost,i,j
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    
    int desx=TargetPos[0]-1;
    int desy=TargetPos[1]-1;
    
    int i=KnightPos[0]-1;
    int j=KnightPos[1]-1;
    
    q.push({0,{i,j}}); //cost,i,j
    visited[i][j]=true;
    
        while(!q.empty()){
            auto z=q.front();
            q.pop();
            
            int cost=z.first;
            int x=z.second.first;
            int y=z.second.second;
            
            if(x==desx && y==desy)
                return cost;
            
            for(int ii=0;ii<8;ii++){
                int tx=x+dx[ii];
                int ty=y+dy[ii];
            
                if(isValid(tx,ty,N,visited)){
                    q.push({cost+1,{tx,ty}});
                    visited[tx][ty]=true;
                }
            }
            
        }
    return -1;
}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends