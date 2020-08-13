#pragma once

#if defined(WIN32)
#include<winsock2.h>
#include<process.h>
#include<io.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/timeb.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

