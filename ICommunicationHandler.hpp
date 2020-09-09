#pragma once
#include <vector>
#include "IConnectionInterface.hpp"

namespace ULCommunicationFramework
{
	struct IServerActivityListener
	{
		virtual void start() = 0;

		virtual ~IServerActivityListener() {}
	};

	using IClientActivityListener = IServerActivityListener;



	template <class MsgIdType, class SendMsgObjType, class RecMsgObjType, class ExceptionType>
	struct IActiveConnectionCommunicationHandler
	{
		virtual void start() = 0;

		virtual void kill(std::function<void(const ExceptionType&)>) = 0;

		virtual void send(SendMsgObjType, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForMessages(MsgIdType, std::function<void(const RecMsgObjType)>, size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void unRegisterForMessages(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual std::string desc() = 0;

		virtual ~IActiveConnectionCommunicationHandler() {}
	};

	template <class RecMsgObjType, class SendMsgObjType, class ExceptionType>
	struct IPassiveConnectionCommunicationHandler
	{
		virtual void kill() = 0;

		virtual void send(SendMsgObjType, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void receive(std::function<void(RecMsgObjType)>, std::function<void(const ExceptionType&)>) = 0;

		virtual ~IPassiveConnectionCommunicationHandler() {}
	};
}
