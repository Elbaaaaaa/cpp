/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:38:25 by ebella            #+#    #+#             */
/*   Updated: 2026/03/11 14:33:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>

enum Type
{
	TYPE_A,
	TYPE_B,
	TYPE_C,
	TYPE_UNKNOWN,
};


Base* generate(void);
Type getType(Base *p);
Type getType(Base &p);
void identify(Base* p);
void identify(Base& p);