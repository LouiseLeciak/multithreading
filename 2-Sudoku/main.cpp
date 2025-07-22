/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:42:47 by lleciak           #+#    #+#             */
/*   Updated: 2025/07/22 11:48:56 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SudokuGrid.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <future> 

int main (int ac, char **av)
{
    (void)av;
    if (ac != 1){
        std::cerr << "invalid argument: too many." << std::endl;
        return 1;
    }
    std::vector<std::string> grids = {
        "530070000600195000098000060800060003400803001700020006060000280000419005000080079",
        "002008000000600201076000380060402007000000000300701060041000720205004000000100900",
        "000000907000420180000705026100904000050000040000507009920108000034059000507000000",
        "300200000000107000706030500070009080900020004010800050009040301000702000000008006",
        "530570000600195000098000060800060003400803001700020006060000280000419005000080079"
    };

    std::vector<SudokuGrid> sudokuGrids;
    std::vector<std::future<bool>> futures;
    
    for (const auto& str : grids) {
        SudokuGrid g;
        g.load_from_string(str);
        sudokuGrids.push_back(g);
    }

    for (auto& g : sudokuGrids) {
        futures.push_back(std::async(std::launch::async, [&g]() {
            return g.solve();
        }));
    }

    for (size_t i = 0; i < sudokuGrids.size(); ++i) {
        bool success = futures[i].get();
        std::cout << "\nGrille #" << (i + 1) << (success ? " resolue" : " echec") << " :\n";
        sudokuGrids[i].print();
    }

    return 0;
}