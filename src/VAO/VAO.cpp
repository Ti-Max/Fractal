#include "VAO.h"

GL::VAO::VAO()
{
	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);

}

void GL::VAO::draw(int count)
{
	glBindVertexArray(mVao);
	if (eboSize !=0)
		glDrawElements(GL_TRIANGLES, eboSize, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, count);
	glBindVertexArray(0);

}
void GL::VAO::draw() {
	glBindVertexArray(mVao);
	glDrawElements(GL_TRIANGLES, eboSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}
void GL::VAO::draw(GLenum type, int count)
{
	glBindVertexArray(mVao);
	glDrawArrays(type, 0, count);
	glBindVertexArray(0);

}
void GL::VAO::addBufferData(const std::vector<float>& data)
{
	glEnableVertexAttribArray(attribId);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribId, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
	attribId++;
}
void GL::VAO::addBufferData(const std::vector<glm::vec2>& data)
{
	glEnableVertexAttribArray(attribId);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribId, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	attribId++;
}
void GL::VAO::addBufferData(const std::vector<glm::vec3>& data)
{
	glEnableVertexAttribArray(attribId);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribId, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	attribId++;
}
void GL::VAO::addBufferData(const std::vector<glm::vec4>& data)
{
	glEnableVertexAttribArray(attribId);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribId, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	attribId++;
}
void GL::VAO::addBufferData(float data[])
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	// fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	// link vertex attributes
	glBindVertexArray(mVao);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void GL::VAO::addEBO(const std::vector<unsigned int>& data)
{
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), data.data(), GL_STATIC_DRAW);
	eboSize = data.size();
}


GL::VAO::~VAO()
{
	glDeleteVertexArrays(1, &mVao);
	//glDeleteBuffers(1, &mVbo);

}
