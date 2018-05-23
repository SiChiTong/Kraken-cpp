#ifndef TESTS_NAVMESH_TRIANGLE_H
#define TESTS_NAVMESH_TRIANGLE_H

#include "navmesh_edge.h"

namespace kraken
{
    class NavmeshTriangle
    {
    public:
        NavmeshTriangle(const NavmeshEdge &a, const NavmeshEdge &b, const NavmeshEdge &c);
        bool checkCounterclockwise() const;
        bool checkUniquePoints() const;
        bool checkDuality() const;
        void setEdges(const NavmeshEdge &e1, const NavmeshEdge &e2, const NavmeshEdge &e3);
        void correctCounterclockwiseness();
        bool isInside(const Vector2D &pos);
        bool operator==(const NavmeshTriangle &tr);

        static float crossProduct(const Vector2D &point_a, const Vector2D &point_b,
                                  const Vector2D &point_c); // TODO : in math_utils ?
        static bool checkCounterclockwise(const Vector2D &point_a, const Vector2D &point_b,
                                          const Vector2D &point_c); // TODO : in math_utils ?
        static bool isInside(const Vector2D &pos, const Vector2D &point_a, const Vector2D &point_b,
                             const Vector2D &point_c); // TODO : in math_utils ?

    private:
        void updateArea();
        bool checkTriangle(const NavmeshEdge &e1, const NavmeshEdge &e2, const NavmeshEdge &e3) const;

        NavmeshNode *points_;
        NavmeshEdge *edges_;
        int* edgesNb_;
        int area_;
    };

}


#endif //TESTS_NAVMESH_TRIANGLE_H
