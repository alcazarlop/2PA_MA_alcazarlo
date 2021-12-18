///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Window basic class header

#ifndef __IMGUI_INTERFACE_H__
#define __IMGUI_INTERFACE_H__ 1

#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "sql_interface.h"
#include "lib_math/matrix2.h"
#include "lib_math/matrix3.h"
#include "lib_math/matrix4.h"

void ImGuiInit(SDL_Window* windows, SDL_Renderer* renderer);
void ImGuiRenderInit(SDL_Window* window);
void ImGuiRenderClear();
void ImGuiEvent(SDL_Event* event);
void ImGuiExit();

void ImGuiShowData(Database* database, Info** info);
void ShowTableData(Info** head);

void ImGuiMatrixCalculator();
void ImGuiMatrixLayout(char* id, int size, int index, Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4& mat4, char flag);

void ImGuiMatrixOperators(int index, Matrix2x2& mat2A, Matrix2x2& mat2B, Matrix2x2& resultMat2,
																		 Matrix3x3& mat3A, Matrix3x3& mat3B, Matrix3x3& resultMat3,
																		 Matix4x4& mat4A, Matix4x4& mat4B, Matix4x4& resultMat4);

void ImGuiMatrixOperations(int index, float& value, Matrix2x2& mat2, Matrix2x2& resultMat2,
																		 								Matrix3x3& mat3, Matrix3x3& resultMat3,
																		 								Matix4x4& mat4, Matix4x4& resultMat4);

#endif // __IMGUI_INTERFACE_H__
