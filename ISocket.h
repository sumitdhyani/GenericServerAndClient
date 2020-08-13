#pragma once

#include <string>
#include <functional>
#include "SocketCommon.h"
#include <CommonUtils/CommonDefs.h>

namespace ULSocketUtils
{
	typedef char BYTE;

	struct IBlockingSocket
	{
		virtual void read(size_t numBytes, BYTE* out) = 0;

		virtual void write(const BYTE* data, size_t len) = 0;

		virtual ~IBlockingSocket() {}
	};
	DEFINE_UNIQUE_PTR(IBlockingSocket)


	struct INonBlockingSocket
	{
		virtual void read(size_t numBytes, BYTE* out) = 0;

		virtual void write(const BYTE* data, size_t len) = 0;

		virtual ~INonBlockingSocket() {}
	};
	DEFINE_UNIQUE_PTR(INonBlockingSocket)

}