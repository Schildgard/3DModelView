#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
public:

	float* vertices;
	unsigned int* indices;
	unsigned int size;

	Mesh();

	void AddMeshComponent(unsigned int& _objectID);

	void AddMeshComponent(unsigned int& _objectID, float* _vertices, unsigned int* _indices, unsigned int _size);
};
