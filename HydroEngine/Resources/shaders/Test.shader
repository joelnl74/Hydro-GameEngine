#shader vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec3 a_Tangent;
layout(location = 3) in vec3 a_Binormal;
layout(location = 4) in vec2 a_TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 v_TexCoord;

void main()
{
	gl_Position = projection * view * model * vec4(a_Position, 1.0);
	v_TexCoord = a_TexCoord;
}
#shader fragment
#version 330 core

in vec2 v_TexCoord;
out vec4 color;

uniform sampler2D u_texture;

void main()
{
	vec4 texColor = texture(u_texture, v_TexCoord) * vec4(1, 1, 1, 1);
	color = texColor;
}