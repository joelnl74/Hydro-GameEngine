#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform float numberOfRows;
uniform vec2 offset;

uniform mat4 orthographic;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = orthographic * view * model * vec4(position.x, position.y, position.z, 1);
	v_TexCoord = (texCoord / numberOfRows) + offset;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
};