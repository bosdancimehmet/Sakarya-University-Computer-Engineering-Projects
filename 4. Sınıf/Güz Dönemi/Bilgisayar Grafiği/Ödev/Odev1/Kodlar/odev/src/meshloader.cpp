#include "meshloader.hpp"
#include <fstream>
#include<iostream>
#include<nlohmann/json.hpp>
#include <vector>
#include "vertexbuffer.hpp"
#include "vertexarrayobject.hpp"
namespace graf
{
    VertexArrayObject* MeshLoader::loadMeshFromFile(const string& fileName)
    {
        VertexArrayObject* vao=nullptr;
        ifstream file(fileName);

        if(file.is_open())
        {
            cout<<"<------MeshLoader readling file "<<fileName<<"------->"<<endl;
            using namespace nlohmann;

            json data = json::parse(file);

            /*---------------------Parsing Mesh File--------------------------*/

            string meshName = data["MeshName"];
            int vertexAttributeCount = data["VertexAttributeCount"];
            vector<string> vertexAttributes = data["VertexAttributes"];
            int triangleCount = data["TriangleCount"];
            vector<float> vertices = data["Vertices"];
            int vertexFloatCount = getVertexFloatCount(vertexAttributes);


             /*---------------------Creating Buffers--------------------------*/
            VertexBuffer* vbo = new VertexBuffer();
            vbo->create(&vertices[0],vertices.size()*sizeof(float));

            vao = new VertexArrayObject();
            vao->create();
            vao->setVertexBuffer(vbo);
            for(auto nextAttribute:vertexAttributes)
                vao->addAttributes(toAttributeType(nextAttribute));
            vao->activateAttributes();

            /*---------------------Printing Log Info--------------------------*/

            cout<<setw(20)<<std::left<<"MeshName"<<":"<<meshName<<endl;
            cout<<setw(20)<<std::left<<"VertexAttributeCount"<<":"<<vertexAttributeCount<<endl;
            cout<<setw(20)<<std::left<<"VertexAttributes"<<":";
            for(auto nextAttribute:vertexAttributes)
                cout<<nextAttribute<<" ";
            cout<<endl;
            cout<<setw(20)<<std::left<<"TriangleCount"<<":"<<triangleCount<<endl;
            
            cout<<setw(30)<<"Vertices"<<":"<<endl;
                
            for(int i=0;i<vertices.size();i+=vertexFloatCount)
            {
                cout<<std::right<<setw(10)<<"Vertex"<<""<<setw(10)<<i/vertexFloatCount<<setw(5)<<" =>";
                for(int j =0;j<vertexFloatCount;j++)
                {
                    cout<<setw(6)<<std::right<<vertices[i+j];
                }
                cout<<endl;
            }           
        }
        else
        {
            cout<<"<------MeshLoader cannot open "<<fileName<<"------->"<<endl;
        }

        return vao;

    }
    int MeshLoader::getVertexFloatCount(const vector<string> &attributes)
    {
        int floatCount =0;

        for(auto nextAttribute:attributes)
        {
            if( nextAttribute=="Position"||
                nextAttribute=="Normal"
                )
                floatCount+=3;
            if(nextAttribute=="Color")
                floatCount+=4;       
            if(nextAttribute=="Texture")
                floatCount+=2;            
        }

        return floatCount;
    }
}