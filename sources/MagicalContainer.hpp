#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
    private:
        void orderPrimes(int element);
        size_t containerSize;
        std::vector<int> container;
        std::vector<int*> pointersToPrime;
        std::vector<int*> pointersToCross;

    public:
        MagicalContainer();
        ~MagicalContainer();


        void addElement(int element);
        void removeElement(int element);
       
        size_t size();

        static bool isPrime(int number);

        class AscendingIterator
        {
        private:
            size_t index;
            MagicalContainer *mContain;

        public:
            // Constructors
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            // Operators
            AscendingIterator &operator++();
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;

            // Other
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            size_t index;
            MagicalContainer *mContain;
            bool isStart = true;
            size_t timesAdded;


        public:
            // Constructors
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &other);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            // Operators
            SideCrossIterator &operator++();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;

            // Others
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            size_t index;
            MagicalContainer *mContain;

        public:
            // Constructors
            PrimeIterator();
            PrimeIterator(MagicalContainer &other);
            ~PrimeIterator();

            // Operators
            PrimeIterator &operator++();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;

            // Other
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}

#endif
