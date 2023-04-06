#include <iostream>

class A {
	// nur in der eigenen klasse
	private:
	int i_private = 3;
	
	// sichtbar in der subklasse, nicht aber außerhalb
	protected:
	int i_protected = 5;
	
	// überall sichtbar
	public:
	int i_public = 1;
	
	// die virtuelle Funktion umgeht das slicing bei einer Referenz des Typs A auf das Objekt b
	virtual void foo() {
		std::cout << "Klasse A" << std::endl;
	}
	
	// die normale Funktion wird bei einer Referenz des Typs A auf das Objekt b ausgewählt
	void bar(){
		std::cout << "Klasse A" << std::endl;
	}
	
};

// public vererbte Klassen behalten die Sichtbarkeit ihrer Member bei
// standard ist private, nichts von den Klassen ist dann sichtbar
class B : public A {
	public:
	int i_public = 1;
	void test() {
		//i_private = 0;	// geht nicht, private
		i_protected = 0;	// kann auf protected zugreifen, da B von A erbt.
		i_public = 0;
		
		// A::foo();		// um auf gleichnamige member von A zuzugreifen kann A:: genutzt werden
	}
	
	// override signalisiert dem Compiler, dass eine andere Funktion überschrieben werden sollte
	// falls dem nicht so ist, bekommt man eine Fehlermeldung
	void foo() override {		
		std::cout << "Klasse B" << std::endl;
	}
	
	void bar(){
		std::cout << "Klasse B" << std::endl;
	}
	
	
};

int main() {
	A a;
	B b;
	A& ref_a = b;
	
	// a.i_private = 0;		// geht nicht, private
	// a.i_protected = 0;	// geht nicht, protected
	a.i_public = 0;
	
	b.test();
	
	std::cout << "bar() wird durch slicing (falsch) ausgewählt" << std::endl;
	a.bar();
	b.bar();
	ref_a.bar();
	std::cout << std::endl;
	
	std::cout << "foo() wird durch lookup (richtig) ausgewählt" << std::endl;
	a.foo();
	b.foo();
	ref_a.foo();
	std::cout << std::endl;
}
