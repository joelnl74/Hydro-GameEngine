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
out vec3 v_Normals;
out vec3 FragPos;

void main()
{
	gl_Position = projection * view * model * vec4(a_Position, 1.0);
	v_TexCoord = a_TexCoord;
	v_Normals = mat3(transpose(inverse(model))) * a_Normal;
	FragPos = vec3(model * vec4(a_Position, 1.0));
}
#shader fragment
#version 330 core

in vec2 v_TexCoord;
in vec3 v_Normals;
in vec3 FragPos;
out vec4 color;

vec3 lightColor = vec3(0.5, 0.6, 0.6);
vec3 lightPosition = vec3(0, 10, -25);

float ambientStrength = 0.05;
vec3 ambient = ambientStrength * lightColor;

vec3 norm = normalize(v_Normals);
vec3 lightDir = normalize(lightPosition - FragPos);

float diff = max(dot(norm, lightDir), 0.0);
vec3 diffuse = diff * lightColor;

vec3 result = (ambient + diffuse);

uniform sampler2D u_texture;

void main()
{
	vec4 texColor = texture(u_texture, v_TexCoord) * vec4(result.x, result.y, result.z, 1);
	color = texColor;
}