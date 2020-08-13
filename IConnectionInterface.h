#pragma once
#include <functional>
#include <string>

enum ConnectionEvent
{
	Started,
	Stopped,
	Killed,
	Resumed,
	Reset,
	Error
};

template <class RecMsgObjType, class SendMsgObjType>
struct IActiveConnection
{
	virtual size_t registerAsListener(std::function<void(std::string)> msgCallback, std::function<void(size_t)> listenerIdCallback) = 0;

	virtual size_t unregisterAsListener(size_t listenerId) = 0;

	virtual void send(SendMsgObjType, std::function<void(bool)>) = 0;

	virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, std::function<void(size_t)>) = 0;

	virtual void unregisterForConnectionEvents(size_t) = 0;

	virtual void kill(std::function<void(bool, std::string)>) = 0;

	virtual ~IActiveConnection() {}
};

template <class RecMsgObjType, class SendMsgObjType>
struct IPassiveConnection
{
	virtual RecMsgObjType receive() = 0;

	virtual void send(SendMsgObjType, std::function<void(bool)>) = 0;

	virtual void kill(std::function<void(bool, std::string)>) = 0;

	virtual ~IPassiveConnection() {}
};
