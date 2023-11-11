class Graph {
public:
    unordered_map<int ,vector<pair<int,int>>>adj;
    int N;
    vector<int>result;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    Graph(int n, vector<vector<int>>& edges) {
           N=n;
           for(auto &edge:edges){
               int u=edge[0];
               int v=edge[1];
               int cost=edge[2];

               adj[u].push_back({v,cost});
           }
    }
    
    void addEdge(vector<int> edge) {
    int u=edge[0];
    int v=edge[1];
    int cost=edge[2];

    adj[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>result(N,INT_MAX); //dist from src to all nodes. initialize with infinity
        result[node1]=0;//dist from src to src =0
        pq.push({0,node1});

        while(!pq.empty()){
            int d=pq.top().first; //pair
            int node=pq.top().second;
            pq.pop();

            for(auto &vec:adj[node]){
                    int adjnode=vec.first;
                    int dist=vec.second;
                    if(d+dist<result[adjnode]){
                        result[adjnode]=d+dist;
                        pq.push({d+dist,adjnode});
                    }
            }
        }

        return result[node2]==INT_MAX?-1:result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);


 //using djikstra algorithm
 */