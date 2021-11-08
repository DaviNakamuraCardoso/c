#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define WIDTH   512
#define HEIGHT  512

typedef struct rgb {
    float red, green, blue;
} rgb_t;

int writeppm(const char* filename);

int main(void)
{
    writeppm("output.ppm");
    return 0;
}


rgb_t stripes(float u, float v)
{
    float n = 20.0;

    return (rgb_t) {
            (sinf(u * n) + 1) * 0.5, 
            (sinf((u + v) * n) + 1.0) * 0.5,
            (cosf(u * n) + 1.0) * 0.5
    }; 
}

rgb_t randomic(float u, float v)
{
    float n = 42.0;

    return (rgb_t) {
        (cosf(u * v * u * v) * n),
        (cosf(u * u * u * u) * n),
        (sinf(v * v * v) * n)
    };
}

rgb_t japan(float u, float v)
{
    float cx = 0.5, cy = 0.5;
    float dx = cx - u, dy = cy - v;
    float r = 0.25;
    unsigned int c = (dx * dx + dy * dy >= r * r);


    return (rgb_t) {1.0, (float) c, (float) c}; 
}

rgb_t shrek(float u, float v)
{
    float cx = 0.5, cy = 0.5;
    float dx = cx - u, dy = cy - v;
    float r = 0.25;
    unsigned int c = (dx * dx + dy * dy >= r * r);

    return (rgb_t) {(float) c, 1.0, (float) c};
}


int writeppm(const char* filename)
{
    FILE *f = fopen(filename, "w");


    fprintf(f, "P6\n%i %i 255\n", WIDTH, HEIGHT);

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            float u = (float) i / WIDTH;
            float v = (float) j / HEIGHT;

            rgb_t shader = shrek(u, v); 

            fprintf(f, "%c%c%c", 
                    (int) (shader.red * 255), 
                    (int) (shader.green * 255), 
                    (int) (shader.blue * 255)); 
        }
    }

    fclose(f);

    return 0;
}
