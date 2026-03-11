/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:21:32 by ebella            #+#    #+#             */
/*   Updated: 2026/02/12 14:21:32 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Original value: " << data.value << std::endl;
	std::cout << "Deserialized value: " << ptr->value << std::endl;
	return 0;
}
