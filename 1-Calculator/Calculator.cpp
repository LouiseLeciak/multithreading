/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:56:15 by lleciak           #+#    #+#             */
/*   Updated: 2025/07/21 11:57:08 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <thread>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>

std::vector<int> generateArray(){
    std::vector<int> array(100);
    std::srand(std::time(nullptr));
    
    for (int i = 0; i < 100; i++){
        array[i] = 1;
    }

    return (array);
}


void    printArray(std::vector<int> arr, int start, int end){
    for (int i = start; i < end; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void sumOf(std::vector<int> arr, int start, int end, int& result)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
		sum += arr[i];

    std::cout << sum << std::endl;
    result = sum;
}

int main(void)
{
    std::vector<int> arr = generateArray();
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    
    std::cout << "threads calculating..." << std::endl;
    std::thread t1(sumOf, arr, 0, 24, std::ref(sum1));
    std::thread t2(sumOf, arr, 25, 49, std::ref(sum2));
    std::thread t3(sumOf, arr, 50, 74, std::ref(sum3));
    std::thread t4(sumOf, arr, 75, 99, std::ref(sum4));
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    std::cout << "threads calculation is over." << std::endl;
    std::cout << "Calculating the sum of every thread..." << std::endl;
    std::cout << "Calculation is over, the sum of every thread is " <<
    sum1 + sum2 + sum3 + sum4 << std::endl;

    return(0);
}

