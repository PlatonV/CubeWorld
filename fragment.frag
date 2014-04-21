uniform vec2 lightPos;
uniform float intensity;
uniform vec4 color;

void main()
{
	vec2 pixel=gl_FragCoord.xy;
    pixel.y=-pixel.y+600.0;
    vec2 aux = vec2(lightPos.x - pixel.x, lightPos.y - pixel.y);
	float len = length(aux);
	float at = intensity / (1.0 + len*10);
	gl_FragColor = vec4(at * 0.001, at * 0.001, at * 0.001, at) * color;
}
