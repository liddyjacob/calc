
struct Expr;
struct Int;
struct Add;
struct Sub;


struct Visitor
{
	virtual void visit(Int* e) = 0;
	virtual void visit(Add* e) = 0;
	virtual void visit(Sub* e) = 0;
}

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

	void visit(Sub* e) override {
		EvalVisitor v1;
		e->e1->accept(v1);

		EvalVisitor v2;
		e->e2->accept(v2);

		ret = v1.ret - v2.ret;	
	}


}


struct Expr{

	virtual ~Expr() = default;
};

struct Int : Expr
{
	Int(int n)
		:val(n)
	{ }

	Int (const Int& n):
		:val(n.n)
	{ }

	void accept(Visitor& v) {v.visit(this);}

	int val;
};


struct Binary: Expr
{


	virtual void accept(Visitor& v) =0;
};



struct Add : Binary{
	using Binary::Binary;

	void 

};

struct Sub : Binary{
	using Binary::Binary();

};
