#ifndef SNAIL_SVG_RECT_HPP
#define SNAIL_SVG_RECT_HPP 1

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

typedef boost::geometry::model::vector<double, 2> vec2;
typedef boost::geometry::model::vector<double, 3> vec3;

typedef boost::geometry::model::vector<float, 4> rgba;

namespace Snail
{
    class Rect
    {
    public:

    vec2 position;
    vec2 size;
    rgba color;

        Rect()
        {
            
        }
        ~Rect()
        {
            
        }

        vector<vec3> getVertices()
        {
            vector<vec3> vertices;
            vertices.push_back(vec3(position.get<0>(), position.get<1>(), 0));
            vertices.push_back(vec3(position.get<0>() + size.get<0>(), position.get<1>(), 0));
            vertices.push_back(vec3(position.get<0>() + size.get<0>(), position.get<1>() + size.get<1>(), 0));
            vertices.push_back(vec3(position.get<0>(), position.get<1>() + size.get<1>(), 0));
            return vertices;
        }
    };

}

#endif