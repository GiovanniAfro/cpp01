/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:37:52 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 10:53:07 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Using newZombie to create a zombie on the heap
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // Using randomChump to create a zombie on the stack
    randomChump("Stack Zombie");

    // Deallocating the heap zombie to prevent memory leaks
    delete heapZombie;

    return 0;
}
