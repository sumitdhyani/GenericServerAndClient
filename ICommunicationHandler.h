#pragma once
#include <string>
#include "IConnectionInterface.h"

struct IServerActivityListener
{
	virtual void start() = 0;

	virtual ~IServerActivityListener() {}
};

using IClientActivityListener = IServerActivityListener;



template <class RecMsgObjType, class SendMsgObjType>
struct IActiveConnectionCommunicationHandler
{
	virtual void start() = 0;

	virtual void pause() = 0;

	virtual void resume() = 0;

	virtual void kill() = 0;

	virtual void reset(IActiveConnection<RecMsgObjType, SendMsgObjType>) = 0;

	virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, std::function<void(size_t)>) = 0;

	virtual void unregisterForConnectionEvents(size_t, std::function<void(bool, std::string)>) = 0;

	virtual ~IActiveConnectionCommunicationHandler() {}
};

template <class RecMsgObjType, class SendMsgObjType >
struct IPassiveConnectionCommunicationHandler
{
	virtual void start() = 0;

	virtual void pause() = 0;

	virtual void resume() = 0;

	virtual void kill() = 0;

	virtual void reset(IPassiveConnection<RecMsgObjType, SendMsgObjType>) = 0;

	virtual void registerForConnectionEvents(std::function<void(ConnectionEvent, std::string)>, std::function<void(size_t)>) = 0;

	virtual void unregisterForConnectionEvents(size_t, std::function<void(bool, std::string)>) = 0;

	virtual ~IPassiveConnectionCommunicationHandler() {}
};

