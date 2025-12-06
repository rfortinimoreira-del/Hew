#version 330 core

in vec3 FragColor;
in vec3 Normal;
in vec3 FragPos;

out vec4 color;

void main() {
    // Iluminação simples
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
    float diff = max(dot(Normal, lightDir), 0.3); // 0.3 é a iluminação ambiente
    
    color = vec4(FragColor * diff, 1.0);
}
