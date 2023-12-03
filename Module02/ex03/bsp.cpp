#include "Point.hpp"
#include <cmath>

bool sameSide(const Point& p1, const Point& p2, const Point& a, const Point& b) 
{
    Fixed cp1 = (b.getX() - a.getX()) * (p1.getY() - a.getY()) - (b.getY() - a.getY()) * (p1.getX() - a.getX());
    Fixed cp2 = (b.getX() - a.getX()) * (p2.getY() - a.getY()) - (b.getY() - a.getY()) * (p2.getX() - a.getX());
    // Verifica se os produtos cruzados têm o mesmo sinal ou são ambos zero
    return cp1 * cp2 >= Fixed(0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    //Esta a verificar se tão dentro do triangulo, os pontos!
    return sameSide(point, a, b, c) && sameSide(point, b, a, c) && sameSide(point, c, a, b);
}