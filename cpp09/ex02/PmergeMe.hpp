#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe &operator=(const PmergeMe& obj);
        std::deque<int> fordJohnsonDeque(std::deque<int>);
        std::vector<int> fordJohnsonVector(std::vector<int>);

        template <typename Container>
        void print_container(Container &con, char *av[])
        {
            std::cout << "Before: ";
            for (int i = 0; av[i]; i++)
                std::cout << std::atoi(av[i]) << " ";
            std::cout << std::endl;
            std::cout << "After: ";
            for (typename Container::iterator it = con.begin(); it != con.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

    private:
    
        template <typename PairContainer, typename MainContainer>
        MainContainer jacobsthal_insertion_order(PairContainer &pairs, MainContainer &main_chain)
        {
            for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
            {
                if (it->first != -1)
                    main_chain.push_back(it->first);
            }

            main_chain.insert(main_chain.begin(), pairs[0].second);
            if (pairs.size() > 1)
            {
                typename MainContainer::iterator upper = (pairs[1].first == -1) ? main_chain.end() : std::lower_bound(main_chain.begin(), main_chain.end(), pairs[1].first);
                typename MainContainer::iterator pos = std::lower_bound(main_chain.begin(), upper, pairs[1].second);
                main_chain.insert(pos, pairs[1].second);
            }

            int Jn = 3;
            int Jn_1 = 1;
            while (Jn_1 < (int)pairs.size())
            {
                int end = std::min(Jn, (int)pairs.size() - 1);
                for (int i = end; i > Jn_1 ; i--)
                {
                    typename MainContainer::iterator upper = (pairs[i].first == -1) ? main_chain.end() : std::lower_bound(main_chain.begin(), main_chain.end(), pairs[i].first);
                    typename MainContainer::iterator pos = std::lower_bound(main_chain.begin(), upper, pairs[i].second);
                    main_chain.insert(pos, pairs[i].second);
                }
                int next = Jn + 2 * Jn_1;
                Jn_1 = Jn;
                Jn = next;
            }
            return main_chain;
        }
};
#endif