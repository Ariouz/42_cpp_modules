# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void) other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {(void) other; return *this;}

PmergeMe::~PmergeMe() {}

/*
    Returns the next group size (2, 2, 6, 10, 22, 42, ...)
*/
size_t PmergeMe::getNextGroupSize(int groupCount)
{
    if (groupCount <= 0)
        return 0;
    if (groupCount == 1)
        return 2;
    return getNextGroupSize(groupCount - 1) + getNextGroupSize(groupCount - 2) * 2;
}
















///////////////////////////// VECTOR /////////////////////////////

/*  
    Get a subvector from another one
*/
std::vector<int> PmergeMe::subVector(const std::vector<int>& vec, size_t start, size_t end) {
    return std::vector<int>(vec.begin() + start, vec.begin() + end);
}

/*
    Return the index of x in S to set it to the index of y
*/
void PmergeMe::getPairIndexesVector(std::vector<t_pair>& pairs, std::vector<int> S, std::vector<t_pair>& indexes)
{
    for (size_t index = 0; index < S.size(); index++)
    {
        int s = S[index];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            t_pair pair = pairs[j];
            if (pair.a == s || pair.b == s)
            {
                int pairVal = pair.a == s ? pair.b : pair.a;
                if (std::find(S.begin(), S.end(), pairVal) == S.end())
                {
                    t_pair p = {(int) index, pairVal};
                    indexes.push_back(p);
                }
                break;
            }
        }
    }
}

/*
    Check if vector contains a pair by its .a value
*/
bool PmergeMe::hasPairAVector(std::vector<t_pair>& pairs, int value)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        t_pair pair = pairs[i];
        if (pair.a == value)
            return true;
    }
    return false;
}

/* 
    Retrieve a pair by its .a value
*/
t_pair PmergeMe::getPairByAVector(std::vector<t_pair>& pairs, int value)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        t_pair pair = pairs[i];
        if (pair.a == value)
            return pair;
    }
    t_pair ret = {-1, -1};
    return ret;
}

/*
    Create a group
*/
std::vector<int> PmergeMe::createGroupVector(size_t index, size_t groupSize, std::vector<t_pair>& indexes)
{
    std::vector<int> group;
    size_t count = 0;
    for (size_t i = index; i < indexes.size(); i++)
    {
        if (count == groupSize)
            break;
        t_pair pair = indexes[i];
        if (pair.a == (int) (i+2))
        {
            group.push_back(pair.b);
            count++;
        }
    }
    return group;
}

/*  
    Group remaining values to insert
*/
void PmergeMe::getGroupsVector(std::vector<t_pair>& indexes, size_t start, std::vector<std::vector<int> >& groups)
{
    size_t totalSize = indexes.size();
    int groupCount = 1;
    size_t index = start;

    while (totalSize > 0)
    {
        size_t groupSize = getNextGroupSize(groupCount);
        std::vector<int> group = createGroupVector(index, groupSize, indexes);
        if (group.size() == 0)
            break;
        std::reverse(group.begin(), group.end());
        groups.push_back(group);
        index += groupSize;
        totalSize -= groupSize;
        groupCount++;
    }
}


/*
    Get appaired value
*/
int PmergeMe::getPairValueVector(int val, std::vector<t_pair>& pairs)
{
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        if (pair.a == val || pair.b == val)
            return pair.a == val ? pair.b : pair.a;
    }
    return -1;
}

/*
    Get value insert index using dichotomy
*/
int PmergeMe::getInsertIndexVector(int val, int start, int end, std::vector<int>& S)
{
    if (start > end)
        return start;
    int mid = (start + end) / 2;
    if (S[mid] > val)
        return getInsertIndexVector(val, start, mid - 1, S);
    else
        return getInsertIndexVector(val, mid + 1, end, S);
}

/*
    Set insertIndexes for remaining values, then insert them using dichotomy
*/
void PmergeMe::stepFiveVector(std::vector<t_pair>& pairs, std::vector<int> S, int unpaired)
{
    int unpairedIndex = -1;
    if (unpaired != -1)
        unpairedIndex = S.size();

    std::vector<t_pair> pairsIndexes;
    getPairIndexesVector(pairs, S, pairsIndexes);
    t_pair remainPair = {unpairedIndex, unpaired};
    pairsIndexes.push_back(remainPair);
    
    std::vector<std::vector<int> > groups;
    getGroupsVector(pairsIndexes, 0, groups);

    for (size_t index = 0; index < groups.size(); index++)
    {
        std::vector<int> group = groups[index];
        for (size_t j = 0; j < group.size(); j++)
        {
            int val = group[j];
            int pairValue = getPairValueVector(val, pairs);
            int maxIndex = -1;
            if (pairValue == -1)
                maxIndex = S.size() - 1;
            else
                maxIndex = std::find(S.begin(), S.end(), pairValue) - S.begin();
            int insertIndex = getInsertIndexVector(val, 0, maxIndex, S);
            S.insert(S.begin() + insertIndex, val);
        }
    }

    std::cout << std::endl << "After  => S: [";
    for (size_t index = 0; index < S.size(); index++)
        std::cout << S[index] << (index == S.size() -1 ? "" : ", ") << "";
    std::cout << "]" << std::endl;
}

/*
    Insert the appaired value of S[0] to S
*/
void PmergeMe::stepFourVector(std::vector<t_pair>& pairs, std::vector<int> maxS, int unpaired)
{
    int minPair = -1;
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        if (pair.a  == maxS[0] || pair.b == maxS[0])
            minPair = std::min(pair.a, pair.b);
    }
    maxS.insert(maxS.begin(), minPair);
    stepFiveVector(pairs, maxS, unpaired);
}

/*
    Sort the maximums vector S
*/
void PmergeMe::stepThreeVector(std::vector<t_pair>& pairs, std::vector<int> maxS, int unpaired)
{
    std::sort(maxS.begin(), maxS.end());
    stepFourVector(pairs, maxS, unpaired);
}

/* 
    Add max number of each pair to the result vector
*/
void PmergeMe::isolateMaxsVector(std::vector<t_pair>& pairs, int unpaired)
{
    std::vector<int> maxS;
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        maxS.push_back(std::max(pair.a, pair.b));
    }
    stepThreeVector(pairs, maxS, unpaired);
}

/*
    Split values into pairs, leaving a value if odd count
*/
void PmergeMe::mergeInsertionSortAlgoVector(std::vector<int>& values, std::vector<t_pair>& pairs)
{
    size_t size = values.size();
    if (size == 2)
    {
        t_pair pair = { values[0], values[1] };
        pairs.push_back(pair);
        return ;
    }

    int i = 0;
    while (size >= 2)
    {
        std::vector<int> sub = subVector(values, i, i+2);
        mergeInsertionSortAlgoVector(sub, pairs);
        i += 2;
        size -= 2;
    }

    int unpaired = -1;
    size = values.size();
    if (subVector(values, i, size).size() == 1)
        unpaired = values[i];
    isolateMaxsVector(pairs, unpaired);
}

/*
    Main function
*/
void PmergeMe::mergeInsertionSortVector(std::vector<int>& values)
{
    std::cout << "Before => S: [";
    for (size_t index = 0; index < values.size(); index++)
        std::cout << values[index] << (index == values.size() -1 ? "" : ", ") << "";

    std::cout << "]" << std::endl;
    std::vector<t_pair> pairs;
    mergeInsertionSortAlgoVector(values, pairs);
}












///////////////////////////// DEQUE /////////////////////////////

/*  
    Get a subDeque from another one
*/
std::deque<int> PmergeMe::subDeque(const std::deque<int>& vec, size_t start, size_t end) {
    return std::deque<int>(vec.begin() + start, vec.begin() + end);
}

/*
    Return the index of x in S to set it to the index of y
*/
void PmergeMe::getPairIndexesDeque(std::deque<t_pair>& pairs, std::deque<int> S, std::deque<t_pair>& indexes)
{
    for (size_t index = 0; index < S.size(); index++)
    {
        int s = S[index];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            t_pair pair = pairs[j];
            if (pair.a == s || pair.b == s)
            {
                int pairVal = pair.a == s ? pair.b : pair.a;
                if (std::find(S.begin(), S.end(), pairVal) == S.end())
                {
                    t_pair p = {(int) index, pairVal};
                    indexes.push_back(p);
                }
                break;
            }
        }
    }
}

/*
    Check if Deque contains a pair by its .a value
*/
bool PmergeMe::hasPairADeque(std::deque<t_pair>& pairs, int value)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        t_pair pair = pairs[i];
        if (pair.a == value)
            return true;
    }
    return false;
}

/* 
    Retrieve a pair by its .a value
*/
t_pair PmergeMe::getPairByADeque(std::deque<t_pair>& pairs, int value)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        t_pair pair = pairs[i];
        if (pair.a == value)
            return pair;
    }
    t_pair ret = {-1, -1};
    return ret;
}

/*
    Create a group
*/
std::deque<int> PmergeMe::createGroupDeque(size_t index, size_t groupSize, std::deque<t_pair>& indexes)
{
    std::deque<int> group;
    size_t count = 0;
    for (size_t i = index; i < indexes.size(); i++)
    {
        if (count == groupSize)
            break;
        t_pair pair = indexes[i];
        if (pair.a == (int) (i+2))
        {
            group.push_back(pair.b);
            count++;
        }
    }
    return group;
}

/*  
    Group remaining values to insert
*/
void PmergeMe::getGroupsDeque(std::deque<t_pair>& indexes, size_t start, std::deque<std::deque<int> >& groups)
{
    size_t totalSize = indexes.size();
    int groupCount = 1;
    size_t index = start;

    while (totalSize > 0)
    {
        size_t groupSize = getNextGroupSize(groupCount);
        std::deque<int> group = createGroupDeque(index, groupSize, indexes);
        if (group.size() == 0)
            break;
        std::reverse(group.begin(), group.end());
        groups.push_back(group);
        index += groupSize;
        totalSize -= groupSize;
        groupCount++;
    }
}


/*
    Get appaired value
*/
int PmergeMe::getPairValueDeque(int val, std::deque<t_pair>& pairs)
{
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        if (pair.a == val || pair.b == val)
            return pair.a == val ? pair.b : pair.a;
    }
    return -1;
}

/*
    Get value insert index using dichotomy
*/
int PmergeMe::getInsertIndexDeque(int val, int start, int end, std::deque<int>& S)
{
    if (start > end)
        return start;
    int mid = (start + end) / 2;
    if (S[mid] > val)
        return getInsertIndexDeque(val, start, mid - 1, S);
    else
        return getInsertIndexDeque(val, mid + 1, end, S);
}

/*
    Set insertIndexes for remaining values, then insert them using dichotomy
*/
void PmergeMe::stepFiveDeque(std::deque<t_pair>& pairs, std::deque<int> S, int unpaired)
{
    int unpairedIndex = -1;
    if (unpaired != -1)
        unpairedIndex = S.size();

    std::deque<t_pair> pairsIndexes;
    getPairIndexesDeque(pairs, S, pairsIndexes);
    t_pair remainPair = {unpairedIndex, unpaired};
    pairsIndexes.push_back(remainPair);
    std::deque<std::deque<int> > groups;
    getGroupsDeque(pairsIndexes, 0, groups);

    for (size_t index = 0; index < groups.size(); index++)
    {
        std::deque<int> group = groups[index];
        for (size_t j = 0; j < group.size(); j++)
        {
            int val = group[j];
            int pairValue = getPairValueDeque(val, pairs);
            int maxIndex = -1;
            if (pairValue == -1)
                maxIndex = S.size() - 1;
            else
                maxIndex = std::find(S.begin(), S.end(), pairValue) - S.begin();
            int insertIndex = getInsertIndexDeque(val, 0, maxIndex, S);
            S.insert(S.begin() + insertIndex, val);
        }
    }
    std::cout << std::endl << "After  => S: [";
    for (size_t index = 0; index < S.size(); index++)
        std::cout << S[index] << (index == S.size() -1 ? "" : ", ") << "";
    std::cout << "]" << std::endl;
}

/*
    Insert the appaired value of S[0] to S
*/
void PmergeMe::stepFourDeque(std::deque<t_pair>& pairs, std::deque<int> maxS, int unpaired)
{
    int minPair = -1;
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        if (pair.a  == maxS[0] || pair.b == maxS[0])
            minPair = std::min(pair.a, pair.b);
    }
    maxS.insert(maxS.begin(), minPair);
    stepFiveDeque(pairs, maxS, unpaired);
}

/*
    Sort the maximums Deque S
*/
void PmergeMe::stepThreeDeque(std::deque<t_pair>& pairs, std::deque<int> maxS, int unpaired)
{
    std::sort(maxS.begin(), maxS.end());
    stepFourDeque(pairs, maxS, unpaired);
}

/* 
    Add max number of each pair to the result Deque
*/
void PmergeMe::isolateMaxsDeque(std::deque<t_pair>& pairs, int unpaired)
{
    std::deque<int> maxS;
    for (size_t index = 0; index < pairs.size(); index++)
    {
        t_pair pair = pairs[index];
        maxS.push_back(std::max(pair.a, pair.b));
    }
    stepThreeDeque(pairs, maxS, unpaired);
}

/*
    Split values into pairs, leaving a value if odd count
*/
void PmergeMe::mergeInsertionSortAlgoDeque(std::deque<int>& values, std::deque<t_pair>& pairs)
{
    size_t size = values.size();
    if (size == 2)
    {
        t_pair pair = { values[0], values[1] };
        pairs.push_back(pair);
        return ;
    }

    int i = 0;
    while (size >= 2)
    {
        std::deque<int> sub = subDeque(values, i, i+2);
        mergeInsertionSortAlgoDeque(sub, pairs);
        i += 2;
        size -= 2;
    }

    int unpaired = -1;
    size = values.size();
    if (subDeque(values, i, size).size() == 1)
        unpaired = values[i];
    isolateMaxsDeque(pairs, unpaired);
}

/*
    Main function
*/
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& values)
{
    std::cout << "Before => S: [";
    for (size_t index = 0; index < values.size(); index++)
        std::cout << values[index] << (index == values.size() -1 ? "" : ", ") << "";

    std::cout << "]" << std::endl;
    std::deque<t_pair> pairs;
    mergeInsertionSortAlgoDeque(values, pairs);
}

