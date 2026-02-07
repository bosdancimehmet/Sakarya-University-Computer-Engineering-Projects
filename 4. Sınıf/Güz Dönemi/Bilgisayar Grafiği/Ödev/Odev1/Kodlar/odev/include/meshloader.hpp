#pragma once
#include<string>
#include<vector>
using namespace std;
namespace graf
{
    class VertexArrayObject;
    class MeshLoader
    {
    public:
        VertexArrayObject* loadMeshFromFile(const string& fileName);
    private:
        int getVertexFloatCount(const vector<string>& attributes);
    }; 
}