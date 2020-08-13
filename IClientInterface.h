#pragma once
#include "IServerInterface.h"

template <class RecMsgObjType, class SendMsgObjType>
using  IActiveConnectionClientInterface = IActiveConnectionServerInterface<RecMsgObjType, SendMsgObjType>;

template <class RecMsgObjType, class SendMsgObjType>
using IPassiveConnectionClientInterface = IPassiveConnectionServerInterface<RecMsgObjType, SendMsgObjType>;
