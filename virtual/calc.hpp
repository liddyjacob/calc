//Virtual implementation of calculator function - 

struct Expr;
struct Int;
struct Mult;
struct Add;


struct Expr { 
	virtual ~Expr() = 0;
	virtual Expr* clone() const = 0;
	virtual void print(std::ostream& os) = 0;
	virtual int eval() = 0;
};


struct Int : Expr{
	Int(int v)
		:val(v)
	{ }

	void print(std::ostream& os) override{
		os << val;
	}

	Int* clone() const override {return new Int(*this);}

	int eval() override {return val;}

	int val;
};

struct Binary : Expr {
	Binary(Expr* e1, Expr* e2)
		: e1(e1), e2(e2)
	{ }
	
	~Binary() {
		delete e1;
		delete e2;
	}

	Expr* e1;
	Expr* e2;
};

struct Add : Binary {
	using Binary::Binary;

	void print(std::ostream& os) override{
		os << '(';
		e1->print(os);
		os << ") + (";
		e2->print(os);
		os << ')';
	}

	Add* clone() const override{
		return new Add(*this);
	}

	int eval() override {
		return e1->eval() + e2->eval();
	}

};
