
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

  ImGui::Begin("Matrix Calculator");

  // ImGui::ShowDemoWindow();
 
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
    ImGui::Text("Mat A Operations");
    ImGuiMatrixOperations(index, value, Mat2A, resultMat2, Mat3A, resultMat3, Mat4A, resultMat4);
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::Text("Matrix Result");
    ImGuiMatrixLayout("Result", size, index, resultMat2, resultMat3, resultMat4, 1);
    ImGui::Text("Value Result %f", value);

    ImGui::EndTable();
  }

  if(ImGui::Button("Matrix 2x2")) { index = 0; size = 2; width = 120.0f; }
  if(ImGui::Button("Matrix 3x3")) { index = 1; size = 3; width = 200.0f; }
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