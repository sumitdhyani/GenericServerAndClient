#include "IClientInterface.h"
#include "ISocket.h"
#include "SocketCommon.h"
#include "SocketOSDependent.h"
#include <MTTools/WorkerThread.h>

namespace mtUTls = ULMTTools;

namespace ULSocketUtils
{
	class BlockingSocket : IBlockingLock
	{
		int m_filehandle;
		size_t m_maxReadSize;
		size_t m_maxWriteSize;
		bool m_socketClosed;

	public:
		BlockingSocket(int filehandle, size_t maxReadSize, size_t maxWriteSize) :
			m_filehandle(filehandle),
			m_maxReadSize(maxReadSize),
			m_maxWriteSize(maxWriteSize),
			m_socketClosed(false)
		{
		}

		virtual void read(size_t numBytes, BYTE* out)
		{
			if (numBytes > m_maxReadSize)
				throw SocketBufferSizeBreachedException(m_maxReadSize, numBytes, true);

			int numRead = ::read(m_filehandle, out, numBytes);
			if (0 > numRead)
				throw TimeoutException();
		}

		virtual void write(const BYTE* data, size_t len)
		{
			

			if (len > m_maxWriteSize)
				throw SocketBufferSizeBreachedException(m_maxWriteSize, len, false);

			int numWritten = ::write(m_filehandle, data, len);
			if (0 >= numWritten)
				throw SocketClosedException();
		}

		virtual void close()
		{
			::closesocket(m_filehandle);
			m_socketClosed = true;
		}

		~BlockingSocket()
		{
			if (!m_socketClosed)
				close();
		}
	};

	class NonBlockingSocket : INonBlockingSocket
	{
		int m_filehandle;
		BYTE* m_readBuffer;
		size_t m_readHead;
		size_t m_maxReadSize;
		size_t m_maxWriteSize;
		bool m_socketClosed;
	public:
		NonBlockingSocket(int filehandle, size_t maxReadSize, size_t maxWriteSize) :
			m_filehandle(filehandle),
			m_maxReadSize(maxReadSize),
			m_maxWriteSize(maxWriteSize),
			m_socketClosed(false)
		{
			m_readBuffer = new BYTE[maxReadSize];
			m_readHead = 0;
		}

		virtual void read(size_t numBytes, BYTE* out)
		{
			int numRead = ::read(m_filehandle, m_readBuffer + m_readHead, numBytes - m_readHead);
			if (numBytes > m_maxReadSize)
				throw SocketBufferSizeBreachedException(m_maxReadSize, numBytes, true);
			else if (-1 == numRead)
				throw SocketEmptyException();
			else if (0 == numRead)
				throw SocketClosedException();
			else if (m_readHead < numBytes)
				throw PartialReadException();
			else
			{
				memcpy(out, m_readBuffer, numBytes);
				m_readHead = 0;
			}
		}

		virtual void write(const BYTE* data, size_t len)
		{
			
			if (len > m_maxWriteSize)
				throw SocketBufferSizeBreachedException(m_maxWriteSize, len, false);

			int numWritten = ::write(m_filehandle, data, len);
			if (0 == numWritten)
				throw SocketClosedException();
			else if(0 > numWritten)
				throw SocketEmptyException();
			else if (numWritten < len)
				throw PartialWriteException();
		}

		~NonBlockingSocket()
		{
			if (!m_socketClosed)
				close();
			delete[] m_readBuffer;
		}
	};


	
	/*class ThreadSafeNonBlockingSocket : INonBlockingSocket
	{
		std::unique_ptr<INonBlockingSocket> m_nonBlockingSocket;
		mtUTls::WorkerThread_SPtr m_worker;
	public:
		ThreadSafeNonBlockingSocket(INonBlockingSocket_UPtr nonBlockingSocket, mtUTls::WorkerThread_SPtr worker) :
			m_nonBlockingSocket(std::move(nonBlockingSocket)),
			m_worker(worker)
		{
		}

		virtual void read(size_t numBytes, BYTE* out)
		{
			m_worker->push([this, numBytes, out]() {m_nonBlockingSocket->read(numBytes, out); });
		}

		virtual void write(const BYTE* data, size_t len)
		{
			m_worker->push([this, data, len]() {m_nonBlockingSocket->write(data, len);});
		}
	};*/
}