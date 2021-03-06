#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <unistd.h>

typedef struct {
  char key[32];
  char value[256];
} http_header_t;

typedef struct {
  char* request_line;
  http_header_t* headers[32];
  char* body;
  int body_length;
  int header_count;
} http_request_t;

time_t http_request_if_modified_since(http_request_t* request);
int http_request_connection_close(http_request_t* request);
void http_request_free(http_request_t* request);

#endif
