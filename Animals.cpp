#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal () {
//		std::cout << "Animal " << this << " created\n";
	};
	virtual ~Animal () {
//		std::cout << "Animal " << this << " destroyed\n";
	};
	void talk ();
	void walk ();
	void smile ();

	void sniff () {
		cout << "\nSniffing!\n";
	}

	void setName (string name) {
		nameOfTheAnimal_ = name;
	}

	string getNameOfTheAnimal () const{
		return nameOfTheAnimal_;
	}

	void setAgeOfTheAnimal (int age) {
		ageOfTheAnimal_ = age;
	}

	int getAgeOfTheAnimal () const {
		return ageOfTheAnimal_;
	}

	void setStepsOfTheDay (int steps) {
		stepsOfTheDay_ = steps;
	}

	int getStepsOfTheDay () const{
		return stepsOfTheDay_;
	}

	
private:
	string nameOfTheAnimal_ = "";
	int ageOfTheAnimal_ = 0;
	int stepsOfTheDay_ = 0;
};

// Травоядные
class Herbivores :public Animal {
public:
	Herbivores () {
//		std::cout << "Herbivore " << this << " created\n";
	};
	virtual ~Herbivores () {
//		std::cout << "Herbivore " << this << " destroyed\n";
	};
	void beingBitten (Animal &attackerHerbivores) {
		cout << "\nBitted by Animal: " << attackerHerbivores.getNameOfTheAnimal ();
	}
private:
	void eatGrass ();
};

// Хищные
class Predatory :public Animal {
public:
	Predatory () {};
	virtual ~Predatory () {};
	void hunt () {
		cout << "\nHunting\n";
	}
	void eatMeat () {
		cout << "\nEating meat!\n";
	}
	void beingBitten (Animal &attackerPredatory) {
		cout << "Bitted by Animal: " << attackerPredatory.getNameOfTheAnimal () << "\n";
	}

private:

};

class Cat :public Predatory {
public:
	Cat () {};
	~Cat () {};
	void meow () {
		cout << "\nMeow!\n";
	}

private:
	int meowCount = 0;
};

class Dog :public Predatory {
public:
	Dog () {};
	~Dog () {};
	void bark () {
		cout << "\nBark!\n";
	}

private:
	int barkCount = 0;
};

class Rabbit : public Herbivores {
public:
	Rabbit () {};
	~Rabbit () {};
	void runAway () {
		cout << "Running away!\n";
	}
};

class Bear : public Predatory {
public:

	Bear () {};
	~Bear () {};


	void growl () {
		cout << "\nGrr! \n";
	}
};

int main () {
	setlocale (LC_ALL, "Russian");

	Herbivores Herbivore;
	Predatory Predator;

	Cat Cat;
	Dog Dog;
	Rabbit Rabbit;
	Bear Bear;

	Cat.setName ("Mysya");
	Dog.beingBitten (Cat);
	Rabbit.runAway ();

	return 0;
}