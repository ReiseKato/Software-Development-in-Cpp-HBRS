#ifndef LINALG_TRIANGLE_HH
#define LINALG_TRIANGLE_HH

#include "Vector2D.hh"
#include <cmath>
#include <cstddef>

namespace linalg
{
    template <typename Coord>
    class Triangle
    {
        private:
            Coord* p0_;
            Coord* p1_;
            Coord* p2_;
        
        public:
            Triangle(Coord* p0, Coord* p1, Coord* p2)
                : p0_(p0), p1_(p1), p2_(p2) {}

            // Accessor methods
            const Coord& p0() const { return *p0_; }
            const Coord& p1() const { return *p1_; }
            const Coord& p2() const { return *p2_; }

            Coord& p0() { return *p0_; }
            Coord& p1() { return *p1_; }
            Coord& p2() { return *p2_; }
    };

    template <typename Coord>
    int sharedPoints(const Triangle<Coord>& t1, const Triangle<Coord> t2)
    {
        int count = 0;
        if (t1.p0() == t2.p0() || t1.p0() == t2.p1() || t1.p0() == t2.p2()) count++;
        if (t1.p1() == t2.p0() || t1.p1() == t2.p1() || t1.p1() == t2.p2()) count++;
        if (t1.p2() == t2.p0() || t1.p2() == t2.p1() || t1.p2() == t2.p2()) count++;
        return count;
    }

    template <typename Coord>
    bool isConnected(const Triangle<Coord>& t1, const Triangle<Coord>& t2)
    {
        return sharedPoints(t1, t2) >= 1;
    }

    template <typename Coord>
    bool isAdjacent(const Triangle<Coord>& t1, const Triangle<Coord>& t2)
    {
        return sharedPoints(t1, t2) >= 2;
    }

    template <typename Coord>
    bool isEqual(const Triangle<Coord>& t1, const Triangle<Coord>& t2)
    {
        return sharedPoints(t1, t2) == 3;
    }

    template <typename Coord>
    bool isPatch(const Triangle<Coord>** triangles, std::size_t size)
    {
        bool adjacent;
        for (std::size_t i = 0; i < size; ++i)
        {
            adjacent = false;
            for (std::size_t j = 0; j < size; ++j)
            {
                if (i != j && isAdjacent(*triangles[i], *triangles[j]))
                {
                    adjacent = true;
                    break;
                }
                if (!adjacent)
                {
                    return false;
                }
            }
        }
        return true;
    }

    template <typename Coord>
    Coord area(const Triangle<Coord>& triangle)
    {
        Coord s12 = triangle.p1() - triangle.p0();
        Coord s13 = triangle.p3() - triangle.p0();

        Coord det = s12.x() * s13.y() - s12.y() * s13.x();
        return std::abs(det) / 2.0;
    }

} // namespace linalg

#endif // LINALG_TRIANGLE_HH