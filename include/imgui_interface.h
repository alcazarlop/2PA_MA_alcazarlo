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
#include "lib_math/vector2.h"
#include "lib_math/vector3.h"
#include "lib_math/vector4.h"
#include "lib_math/math_utils.h"

void ImGuiInit(SDL_Window* windows, SDL_Renderer* renderer);
void ImGuiRenderInit(SDL_Window* window);
void ImGuiRenderClear();
void ImGuiEvent(SDL_Event* event);
void ImGuiExit();

//SQL Funcs
void ImGuiShowData(Database* database, Info** info);
void ShowTableData(Info** head);

//Matrix Calcualtion Funcs
void ImGuiMatrixCalculator();
void ImGuiMatrixLayout(char* id, int size, int index, Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4& mat4, char flag);

void ImGuiMatrixOperators(int index, Matrix2x2& mat2A, Matrix2x2& mat2B, Matrix2x2& resultMat2,
																		 Matrix3x3& mat3A, Matrix3x3& mat3B, Matrix3x3& resultMat3,
																		 Matix4x4& mat4A, Matix4x4& mat4B, Matix4x4& resultMat4);

void ImGuiMatrixScalarOperators(int index, Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4&mat4,
																				   Matrix2x2& resMat2, Matrix3x3& resMat3, Matix4x4& resMat4);

void ImGuiMatrixOperations(int index, float& value, Matrix2x2& mat2, Matrix2x2& resultMat2,
																		 								Matrix3x3& mat3, Matrix3x3& resultMat3,
																		 								Matix4x4& mat4, Matix4x4& resultMat4);


//Vector Calculation Funcs
void ImGuiVectorCalculator();
void ImGuiVectorLayout(int index, char* id, Vector2& vec2, Vector3& vec3, Vector4& vec4, char flag);
void ImGuiVectorOperators(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
																		 Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
																		 Vector4& vec4A, Vector4& vec4B, Vector4 &resVec4);

void ImGuiVectorScalarOperators(int index, Vector2& vec2, Vector3& vec3, Vector4& vec4,
																		 Vector2& resVec2, Vector3& resVec3, Vector4& resVec4);

void ImGuiVectorOperations(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
																			Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
																			Vector4& vec4A, Vector4& vec4B, Vector4& resVec4,
																			float& res);

#endif // __IMGUI_INTERFACE_H__
