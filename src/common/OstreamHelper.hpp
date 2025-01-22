/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** OstreamHelper.hpp
*/

#ifndef OSTREAMHELPER_HPP
#define OSTREAMHELPER_HPP

#include <vector>
#include <ostream>
#include <map>
#include <unordered_map>
#include <list>
#include <deque>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <memory>

#include <SFML/Graphics.hpp>

template<typename T>
std::ostream &sequence_container(std::ostream &os, const std::string_view &name, const T &type)
{
    os << name << "(";
    size_t i = 0;
    size_t size = std::distance(std::begin(type), std::end(type)) - 1;
    for (auto &it : type) {
        if (i == size) {
            os << it;
        } else {
            os << it << ", ";
        }
        i++;
    }
    os << ")";
    return os;
}

// sequence_container
template<typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &array)
{
    return sequence_container(os, "std::array", array);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector)
{
    return sequence_container(os, "std::vector", vector);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::deque<T> &deque)
{
    return sequence_container(os, "std::deque", deque);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::forward_list<T> &forward_list)
{
    return sequence_container(os, "std::forward_list", forward_list);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &list)
{
    return sequence_container(os, "std::list", list);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &set)
{
    return sequence_container(os, "std::set", set);
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::set<T, U> &set)
{
    return sequence_container(os, "std::set", set);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &unordered_set)
{
    return sequence_container(os, "std::unordered_set", unordered_set);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &multiset)
{
    return sequence_container(os, "std::multiset", multiset);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &unordered_multiset)
{
    return sequence_container(os, "std::unordered_multiset", unordered_multiset);
}


template<typename T>
std::ostream &associative_container(std::ostream &os, const std::string_view &name, const T &type)
{
    os << name << "{";
    size_t i = 0;
    for (auto &it : type) {
        if (i == type.size() - 1) {
            os << it.first << ": " << it.second;
        } else {
            os << it.first << ": " << it.second << ", ";
        }
        i++;
    }
    os << "}";
    return os;
}

// associative_container
template<typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<K,V> &unordered_map)
{
    return associative_container(os, "std::unordered_map", unordered_map);
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V> &map) {
    return associative_container(os, "std::map", map);
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::multimap<K,V> &multimap)
{
    return associative_container(os, "std::multimap", multimap);
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::unordered_multimap<K,V> &unordered_multimap)
{
    return associative_container(os, "std::unordered_multimap", unordered_multimap);
}

template<typename T>
std::ostream &container_adaptors_stack(std::ostream &os, const std::string_view &name, const T &type)
{
    os << name << "(";
    int i = 0;
    T tmp = type;
    while (!tmp.empty()) {
        os << tmp.top();
        tmp.pop();
        if (!tmp.empty())
            os << ", ";
    }
    os << ")";
    return os;
}

template<typename T>
std::ostream &container_adaptors_queue(std::ostream &os, const std::string_view &name, const T &type)
{
    os << name << "(";
    T tmp = type;
    while (!tmp.empty()) {
        os << tmp.front();
        tmp.pop();
        if (!tmp.empty())
            os << ", ";
    }
    os << ")";
    return os;
}

// container adaptors
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::stack<T> &stack)
{
    return container_adaptors_stack(os, "std::stack", stack);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::queue<T> &queue)
{
    return container_adaptors_queue(os, "std::queue", queue);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::priority_queue<T> &priority_queue)
{
    return container_adaptors_queue(os, "std::priority_queue", priority_queue);
}

template<typename T, typename U, typename F>
std::ostream &operator<<(std::ostream &os, const std::priority_queue<T, U, F> &priority_queue)
{
    return container_adaptors_queue(os, "std::priority_queue", priority_queue);
}


template <size_t Index, typename... Args>
void printTuple(std::ostream& os, const std::tuple<Args...>& t);

template <size_t Index, typename... Args>
void printTupleElement(std::ostream& os, const std::tuple<Args...>& t) {
    os << std::get<Index>(t);
}

template <size_t Index, typename... Args>
void printTupleHelper(std::ostream& os, const std::tuple<Args...>& t) {
    printTupleElement<Index>(os, t);
    if constexpr (Index +1 < sizeof...(Args)) {
        os << ", ";
        printTupleHelper<Index + 1>(os, t);
    }
}

template <typename... Args>
void printTupleHelper(std::ostream& os, const std::tuple<Args...>& t) {}

template <typename... Args>
void printTuple(std::ostream& os, const std::tuple<Args...>& t) {
    os << "std::tuple(";
    printTupleHelper<0>(os, t);
    os << ")";
}

template <typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
    printTuple(os, t);
    return os;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &v)
{
    os << "std::pair(" << v.first << ", " << v.second << ")";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::shared_ptr<T> &v)
{
    os << "std::shared_ptr(" << *v.get() << ")";
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::unique_ptr<T> &v)
{
    os << "std::unique_ptr(" << *v << ")";
    return os;
}

#endif //OSTREAMHELPER_HPP
