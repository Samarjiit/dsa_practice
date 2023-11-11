class Graph {
public:
vector<vector<pair<int,int>>>adj; //adjacency list creation using matrix
    Graph(int n, vector<vector<int>>& edges) {
            adj.resize(n);
            for(auto e:edges){
                adj[e[0]].push_back({e[1],e[2]});   //e[0] is the source node 
            }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});//pushing cost and src node

        vector<int>cost(adj.size(),INT_MAX); //storing all the cost of each node;
        cost[node1]=0;

        while(!pq.empty()){
            auto currCost=pq.top().first,currNode=pq.top().second;
            pq.pop();


            for(auto neighbour:adj[currNode]){
                if(cost[neighbour.first]>cost[currNode]+neighbour.second){ //neighbour.first =node 2(Destination)
                    cost[neighbour.first]=cost[currNode]+neighbour.second;
                    pq.push({cost[neighbour.first],neighbour.first});
                }
            }
        }
        return cost[node2]==INT_MAX?-1:cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);


 //using djikstra algorithm
 */