#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
string line;
ifstream fin("graph.txt");
if(fin.is_open())
{
cout<<"Src\tDest\tDist\n";
while(getline(fin,line))
{cout<<line<<"\n";
}
fin.close();
}
else
{
cout<<"Unable to open file";
}
return 0;
}
