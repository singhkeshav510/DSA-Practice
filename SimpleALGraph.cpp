#include<bits/stdc++.h>
using namespace std;
class Graph{
	int vertex;
	vector<int> *v;
	public:
		Graph(int vertex){
			this->vertex=vertex;
			v=new vector<int>[vertex];
		}
		void addEdge(int,int);
		void printGraph();
		void BFSSearch(int);
		void DFSSearch(int);
		void DFSUtil(int,bool[]);
};
void Graph::addEdge(int u,int r){
	v[u].push_back(r);
	v[r].push_back(u);
}
void Graph::printGraph(){
	for(int i = 0; i < vertex; ++i) 
    	{ 
        	cout << "\n Adjacency list of vertex "<< i << "\n head "; 
        	for (auto x : v[i]) 
           		cout << "-> " << x; 
        	printf("\n"); 
    	}
}
void Graph::BFSSearch(int s){
	 
    bool *visited = new bool[vertex]; 
    for(int i = 0; i < vertex; i++) 
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    vector<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front();  
        for (i = v[s].begin(); i != v[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
}
void Graph::DFSUtil(int u,bool t[]){
	t[u]=true;
	cout << u << " ";  
    vector<int>::iterator i; 
    for (i = v[u].begin(); i != v[u].end(); ++i) 
        if (!t[*i]) 
            DFSUtil(*i, t); 
}
void Graph::DFSSearch(int u){
	bool *b=new bool[vertex];
	for(int i=0;i<vertex;i++){
		b[i]=false;
	}
	DFSUtil(u,b);
}
int main(){

	int v;
	cout<<"Enter the number of vertices in Graph\n";
	cin>>v;
	Graph g(v);
	while(1){
		cout<<"SELECT THE OPTION YOU WANT TO PERFORM\n1:Add Edge\n2:Print Graph\n3:BFS Search\n4:DFS Search\n";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:{
					int a,b;
					cout<<"Type the vertices between whose you want edge\n";
					cin>>a>>b;
					g.addEdge(a,b);
					break;
				}
			case 2:{
				       g.printGraph();
				       break;
			       }
			case 3:{
				       cout<<"BFS Search\n";
				       cout<<"From which vertex you wanna start\n";
				       int x;
				       cin>>x;
				       g.BFSSearch(x);
				       break;
			       }
			case 4:{
				       cout<<"DFS Search\n";
				       cout<<"From which vertex youwanna start\n";
				       int x;
				       cin>>x;
				       g.DFSSearch(x);
				       break;
			       }
			default:	cout<<"Enter a valid number\n";
		}
		cout<<"Do yo want to continue: y|yes n|no\n";
		char c;
		cin>>c;
		if(c=='n'||c=='N')
			break;
	}
}	
	
