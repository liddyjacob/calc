
#include <iostream>

#include "calc.hpp"

std::ostream& operator<<(std::ostream& os, const Expr* e)
{
//	e->print(os);
	return os;

}

int main(){

Expr* eptr = new Mul(new Add(new Div(new Int(6), new Int(2)),
														 new Int(4)),
                     new Sub(new Int(2), new Int(5))
						        );

//std::cout << eptr << " = " << eptr->eval() << std::endl;

return 0;

}
