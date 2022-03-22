#pragma once
#include "Vec2.h"

namespace settings
{
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;

    inline constexpr int cellSize = 23;
    inline constexpr int padding = 2;
    inline constexpr Vec2<int> boardPosition{ 200,120 };
    inline constexpr Vec2<int> boardWidthHeight{ 10,20 };

    

}
/*
//color type , RGBA (32bit)
typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

//Rctangle type
typedef struct Rectangle {
    float x;
    float y;
    float width;
    float height;
} Rectangle;

// Image tyoe, bpp always RGBA (32bit)
// NOTE L Data stored in cpu memory(ram)
typedef struct Image {
    void* data;  //Image raw data
    int with;  //Image base width
    int height;  //Image base height
    int mipmaps;  //Mipmap levels, 1 by default
    int format;  //Data format (PixelFormat type)
} Image;
*/