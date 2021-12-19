
#include "imgui_interface.h"

void ImGuiInit(SDL_Window* window, SDL_Renderer* renderer){
	ImGui::CreateContext();
  ImGui_ImplSDL2_InitForSDLRenderer(window);
  ImGui_ImplSDLRenderer_Init(renderer);
  ImGui::SetNextWindowSize(ImVec2(320, 400));
}

void ImGuiRenderInit(SDL_Window* window){
  ImGui_ImplSDLRenderer_NewFrame();
  ImGui_ImplSDL2_NewFrame(window);
  ImGui::NewFrame();
}

void ImGuiRenderClear(){
  ImGui::Render();
  ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiEvent(SDL_Event* event)
{
  ImGui_ImplSDL2_ProcessEvent(event);
}

void ImGuiExit(){
  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
}

void ImGuiShowData(Database* database, Info** info){

  static bool open = false;

  ImGui::Begin("SQL Window", nullptr);

  ImGui::Text("Database status:"); 
  ImGui::SameLine();
  ImGui::TextColored(ImVec4(0,1,0,1), "%s", open ? "Open" : "Close"); 
  ImGui::SameLine();

  if(ImGui::SmallButton(open ? " Close Test Database " : " Open Test Database ")){
    if(!open){
      SQLInit(database, info, "../data/test.db");
      open = true;
    }
    else{
      SQLClose(database);
      open = false;
    }
  }

  if(open){
    ImGui::InputText("Query", database->sql_query, kQuerySize);
    ImGui::SameLine();
    if(ImGui::Button("Execute")){
      SQLExecute(database, info);
    }
    ShowTableData(info);  
  }

  ImGui::End();
}

void ShowTableData(Info** head){
  if(nullptr != *head){
    for(Info* node = *head; node != nullptr; node = node->next){
      if(ImGui::CollapsingHeader(node->value)){
        ImGui::Text("Name: %s", node->colname);
        ImGui::Text("Value: %s", node->value);
      }
    }
    ImGui::Spacing();
  }
  else return;
}

void ImGuiMatrixCalculator(){
  
  static int size = 2;
  static int index = 0;
  static float width = 180.0f;
  static float value = 0.0f;

  static Matrix2x2 Mat2A;
  static Matrix2x2 Mat2B;
  static Matrix2x2 resultMat2;

  static Matrix3x3 Mat3A;
  static Matrix3x3 Mat3B;
  static Matrix3x3 resultMat3;

  static Matix4x4 Mat4A;
  static Matix4x4 Mat4B;
  static Matix4x4 resultMat4;

  ImGui::SetNextWindowSize(ImVec2(700.0f, 290.0f));
  ImGui::Begin("Matrix Calculator", nullptr, ImGuiWindowFlags_NoResize);

  if (ImGui::BeginTable("Matrix Calculator", 3)){
    ImGui::TableSetupColumn("Matrix A", ImGuiTableColumnFlags_WidthFixed, width); 
    ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 25.0f);
    ImGui::TableSetupColumn("Matrix B", ImGuiTableColumnFlags_WidthFixed, width);       
    ImGui::TableHeadersRow();

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGuiMatrixLayout("A", size, index, Mat2A, Mat3A, Mat4A, 0);
    ImGui::TableSetColumnIndex(1);
    ImGuiMatrixOperators(index, Mat2A, Mat2B, resultMat2, Mat3A, Mat3A, resultMat3, Mat4A, Mat4B, resultMat4);
    ImGui::TableSetColumnIndex(2);
    ImGuiMatrixLayout("B", size, index, Mat2B, Mat3B, Mat4B, 0);
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::Text("Matrix Result");
    ImGuiMatrixLayout("Result", size, index, resultMat2, resultMat3, resultMat4, 1);
    ImGui::Spacing();
    ImGui::Text("Value Result %f", value);
    ImGui::TableSetColumnIndex(2);
    ImGui::Text("Mat A Operations");
    ImGuiMatrixOperations(index, value, Mat2A, resultMat2, Mat3A, resultMat3, Mat4A, resultMat4);

    ImGui::EndTable();
  }

  if(ImGui::Button("Matrix 2x2")) { index = 0; size = 2; width = 120.0f; }
  ImGui::SameLine();
  if(ImGui::Button("Matrix 3x3")) { index = 1; size = 3; width = 200.0f; }
  ImGui::SameLine();
  if(ImGui::Button("Matrix 4x4")) { index = 2; size = 4; width = 250.0f; }

  ImGui::End();
}

void ImGuiMatrixLayout(char* id, int size, int index, 
                       Matrix2x2& mat2, Matrix3x3& mat3, Matix4x4& mat4, char flag){
  
  char buffer[3];
  memset(buffer, '\0', 3);
  if(ImGui::BeginTable(id, size)){
    for(int i = 0; i < size * size; ++i){
      if(i % size == 0)
        ImGui::TableNextRow();
      ImGui::TableNextColumn();
      ImGui::PushItemWidth(40.0f);
      if(flag == 0){
        switch(index){
          case 0: ImGui::InputFloat(_itoa(i, buffer, 10), &mat2.m[i]); break;
          case 1: ImGui::InputFloat(_itoa(i, buffer, 10), &mat3.m[i]); break;
          case 2: ImGui::InputFloat(_itoa(i, buffer, 10), &mat4.m[i]); break;
        }
      }
      if(flag == 1){
        switch(index){
          case 0: ImGui::Text("%02f", mat2.m[i]); break;
          case 1: ImGui::Text("%02f", mat3.m[i]); break;
          case 2: ImGui::Text("%02f", mat4.m[i]); break;
        }
      }
    }
    ImGui::EndTable();
  }
}

void ImGuiMatrixOperators(int index, Matrix2x2& mat2A, Matrix2x2& mat2B, Matrix2x2& resultMat2,
                                     Matrix3x3& mat3A, Matrix3x3& mat3B, Matrix3x3& resultMat3,
                                     Matix4x4& mat4A, Matix4x4& mat4B, Matix4x4& resultMat4)
{
  if(ImGui::Button("+")){
    switch(index){
      case 0: resultMat2 = mat2A + mat2B; break;
      case 1: resultMat3 = mat3A + mat3B; break;
      case 2: resultMat4 = mat4A + mat4B; break;
    }
  }
  if(ImGui::Button("-")){
    switch(index){
      case 0: resultMat2 = mat2A - mat2B; break;
      case 1: resultMat3 = mat3A - mat3B; break;
      case 2: resultMat4 = mat4A - mat4B; break;
    }
  }
  if(ImGui::Button("*")){
    switch(index){
      case 0: resultMat2 = mat2A.Multiply(mat2B); break;
      case 1: resultMat3 = mat3A.Multiply(mat3B); break;
      case 2: resultMat4 = mat4A.Multiply(mat4B); break;
    }
  }
}

void ImGuiMatrixOperations(int index, float& value, Matrix2x2& mat2, Matrix2x2& resultMat2,
                                                    Matrix3x3& mat3, Matrix3x3& resultMat3,
                                                    Matix4x4& mat4, Matix4x4& resultMat4)
{
  switch(index){
    case 0: 
    {
      if(ImGui::Button("Traspose")) { resultMat2 = mat2.Transpose(); }
      ImGui::SameLine();
      if(ImGui::Button("Adjoint")) { resultMat2 = mat2.Adjoint(); }
      if(ImGui::Button("Inverse")) { resultMat2 = mat2.Inverse(); }
      ImGui::SameLine();
      if(ImGui::Button("Determinant")) { value = mat2.Determinant(); }
      break;
    }
    case 1: 
    {
      if(ImGui::Button("Transpose")) { resultMat3 = mat3.Transpose(); }
      ImGui::SameLine();
      if(ImGui::Button("Adjoint")) { resultMat3 = mat3.Adjoint(); }
      if(ImGui::Button("Inverse")) { mat3.GetInverse(resultMat3); }
      ImGui::SameLine();
      if(ImGui::Button("Determinant")) { value = mat3.Determinant(); }
      break;
    }
    case 2: 
    {
      if(ImGui::Button("Transpose")) { resultMat4 = mat4.Transpose(); }
      ImGui::SameLine();
      if(ImGui::Button("Adjoint")) { resultMat4 = mat4.Adjoint(); }
      if(ImGui::Button("Inverse")) { mat4.GetInverse(&resultMat4); }
      ImGui::SameLine();
      if(ImGui::Button("Determinant")) { value = mat4.Determinant(); }
      break;
    }
  }
}    

void ImGuiVectorCalculator(){

  static int index = 0;
  static float res = 0.0f;

  static Vector2 Vec2A;
  static Vector2 Vec2B;
  static Vector2 resultVec2;

  static Vector3 Vec3A;
  static Vector3 Vec3B;
  static Vector3 resultVec3;

  static Vector4 Vec4A;
  static Vector4 Vec4B;
  static Vector4 resultVec4;

  ImGui::SetNextWindowSize(ImVec2(500.0f, 300.0f));
  ImGui::Begin("Vector Calculator", nullptr,  ImGuiWindowFlags_NoResize);

  if(ImGui::BeginTable("Vector2", 4)){
    ImGui::TableSetupColumn("Vector A", ImGuiTableColumnFlags_WidthFixed, 100.0f); 
    ImGui::TableSetupColumn("Vector Ops", ImGuiTableColumnFlags_WidthFixed, 80.0f); 
    ImGui::TableSetupColumn("Scalar Ops", ImGuiTableColumnFlags_WidthFixed, 110.0f); 
    ImGui::TableSetupColumn("Vector B", ImGuiTableColumnFlags_WidthFixed, 180.0f); 
    ImGui::TableHeadersRow();

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGuiVectorLayout(index, "1", Vec2A, Vec3A, Vec4A, 0);

    ImGui::TableSetColumnIndex(1);
    ImGuiVectorOperators(index, Vec2A, Vec2B, resultVec2, 
                                Vec3A, Vec3B, resultVec3, 
                                Vec4A, Vec4B, resultVec4);

    ImGui::TableSetColumnIndex(2);
    ImGuiScalarOperators(index, Vec2A, Vec3A, Vec4A, resultVec2, resultVec3, resultVec4);

    ImGui::TableSetColumnIndex(3);
    ImGuiVectorLayout(index, "2", Vec2B, Vec3B, Vec4B, 0);

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    ImGui::Text("Resutl");
    ImGuiVectorLayout(index, "3", resultVec2, resultVec3, resultVec4, 1);
    ImGui::Spacing();
    ImGui::Text("Value %f", res);

    ImGui::TableSetColumnIndex(2);
    ImGui::Text("All operations \nare apply \nover Vector A");

    ImGui::TableSetColumnIndex(3);
    ImGui::Text("Operations");
    ImGuiVectorOperations(index, Vec2A, Vec2B, resultVec2,
                                 Vec3A, Vec3B, resultVec3,
                                 Vec4A, Vec4B, resultVec4,
                                 res);


    ImGui::EndTable();
  }

  if(ImGui::Button("Vector 2")) { index = 0; } ImGui::SameLine();
  if(ImGui::Button("Vector 3")) { index = 1; } ImGui::SameLine();
  if(ImGui::Button("Vector 4")) { index = 2; }

  ImGui::End();

}

void ImGuiVectorLayout(int index, char* id, Vector2& vec2, Vector3& vec3, Vector4& vec4, char flag){

  char* buffer_X = (char*) calloc(5, sizeof(char));
  char* buffer_Y = (char*) calloc(5, sizeof(char));
  char* buffer_Z = (char*) calloc(5, sizeof(char));
  char* buffer_W = (char*) calloc(5, sizeof(char));

  buffer_X = strcat(buffer_X, "x##");
  buffer_Y = strcat(buffer_Y, "y##");
  buffer_Z = strcat(buffer_Z, "z##");
  buffer_W = strcat(buffer_W, "w##");

  switch(index){
    case 0: 
    {
      if(flag == 0){
        ImGui::PushItemWidth(60.0f);
        ImGui::InputFloat(strcat(buffer_X, id), &vec2.x);
        ImGui::InputFloat(strcat(buffer_Y, id), &vec2.y);
      }
      if(flag == 1){
        ImGui::Text("x %f", vec2.x);
        ImGui::Text("y %f", vec2.y);
      }
      break;
    }
    case 1: 
    {
      if(flag == 0){
        ImGui::PushItemWidth(60.0f);
        ImGui::InputFloat(strcat(buffer_X, id), &vec3.x);
        ImGui::InputFloat(strcat(buffer_Y, id), &vec3.y);
        ImGui::InputFloat(strcat(buffer_Z, id), &vec3.z);
      }
      if(flag == 1){
        ImGui::Text("x %f", vec3.x);
        ImGui::Text("y %f", vec3.y);
        ImGui::Text("z %f", vec3.z);
      }
      break;
    }
    case 2: 
    {
      if(flag == 0){
        ImGui::PushItemWidth(60.0f);
        ImGui::InputFloat(strcat(buffer_X, id), &vec4.x);
        ImGui::InputFloat(strcat(buffer_Y, id), &vec4.y);
        ImGui::InputFloat(strcat(buffer_Z, id), &vec4.z);
        ImGui::InputFloat(strcat(buffer_W, id), &vec4.w);
      }
      if(flag == 1){
        ImGui::Text("x %f", vec4.x);
        ImGui::Text("y %f", vec4.y);
        ImGui::Text("z %f", vec4.z);
        ImGui::Text("w %f", vec4.w);
      }
      break;
    }
  }

  free(buffer_X);
  free(buffer_Y);
  free(buffer_Z);
  free(buffer_W);

}

void ImGuiVectorOperators(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
                                     Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
                                     Vector4& vec4A, Vector4& vec4B, Vector4& resVec4)
{
  if(ImGui::Button("+##2")){
    switch(index){
      case 0: resVec2 = vec2A + vec2B; break;
      case 1: resVec3 = vec3A + vec3B; break;
      case 2: resVec4 = vec4A + vec4B; break;
    }
  }
  if(ImGui::Button("-##2")){
     switch(index){
      case 0: resVec2 = vec2A - vec2B; break;
      case 1: resVec3 = vec3A - vec3B; break;
      case 2: resVec4 = vec4A - vec4B; break;
    }
  }
}

void ImGuiScalarOperators(int index, Vector2& vec2, Vector3& vec3, Vector4& vec4,
                                     Vector2& resVec2, Vector3& resVec3, Vector4& resVec4){

  static float value = 0.0f;

  if(ImGui::Button("+##4")){
    switch(index){
      case 0: resVec2 = vec2 + value; break;
      case 1: resVec3 = vec3 + value; break;
      case 2: resVec4 = vec4 + value; break;
    }
  }
  ImGui::SameLine();
  if(ImGui::Button("-##4")){
     switch(index){
      case 0: resVec2 = vec2 - value; break;
      case 1: resVec3 = vec3 - value; break;
      case 2: resVec4 = vec4 - value; break;
    }
  }
  if(ImGui::Button("*##4")){
     switch(index){
      case 0: resVec2 = vec2 * value; break;
      case 1: resVec3 = vec3 * value; break;
      case 2: resVec4 = vec4 * value; break;
    }
  }
  ImGui::SameLine();
  if(ImGui::Button("/##4")){
     switch(index){
      case 0: resVec2 = vec2 / value; break;
      case 1: resVec3 = vec3 / value; break;
      case 2: resVec4 = vec4 / value; break;
    }
  }

  ImGui::InputFloat("Scalar:", &value);

}

void ImGuiVectorOperations(int index, Vector2& vec2A, Vector2& vec2B, Vector2& resVec2,
                                      Vector3& vec3A, Vector3& vec3B, Vector3& resVec3,
                                      Vector4& vec4A, Vector4& vec4B, Vector4& resVec4,
                                      float& res)
{

  static float time = 0.0f;

  switch(index){
    case 0:
    {
      if(ImGui::Button("Magnitude")){ res = vec2A.Magnitude(); } 
      ImGui::SameLine();
      if(ImGui::Button("SqrMagnitude")) { res = vec2A.SqrMagnitude(); }

      if(ImGui::Button("Distance")) { res = vec2A.Distance(vec2A, vec2B); }
      ImGui::SameLine();
      if(ImGui::Button("Dot Product")) { res = vec2A.DotProduct(vec2A, vec2B); }

      if(ImGui::Button("Scale")) { vec2A.Scale(vec2A); } 
      ImGui::SameLine();
      if(ImGui::Button("Normalize")) {resVec2 = vec2A.Normalized(); }

      if(ImGui::Button("Lerp")){ resVec2 = resVec2.Lerp(vec2A, vec2B, time); }
      ImGui::SameLine();
      if(ImGui::Button("Lerp Unclamped")){ resVec2 = resVec2.LerpUnclamped(vec2A, vec2B, time); }
    }
    break;
    case 1:
    {
      if(ImGui::Button("Magnitude")){ res = vec3A.Magnitude(); } 
      ImGui::SameLine();
      if(ImGui::Button("SqrMagnitude")) { res = vec3A.SqrMagnitude(); }

      if(ImGui::Button("Distance")) { res = vec3A.Distance(vec3A, vec3B); }
      ImGui::SameLine();
      if(ImGui::Button("Dot Product")) { res = vec3A.DotProduct(vec3A, vec3B); }

      if(ImGui::Button("Scale")) { vec3A.Scale(vec3A); } 
      ImGui::SameLine();
      if(ImGui::Button("Normalize")) {resVec3 = vec3A.Normalized(); }

      if(ImGui::Button("Lerp")){ resVec3 = resVec3.Lerp(vec3A, vec3B, time); }
      ImGui::SameLine();
      if(ImGui::Button("Lerp Unclamped")){ resVec3 = resVec3.LerpUnclamped(vec3A, vec3B, time); }

      if(ImGui::Button("Cross Product")){ resVec3 = resVec3.CrossProduct(vec3A, vec3B); }
      ImGui::SameLine();
      if(ImGui::Button("Reflect")){ resVec3 = resVec3.Reflect(vec3A, vec3B); }
    }
    break;
    case 2:
    {
      if(ImGui::Button("Magnitude")){ res = vec4A.Magnitude(); } 
      ImGui::SameLine();
      if(ImGui::Button("SqrMagnitude")) { res = vec4A.SqrMagnitude(); }

      if(ImGui::Button("Distance")) { res = vec4A.Distance(vec4A, vec4B); }
      ImGui::SameLine();
      if(ImGui::Button("Dot Product")) { res = vec4A.DotProduct(vec4A, vec4B); }

      if(ImGui::Button("Scale")) { vec4A.Scale(vec4A); } 
      ImGui::SameLine();
      if(ImGui::Button("Normalize")) {resVec4 = vec4A.Normalized(); }

      if(ImGui::Button("Lerp")){ resVec4 = resVec4.Lerp(vec4A, vec4B, time); }
    }
    break;
  }
  ImGui::InputFloat("Time", &time);
}
