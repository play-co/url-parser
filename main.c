#include <stdio.h>
#include <string.h>

#include "url_parser.h"

int main() {

    char buf[1024];

    struct http_parser_url parse_info;
    const char *url = "ws://debug.example.com:123/my/path";

    http_parser_parse_url(url, strlen(url), 0, &parse_info);

#define PRINT(field) \
    do { \
        snprintf(buf, parse_info.field_data[field].len + 1, "%s", \
                &url[parse_info.field_data[field].off]); \
        printf( #field ": %s\n", buf); \
    } while (0)

    printf("port: %d\n", parse_info.port);

    PRINT(UF_SCHEMA);
    PRINT(UF_HOST);
    PRINT(UF_PORT);
    PRINT(UF_PATH);

    return 0;
}
