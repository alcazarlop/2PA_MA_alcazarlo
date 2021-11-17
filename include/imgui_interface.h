
#ifndef __IMGUI_INTERFACE_H__
#define __IMGUI_INTERFACE_H__ 1

#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "sql_interface.h"

void ImGuiInit(SDL_Window* windows, SDL_Renderer* renderer);
void ImGuiRenderInit(SDL_Window* window);
void ImGuiRenderClear();
void ImGuiEvent(SDL_Event* event);
void ImGuiExit();

void ImGuiShowData(Database* database, Info** info);
void ShowTableData(Info** head);

#endif // __IMGUI_INTERFACE_H__
