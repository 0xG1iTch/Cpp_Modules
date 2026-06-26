#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& obj){(void) obj;}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){
    (void) obj;
    return *this;
}
PmergeMe::~PmergeMe(){}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> con)
{
    if (con.size() <= 1) return con;
    std::deque<std::pair<int, int> > local;
    for (size_t i = 0; i < con.size() - 1; i += 2)
    {
        if (con[i] > con[i + 1])
            local.push_back(std::make_pair(con[i], con[i + 1]));
        else
            local.push_back(std::make_pair(con[i + 1], con[i]));
    }
    if ((con.size()) % 2 == 1)
        local.push_back(std::make_pair(-1, con[con.size() - 1]));
    std::deque<int> large;
    for(size_t i = 0; i < local.size(); i++)
    {
        if (local[i].first != -1)
            large.push_back(local[i].first);
    }
    std::deque<int> winners = fordJohnsonDeque(large);
    std::deque<std::pair<int,int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); i++)
    {
        int loser;
        for (size_t j = 0; j < local.size(); j++)
        {
            if(winners[i] == local[j].first)
                loser = local[j].second;
        }
        sortedPairs.push_back(std::make_pair(winners[i], loser));
    }
    for (size_t j = 0; j < local.size(); j++)
    {
        if (local[j].first == -1)
            sortedPairs.push_back(local[j]);
    }    
    std::deque<int> main_chain;
    return jacobsthal_insertion_order(sortedPairs, main_chain);
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> con)
{
    if (con.size() <= 1) return con;
    std::vector<std::pair<int, int> > local;
    for (size_t i = 0; i < con.size() - 1; i += 2)
    {
        if (con[i] > con[i + 1])
            local.push_back(std::make_pair(con[i], con[i + 1]));
        else
            local.push_back(std::make_pair(con[i + 1], con[i]));
    }
    if ((con.size()) % 2 == 1)
        local.push_back(std::make_pair(-1, con[con.size() - 1]));
    std::vector<int> large;
    for(size_t i = 0; i < local.size(); i++)
    {
        if (local[i].first != -1)
            large.push_back(local[i].first);
    }
    std::vector<int>  winners = fordJohnsonVector(large);
    std::vector<std::pair<int,int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); i++)
    {
        int loser;
        for (size_t j = 0; j < local.size(); j++)
        {
            if(winners[i] == local[j].first)
                loser = local[j].second;
        }
        sortedPairs.push_back(std::make_pair(winners[i], loser));
    }
    for (size_t j = 0; j < local.size(); j++)
    {
        if (local[j].first == -1)
            sortedPairs.push_back(local[j]);
    }    
    std::vector<int> main_chain;
    return jacobsthal_insertion_order(sortedPairs, main_chain);
}