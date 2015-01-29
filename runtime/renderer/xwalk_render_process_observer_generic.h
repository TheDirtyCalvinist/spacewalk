// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_RUNTIME_RENDERER_XWALK_RENDER_PROCESS_OBSERVER_GENERIC_H_
#define XWALK_RUNTIME_RENDERER_XWALK_RENDER_PROCESS_OBSERVER_GENERIC_H_

#include <string>

#include "base/compiler_specific.h"
#include "content/public/renderer/render_process_observer.h"
#include "url/gurl.h"
#include "v8/include/v8.h"
#include "xwalk/application/common/security_policy.h"

namespace blink {
class WebFrame;
}  // namespace blink

namespace xwalk {

// FIXME: Using filename "xwalk_render_process_observer_generic.cc(h)" temporary
// , due to the conflict filename with Android port.
// A RenderViewObserver implementation used for handling XWalkView
// specific render-process wide IPC messages.
class XWalkRenderProcessObserver : public content::RenderProcessObserver {
 public:
  XWalkRenderProcessObserver();
  virtual ~XWalkRenderProcessObserver();

  // content::RenderProcessObserver implementation.
  virtual bool OnControlMessageReceived(const IPC::Message& message) OVERRIDE;
  virtual void WebKitInitialized() OVERRIDE;
  virtual void OnRenderProcessShutdown() OVERRIDE;

  bool IsWarpMode() const {
    return security_mode_ == application::SecurityPolicy::WARP;
  }
  bool IsCSPMode() const {
    return security_mode_ == application::SecurityPolicy::CSP;
  }

  const GURL& app_url() const { return app_url_; }
#if defined(OS_TIZEN)
  std::string GetOverridenUserAgent() const;
#endif

 private:
  void OnSetAccessWhiteList(
      const GURL& source, const GURL& dest, bool allow_subdomains);
  void OnEnableSecurityMode(
      const GURL& url, application::SecurityPolicy::SecurityMode mode);
  void OnSuspendJSEngine(bool is_pause);
#if defined(OS_TIZEN)
  void OnUserAgentChanged(const std::string& userAgentString);
  std::string overriden_user_agent_;
#endif

  bool is_webkit_initialized_;
  bool is_suspended_;
  application::SecurityPolicy::SecurityMode security_mode_;
  GURL app_url_;
};
}  // namespace xwalk

#endif  // XWALK_RUNTIME_RENDERER_XWALK_RENDER_PROCESS_OBSERVER_GENERIC_H_
