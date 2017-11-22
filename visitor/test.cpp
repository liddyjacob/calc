
#include <iostream>

#include "calc.hpp"
//#include "calc.cpp"

int main(){

Expr* eptr = new Mul(new Add(new Div(new Int(6), new Int(2)),
														 new Int(4)),
                     new Sub(new Int(2), new Int(5))
						        );

std::cout << eptr << " = " << eval(eptr) << std::endl;

return 0;

}
