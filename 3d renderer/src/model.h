#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include <stb/stb_image.h>
#include "mesh.h"



class Model {
public:

    Model(std::string const& path, bool gamma = false)
    {
        loadModel(path);
    }
    void Draw(Shader& shader, Camera& cam);
private:
    std::vector<Mesh> meshes;
    std::string directory;
   

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        std::string typeName);

};
#endif // !MODEL_CLASS_H
