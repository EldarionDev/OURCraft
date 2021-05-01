#ifndef MINECRAFT_PROJECTION_H
#define MINECRAFT_PROJECTION_H

class Projection {
public:
    Projection(float right, float left, float top, float bottom, float near, float far);
    Projection(float aspect_ratio, float fov, float near, float far);
};

#endif
