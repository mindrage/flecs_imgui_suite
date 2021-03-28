#include <flecs.h>
#include <flecs_imgui.h>
#include <imgui_backend.h>


int main()
{
  if(!ImGui::Backend::Init())
    return 1;

  while(ImGui::Backend::Begin()) {
    
    ImGui::ShowDemoWindow();

    ImGui::Backend::End();
  }

  ImGui::Backend::Destroy();

  return 0;
}
