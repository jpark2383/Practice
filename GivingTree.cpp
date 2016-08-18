/*------------------------------------------------------------------*/
//The Giving Tree of Errors (lexicological s-expression given list of edges)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
#define numNodes 26
static string lexico(char root, bool graph[][numNodes])
{
    int j;
    string l = "";
    string r = "";
    string res = "(";
    int temproot = root - 'A';
    for(int i = 0; i < numNodes; i++){
       if(graph[temproot][i]){
           l = lexico((char)(i+'A'), graph);
           for(j = i+1; j < numNodes; j++){
               if(graph[temproot][j]){
                   r = lexico((char)(j+'A'), graph);
                   break;
               }
           }
           break;
       }
    }
    res = res+root+l+r+")";
    return res;
}

bool hasCycleRecursive(int v, bool visited[], unordered_map<int, vector<int>> node, int parent)
{
        visited[v] = true;
        vector<int>::iterator it;
        for(it = node[v].begin(); it != node[v].end(); ++it){
            if(!visited[*it]){
                if(hasCycleRecursive(*it, visited, node, v))
                    return true;
            }
            else if(*it != parent)
                return true;
        }
    return false;
}

bool hasCycle(unordered_map<int, vector<int>> adj, bool activeNodes[])
{
    bool *visited = new bool[numNodes];
    for(int i = 0; i < numNodes; i++){
        visited[i] = false;
    }
    for(int i = 0; i < numNodes; i++){
        if(activeNodes[i]){
            if(!visited[i]){
                if(hasCycleRecursive(i,visited, adj,-1))
                    return true;
            }
        }
    }
    return false;
}
int main() {
    string in;
    getline(cin,in);
    bool dupeFlag = 0;
    int length = in.length();
    int n = 0;
    int parent = 0;
    int child = 0;
    int index = 0;
    int rootVal = 0;
    bool activeNodes [numNodes];
    int inEdges[numNodes];
    bool tree [numNodes][numNodes] = { {0} };
    for(int i = 0; i< numNodes; i++){
        activeNodes[i] = false;
        inEdges[i] = 0;
    }
    unordered_map<int,vector<int>> nodes;
    unordered_map<int,vector<int>> edges;
    // load map with edges and check format
    while(index < length){
        if(in[index] != '('){
            cout << "E1";
            return 0;
        }
        index++;
        parent = in[index] - 'A';
        if((parent > 26 || parent < 0)){
            cout << "E1";
            return 0;   
        }
        index++;
        if(in[index] != ','){
            cout << "E1";
            return 0;
        }
        index++;
        child = in[index] - 'A';
        if((parent > 26 || parent < 0)){
            cout << "E1";
            return 0;   
        }
        //Check for Duplicates
        if(nodes[parent].size() > 0){
            for(unsigned int u = 0;u < nodes[parent].size(); u++){
                if(nodes[parent][u] == child)
                    dupeFlag = 1;
            }
        }
        if(dupeFlag == 1){
            cout << "E2";
            return 0;
        }
        else{
            activeNodes[parent] = true;
            activeNodes[child] = true;
            inEdges[child]++;
            nodes[parent].push_back(child);
            edges[parent].push_back(child);
            edges[child].push_back(parent);
            tree[parent][child] = true;
        }
        index++;
        if((in[index] != ')')&& (index >= length)){
            cout << "E1";
            return 0;
        }
        index++;
        if((in[index] != ' ') && (index >= length) && in[index] != '\0'){
            cout<< "E1";
            return 0;
        }
        index++;
    }
//Check for more than 2 children to 1 parent
    for(int i = 0; i < numNodes; i++){
        if(nodes[i].size() > 2){
            cout << "E3";
            return 0;
        }
        if(nodes[i].size() > 0)
            n++;
    }
//Check for multiple roots
    int roots = 0;
    for(int i = 0; i < numNodes; i++){
        if(activeNodes[i] == true && inEdges[i] == 0){
            roots++;
        }
        if(roots > 1){
            cout << "E4";
            return 0;
        }
    }
    for(int i = 0; i < numNodes; i++){
        if(activeNodes[i] == true && inEdges[i] == 0){
            rootVal = i;
            break;
        }
    }    

//Cycle Detection
    if(hasCycle(edges, activeNodes)){
        cout << "E5" << endl;
        return 0;
    }
    char temproot = rootVal +'A';
    //lexicographic output
    
    string lex = lexico(temproot, tree);
    cout << lex;
    return 0;
}