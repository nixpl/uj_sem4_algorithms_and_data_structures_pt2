#pragma once

template <typename T1, typename T2>
class Pair
{
private:
    T1 first;
    T2 second;

public:
    Pair(const T1 &f, const T2 &s);

    T1 getFirst() const;
    T2 getSecond() const;

    bool operator<(const Pair &other) const;

    bool operator>(const Pair &other) const;

    bool operator<=(const Pair &other) const;

    bool operator>=(const Pair &other) const;
};