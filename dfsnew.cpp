#include<iostream>
#include <list>
#include<fstream>
#include<sstream>
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFSL();    // prints DFS traversal of the complete graph
    void DFSM(int b);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFSL()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            DFSUtil(i, visited);
}



void Graph::DFSM(int i)
{
    int j;
	cout<<i<<" ";
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
}


 
int main()
{




int vert[18],m=0;
string newline;
ifstream file("graph.txt");
if(file.is_open())
{
while(getline(file,newline))
{
istringstream iss(newline);

int n;
while (iss >> n) {
vert[m]=n;
m++;
 }

}
file.close();
}



int a[12],temp;
int o=0,p=0;
while(o<12)
{
	a[o]=vert[p];
	a[o+1]=vert[p+1];
	o=o+2;
	p=p+3;
}


for(int i=0;i<12;i++)
{
	for(int j=0;j<9-i;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}


int nv=a[9]+1;

cout<<"Number of vertices in graph is "<<nv<<"\n";


int mat[5][5];
string line;
ifstream fin("graph.txt");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        mat[i][j]=0;
    }
    string str;
    while(getline(fin,str))
    {

        istringstream ss(str);
        int node,i;
        ss>>node;
        while(ss>>i){
        mat[node][i]=1;
}    }

cout<<"Adjacency Matrix:\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {

            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
fin.close();





 Graph g(nv);


int distance;
cout<<"\nEnter max possible distance(threshold):";
cin>>distance;

int i=2,cnt=0;
while(i<18)
{
	if(vert[i]<=distance)
	{
		g.addEdge(vert[i-2],vert[i-1]);
		cnt++;
	}
	i=i+3;
}

int thresh;
int maxlinks=nv*(nv-1)/2;
cout<<"\nNumber of maximum possible links="<<maxlinks;
cout<<"\nNumber of active links="<<cnt;
cout<<"\nEnter % threshold for number of links:";
cin>>thresh;
if(cnt<(thresh*maxlinks/100))
{
	cout<<"\nUsing Adjacency List\n";
    cout << "\nFollowing is Depth First Traversal (starting from vertex 0) \n";
    g.DFSL();
}
else
{
	cout<<"\nUsing Adjacency Matrix\n";
    cout << "\nFollowing is Depth First Traversal (starting from vertex 0) \n";
 //read the adjecency matrix
int G[][],visit[];
    for(i=0;i<5;i++)
        {for(j=0;j<5;j++)
            {G[i][j]=mat[i][j];}}

    //visited is initialized to zero
    for(i=0;i<5;i++)
        visit[i]=0;

    DFSM(0);
}


 
    return 0;
}
