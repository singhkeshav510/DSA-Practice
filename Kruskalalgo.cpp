#include<bits/stdc++.h>//kruskal algorithm
using namespace std;
class Edge{
	public:
		int s,d,w;
};
class Graph{
	public:
		int v,e;
		Edge* ed;
		Graph(int vertex,int edge){
			v=vertex;
			e=edge;
			ed=new Edge[e];
		}	
};
class Subset{
	public:
		int parent,rank;
};
int find(Subset subsets[],int i){
	if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;
}
void Union(Subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
     else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->w > b1->w;
}
void KruskalMST(Graph* g){
	int v=g->v;
	Edge res[v];
	int e=0,i=0;
	qsort(g->ed,g->e,sizeof(g->ed[0]),myComp);
	Subset* s=new Subset[(v*sizeof(Subset))];
	for (int j = 0; j < v; ++j)
  	  {
        	s[j].parent = j;
        	s[j].rank = 0;
  	  }
	while (e < v-1 && i < g->e)
    	{
        Edge next_edge = g->ed[i++];
	int x = find(s, next_edge.s);
        int y = find(s, next_edge.d);
        	if (x != y)
        	{
            	res[e++] = next_edge;
            	Union(s, x, y);
        	}
    	}
	cout<<"Following are the edges in the constructed MST\n";
	    for (i = 0; i < e; ++i)
       	 cout<<res[i].s<<" -- "<<res[i].d<<" == "<<res[i].w<<endl;
   	 return;
}
int main(){
	cout<<"Creation of MST using Kruskal Algorithm\n";
	int v,e,n=0;
	cin>>v>>e;
	Graph* g=new Graph(v,e);
	while(n<e){
		cout<<"add edge\n";
		int sr,ds,we;
		cin>>sr>>ds>>we;
		g->ed[n].s=sr;
		g->ed[n].d=ds;
		g->ed[n].w=we;
		n++;
	}
	KruskalMST(g);
}
