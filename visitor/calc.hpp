
struct Expr;
struct Int;
struct Add;
struct Sub;


struct Visitor
{
	virtual void visit(Int* e) = 0;
	virtual void visit(Add* e) = 0;
	virtual void visit(Sub* e) = 0;
	virtual void visit(Mul* e) = 0;
	virtual void visit(Div* e) = 0;
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
}

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
}



struct Expr{
	virtual ~Expr() = { }
	virtual void accept(Visitor& v) = 0;
	virtual Expr* clone() = 0;
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

	Int* clone() override{
		return new Int(v);
	}

	int val;
};


struct Binary : Expr
{
	Binary(Expr e1, Expr e2)
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


