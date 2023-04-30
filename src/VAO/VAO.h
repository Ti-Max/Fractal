#pragma once
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

namespace GL 
{
	class VAO
	{
	public:
		VAO();
		~VAO();
		void addBufferData(const std::vector<float>& data);
		void addBufferData(const std::vector<glm::vec2>& data);
		void addBufferData(const std::vector<glm::vec3>& data);
		void addBufferData(const std::vector<glm::vec4>& data);
		void addEBO(const std::vector<unsigned int>& data);

		void addBufferData(float data[]);

		void draw(int count);
		void draw();//with EBO
		void draw(GLenum type, int count);
	private:
		unsigned int attribId = 0;
		unsigned int mVao;
		unsigned int ebo = 0;
		unsigned int eboSize = 0;
	};
}