#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer ::sortElements()
{
}

void MagicalContainer::updatePrimeIterator() {}

void MagicalContainer::updateSideCrossIterator() {}

void MagicalContainer::updateAscendingIterator() {}

void MagicalContainer::updateAllIterators() {}

void MagicalContainer::sortAscending()
{
    for (unsigned int i = 0; i < this->container.size(); i++)
    {
        for (unsigned int j = 0; j < container.size() - i - 1; j++)
        {
            if (container[j] > container[j + 1])
            {
                swap(container[j], container[j + 1]);
            }
        }
    }
}

bool MagicalContainer::prime(int element)
{

    if (element <= 1)
    {
        return false;
    }
    else if (element == 2)
    {
        return true;
    }
    else if (element % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 3; i <= sqrt(element); i += 2)
        {
            if (element % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void MagicalContainer::addElement(int element)
{
    this->container.push_back(element);
}

void MagicalContainer::removeElement(int element) {}

//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------AscendingIterator--------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------Constructors and Destructors-------------------------------------------------------//

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index) : container(container), index(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), index(other.index) {}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept : container(other.container), index(other.index) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return 0;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int)
{
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------SideCrossIterator--------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------Constructors and Destructors-------------------------------------------------------//

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index) : container(container), index(index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept : container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return 0;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int)
{
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return this->index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------PrimeIterator------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------Constructors and Destructors-------------------------------------------------------//

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index) : container(container), index(index) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept : container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return 0;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int)
{
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
{
    if (this != &other)
    {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}

//------------------------------------------------------------------------------------------------------------------------------------------//
