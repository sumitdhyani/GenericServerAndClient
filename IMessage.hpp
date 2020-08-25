#pragma once
#include "IConnectionInterface.hpp"

namespace ULCommunicationFramework
{
	template<class RawMsgType>
	struct IMessage
	{
		typedef IMsgPropagator<RawMsgType> IMsgPropagator;
		DEFINE_PTR(IMsgPropagator)
		virtual void send(RawMsgType, IMsgPropagator_SPtr, std::function<void(bool)>) = 0;
	};
}
