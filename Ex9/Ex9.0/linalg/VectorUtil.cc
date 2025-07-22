#include "VectorUtil.hh"
#include "Vector2D.hh"
#include "Vector3D.hh"

namespace linalg
{
    void baryIO()
    {
        std::cout << "Choose dimension (2D or 3D): ";
        std::string dimension;

        std::cin >> dimension;
        baryIO(dimension);
    }

    void baryIO(std::string const& dimension)
    {
        if (dimension == "2D") {
            baryIO2D();
            // Additional operations can be performed on v2d
        } else if (dimension == "3D") {
            baryIO3D();
        } else {
            std::cerr << "Invalid dimension choice. Please enter '2D' or '3D'." << std::endl;
        }
    }
}