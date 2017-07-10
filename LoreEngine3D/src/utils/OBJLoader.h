#pragma once
#include "FileUtilites.h"
#include "../math/Vector.h"
#include "../graphics/Mesh.h"
#include <vector>

Mesh loadMesh(const char* path);
std::vector<std::string> split(std::string string, char delim);
