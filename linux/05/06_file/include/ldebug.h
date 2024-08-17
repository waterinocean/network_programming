#ifndef DEBUG_H
#define DEBUG_H

#ifndef NDEBUG
#define DBGprint(...) printf("%s[%d] - %s:", __FILE__, __LINE__, __FUNCTION__); printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

#endif
