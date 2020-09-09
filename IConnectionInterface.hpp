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


	template <class RecMsgObjType, class SendMsgObjType, class ExceptionType>
	struct IConnection
	{
		virtual void receive(std::function<void(RecMsgObjType)>, std::function<void(const ExceptionType&)>) = 0;

		virtual void send(SendMsgObjType, std::function<void(const ExceptionType&)>) = 0;

		virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void unregisterForConnectionEvents(size_t, std::function<void(const ExceptionType&)>) = 0;

		virtual void kill(std::function<void(const ExceptionType&)>) = 0;

		virtual std::string desc() = 0;

		virtual ~IConnection() {}
	};
}