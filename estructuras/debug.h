/**
  @file debug.h
  @brief Macro por DEBUG 

  Macro para contar con una suite de DEBUG

  @author Erik Navarro
  @date 02/2013

*/

#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <errno.h>
#include <string.>

#ifndef DEBUG
 #define DEBUG 1
#endif

#define DEBUG_NON   -1
#define DEBUG_ERROR 0
#define DEBUG_WARN  1
#define DEBUG_INFO  2
#define DEBUG_LOG   3

#define debug_print(type, fmt, line,...) \
    fprintf(stderr, "[%s] %s:%d %s(): " fmt "\n",type, __FILE__,line,__FUNCTION__,##__VA_ARGS__)

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(fmt, ...) \
	if(DEBUG >= DEBUG_ERROR) { fprintf(stderr, "[%s] %s:%d %s() [errno: %s]: " fmt "\n","ERROR", __FILE__,__LINE__,__FUNCTION__,clean_errno(),##__VA_ARGS__); }

#define log_warn(fmt, ...) \
	if(DEBUG >= DEBUG_WARN) { debug_print("WARN",fmt,__LINE__,##__VA_ARGS__); }

#define log_info(fmt, ...) \
	if(DEBUG >= DEBUG_INFO) { debug_print("INFO",fmt,__LINE__,##__VA_ARGS__); }

#define log_debug(fmt, ...) \
	if(DEBUG >= DEBUG_LOG) { debug_print("DEBUG",fmt,__LINE__,##__VA_ARGS__); }


#endif
