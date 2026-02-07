#define GLM_ENABLE_EXPERIMENTAL
#include "meshloader.hpp"
#include <fstream>
#include<iostream>
#include<nlohmann/json.hpp>
#include<glm/gtx/transform.hpp>
#include <vector>
#include "vertexbuffer.hpp"
#include "vertexarrayobject.hpp"
#include "indexbuffer.hpp"
namespace graf
{
    string ShapeType::Circle = "Circle";
    string ShapeType::Quad = "Quad";
    string ShapeType::Cylinder = "Cylinder";
    string ShapeType::Cone = "Cone";
    MeshLoader* MeshLoader::m_instance=nullptr;
    MeshLoader::MeshLoader()
    {
        
    }
    VertexArrayObject* MeshLoader::loadMeshFromFile(const string& fileName)
    {
        VertexArrayObject* vao=nullptr;

        auto loader = getInstance();

        if(loader->m_vaos.count(fileName)==0)
        {

       
            string meshpath = "./meshes/"+fileName;
            ifstream file(meshpath);

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
                vector<unsigned int> indices = data["Indices"];
                int vertexFloatCount = getVertexFloatCount(vertexAttributes);


                /*---------------------Creating Buffers--------------------------*/
                VertexBuffer* vbo = new VertexBuffer();
                vbo->create(&vertices[0],vertices.size()*sizeof(float));

                IndexBuffer* ibo = new IndexBuffer();
                ibo->create(indices.data(),indices.size()*sizeof(unsigned int));


                vao = new VertexArrayObject();
                vao->create();
                vao->setVertexBuffer(vbo);
                vao->setIndexBuffer(ibo);
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
        }
        else
        {
            vao = loader->m_vaos[fileName];
        }
        return vao;

    }
    VertexArrayObject *MeshLoader::createMesh(const string &shapeType)
    {
        if(shapeType==ShapeType::Circle)
            return createCircle();
        if(shapeType==ShapeType::Cone)
            return createCone();
        if(shapeType == "Cylinder") return createCylinder();
        return nullptr;
    }
    VertexArrayObject* MeshLoader::createCone()
    {
        VertexArrayObject* vao=nullptr;

        auto loader = getInstance();

        if(loader->m_vaos.count(ShapeType::Cone)==0)
        {
            vector<VertexUnlit> vertices;
            vector<unsigned int> indices;

            float angle =10;

            int vertexCount = 360.0f/angle;
            vertices.resize(vertexCount*2);
            for(int i=0;i<vertexCount;i++)
            {
                float nextAngle = i*angle;

                VertexUnlit vertex;
                vertex.position.x = cosf(glm::radians(nextAngle));
                vertex.position.y = 0;
                vertex.position.z = sinf(glm::radians(nextAngle));

                vertex.texCoords.s = 0.5f+0.5f*cosf(glm::radians(nextAngle));
                vertex.texCoords.t = 0.5f+0.5f*sinf(glm::radians(nextAngle));
                vertices[i] = vertex;

                vertices[i+vertexCount] = vertex;


            }
            float r = sqrtf(2);
            float totalAngle = 360.0f/r;
            angle = totalAngle/(vertexCount-1);


            VertexUnlit nextVertex;
            nextVertex.position = vertices[vertexCount].position;
            
            vertices.push_back(nextVertex);

            for(int i=0;i<=vertexCount;i++)
            {
                float nextAngle = angle*i;
                vertices[i+vertexCount].texCoords.s = 0.5f+0.5f*cosf(glm::radians(nextAngle));
                vertices[i+vertexCount].texCoords.t = 0.5f+0.5f*sinf(glm::radians(nextAngle));
           
            }


            VertexUnlit topVertex;
            topVertex.position = glm::vec3(0.0f,1.0f,0.0f);
            topVertex.texCoords = glm::vec2(0.5f,0.5f);
            vertices.push_back(topVertex);

            

            //---------------------------------------------------
            //---------------------Tabanın indeksleri bulunuyor--
            //---------------------------------------------------
            for(int i=0;i<vertexCount-2;i++)
            {
                indices.push_back(0);
                indices.push_back(i+1);
                indices.push_back(i+2);
            }
            //---------------------------------------------------
            //-----------------Yan yüzeyin indeksleri bulunuyor--
            //---------------------------------------------------  
            
            int topIndex = vertices.size()-1;
            for(int i=0;i<vertexCount-1;i++)
            {
                indices.push_back(topIndex);
                indices.push_back(vertexCount+i);
                indices.push_back(vertexCount+i+1);
            }
            indices.push_back(topIndex);
            indices.push_back(topIndex-1);
            indices.push_back(topIndex-2);

            VertexBuffer* vbo = new VertexBuffer();
            vbo->create(&vertices[0],vertices.size()*sizeof(VertexUnlit));

            IndexBuffer* ibo = new IndexBuffer();
            ibo->create(indices.data(),indices.size()*sizeof(unsigned int));


            vao = new VertexArrayObject();
            vao->create();
            vao->setVertexBuffer(vbo);
            vao->setIndexBuffer(ibo);
            vao->addAttributes(VertexAttributeType::Position);
            vao->addAttributes(VertexAttributeType::Texture);
            vao->activateAttributes();           

            loader->m_vaos[ShapeType::Cone] = vao;
        }
        else
        {
            vao = loader->m_vaos[ShapeType::Cone];
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

    VertexArrayObject *MeshLoader::createCircle()
    {
        VertexArrayObject* vao=nullptr;

        auto loader = getInstance();

        if(loader->m_vaos.count(ShapeType::Circle)==0)
        {
            vector<VertexUnlit> vertices;
            vector<unsigned int> indices;

            float angle =10;

            int vertexCount = 360.0f/angle;

            for(int i=0;i<vertexCount;i++)
            {
                float nextAngle = i*angle;

                VertexUnlit vertex;
                vertex.position.x = cosf(glm::radians(nextAngle));
                vertex.position.y = sinf(glm::radians(nextAngle));
                vertex.position.z = 0.0f;

                vertex.texCoords.s = 0.5f+0.5f*cosf(glm::radians(nextAngle));
                vertex.texCoords.t = 0.5f+0.5f*sinf(glm::radians(nextAngle));
                vertices.push_back(vertex);
            }


            for(int i=0;i<vertexCount-2;i++)
            {
                indices.push_back(0);
                indices.push_back(i+1);
                indices.push_back(i+2);
            }


            VertexBuffer* vbo = new VertexBuffer();
            vbo->create(&vertices[0],vertices.size()*sizeof(VertexUnlit));

            IndexBuffer* ibo = new IndexBuffer();
            ibo->create(indices.data(),indices.size()*sizeof(unsigned int));


            vao = new VertexArrayObject();
            vao->create();
            vao->setVertexBuffer(vbo);
            vao->setIndexBuffer(ibo);
            vao->addAttributes(VertexAttributeType::Position);
            vao->addAttributes(VertexAttributeType::Texture);
            vao->activateAttributes();           

            loader->m_vaos[ShapeType::Circle] = vao;
        }
        else
        {
            vao = loader->m_vaos[ShapeType::Circle];
        }
        return vao;

    }

    
    VertexArrayObject* MeshLoader::createCylinder()
    {
        VertexArrayObject* vao = nullptr;
        auto loader = getInstance();

        if (loader->m_vaos.count("Cylinder") == 0)
        {
            vector<VertexUnlit> vertices;
            vector<unsigned int> indices;
            
            int segments = 24; // 24 kenarlı silindir daha yuvarlak olur
            float radius = 0.5f;
            float height = 1.0f;
            float angleStep = 360.0f / segments;

            // Üst ve Alt Merkez Noktaları
            VertexUnlit topCenter, bottomCenter;
            topCenter.position = glm::vec3(0, height/2, 0);
            topCenter.texCoords = glm::vec2(0.5f, 0.5f);
            
            bottomCenter.position = glm::vec3(0, -height/2, 0);
            bottomCenter.texCoords = glm::vec2(0.5f, 0.5f);

            vertices.push_back(topCenter);    // 0
            vertices.push_back(bottomCenter); // 1

            // Yan Yüzey Vertexleri
            for (int i = 0; i <= segments; i++)
            {
                float angle = glm::radians(i * angleStep);
                float x = cos(angle) * radius;
                float z = sin(angle) * radius;
                float u = (float)i / segments;

                // Üst Çember Noktası
                VertexUnlit vTop;
                vTop.position = glm::vec3(x, height/2, z);
                vTop.texCoords = glm::vec2(u, 1.0f);
                vertices.push_back(vTop);

                // Alt Çember Noktası
                VertexUnlit vBottom;
                vBottom.position = glm::vec3(x, -height/2, z);
                vBottom.texCoords = glm::vec2(u, 0.0f);
                vertices.push_back(vBottom);
            }

            // İndeksler (Yan Yüzeyler)
            int baseIndex = 2;
            for (int i = 0; i < segments; i++)
            {
                int top1 = baseIndex + i * 2;
                int bottom1 = top1 + 1;
                int top2 = top1 + 2;
                int bottom2 = bottom1 + 2;

                // İlk Üçgen
                indices.push_back(top1);
                indices.push_back(bottom1);
                indices.push_back(top2);

                // İkinci Üçgen
                indices.push_back(bottom1);
                indices.push_back(bottom2);
                indices.push_back(top2);
            }
            
            // Üst ve Alt Daireler için indeks eklemesi de yapılabilir ama 
            // şimdilik yan yüzeyler yeterli
            for(int i=0; i<segments; i++)
            {
                int top1 = baseIndex + i * 2;
                int top2 = baseIndex + (i+1) * 2;
                indices.push_back(0); // Top Center
                indices.push_back(top2);
                indices.push_back(top1);

                int bot1 = baseIndex + i * 2 + 1;
                int bot2 = baseIndex + (i+1) * 2 + 1;
                indices.push_back(1); // Bottom Center
                indices.push_back(bot1);
                indices.push_back(bot2);
            }

            VertexBuffer* vbo = new VertexBuffer();
            vbo->create(&vertices[0], vertices.size() * sizeof(VertexUnlit));

            IndexBuffer* ibo = new IndexBuffer();
            ibo->create(indices.data(), indices.size() * sizeof(unsigned int));

            vao = new VertexArrayObject();
            vao->create();
            vao->setVertexBuffer(vbo);
            vao->setIndexBuffer(ibo);
            vao->addAttributes(VertexAttributeType::Position);
            vao->addAttributes(VertexAttributeType::Texture);
            vao->activateAttributes();

            loader->m_vaos["Cylinder"] = vao;
        }
        else
        {
            vao = loader->m_vaos["Cylinder"];
        }
        return vao;
    }

   MeshLoader *MeshLoader::getInstance()
    {
        if(!m_instance)
            m_instance = new MeshLoader;
        return m_instance;
    }
}