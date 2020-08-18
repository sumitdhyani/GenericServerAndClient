#pragma once
#include "IConnectionInterface.h"

template<class RawMsgType>
struct IMessage
{
	virtual void send(RawMsgType, IMsgPropagator<RawMsgType>) = 0;
};