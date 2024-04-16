#include "Pair.h"

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 &f, const T2 &s) : first(f), second(s) {}

template <typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const
{
    return first;
}

template <typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const
{
    return second;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair &other) const
{
    return second < other.second;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair &other) const
{
    return second > other.second;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<=(const Pair &other) const
{
    return second <= other.second;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>=(const Pair &other) const
{
    return second >= other.second;
}

template class Pair<int, int>;
