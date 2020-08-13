#pragma once
#include <functional>

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
	virtual size_t registerAsListener(std::function<void(RecMsgObjType)>) = 0;

	virtual void send(SendMsgObjType, std::function<void(bool)>) = 0;

	virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, std::function<void(size_t)>) = 0;

	virtual void unregisterForConnectionEvents(size_t, std::function<void(bool, std::string)>) = 0;

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
