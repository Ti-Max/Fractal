#pragma once
#include <GL/glew.h>

#include <iostream>
#include <map>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Shader/Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class mText
{
private:
	int width, height;
	struct Character {
		GLuint TextureID;   // ID handle of the glyph texture
		glm::ivec2 Size;    // Size of glyph
		glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
		GLuint Advance;    // Horizontal offset to advance to next glyph
	};
	std::map<GLchar, Character> Characters;
	GLuint VAO, VBO;

public:
	mText(int width, int height);
	void Write(Shader& s, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
};

