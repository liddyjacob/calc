
#include "calc.hpp"
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


