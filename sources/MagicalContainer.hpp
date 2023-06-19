#pragma once

#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdexcept>
#include <list>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> container = {};
        vector<int*> primeContainer = {};
        vector<int*> sideCrossContainer = {};
        vector<int*> ascendingContainer = {};

    public:
        //-------------------------------------------Methods----------------------------------------//
        void addElement(int element);
        void removeElement(int element);
        size_t size() const { return container.size(); };
        void updatePrimeIterator();
        void updateSideCrossIterator();
        void updateAscendingIterator();
        void updateAllIterators();
        void sortContainer();
        bool prime(int element);

        //------------------------------------------------------------------------------------------//
        //-------------------------------------------Classes----------------------------------------//
        //------------------------------------------------------------------------------------------//
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            vector<int*>::iterator i;

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept = default;
            ~AscendingIterator() = default;
            //-------------------------------------Operators----------------------------------------//
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept { return *this; };
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();
            AscendingIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            vector<int*>::iterator i;

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            ~SideCrossIterator() = default;
            //-------------------------------------Operators----------------------------------------//
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept { return *this; };
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();
            SideCrossIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            vector<int*>::iterator i;

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(PrimeIterator &&other) noexcept = default;
            ~PrimeIterator() = default;
            //-------------------------------------Operators----------------------------------------//
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator=(PrimeIterator &&other) noexcept { return *this; };
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();
            PrimeIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            PrimeIterator &begin();
            PrimeIterator &end();
        };
    };
};
