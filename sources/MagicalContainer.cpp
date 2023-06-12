#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

// MAGICAL CONTAINER FUNCTIONS

MagicalContainer::MagicalContainer()
    : containerSize(0)
{
}

MagicalContainer::~MagicalContainer()
{
    for (int* prime : pointersToPrime)
    {
        delete prime;
    }
}

void MagicalContainer::orderPrimes(int element)
{
    int* prime = new int(element);
    if (pointersToPrime.size() == 0)
    {
        pointersToPrime.emplace_back(prime);
        return;
    }

    for (size_t i = 0; i < pointersToPrime.size(); i++)
    {
        if (*pointersToPrime[i] > element)
        {
            pointersToPrime.insert(pointersToPrime.begin() + static_cast<std::vector<int*>::difference_type>(i), prime);
            return;
        }
    }
    pointersToPrime.insert(pointersToPrime.end(), prime);
}


void MagicalContainer::addElement(int element)
{
    if(isPrime(element))
    {
        orderPrimes(element);
    }
    if(containerSize == 0)
    {
        container.emplace_back(element);
        containerSize++;
        return;
    }
    for (size_t i = 0; i < containerSize; i++)
    {
        if(container[i] > element)
        {
            container.insert(container.begin() + static_cast<std::vector<int>::difference_type>(i) ,element);
            containerSize++;
            return;
        }
    }
    container.insert(container.end(), element);
    containerSize++;
}

void MagicalContainer::removeElement(int element)
{
    auto it = std::find(container.begin(), container.end(), element);
    if (it != container.end())
    {
        container.erase(it);
        containerSize--;
    }
    else
    {
        throw std::runtime_error("Number Not In Container");
    }
}

bool MagicalContainer::isPrime(int number)
{
    if(number == 1 || number == 0)
    {
        return false;
    }
    
    if(number == 2)
    {
        return true;
    }

    if(number % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i < number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    
    return true;

}

size_t MagicalContainer::size()
{
    return containerSize;
}

// ASCENDINGITERATOR FUNCTIONS

MagicalContainer::AscendingIterator::AscendingIterator()
    : index(0), mContain(nullptr)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : index(0), mContain(&container)
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : index(other.index), mContain(other.mContain)
{
}

MagicalContainer::AscendingIterator::~AscendingIterator()
{
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Not Good");
    }
    else
    {
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return (mContain == other.mContain) && (index == other.index);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index < other.index;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return mContain->container[index];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if(index == mContain->size())
    {
        throw std::runtime_error("Can't go higher");    
    }
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*mContain);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator endIter(*mContain);
    endIter.index = mContain->size();
    return endIter;
}

// SIDECROSSITERATOR FUNCTIONS

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : index(0), mContain(nullptr)
{
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &other)
    : index(0), mContain(&other) , timesAdded(0)
{
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : index(other.index), mContain(other.mContain)
{
}

MagicalContainer::SideCrossIterator::~SideCrossIterator()
{
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Not Good");
    }
    else
    {
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return (mContain == other.mContain) && (index == other.index);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index < other.index;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return mContain->container[index];
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (index == mContain->size())
    {
        throw std::runtime_error("You are in the last element");
    }
    if (index == (mContain->containerSize / 2))
    {
        index = mContain->containerSize;
        return *this;
    }

    if (index < (mContain->containerSize / 2))
    {
        index = mContain->containerSize - index - 1;
        return *this;
    }

    else if (index > (mContain->containerSize / 2))
    {
        index = mContain->containerSize - index;
        return *this;
    }


    return *this;
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    index = 0;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(*mContain);
    iter.index = mContain->containerSize;
    return iter;
}


// PRIMEITERATOR FUNCTIONS

MagicalContainer::PrimeIterator::PrimeIterator()
    : index(0), mContain(nullptr)
{
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other)
    : index(0), mContain(&other)
{
}

MagicalContainer::PrimeIterator::~PrimeIterator()
{
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Not Good");
    }
    else
    {
        index = other.index;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return (mContain == other.mContain) && (index == other.index);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if (mContain != other.mContain)
    {
        throw std::runtime_error("Invalid comparison");
    }
    return index < other.index;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return *mContain->pointersToPrime[index];
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if(index >= mContain->pointersToPrime.size())
    {
        throw std::runtime_error("End Of Primes");
    }
    index++;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    PrimeIterator beginIter(*mContain);
    beginIter.index = 0;
    return beginIter;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator endIter(*mContain);
    endIter.index = mContain->pointersToPrime.size();
    return endIter;
}
