#include "OBJLoader.h"

Mesh* loadMesh(const char* path)
{
	std::vector<Vector3f> vertices;
	std::vector<Vector2f> texCoords;
	std::vector<Vector3f> normals;
	std::vector<Index> indices;

	std::string fileString = readFile(path);

	std::vector<std::string> lines = split(fileString, '\n');

	for (std::string line : lines)
	{
		std::vector<std::string> tokens = split(line, ' ');
		if (line.length() > 0) {

			if (tokens[0] == "#") continue;

			else if (tokens[0] == "v")
			{
				vertices.push_back(
					Vector3f
					(
						strtof(tokens[1].c_str(), 0),
						strtof(tokens[2].c_str(), 0),
						strtof(tokens[3].c_str(), 0)
						)
					);
			}
			else if (tokens[0] == "vt")
			{
				texCoords.push_back(
					Vector2f
					(
						strtof(tokens[1].c_str(), 0),
						strtof(tokens[2].c_str(), 0)
						)
					);
			}
			else if (tokens[0] == "vn")
			{
				normals.push_back(
					Vector3f
					(
						strtof(tokens[1].c_str(), 0),
						strtof(tokens[2].c_str(), 0),
						strtof(tokens[3].c_str(), 0)
						)
					);
			}
			else if (tokens[0] == "f")
			{

				Index index;

				std::vector<std::string> c1 = split(tokens[1], '/');
				std::vector<std::string> c2 = split(tokens[2], '/');
				std::vector<std::string> c3 = split(tokens[3], '/');

				if (c1.size() == 3) {	/* Vert/Tex/Norm */						// BAD WAY TO DO IT!

					index.vi = (short)std::stoi(c1[0]) - 1;
					if(c1[1] != "") index.ti = (short)std::stoi(c1[1]) - 1;
					index.ni = (short)std::stoi(c1[2]) - 1;

					indices.push_back(index);

					index.vi = (short)std::stoi(c2[0]) - 1;
					if (c2[1] != "") index.ti = (short)std::stoi(c2[1]) - 1;
					index.ni = (short)std::stoi(c2[2]) - 1;

					indices.push_back(index);

					index.vi = (short)std::stoi(c3[0]) - 1;
					if (c2[1] != "") index.ti = (short)std::stoi(c3[1]) - 1;
					index.ni = (short)std::stoi(c3[2]) - 1;

					indices.push_back(index);

				}

				else if (c1.size() == 2)
				{
					index.vi = (short)std::stoi(c1[0]) - 1;
					index.ti = (short)std::stoi(c1[1]) - 1;

					indices.push_back(index);

					index.vi = (short)std::stoi(c2[0]) - 1;
					index.ti = (short)std::stoi(c2[1]) - 1;

					indices.push_back(index);

					index.vi = (short)std::stoi(c3[0]) - 1;
					index.ti = (short)std::stoi(c3[1]) - 1;

					indices.push_back(index);
				}

			}
		}
	}

	const unsigned int vertexSize = vertices.size() * 3;
	const unsigned int texCoordSize = texCoords.size() * 2;
	const unsigned int normalSize = normals.size() * 3;
	const unsigned int indexSize = indices.size();

	GLfloat* verticesArray = new GLfloat[vertexSize * 3];
	GLfloat* texCoordsArray = new GLfloat[texCoordSize * 2];
	GLfloat* normalsArray = new GLfloat[normalSize * 3];
	GLushort* indicesArray = new GLushort[indexSize]; // Fix later

	unsigned int temp = 0;

	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		verticesArray[temp + 0] = vertices[i].x;
		verticesArray[temp + 1] = vertices[i].y;
		verticesArray[temp + 2] = vertices[i].z;
		temp += 3;
	}

	temp = 0;

	for (unsigned int i = 0; i < texCoords.size(); i++)
	{
		texCoordsArray[temp + 0] = texCoords[i].x;
		texCoordsArray[temp + 1] = texCoords[i].y;
		temp += 2;
	}

	temp = 0;

	for (unsigned int i = 0; i < normals.size(); i++)
	{
		normalsArray[temp + 0] = normals[i].x;
		normalsArray[temp + 1] = normals[i].y;
		normalsArray[temp + 2] = normals[i].z;
		temp += 3;
	}

	for (unsigned int i = 0; i < indices.size(); i++)
	{
		indicesArray[i] = indices[i].vi;
	}

	std::cout << " Mesh [" << path << "] loaded successfully." << std::endl;

	if(texCoordSize > 0)
		return new Mesh(verticesArray, vertexSize, indicesArray, indexSize, 0, 0, texCoordsArray, texCoordSize);
	else
		return new Mesh(verticesArray, vertexSize, indicesArray, indexSize, 0, 0, verticesArray, vertexSize);
}

std::vector<std::string> split(std::string string, char delim)
{
	std::vector<std::string> strings;
	std::string temp = "";

	for (unsigned int i = 0; i < string.length(); i++) {

		if (string.at(i) != delim) {
			temp += string.at(i);
		}
		else {
			strings.push_back(temp);
			temp = "";
		}

	}

	strings.push_back(temp);

	return strings;
}