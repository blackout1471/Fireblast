#pragma once

#include "glm/glm.hpp"

namespace Fireblast 
{
	struct Vertex2D
	{
		glm::vec3 Vertice;
		glm::vec4 Color;
		glm::vec2 Uv;
		unsigned int TextureID;
	};

	struct Vertex3D
	{

	};
}