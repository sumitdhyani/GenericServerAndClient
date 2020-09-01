#pragma once
#include <string>
#include <functional>
#include <CommonUtils/CommonDefs.hpp>
#include "IConnectionInterface.hpp"
#include "ICommunicationHandler.hpp"

namespace ULCommunicationFramework
{
	template <class MsgIdType, class RawMsgType, class RecMsgObjType, class ExceptionType>
	struct IServerInterface
	{
		typedef IActiveConnectionCommunicationHandler<MsgIdType, RawMsgType, RecMsgObjType, ExceptionType> IActiveConnectionCommunicationHandler;
		DEFINE_UNIQUE_PTR(IActiveConnectionCommunicationHandler)
		typedef std::function<void(IActiveConnectionCommunicationHandler_UPtr)> NewConnectionCallback;

		virtual void start() = 0;

		virtual void registerForNewConnections(NewConnectionCallback, std::function<void(size_t)>) = 0;

		virtual void unregisterForNewConnections(size_t) = 0;

		virtual ~IServerInterface() {}
	};
}