#pragma once

#include <vector>
#include <cmath>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> container = {};

    public:
        //---------------------------------------Constructors---------------------------------------//
        MagicalContainer();
        ~MagicalContainer();

        //-------------------------------------------Methods----------------------------------------//
        void addElement(int element);
        void removeElement(int element);
        size_t size() const { return container.size(); };
        void sortElements();
        void updatePrimeIterator();
        void updateSideCrossIterator();
        void updateAscendingIterator();
        void updateAllIterators();
        void sortAscending();
        bool prime(int element);

        //------------------------------------------------------------------------------------------//
        //-------------------------------------------Classes----------------------------------------//
        //------------------------------------------------------------------------------------------//
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            AscendingIterator(MagicalContainer &container, size_t index);

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept;
            ~AscendingIterator();
            //-------------------------------------Operators----------------------------------------//
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();
            AscendingIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            AscendingIterator begin() { return AscendingIterator(container, 0); }
            AscendingIterator end() { return AscendingIterator(container, container.size()); }
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            SideCrossIterator(MagicalContainer &container, size_t index);

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(SideCrossIterator &&other) noexcept;
            ~SideCrossIterator();
            //-------------------------------------Operators----------------------------------------//
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();
            SideCrossIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            SideCrossIterator begin() { return SideCrossIterator(container, 0); }
            SideCrossIterator end() { return SideCrossIterator(container, container.size()); }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index;
            PrimeIterator(MagicalContainer &container, size_t index);

        public:
            //-----------------------------Constructors and Destructors-----------------------------//
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(PrimeIterator &&other) noexcept;
            ~PrimeIterator();
            //-------------------------------------Operators----------------------------------------//
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();
            PrimeIterator operator++(int);
            //-------------------------------------------Methods------------------------------------//
            PrimeIterator begin() { return PrimeIterator(container, 0); }
            PrimeIterator end() { return PrimeIterator(container, container.size()); }
        };
    };
};
