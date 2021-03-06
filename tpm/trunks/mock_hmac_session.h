//
// Copyright (C) 2015 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef TRUNKS_MOCK_HMAC_SESSION_H_
#define TRUNKS_MOCK_HMAC_SESSION_H_

#include <string>

#include <gmock/gmock.h>

#include "trunks/hmac_session.h"

namespace trunks {

class MockHmacSession : public HmacSession {
 public:
  MockHmacSession();
  ~MockHmacSession() override;

  MOCK_METHOD0(GetDelegate, AuthorizationDelegate*());
  MOCK_METHOD3(StartBoundSession, TPM_RC(
      TPMI_DH_ENTITY bind_entity,
      const std::string& bind_authorization_value,
      bool enable_encryption));
  MOCK_METHOD1(StartUnboundSession, TPM_RC(bool enable_encryption));
  MOCK_METHOD1(SetEntityAuthorizationValue, void(const std::string& value));
  MOCK_METHOD1(SetFutureAuthorizationValue, void(const std::string& value));

 private:
  DISALLOW_COPY_AND_ASSIGN(MockHmacSession);
};

}  // namespace trunks

#endif  // TRUNKS_MOCK_HMAC_SESSION_H_
