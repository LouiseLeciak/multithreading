/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SudokuGrid.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:19:24 by lleciak           #+#    #+#             */
/*   Updated: 2025/07/22 11:12:23 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKUGRID_HPP
#define SUDOKUGRID_HPP

#include <string>

class SudokuGrid {
    public:
        static const int size = 9;
        int grid[size][size];
        
        bool solve();
        bool is_valid(int row, int col, int val);
        void load_from_string(std::string grid);
        void print();
};

#endif