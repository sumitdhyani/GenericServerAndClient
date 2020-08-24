#pragma once
#include "IConnectionInterface.hpp"

namespace ULCommunicationFramework
{
	template<class RawMsgType>
	struct IMessage
	{
		virtual void send(RawMsgType, IMsgPropagator<RawMsgType>) = 0;
	};
}
