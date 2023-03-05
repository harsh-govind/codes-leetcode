class Solution {
public:
    int minJumps(vector<int>& arr) {
         queue<int> q;
    vector<int> dist(arr.size(),INT_MAX);
 
    if(arr.size()<=1) return 0;
    
    q.push(0);

    map<int,vector<int>> rg;
    
    for(int i=0;i<arr.size();i++)
        rg[arr[i]].push_back(i);
    
    dist[0]=0;
    
    
    
    while(q.size())
    {
        
        int j = q.front();
        q.pop();
      
        
        for(int i=0;i<rg[arr[j]].size();i++)
        {
            if(dist[rg[arr[j]][i]]  > (dist[j]+1) )    
            {
                dist[rg[arr[j]][i]] = (dist[j]+1);
                q.push(rg[arr[j]][i]);
            } 
        }
            
        if(j+1 < arr.size() && dist[j+1] > dist[j]+1)
        {
            dist[j+1] = dist[j]+1;   
            q.push(j+1);
        }
        
        if(j-1 >=0  && dist[j-1] > dist[j]+1)
        {
            dist[j-1] = dist[j]+1;
            q.push(j-1);
        }
        
        
        rg[arr[j]].clear();
       
        
    }
  
    return dist[arr.size()-1];
    }
};