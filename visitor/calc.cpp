
#include "calc.hpp"

#include <iostream>
#include <sstream>

int eval(Expr* eptr);

struct EvalVisitor : Visitor
{
	int ret;

	void visit(Int* e) override {
		ret = e->val;
	}

	void visit(Add* e) override {
		EvalVisitor v1;
		e->e1->accept(v1);

		EvalVisitor v2;
		e->e2->accept(v2);

		ret = v1.ret + v2.ret;
	
	}

	void visit(Div* e) override {
		EvalVisitor v1;
		e->e1->accept(v1);

		EvalVisitor v2;
		e->e2->accept(v2);

		assert(v2.ret != 0);

		ret = v1.ret / v2.ret;	
	}

	void visit(Mul* e) override {
		EvalVisitor v1;
		e->e1->accept(v1);

		EvalVisitor v2;
		e->e2->accept(v2);

		ret = v1.ret * v2.ret;	
	}


	void visit(Sub* e) override {
		EvalVisitor v1;
		e->e1->accept(v1);

		EvalVisitor v2;
		e->e2->accept(v2);

		ret = v1.ret - v2.ret;	
	}
};

struct PrintVisitor : Visitor
{
	std::ostringstream ostr;


	void visit(Int* e) override {
		ostr << e->val;
	}

	void visit(Add* e) override {
		ostr << '(';

		PrintVisitor v1;
		e->e1->accept(v1);

		ostr << v1.ostr.rdbuf();

		ostr << ") + (";

		PrintVisitor v2;
		e->e2->accept(v2);

		ostr << v2.ostr.rdbuf();


		ostr << ")";
	
	}

	void visit(Div* e) override {
		ostr << '(';

		PrintVisitor v1;
		e->e1->accept(v1);

		ostr << v1.ostr.rdbuf();


		ostr << ") / (";

		PrintVisitor v2;
		e->e2->accept(v2);

		ostr << v2.ostr.rdbuf();


		ostr << ")";
	
	}

	void visit(Mul* e) override {
		ostr << '(';

		PrintVisitor v1;
		e->e1->accept(v1);

		ostr << v1.ostr.rdbuf();


		ostr << ") * (";

		PrintVisitor v2;
		e->e2->accept(v2);

		ostr << v2.ostr.rdbuf();


		ostr << ")";
	
	}


	void visit(Sub* e) override {
		ostr << '(';

		PrintVisitor v1;
		e->e1->accept(v1);

		ostr << v1.ostr.rdbuf();

		ostr << ") - (";

		PrintVisitor v2;
		e->e2->accept(v2);

		ostr << v2.ostr.rdbuf();

		ostr << ")";
	
	}

};

int eval(Expr* e){
	EvalVisitor ev;
	e->accept(ev);
	return ev.ret;
}

std::ostream& operator<<(std::ostream& os, Expr* e){
	std::stringstream ss;
	PrintVisitor pv;
	e->accept(pv);
	os << pv.ostr.str();

	return os;
}
