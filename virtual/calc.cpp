
#include "calc.hpp"

/*

	Idea: eval is piecewise:

		             / e if e is int
		             | eval(e.e1) + eval(e.e2) if e is add
		eval(*e) =  {  eval(e.e1) - eval(e.e2) if e is sub
		             | .
		             \ .
  'v
*/

int eval(Expr* e){
	match(e){
		case Int* n:
		case Add* a:
		case Sub* s:
	}
}
