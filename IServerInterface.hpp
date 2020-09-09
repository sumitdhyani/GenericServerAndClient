#pragma once
#include <string>
#include <functional>
#include <CommonUtils/CommonDefs.hpp>
#include "IConnectionInterface.hpp"
#include "ICommunicationHandler.hpp"

namespace ULCommunicationFramework
{
	template <class MsgIdType, class SendMsgObjType, class RecMsgObjType, class ConnectionHandleType, class ConnectionIDType, class ExceptionType>
	struct IServerInterface
	{
		typedef std::function<void(ConnectionIDType, ConnectionHandleType)> NewConnectionCallback;

		virtual void start() = 0;

		virtual void registerForNewConnections(size_t, NewConnectionCallback, std::function<void(const ExceptionType&)>) = 0;

		virtual void unregisterForNewConnections(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual ~IServerInterface() {}
	};
}