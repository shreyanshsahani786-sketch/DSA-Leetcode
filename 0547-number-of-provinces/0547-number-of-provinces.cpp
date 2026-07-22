class Solution {
public:

    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& visited)
    {
        // Mark current city as visited
        visited[city] = true;

        int n = isConnected.size();

        // Visit all connected cities
        for(int neighbour = 0; neighbour < n; neighbour++)
        {
            if(isConnected[city][neighbour] == 1 &&
               !visited[neighbour])
            {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();

        vector<bool> visited(n, false);

        int provinces = 0;

        for(int city = 0; city < n; city++)
        {
            if(!visited[city])
            {
                provinces++;

                dfs(city, isConnected, visited);
            }
        }

        return provinces;
    }
};