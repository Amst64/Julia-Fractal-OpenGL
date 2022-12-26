#version 330

in vec2 vFragPos;

uniform float uCx;
int DIM = 1000;

out vec4 fFragColor;

vec2 complexSqr(vec2 z) 
{
    float x = pow(z.x, 2) - pow(z.y, 2);
    float y = 2 * z.x * z.y;

    return vec2(x, y);
}


float magnitude2(vec2 z) 
{
    return z.x * z.x + z.y * z.y;
}

int julia(float x, float y) 
{
    
    const float scale = 1.5;
    float jx = scale * ((DIM/2.0) - x)/(DIM/2.0);
    float jy = scale * ((DIM/2.0) - y)/(DIM/2.0);

    vec2 c = vec2(uCx, 0.156);
    vec2 a = vec2(jx, jy);

    int i = 0;
    for (i = 0; i < 200; i++) {
        a = complexSqr(a) + c;
        if (length(a) > 2) {
            return 0;
        }
            
    }
    return 1;
}


void main()
{
    vec2 z     = vec2(gl_FragCoord);
    if (julia(z.x, z.y) == 0) {
        fFragColor = vec4(1);
    }
    else {
        fFragColor = vec4(vec3(z.x/DIM, z.y/DIM, 1), 1);
    }     
}