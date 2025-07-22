/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SudokuGrid.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:17:20 by lleciak           #+#    #+#             */
/*   Updated: 2025/07/22 11:49:03 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pour la structure et la resolution d'une grille
#include "SudokuGrid.hpp"
#include <iostream>


bool SudokuGrid::solve()
{
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (grid[row][col] == 0) { // case vide
                for (int val = 1; val <= 9; ++val) {
                    if (is_valid(row, col, val)) {
                        grid[row][col] = val;
                        if (solve()) return true;
                        grid[row][col] = 0; // backtrack
                    }
                }
                return false; // aucun chiffre possible ici
            }
        }
    }
    return true; // plus de case vide => sudoku résolu
}

bool SudokuGrid::is_valid(int row, int col, int val)
{
    // Vérifie ligne et colonne
    for (int i = 0; i < size; ++i) {
        if (grid[row][i] == val || grid[i][col] == val)
            return false;
    }

    // Vérifie le bloc 3x3
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[start_row + i][start_col + j] == val)
                return false;
        }
    }

    return true;
}

void SudokuGrid::load_from_string(std::string input)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            char c = input[i * size + j];
            grid[i][j] = c - '0';
        }
    }
}

void SudokuGrid::print()
{

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int value = grid[i][j];
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

// https://www.geeksforgeeks.org/dsa/sudoku-backtracking-7/

