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
#include "path.h"

/** @brief Initializes ImGui for SDL2
 * 
 * The set of the necessary functions to correctly initialize
 * ImGui on SDL2
 * 
 * @param The window where ImGui will be displayed
 * @param The render for display ImGui
 */ 
void ImGuiInit(SDL_Window* windows, SDL_Renderer* renderer);

/** @brief Initializes the render of OpenGL for ImGui 
 * 
 * Contains the necessary functions to render ImGui on SDL
 * 
 * @param The window to render
 */ 
void ImGuiRenderInit(SDL_Window* window);

/** @brief Clears the renderer for ImGui
 * 
 * Contains the functions that clears ImGui's renderer
 */
void ImGuiRenderClear();

/** @brief Manages the event queue for ImGui
 * 
 * Contains the functions to manage events on ImGui
 * 
 * @param The queue of events
 */
void ImGuiEvent(SDL_Event* event);

/** @brief Destroys and frees the ImGui instances
 * 
 * Contains the functions for correctly close ImGui
 */
void ImGuiExit();

//SQL Funcs

/** @brief Shows the SQL manager window
 * 
 * The functions shows and manages the different 
 * options for the SQL database
 * 
 * @param The database which be consulted
 * @param The struct that contain the information 
 * 				consulted in the database
 */
void ImGuiShowData(Database* database, Info** info);

/** @brief Shows the information consulted in the database
 * 
 * The functions displays the infomation that had been queried.
 *
 *  @param The struct that contain the information 
 * 				consulted in the database
 */
void ShowTableData(Info** head);

//Matrix Calcualtion Funcs

/** @brief Displays the matrix calculator
 * 
 * The function contains the different matrix overlays
 * and options
 */
void ImGuiMatrixCalculator();

/** @brief Contains the matrix layouts and operations
 * 
 * The function displays the different operations for 
 * the matrix and its current layout
 * 
 * @param The id of the matrix 
 * @param The size of the matrix (2, 3 or 4)
 * @param Determinates what matrix (2, 3 or 4) is shown
 * @param The matrix2x2 to show
 * @param The matrix3x3 to show
 * @param The matrix4x4 to show
 * @param The flag that shows either the matrix or the result of the matrix
 */
void ImGuiMatrixLayout(char* id, int size, int index, Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4& mat4, char flag);

/** @brief The operators, NOT operations, for the matrix with other matrix
 * 
 * Contains the different operators (+, -, *) implemented 
 * for the matrix and shows the different options. This function
 * ONLY contains the operators between matrix, not scalar values.
 * 
 * @param Determinates what matrix (2, 3 or 4) is shown
 * @param The first matrix2x2 to operate with
 * @param The second matrix2x2 to operate with
 * @param The result of the matrix2x2
 * @param The first matrix3x3 to operate with
 * @param The second matrix3x3 to operate with
 * @param The result of the matrix3x3
 * @param The first matrix4x4 to operate with
 * @param The second matrix4x4 to operate with
 * @param The result of the matrix4x4 
 */
void ImGuiMatrixOperators(int index, Matrix2x2& mat2A, Matrix2x2& mat2B, Matrix2x2& resultMat2,
																		 Matrix3x3& mat3A, Matrix3x3& mat3B, Matrix3x3& resultMat3,
																		 Matix4x4& mat4A, Matix4x4& mat4B, Matix4x4& resultMat4);

/** @brief The operators, NOT operations, of the matrix with scalar values
 * 
 * Contains the different operators (+, -, /, *) implemented 
 * for the matrix and shows the different options. This functions
 * ONLY contains the operators between matrix and scalar values.
 * 
 * @param Determinates what matrix (2, 3 or 4) is shown
 * @param The first matrix2x2 to operate with
 * @param The result of the matrix2x2
 * @param The first matrix3x3 to operate with
 * @param The result of the matrix3x3
 * @param The first matrix4x4 to operate with
 * @param The result of the matrix4x4 
 */
void ImGuiMatrixScalarOperators(int index, Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4&mat4,
																				   Matrix2x2& resMat2, Matrix3x3& resMat3, Matix4x4& resMat4);

/** @brief The operations, NOT operators, of the matrix 
 * 
 * Contains the different operations (Adjoint, Inverse, ...) 
 * implemented for the matrix
 * 
 * @param Determinates what matrix (2, 3 or 4) is shown
 * @param The value of the determinate of the matrix
 * @param The first matrix2x2 to operate with
 * @param The result of the matrix2x2
 * @param The first matrix3x3 to operate with
 * @param The result of the matrix3x3
 * @param The first matrix4x4 to operate with
 * @param The result of the matrix4x4 
 */
void ImGuiMatrixOperations(int index, float& value, Matrix2x2& mat2, Matrix2x2& resultMat2,
																		 								Matrix3x3& mat3, Matrix3x3& resultMat3,
																		 								Matix4x4& mat4, Matix4x4& resultMat4);

//Vector Calculation Funcs

/** @brief Displays the Vector calculator window
 * 
 * Displays the vector calculator window, and it's options
 */ 
void ImGuiVectorCalculator();

/** @brief The layout of the vectors
 * 
 * The functions contains the layout of the vector
 * and it's different options
 * 
 * @param Determinates the type of the vector
 * @param The id for the different vector variables (x, y, ...)
 * @param The vector2 to display
 * @param The vector3 to display
 * @param The vector4 to display
 * @param The flag to either show the vectors or the result
 */ 
void ImGuiVectorLayout(int index, char* id, Vector2& vec2, Vector3& vec3, Vector4& vec4, char flag);

/** @brief Contains the operators options between vector, NOT scalar values
 * 
 * Contains the different operators implemented 
 * for the vectors.
 * 
 * @param Determinates the type of the vector
 * @param The first vector2 to operate
 * @param The second vector2 to operate
 * @param The result vector2 
 * @param The first vector3 to operate
 * @param The second vector3 to operate
 * @param The result vector3 
 * @param The first vector3 to operate
 * @param The second vector4 to operate
 * @param The result vector4 
 */ 
void ImGuiVectorOperators(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
																		 Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
																		 Vector4& vec4A, Vector4& vec4B, Vector4 &resVec4);

/** @brief Contains the vector scalar operators
 * 
 * The different operators between vectors and scalar values
 * 
 * @param Determinates the type of the vector
 * @param The vector2 to operate
 * @param The vector3 to operate
 * @param The vector4 to operate
 * @param The result vector2 
 * @param The result vector3 
 * @param The result vector4 
 */ 
void ImGuiVectorScalarOperators(int index, Vector2& vec2, Vector3& vec3, Vector4& vec4,
																		 Vector2& resVec2, Vector3& resVec3, Vector4& resVec4);

/** @brief Contains the differen operations of the vectors
 * 
 * The functions contains the different operations
 * implemented for the vectors. Some operations will only be 
 * applied to the first vector, the second is just needed for other
 * vector operations
 * 
 * @param Determinates the type of the vector
 * @param The first vector2 to operate
 * @param The second vector2 to operate
 * @param The result vector2 
 * @param The first vector3 to operate
 * @param The second vector3 to operate
 * @param The result vector3 
 * @param The first vector4 to operate
 * @param The second vector4 to operate
 * @param The result vector4 
 * @param The value of determinate vector operations
 */ 
void ImGuiVectorOperations(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
																			Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
																			Vector4& vec4A, Vector4& vec4B, Vector4& resVec4,
																			float& res);

//ImGui 2D Transform Funcs

/** @brief (DEPRECATED) Displays a window to transform a determinate 2D entity 
 * 
 * The function contains different options to transform
 * a determinate 2D figure
 * 
 * @param The path class to draw
 */ 
void ImGui2DTransform(Path& path);

#endif // __IMGUI_INTERFACE_H__
