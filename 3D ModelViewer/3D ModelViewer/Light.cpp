#include "light.h"

Light* Light::currentInstance = nullptr;

Light::Light()
{
}

void Light::CreateLightSource(unsigned int _objectID, float* _vertices, unsigned int* _indices, unsigned int _size)
{
	if (currentInstance)
	{
		currentInstance->HandleLightSourceCreation(_objectID, _vertices, _indices, _size);
	}

}

void Light::HandleLightSourceCreation(unsigned int _objectID, float* _vertices, unsigned int* _indices, unsigned int _size)
{
	//	//SET VALUES FOR STANDARD MATERIAL STANDARD MATERIAL
	material.size = 3 * size;

	glGenVertexArrays(1, &_objectID);
	glBindVertexArray(_objectID);


	unsigned int vbo;
	unsigned int ebo;

	//CREATE BUFFER AND STORE VERTICES IN IT
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, _size, (_vertices), GL_STATIC_DRAW);


	//POSITION ATTRIB
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//COLOR ATTRIB
	unsigned int colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, material.size, material.colorArray, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	//SET ELEMENT BUFFER FOR INDICES
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), _indices, GL_STATIC_DRAW);
	
}