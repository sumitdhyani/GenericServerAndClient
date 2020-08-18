#pragma once
#include "IConnectionInterface.h"

namespace ULCommunicationFramework
{
	template<class RawMsgType>
	struct IMessage
	{
		virtual void send(RawMsgType, IMsgPropagator<RawMsgType>) = 0;
	};
}