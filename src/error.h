#ifndef ERROR_H
#define ERROR_H

typedef enum error_t {
  /* Memory handling errors */
  PEZP_MEMORY_MALLOC_ERROR  = 0x00,
  PEZP_MEMORY_REALLOC_ERROR = 0x01,
  PEZP_MEMORY_CALLOC_ERROR  = 0x02,
  /*  */
  PEZP_SUCCESS
} error_t;

#endif