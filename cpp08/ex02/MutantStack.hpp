#ifndef MUTANT_HPP
# define MUTANT_HPP

# include <stack>
# include <deque>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack() {};
        MutantStack(const MutantStack& other) : std::stack<T, C>(other) {*this = other;}
        MutantStack& operator=(const MutantStack& other) {
            if (this == &other) return *this;
            this->std::stack<T, C>::operator=(other);
            return *this;
        }

        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;
        typedef typename C::reverse_iterator reverse_iterator;
        typedef typename C::const_reverse_iterator const_reverse_iterator;

        iterator begin() {return this->std::stack<T, C>::c.begin();}
        iterator end() {return this->std::stack<T, C>::c.end();}

        const_iterator begin() const {return this->std::stack<T, C>::c.begin();}
        const_iterator end() const {return this->std::stack<T, C>::c.end();}

        reverse_iterator rbegin() {return this->std::stack<T, C>::c.rbegin();}
        reverse_iterator rend() {return this->std::stack<T, C>::c.rend();}

        const_reverse_iterator rbegin() const {return this->std::stack<T, C>::c.rbegin();}
        const_reverse_iterator rend() const {return this->std::stack<T, C>::c.rend();}

};

#endif