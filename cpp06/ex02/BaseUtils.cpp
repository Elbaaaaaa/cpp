/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:37:49 by ebella            #+#    #+#             */
/*   Updated: 2026/03/11 14:34:32 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseUtils.hpp"

/*

	Randomly instantiates A,B or C.
	
	returns the instance as a Base pointer.

*/
Base* generate(void)
{
	int randValue = rand() % 3;
	switch (randValue)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

/*

	We safely detect the real type of p, 
	using dynamic_cast.
	
	if the type is not the right one,
	dynamic_cast returns nullptr, and does
	not enter in the if condition.

*/
Type getType(Base* p)
{
	if (!p)
		return TYPE_UNKNOWN;
	if (dynamic_cast<A*>(p))
		return TYPE_A;
	else if (dynamic_cast<B*>(p))
		return TYPE_B;
	else if (dynamic_cast<C*>(p))
		return TYPE_C;
	else 
		return (TYPE_UNKNOWN);
}

/*

	using reference (&p) to get the real type,
	of the object p;

*/
Type getType(Base& p)
{
	if (dynamic_cast<A*>(&p))
		return TYPE_A;
	else if (dynamic_cast<B*>(&p))
		return TYPE_B;
	else if (dynamic_cast<C*>(&p))
		return TYPE_C;
	else
		return TYPE_UNKNOWN;
}

/*

	Prints the type of the object pointed by p.

*/
void identify(Base* p)
{
	Type t = getType(p);
	if (t == TYPE_UNKNOWN)
		std::cout << "unknown type :/" << std::endl;
	else if (t == TYPE_A)
		std::cout << "type A !" << std::endl;
	else if (t == TYPE_B)
		std::cout << "type B !" << std::endl;
	else if (t == TYPE_C)
		std::cout << "type C !" << std::endl;
}

/*

	Prints the type of the object pointed by p.

*/
void identify(Base& p)
{
	Type t = getType(p);
	if (t == TYPE_UNKNOWN)
		std::cout << "unknown type :/" << std::endl;
	else if (t == TYPE_A)
		std::cout << "type A !" << std::endl;
	else if (t == TYPE_B)
		std::cout << "type B !" << std::endl;
	else if (t == TYPE_C)
		std::cout << "type C !" << std::endl;
}