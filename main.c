#include <stdio.h>
#include <string.h>

#include "url_parser.h"

int main() {

    struct http_parser_url parse_info;
    const char *url = "ws://debug.example.com:123/my/path";

    http_parser_parse_url(url, strlen(url), 0, &parse_info);

#define PRINT(field) \
    do { \
        printf( #field ": %*s\n", parse_info.field_data[field].len, \
                &url[parse_info.field_data[field].off]);            \
    } while (0)

    printf("port: %d\n", parse_info.port);

    PRINT(UF_SCHEMA);
    PRINT(UF_HOST);
    PRINT(UF_PORT);
    PRINT(UF_PATH);

    return 0;
}
