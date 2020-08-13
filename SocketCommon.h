#pragma once
#include <stdexcept>
#include <string>
namespace ULSocketUtils
{
	const std::string DATA_NOT_AVAILABLE_ERROR("Trying to read on socket with no data");
	const std::string PARTIAL_READ_ERROR("Socket, available less than asked");
	const std::string PARTIAL_WRITE_ERROR("Partial write due to full buffer at the moment");
	const std::string READ_UNAVAILABLE_ERROR("Trying to read on socket with no data");
	const std::string INVALID_RW_ERROR("Trying to read/write on closed socket");
	const std::string TIMEOUT_EXCEPTION("Timed out reading on blocking socket");

	struct SocketException : std::runtime_error
	{
		SocketException(const std::string& msg) : std::runtime_error(msg)
		{
		}
	};

	struct SocketClosedException : SocketException
	{
		SocketClosedException() : SocketException(INVALID_RW_ERROR)
		{
		}
	};

	struct SocketBufferSizeBreachedException : SocketException
	{
		SocketBufferSizeBreachedException(size_t allowedSize, size_t attemptedSize, bool isRead)
			: SocketException(std::string("Socket limit breached while trying to") + (isRead? "read" : "write") + " on socket, attempted: " + std::to_string(attemptedSize) + ", allowed: " + std::to_string(allowedSize))
		{
		}
	};


	struct BlockingSocketException : SocketException
	{
		BlockingSocketException(const std::string& msg) : SocketException(msg)
		{
		}
	};

	struct TimeoutException : BlockingSocketException
	{
		TimeoutException() : BlockingSocketException(TIMEOUT_EXCEPTION)
		{
		}
	};

	struct NonBlockingSocketException : SocketException
	{
		NonBlockingSocketException(const std::string& msg) : SocketException(msg)
		{
		}
	};

	struct SocketEmptyException : NonBlockingSocketException
	{
		SocketEmptyException() : NonBlockingSocketException(DATA_NOT_AVAILABLE_ERROR)
		{
		}
	};

	struct PartialReadException : NonBlockingSocketException
	{
		PartialReadException() : NonBlockingSocketException(DATA_NOT_AVAILABLE_ERROR)
		{
		}
	};

	struct PartialWriteException : NonBlockingSocketException
	{
		PartialWriteException() : NonBlockingSocketException(DATA_NOT_AVAILABLE_ERROR)
		{
		}
	};
}