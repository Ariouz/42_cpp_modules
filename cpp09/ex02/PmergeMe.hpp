#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>

    typedef struct s_pair
    {
        int a;
        int b;
    }   t_pair;

class PmergeMe 
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();


        void                mergeInsertionSortVector(std::vector<int>& values);
        void                mergeInsertionSortDeque(std::deque<int>& values);


    private:
        size_t              getNextGroupSize(int groupCount);

    
        // VECTOR
        std::vector<int>    subVector(const std::vector<int>& vec, size_t start, size_t end);
        void                getPairIndexesVector(std::vector<t_pair>& pairs, std::vector<int> S, std::vector<t_pair>& indexes);
        bool                hasPairAVector(std::vector<t_pair>& pairs, int value);
        t_pair              getPairByAVector(std::vector<t_pair>& pairs, int value);
        std::vector<int>    createGroupVector(size_t index, size_t groupSize, std::vector<t_pair>& indexes);
        void                getGroupsVector(std::vector<t_pair>& indexes, size_t start, std::vector<std::vector<int> >& groups);
        int                 getPairValueVector(int val, std::vector<t_pair>& pairs);
        int                 getInsertIndexVector(int val, int start, int end, std::vector<int>& S);
        void                stepFiveVector(std::vector<t_pair>& pairs, std::vector<int> S, int unpaired);
        void                stepFourVector(std::vector<t_pair>& pairs, std::vector<int> maxS, int unpaired);
        void                stepThreeVector(std::vector<t_pair>& pairs, std::vector<int> maxS, int unpaired);
        void                isolateMaxsVector(std::vector<t_pair>& pairs, int unpaired);
        void                mergeInsertionSortAlgoVector(std::vector<int>& values, std::vector<t_pair>& pairs);

        // DEQUE
        std::deque<int>     subDeque(const std::deque<int>& vec, size_t start, size_t end);
        void                getPairIndexesDeque(std::deque<t_pair>& pairs, std::deque<int> S, std::deque<t_pair>& indexes);
        bool                hasPairADeque(std::deque<t_pair>& pairs, int value);
        t_pair              getPairByADeque(std::deque<t_pair>& pairs, int value);
        std::deque<int>     createGroupDeque(size_t index, size_t groupSize, std::deque<t_pair>& indexes);
        void                getGroupsDeque(std::deque<t_pair>& indexes, size_t start, std::deque<std::deque<int> >& groups);
        int                 getPairValueDeque(int val, std::deque<t_pair>& pairs);
        int                 getInsertIndexDeque(int val, int start, int end, std::deque<int>& S);
        void                stepFiveDeque(std::deque<t_pair>& pairs, std::deque<int> S, int unpaired);
        void                stepFourDeque(std::deque<t_pair>& pairs, std::deque<int> maxS, int unpaired);
        void                stepThreeDeque(std::deque<t_pair>& pairs, std::deque<int> maxS, int unpaired);
        void                isolateMaxsDeque(std::deque<t_pair>& pairs, int unpaired);
        void                mergeInsertionSortAlgoDeque(std::deque<int>& values, std::deque<t_pair>& pairs);
    
    };

#endif