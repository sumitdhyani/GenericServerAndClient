#pragma once
#include "IConnectionInterface.hpp"

namespace ULCommunicationFramework
{
	template<class RawMsgType, class ExceptionType>
	struct IMessage
	{
		typedef IMsgPropagator<RawMsgType, ExceptionType> IMsgPropagator;
		DEFINE_PTR(IMsgPropagator)
		virtual void send(IMsgPropagator&, std::function<void(ExceptionType&)>) = 0;

		virtual RawMsgType raw() = 0;
	};
}
