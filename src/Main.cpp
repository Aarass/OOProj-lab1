#include <iostream>
#include "Board.h"

std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Board board;

	/*RegularField* rf1 = new RegularField(FieldEffect::O);
	RegularField* rf2 = new RegularField(FieldEffect::P);
	RegularField* rf3 = new RegularField(FieldEffect::H);
	
	Crossroad* c1 = new Crossroad();
	Crossroad* c2 = new Crossroad();

	TwoWayField* twf1 = new TwoWayField();
	TwoWayField* twf2 = new TwoWayField();
	TwoWayField* twf3 = new TwoWayField();

	RegularField* rf4 = new RegularField(FieldEffect::X);
	RegularField* rf5 = new RegularField(FieldEffect::S);
	RegularField* rf6 = new RegularField(FieldEffect::T);

	RegularField* rf7 = new RegularField(FieldEffect::NONE);

	rf1->addNext(rf2);
	rf2->addNext(rf3);
	rf3->addNext(c1);

	c1->addNext(rf4);

	rf4->addNext(rf5);
	rf5->addNext(rf6);
	rf6->addNext(c2);

	c2->addNext(rf7);
	rf7->addNext(rf1);

	c1->addLeft(twf1);
	twf1->addPrev(c1);

	twf1->addNext(twf2);
	twf2->addPrev(twf1);

	twf2->addNext(twf3);
	twf3->addPrev(twf2);

	twf3->addNext(c2);
	c2->addLeft(twf3);

	Field* curr = rf1;

	int d, t;
	std::cin >> d >> t;
	while (d != '\n')
	{
		Direction dir = d == 1 ? Direction::FORWARD : Direction::BACKWARD;
		bool st = t == 1 ? true : false;
		Field* next = curr->nextField(dir, st);

		std::cout << next->getEffect() << std::endl;
		
		curr = next;

		std::cin >> d >> t;
	}*/

	return 0;
}
std::ostream& operator<< (std::ostream& out, FieldEffect f)
{
	switch (f)
	{
	case FieldEffect::NONE:
		out << "None" << std::endl;
		break;
	case FieldEffect::O:
		out << "O" << std::endl;
		break;
	case FieldEffect::P:
		out << "P" << std::endl;
		break;
	case FieldEffect::H:
		out << "H" << std::endl;
		break;
	case FieldEffect::X:
		out << "X" << std::endl;
		break;
	case FieldEffect::S:
		out << "S" << std::endl;
		break;
	case FieldEffect::T:
		out << "T" << std::endl;
		break;
	default:
		break;
	}
	return out;
}