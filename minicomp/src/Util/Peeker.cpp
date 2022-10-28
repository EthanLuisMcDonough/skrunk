#include "Peeker.h"
#include <string_view>

using namespace Util;
using std::function, std::optional, std::input_iterator, std::nullopt, 
       std::make_optional, std::size_t;

template <input_iterator T>
Peeker<T>::Peeker(T i, T e) : iter(i), end(e), index(0), next(nullopt) {
    value = (iter != end) ? make_optional(*iter) : nullopt;
}

template <input_iterator T>
const std::optional<typename T::value_type>& Peeker<T>::current() const {
    return value;
}

template <input_iterator T>
const std::optional<typename T::value_type>& Peeker<T>::peek() {
    if (!next.has_value() && iter != end && ++iter != end) {
        next = *iter;
    }
    return next;
}

template <input_iterator T>
bool Peeker<T>::has_value() const {
    return value.has_value();
}

template <input_iterator T>
bool Peeker<T>::has_next() const {
    return next.has_value() || iter != end;
}

template <input_iterator T>
const optional<typename T::value_type>& Peeker<T>::advance() {
    if (next) {
        value.swap(next);
    } else if (iter != end && ++iter != end) {
        value = { *iter };
    } else {
        value = nullopt;
    }
    next = nullopt;

    if (has_value()) {
        index++;
    }

    return current();
}

template <input_iterator T>
size_t Peeker<T>::get_index() const {
    return index;
}

template <input_iterator T>
const optional<typename T::value_type>& Peeker<T>::next_if(function<bool(const typename T::value_type&)> predicate) {
    if (auto next = peek()) {
        if (predicate(*next)) {
            return advance();
        }
    }
    return nullopt;
}

template <input_iterator T>
void Peeker<T>::skip_while(function<bool(const typename T::value_type&)> predicate) {
    while (has_value() && predicate(*current())) {
        advance();
    }
}

template class Peeker<std::string_view::iterator>;