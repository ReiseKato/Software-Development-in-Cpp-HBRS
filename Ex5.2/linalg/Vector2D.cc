#include "Vector2D.hh"

namespace linalg {

std::ostream& operator<<(std::ostream& os, Vector2D const& v) {
    os << "(" << v.x() << "," << v.y() << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2D& v) {
    char c;
    is >> c;       // Read '('
    is >> v.x_;
    is >> c;       // Read ','
    is >> v.y_;
    is >> c;       // Read ')'
    return is;
}

} // namespace linalg
