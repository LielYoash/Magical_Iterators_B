#include "MagicalContainer.hpp"


using namespace std;
using namespace ariel;



void MagicalContainer::updatePrimeIterator()
{
    primeContainer.clear();
    for (auto iterator = this->container.begin(); iterator != this->container.end(); iterator++)
    {
        if (prime(*iterator))
        {
            this->primeContainer.push_back(&(*iterator));
        }
    }
}

void MagicalContainer::updateSideCrossIterator()
{
    sideCrossContainer.clear();
    auto beginning = this->container.begin();
    auto end = this->container.end();
    if (beginning == end)
    {
        sideCrossContainer.push_back(&(*beginning));
    }
    while (beginning < end)
    {
        sideCrossContainer.push_back(&(*beginning));
        sideCrossContainer.push_back(&(*end));
        beginning++;
        end--;
    }
}

void MagicalContainer::updateAscendingIterator()
{
    ascendingContainer.clear();
    for (auto iterator = this->container.begin(); iterator != this->container.end(); iterator++)
    {
        this->ascendingContainer.push_back(&(*iterator));
    }
}

void MagicalContainer::updateAllIterators()
{
    updatePrimeIterator();
    updateSideCrossIterator();
    updateAscendingIterator();
}

void MagicalContainer::sortContainer()
{
    for (unsigned int i = 0; i < container.size(); i++)
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

void MagicalContainer::removeElement(int element)
{
    for (auto iterator = this->container.begin(); iterator != this->container.end(); iterator++)
    {
        if (*iterator == element)
        {
            this->container.erase(iterator);
            updateAllIterators();
            return;
        }
    }
    throw runtime_error("Element not found");
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------AscendingIterator--------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------Constructors----------------------------------------------------------------//

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container), i(container.ascendingContainer.begin()), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), i(other.i), index(other.index) {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        throw runtime_error("Cannot assign iterator");
    }
    this->index = other.index;
    this->i = other.i;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->i == this->container.ascendingContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    ++this->index;
    ++this->i;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int)
{
    if (this->i == this->container.ascendingContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    AscendingIterator temp = *this;
    ++this->i;
    ++this->index;
    return temp;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    if (&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return *this != other;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    if (&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    if (&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index < other.index;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    if (i == this->container.ascendingContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    return **i;
}

MagicalContainer :: AscendingIterator &MagicalContainer::AscendingIterator::begin(){
    i = container.ascendingContainer.begin();
    index = 0;
    return *this;
}

MagicalContainer :: AscendingIterator &MagicalContainer::AscendingIterator::end(){
    i = container.ascendingContainer.end();
    index = container.ascendingContainer.size();
    return *this;
}



//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------SideCrossIterator--------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------Constructors and Destructors-------------------------------------------------------//

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), i(container.sideCrossContainer.begin()), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), i(other.i), index(other.index) {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        throw runtime_error("Cannot assign iterator");
    }
        this->index = other.index;
        this->i = other.i;
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if(this->i == this->container.sideCrossContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    this->i++;
    this->index++;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int)
{
    if(this->i == this->container.sideCrossContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    SideCrossIterator temp = *this;
    this->i++;
    this->index++;
    return temp;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return *this!= other;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index < other.index;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    if(i == this->container.sideCrossContainer.end())
    {
        throw out_of_range("Iterator out of bounds");
    }
    return **i;
}

MagicalContainer :: SideCrossIterator &MagicalContainer::SideCrossIterator::begin(){
    i = container.sideCrossContainer.begin();
    index = 0;
    return *this;
}

MagicalContainer :: SideCrossIterator &MagicalContainer::SideCrossIterator::end(){
    i = container.sideCrossContainer.end();
    index = container.sideCrossContainer.size();
    return *this;
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------PrimeIterator------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------Constructors and Destructors-------------------------------------------------------//

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),i(container.primeContainer.begin()) ,index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container),i(other.i) ,index(other.index) {}

//----------------------------------------------------------------Operators-----------------------------------------------------------------//
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        throw runtime_error("Cannot assign iterator");
    }
        this->index = other.index;
        this->i = other.i;
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if(this->i == this->container.primeContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    this->i++;
    this->index++;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int)
{
    if(this->i == this->container.primeContainer.end())
    {
        throw runtime_error("Iterator out of bounds");
    }
    PrimeIterator temp = *this;
    this->i++;
    this->index++;
    return temp;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return *this!= other;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw invalid_argument("Cannot compare iterators");
    }
    return this->index < other.index;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    if(i == this->container.primeContainer.end())
    {
        throw out_of_range("Iterator out of bounds");
    }
    return **i;
}

MagicalContainer :: PrimeIterator &MagicalContainer::PrimeIterator::begin(){
    i = container.primeContainer.begin();
    index = 0;
    return *this;
}

MagicalContainer :: PrimeIterator &MagicalContainer::PrimeIterator::end(){
    i = container.primeContainer.end();
    index = container.primeContainer.size();
    return *this;
}

//------------------------------------------------------------------------------------------------------------------------------------------//
