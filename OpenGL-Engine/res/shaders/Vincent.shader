#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform float deltaTime;

uniform mat4 projectionMatirx;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projectionMatirx * view * model * vec4(position.x, position.y + sin(deltaTime * 0.5)* 1, position.z, 1);
	v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform sampler2D u_Texture1;

void main()
{
	vec4 texColor = mix(texture(u_Texture1, v_TexCoord), texture(u_Texture, v_TexCoord) , 0.5f);
	color = texColor;
};