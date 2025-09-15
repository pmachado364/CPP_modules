#include "Point.hpp"

static Fixed get_area(Point const& a, Point const& b, Point const& c) {

	//a formula da area de um triangulo e A = ½ (b × h; o que nao functiona aqui)
	//entao usamos a formula com coordenadas dos pontos :
	//area triangulo = ((x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2

	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();

	Fixed area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed area_abc = get_area(a, b, c);
	Fixed area_abp = get_area(a, b, point);
	Fixed area_acp = get_area(a, c, point);
	Fixed area_bcp = get_area(b, c, point);

	if (area_abp == 0 || area_acp == 0 || area_bcp == 0)
		return false;
	return (area_abc == area_abp + area_acp + area_bcp);
}

