/*
 * All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
 * its licensors.
 *
 * For complete copyright and license terms please see the LICENSE at the root of this
 * distribution (the "License"). All use of this software is governed by the License,
 * or, if provided, by the license below or the license accompanying this file. Do not
 * remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 */

#include <aws/gamelift/internal/model/request/WebSocketStopMatchBackfillRequest.h>
#include <aws/gamelift/internal/util/JsonHelper.h>

namespace Aws {
namespace GameLift {
namespace Internal {

bool WebSocketStopMatchBackfillRequest::Serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    Message::Serialize(writer);
    JsonHelper::WriteNonEmptyString(writer, GAME_SESSION_ARN, m_gameSessionArn);
    JsonHelper::WriteNonEmptyString(writer, MATCHMAKING_CONFIG_ARN, m_matchmakingConfigurationArn);
    JsonHelper::WriteNonEmptyString(writer, TICKET_ID, m_ticketId);
    return true;
}

bool WebSocketStopMatchBackfillRequest::Deserialize(const rapidjson::Value &value) {
    Message::Deserialize(value);
    m_gameSessionArn = JsonHelper::SafelyDeserializeString(value, GAME_SESSION_ARN);
    m_matchmakingConfigurationArn = JsonHelper::SafelyDeserializeString(value, MATCHMAKING_CONFIG_ARN);
    m_ticketId = JsonHelper::SafelyDeserializeString(value, TICKET_ID);
    return true;
}

std::ostream &operator<<(std::ostream &os, const WebSocketStopMatchBackfillRequest &stopMatchBackfillMessage) {
    const Message *message = &stopMatchBackfillMessage;
    os << message->Serialize();
    return os;
}

} // namespace Internal
} // namespace GameLift
} // namespace Aws