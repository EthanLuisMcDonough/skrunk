export module Peeker;

import <iterator>;
import <functional>;
import <optional>;

export namespace Util {
     template <std::input_iterator T>
     class Peeker {
        T iter;
        T end;

        std::size_t index;

        std::optional<typename T::value_type> next;
        std::optional<typename T::value_type> value;
    public:
        Peeker(T i, T e) : iter(i), end(e), index(0), next(std::nullopt) {
            value = (iter != end) ? std::make_optional(*iter) : std::nullopt;
        }

        const std::optional<typename T::value_type>& current() const {
            return value;
        }
        const std::optional<typename T::value_type>& peek() {
            if (!next.has_value() && iter != end && ++iter != end) {
                next = *iter;
            }
            return next;
        }

        bool has_value() const {
            return value.has_value();
        }
        bool has_next() const {
            return next.has_value() || iter != end;
        }

        virtual bool advance() {
            if (next) {
                value.swap(next);
            } else if (iter != end && ++iter != end) {
                value = { *iter };
            } else {
                value = std::nullopt;
            }
            next = std::nullopt;

            if (has_value()) {
                index++;
            }

            return has_value();
        }

        std::size_t get_index() const {
            return index;
        }

        bool next_if(std::function<bool(const typename T::value_type&)> predicate) {
            if (auto next = peek()) {
                return predicate(*next) && advance();
            }
            return false;
        }
    };
}