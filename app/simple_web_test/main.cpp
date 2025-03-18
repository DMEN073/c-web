#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>
#include <SDL.h>
#include <SDL/SDL_opengl.h>
#include <emscripten.h>

// SDL Window
SDL_Window *window;
SDL_GLContext gl_context;

// Main loop function for Emscripten
void main_loop()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
        {
            emscripten_cancel_main_loop();
            return;
        }
    }

    // Start a new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // ImGui UI
    ImGui::Text("Hello, ImGui with Emscripten!");

    // Render ImGui
    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

int main()
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("ImGui + Emscripten", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    gl_context = SDL_GL_CreateContext(window);

    // Initialize ImGui
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 100");

    // Start the main loop
    emscripten_set_main_loop(main_loop, 0, 1);

    return 0;
}
