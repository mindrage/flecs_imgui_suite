#pragma once

#include "imgui.h"

namespace ImGui {
  namespace Backend {

    bool Init();
    bool Begin();
    void End();
    void Destroy();
  }
}