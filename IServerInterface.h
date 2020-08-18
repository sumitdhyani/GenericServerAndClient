#pragma once
#include <string>
#include <functional>
#include "IConnectionInterface.h"

namespace ULCommunicationFramework
{
	template <class RecMsgObjType, class SendMsgObjType>
	struct IActiveConnectionServerInterface
	{
		virtual void start() = 0;

		virtual void registerForNewConnections(std::function<void(IActiveConnection<RecMsgObjType, SendMsgObjType>)>, std::function<void(size_t)>) = 0;

		virtual void unregisterForNewConnections(size_t, std::function<void(bool, std::string)>) = 0;

		virtual ~IActiveConnectionServerInterface() {}
	};


	template <class RecMsgObjType, class SendMsgObjType>
	struct IPassiveConnectionServerInterface
	{
		virtual void start() = 0;

		virtual void registerForNewConnections(std::function<void(IPassiveConnection<RecMsgObjType, SendMsgObjType>)>, std::function<void(size_t)>) = 0;

		virtual void unregisterForNewConnections(size_t, std::function<void(bool, std::string)>) = 0;

		virtual ~IPassiveConnectionServerInterface() {}
	};
}