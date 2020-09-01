#pragma once
#include <vector>
#include "IMessage.hpp"
#include "IConnectionInterface.hpp"

namespace ULCommunicationFramework
{
	struct IServerActivityListener
	{
		virtual void start() = 0;

		virtual ~IServerActivityListener() {}
	};

	using IClientActivityListener = IServerActivityListener;



	template <class MsgIdType, class RawMsgType, class RecMsgObjType, class ExceptionType>
	struct IActiveConnectionCommunicationHandler
	{
		typedef IMessage<RawMsgType, ExceptionType> IMessage;
		DEFINE_UNIQUE_PTR(IMessage)
		DEFINE_UNIQUE_PTR(RecMsgObjType)

		virtual void start() = 0;

		virtual void kill(std::function<void(ExceptionType&)>) = 0;

		virtual void send(IMessage_UPtr, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForMessages(MsgIdType, std::function<void(RecMsgObjType_UPtr)>, size_t, std::function<void(ExceptionType&)>) = 0;

		virtual void unRegisterForMessages(size_t, std::function<void(ExceptionType&)>) = 0;

		virtual ~IActiveConnectionCommunicationHandler() {}
	};

	template <class RecMsgObjType, class SendMsgObjType, class ExceptionType>
	struct IPassiveConnectionCommunicationHandler
	{
		typedef IMessage<RecMsgObjType, ExceptionType> IMessage;
		DEFINE_UNIQUE_PTR(IMessage)

		virtual void kill() = 0;

		virtual void send(IMessage_UPtr, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void receive(std::function<void(RecMsgObjType)>, std::function<void(const ExceptionType&)>) = 0;

		virtual ~IPassiveConnectionCommunicationHandler() {}
	};
}
