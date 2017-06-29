#ifndef LOG_H
#define LOG_H

#include <cstdio>
#include <tuple>
#include <SDL2/SDL.h>

// implementation details, users never invoke these directly
namespace detail {
    template <typename F, typename Tuple, bool Done, int Total, int... N>
    struct call_impl {
        static void call(F f, Tuple && t) {
            call_impl<F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t));
        }
    };

    template <typename F, typename Tuple, int Total, int... N>
    struct call_impl<F, Tuple, true, Total, N...> {
        static void call(F f, Tuple && t) {
            f(std::get<N>(std::forward<Tuple>(t))...);
        }
    };
}

class Log {
public:
    enum LogLevel { ERROR, WARNING, DEBUG, INFO };
    static void setLogLevel(LogLevel logLevel) { _logLevel = logLevel; }

    template<class ...Ts>
    static void print(LogLevel logLevel, Ts ...ts) {
        if (logLevel <= _logLevel) {
            std::printf("[%8.3f] ", SDL_GetTicks() / 1000.);
            call(std::printf, std::make_tuple(ts...));
            std::printf("\n");
        }
    }

private:
    static LogLevel _logLevel;
    static bool _callInCycle;

    template <typename F, typename Tuple>
    static void call(F f, Tuple && t);
};

template <typename F, typename Tuple>
void Log::call(F f, Tuple && t)
{
    typedef typename std::decay<Tuple>::type ttype;
    detail::call_impl<F, Tuple, 0 == std::tuple_size<ttype>::value, std::tuple_size<ttype>::value>::call(f, std::forward<Tuple>(t));
}

#endif
