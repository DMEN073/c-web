#include "imgui.h"
// #include "imgui_impl_sdl2.h"
// #include "imgui_impl_opengl3.h"

int main()
{
    ImGui::CreateContext();
    ImGui::NewFrame();
    ImGui::Text("Hello, ImGui with Emscripten!");
    ImGui::Render();
    return 0;
}