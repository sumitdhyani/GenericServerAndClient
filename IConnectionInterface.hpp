#pragma once
#include <functional>
#include <string>

namespace ULCommunicationFramework
{
	enum class ConnectionEvent
	{
		Started,
		Stopped,
		Killed,
		Resumed,
		Reset,
		Error
	};


	template <class MsgObjType, class ExceptionType>
	struct IMsgPropagator
	{
		virtual void send(MsgObjType, std::function<void(const ExceptionType&)>) = 0;
	};

	template <class RecMsgObjType, class SendMsgObjType, class ExceptionType>
	struct IConnection : IMsgPropagator<SendMsgObjType, ExceptionType>
	{
		virtual void receive(std::function<void(RecMsgObjType)>, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void kill(std::function<void(const ExceptionType&)>) = 0;

		virtual std::string desc() = 0;

		virtual ~IConnection() {}
	};
}