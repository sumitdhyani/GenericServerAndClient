#pragma once
#include "IServerInterface.hpp"

namespace ULCommunicationFramework
{
	template <class RecMsgObjType, class SendMsgObjType>
	using  IActiveConnectionClientInterface = IActiveConnectionServerInterface<RecMsgObjType, SendMsgObjType>;

	template <class RecMsgObjType, class SendMsgObjType>
	using IPassiveConnectionClientInterface = IPassiveConnectionServerInterface<RecMsgObjType, SendMsgObjType>;
}
