
#include <cassert>
#include <iostream>

struct Expr;
struct Int;
struct Add;
struct Sub;
struct Mul;
struct Div;

struct EvalVisitor;
struct PrintVisitor;
int eval(Expr*);
std::ostream& operator<<(std::ostream& os, Expr* e);


struct Visitor
{
	virtual void visit(Int* e) = 0;
	virtual void visit(Add* e) = 0;
	virtual void visit(Sub* e) = 0;
	virtual void visit(Mul* e) = 0;
	virtual void visit(Div* e) = 0;
};



struct Expr{
	virtual ~Expr() { }
	virtual void accept(Visitor& v) = 0;
	virtual Expr* clone() = 0;
};

struct Int : Expr
{
	Int(int n)
		:val(n)
	{ }

	Int (const Int& n)
		: val(n.val)
	{ }

	void accept(Visitor& v) {v.visit(this);}

	Int* clone() override{
		return new Int(val);
	}

	int val;
};


struct Binary : Expr
{
	Binary(Expr* e1, Expr* e2)
		:e1(e1), e2(e2)
	{ }

	~Binary() override{
		delete e1;
		delete e2;
	}

	Expr* e1;
	Expr* e2;
};




struct Add : Binary{
	using Binary::Binary;

	void accept(Visitor& v) override{
		v.visit(this);
	}


	Add* clone() override{
		return new Add(*this);
	}

};

struct Sub : Binary{
	using Binary::Binary;

	void accept(Visitor& v) override{
		v.visit(this);
	}


	Sub* clone() override{
		return new Sub(*this);
	}

};


struct Mul : Binary{
	using Binary::Binary;

	void accept(Visitor& v) override{
		v.visit(this);
	}


	Mul* clone() override{
		return new Mul(*this);
	}

};


struct Div : Binary{
	using Binary::Binary;

	void accept(Visitor& v) override{
		v.visit(this);
	}


	Div* clone() override{
		return new Div(*this);
	}

};


