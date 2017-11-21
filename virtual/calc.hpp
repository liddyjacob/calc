//Virtual implementation of calculator function - 

struct Expr;
struct Int;
struct Mult;
struct Add;


struct Expr { 
	virtual ~Expr() = 0;
	virtual Expr* clone() = 0;
	virtual void print() = 0;
	virtual int eval() = 0;
}

