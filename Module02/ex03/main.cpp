#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main ( void )
{
	Point	a( -3.0f, -5.0f);
	Point	b(7.0f, -3.0f);
	Point	c ( 2.0f, 8.0f );

	std::cout << std::endl << "*** Drawing a triangle with vertices at (-3, -5), (2, 8), (7, -3) ***" << std::endl;
	std::cout << "Check it out at https://www.easycalculation.com/analytical/draw-triangle.php" << std::endl << std::endl;

	Point	Tests[5];
	Tests[0] = Point( 2.0f, -4.0f );
	Tests[1] = Point( 2.0f, -3.8f );
	Tests[2] = Point( -2.0f, 6.0f );
	Tests[3] = Point( 5.0f, 0.004f );
	Tests[4] = Point( 2.0f, 20.0f );

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Point ( " << Tests[i].getX() << " , " << Tests[i].getY() << " ) "; 
		if (bsp(a, b, c, Tests[i]))
			std::cout << "is inside" << std::endl;
		else
			std::cout << "is outside." << std::endl;
	}
	std::cout << std::endl;
}