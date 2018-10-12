#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform float deltaTime;
uniform float numberOfRows;

uniform mat4 projectionMatirx;
uniform mat4 view;
uniform mat4 model;
uniform mat4 orthographicModel;

void main()
{
	gl_Position = projectionMatirx * view * model * vec4(position.x, position.y + sin(deltaTime*.5)*0.05, position.z, 1);
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

uniform vec3 ambientLight;

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform sampler2D u_Texture2;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord) + texture(u_Texture2, v_TexCoord);
	color = texColor;
};