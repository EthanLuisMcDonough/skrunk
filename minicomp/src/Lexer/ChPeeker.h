#pragma once

#include <string_view>
#include <functional>
#include <optional>
#include "Peeker.h"
#include "Location.h"

namespace Lexer {
    class ChPeeker : public Util::Peeker<std::string_view::iterator> {
        Location loc;
        std::string_view str;

    public:
        ChPeeker(std::string_view);

        virtual const std::optional<char>& advance();

        Location get_start() const;
        Location get_end() const;

        std::string_view take_while(std::function<bool(char)>);

        const std::optional<char>& next_eq(char);
        const std::optional<char>& next_any(const char*);
    };
}