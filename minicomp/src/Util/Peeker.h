#pragma once

#include <iterator>
#include <functional>
#include <optional>
#include <cstddef>

namespace Util {
    template <std::input_iterator T>
    class Peeker {
        T iter;
        T end;

        std::size_t index;

        std::optional<typename T::value_type> next;
        std::optional<typename T::value_type> value;
    public:
        Peeker(T, T);

        const std::optional<typename T::value_type>& current() const;
        const std::optional<typename T::value_type>& peek();

        bool has_value() const;
        bool has_next() const;

        virtual const std::optional<typename T::value_type>& advance();

        std::size_t get_index() const;

        const std::optional<typename T::value_type>& next_if(std::function<bool(const typename T::value_type&)>);
        void skip_while(std::function<bool(const typename T::value_type&)>);
    };
}