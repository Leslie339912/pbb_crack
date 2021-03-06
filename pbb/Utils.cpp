#include "stdafx.h"
#include "Utils.h"
#include <boost/make_shared.hpp>

pvKey utils::str2key(const char *str)
{
    pvKey key = boost::make_shared<vKey>();

    char buf[3] = { 0 };
    for ( int i = 0; i < 16; i++ ) {
        memcpy(buf, &str[i * 2], 2);

        key->v[i] = (unsigned char)strtol(buf, 0, 16);
    }

    return key;
}

void utils::output(const unsigned char *mem, std::size_t size)
{
    for ( std::size_t i = 0; i < size; i++ ) {
        printf("%.2x ", mem[i]);

        if ( ( i + 1 ) % 0x10 == 0 ) printf("\r\n");
    }

    if ( size % 0x10 != 0 ) {
        printf("\r\n");
    }
}